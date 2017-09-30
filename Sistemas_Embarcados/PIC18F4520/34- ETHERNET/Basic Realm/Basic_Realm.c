/*
 * Project Name:
     basicRealm
 * Target Platform:
     PIC18 family, should work also on PIC16 with reduced possibilities
 * Copyright:
     (c) mikroElektronika, 2008.
 * Revision History:
     20080108:
       - Initial release. Author: Bruno Gavand.
 *
 * description  :
 *              This program show how to use the HTTP utils mini-library,
 *              to build a private web zone (username + password needed)
 *              with basic realm authentication method.
 *                               username: mikroe
 *                               password: basicrealm
 *              Includes also some other useful functions and methods.
 *
 *      mE Serial Ethernet board on PORTC
 *      RC0 : !RESET    to ENC reset input pin
 *      RC1 : !CS       to ENC chip select input pin
 *      RC0 : !RESET    to ENC reset input pin
 *      RC1 : !CS       to ENC chip select input pin
 *      the ENC28J60 SPI bus CLK, SO, SI must be connected to the corresponding SPI pins of the PIC
 *      the INT and WOL signals from the ENC are not used
 *
 * Test configuration:
     MCU:             PIC18F4520
                      http://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf
     Dev.Board:       EasyPIC6
                      http://www.mikroe.com/en/tools/easypic6/
     Oscillator:      HS-PLL4, 08.000MHz
     Ext. Modules:    mE Serial Ethernet board
                      http://www.mikroe.com/en/tools/serialeth/
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/en/compilers/mikroc/pro/pic/
 * NOTES:
     - Since the ENC28J60 doesn't support auto-negotiation, full-duplex mode is
       not compatible with most switches/routers.  If a dedicated network is used
       where the duplex of the remote node can be manually configured, you may
       change this configuration.  Otherwise, half duplex should always be used.
     - External power supply should be used due to Serial Ethernet Board power consumption. 
     - PORTC : pull-up    (place jumper J3 to upper position)  (board specific)

 */

/*
 * library header
 */
#include        "httpUtils.h"

/*
 * pictures
 */
#include        "pictures.h"

/*
 * HTTP request buffer size (extra bytes will be ignored)
 */
#define  HTTP_REQUEST_SIZE 50

/*
 * username and password of the private zone,
 * separated by a period
 */
#define PRIVATE_LOGINPASSWD     "mikroe:basicrealm"

/*
 * reply message if authorization fails or if user gives up
 */
#define MSG_DENIED              "Authorization Required"

/*
 * private web zone name, will be displayed by the browser
 */
#define ZONE_NAME               "HTTP Utils private zone"

/*
 * main page : public zone
 */
const unsigned char publicHTML[] = "<html><body>\
<center>\
<h1>Microgenios Soluções Eletrônica Ltda - www.microgenios.com.br</h1>\
<h1>Autenticação com MikroC PRO for PIC</h1>\
<h2>\
<img src=\"/stop.gif\">\
<a href=\"/private\"> Clique aqui e digite sua senha</a>\
<img src=\"/stop.gif\">\
</h2>\
</center>\
</body></html>" ;

/*
 * second page : private zone
 */
const unsigned char privateHTML[] = "<html><body>\
<center>\
<h2>\
<font color=red>\
<h1>Bem vindo a area Privada</h1>\
<img src=\"/good.gif\">\
<a href=\"/private/redirect\">Clique aqui e seja redirecionado para o site Microgenios</a>\
<img src=\"/good.gif\">\
</font>\
</h2>\
</center>\
</body></html>" ;

/*
 * path names
 */
unsigned char path_private[]    = "/private" ;          // private zone
unsigned char path_redirect[]   = "/redirect" ;         // redirect under private zone
unsigned char path_stop[]       = "/stop.gif" ;         // image
unsigned char path_good[]       = "/good.gif" ;         // another image

// mE ehternet NIC pinout
sfr sbit SPI_Ethernet_Rst at LATC.B0;
sfr sbit SPI_Ethernet_CS  at LATC.B1;
sfr sbit SPI_Ethernet_Rst_Direction at TRISC.B0;
sfr sbit SPI_Ethernet_CS_Direction  at TRISC.B1;
// end ethernet NIC definitions

/*
 * put your network settings here
 */
unsigned char   myMacAddr[6]      = {0x00, 0x14, 0xA5, 0x76, 0x19, 0x3f} ;  // ethernet board MAC address
unsigned char   myIpAddr[4]  = {192, 168,  1, 60 } ;                       // my IP address
unsigned char   gwIpAddr[4]  = {192, 168,  1,  1 } ;                       // gateway (router) IP address
unsigned char   ipMask[4]    = {255, 255, 255,  0 } ;                       // network mask (for example : 255.255.255.0)
unsigned char   dnsIpAddr[4] = {192, 168,  1,  1 } ;                       // DNS server IP address

/*
 * URL for redirection
 */
unsigned char redirURL[]          = "http://www.microgenios.com.br/" ;

/*
 * buffer to receive a copy of HTTP request
 */
unsigned char http_request[HTTP_REQUEST_SIZE + 1] ;

/*
 * no reply to UDP requests
 */
unsigned int    SPI_Ethernet_UserUDP(unsigned char *remoteHost, unsigned int remotePort, unsigned int destPort, unsigned int reqLength)
        {
        return(0) ;
        }

/*
 * TCP request processing
 */
unsigned int    SPI_Ethernet_UserTCP(unsigned char *remoteHost, unsigned int remotePort, unsigned int localPort, unsigned int reqLength, char *canClose)
        {
        unsigned int    len = 0 ;       // my reply length
        unsigned char   admin ;         // admin flag set when private zon is allowed
        unsigned char   *ptr ;          // pointer to buffer

        // should we close tcp socket after response is sent?
        // library closes tcp socket by default if canClose flag is not reset here
        // *canClose = 0; // 0 - do not close socket
                          // otherwise - close socket

        /*
         * check if request is on TCP port 80 (HTTP)
         */
        if(localPort != 80)
                {
                return(0) ;             // no reply to other ports
                }

        /*
         * check for a GET request
         */
        if(HTTP_getRequest(http_request, &reqLength, HTTP_REQUEST_SIZE) == 0)
                {
                return(0) ;             // no reply if not found
                }

        /*
         * try to find authorization
         */
        admin = HTTP_basicRealm(reqLength, PRIVATE_LOGINPASSWD) ;

        /*
         * process request string
         */
        if(memcmp(http_request, path_private, sizeof(path_private) - 1) == 0)   // is path under private section ?
                {
                // yes, points to sub path
                ptr = http_request + sizeof(path_private) - 1;

                // check if access is granted
                if(admin == 0)
                        {
                        // no, reply with access denied message
                        len = HTTP_accessDenied(ZONE_NAME, MSG_DENIED) ;
                        }
                else
                        {
                        // yes, test path if redirection is requested
                        if(memcmp(ptr, path_redirect, sizeof(path_redirect) - 1) == 0)
                                {
                                // yes, reply with redirect string
                                len = HTTP_redirect(redirURL) ;
                                }
                        else
                                {
                                // no, reply with private page
                                len = HTTP_html(privateHTML) ;
                                }
                        }
                }
        else if(memcmp(http_request, path_stop, strlen(path_stop)) == 0)        // is 'stop' image requested ?
                {
                // yes, reply with image header and dump image
                len = HTTP_imageGIF(dump_stop_GIF, DUMP_STOP_GIF_SIZE) ;
                }
        else if(memcmp(http_request, path_good, strlen(path_good)) == 0)        // is 'good' image requested ?
                {
                // yes, reply with image header and dump image
                len = HTTP_imageGIF(dump_good_GIF, DUMP_GOOD_GIF_SIZE) ;
                }
        else if(memcmp(http_request, "/", 1) == 0)                              // is home page requested ?
                {
                // yes, reply with html header and dump page
                len = HTTP_html(publicHTML) ;
                }
        else
                {
                // any other case, reply with error 404 (not found)
                len = HTTP_error() ;
                }

        return(len) ;   // return reply buffer length to library
        }

/*
 * program entry point
 */
void    main()
        {
        ADCON1 |= 0x0F;                  // Configure AN pins as digital
        CMCON  |= 7;                     // Turn off comparators

        SPI1_Init() ;    // init SPI communication with ethernet board
        SPI_Rd_Ptr = SPI1_Read;
        SPI_Ethernet_Init(myMacAddr, myIpAddr, 1) ; // init ethernet board

        // dhcp will not be used here, so use preconfigured addresses
        SPI_Ethernet_confNetwork(ipMask, gwIpAddr, dnsIpAddr) ;

        for(;;)         // forever
                {
                /*
                 * if necessary, test the return value to get error code
                 */
                SPI_Ethernet_doPacket() ;   // process incoming Ethernet packets and do services
                }
        }
