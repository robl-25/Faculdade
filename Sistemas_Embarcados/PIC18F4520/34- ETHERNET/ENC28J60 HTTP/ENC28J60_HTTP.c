/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Exemplo WebServer com ENC28J60
         OBJETIVO: Aprender a ler temperatura e usar o CUSTOM CHAR.
            AUTOR: Fabio Mulero.[fabio@microgenios.com.br]
********************************************************************************
 MICROCONTROLADOR: PIC18F4520.
 http://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf

 PLACA DE DESENVOLVIMENTO: KIT PICgenios - PIC18F
 http://www.microgenios.com.br/news/index.php?option=com_content&task=view&id=88&Itemid=134

 PLACA ETHERNET - ENC28J60
 http://www.microgenios.com.br/
 
 SOFTWARE: MikroC PRO for PIC
 http://www.mikroe.com/en/compilers/mikroc/pro/pic/

************************ Configurações do KIT Picgenios ************************
 CRISTAL: 8Mhz.

 CHAVES DE FUNÇÃO:
  --------------------- ----------------------
 |GLCD\LCD ( 1) = ON   |DIS1     ( 1) = OFF   |
 |RX       ( 2) = OFF  |DIS2     ( 2) = OFF   |
 |TX       ( 3) = OFF  |DIS3     ( 3) = OFF   |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = OFF   |
 |REL2     ( 5) = OFF  |INFR     ( 5) = OFF   |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = ON    |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = ON    |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = OFF  |AN0      ( 9) = OFF   |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
OBS:
- HABILITAR BIBLIOTECA LCD.
- HABILITAR BIBLIOTECA A/D.
- HABILITAR BIBLIOTECA CONVERTIONS.

- CONECTAR A PLACA ETHERNET NA EXPANSÃO DO PORTC.
********************************************************************************
*/
// Configurar flags de duplex
#define Spi_Ethernet_HALFDUPLEX     0x00  // half duplex
#define Spi_Ethernet_FULLDUPLEX     0x01  // full duplex

// Pinos de Conecção da Placa Ethernet
sfr sbit SPI_Ethernet_Rst at PORTC.B0;
sfr sbit SPI_Ethernet_CS  at PORTC.B1;
sfr sbit SPI_Ethernet_Rst_Direction at TRISC.B0;
sfr sbit SPI_Ethernet_CS_Direction  at TRISC.B1;

// CONFIGURAÇÃO DOS PINOS DO LCD.
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;

// DIREÇÃO DOS PINOS.
sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;

/************************************************************
 * Configuração da constantes de ROM
 */
const code unsigned char httpHeader[] = "HTTP/1.1 200 OK\nContent-type: " ;  // HTTP header
const code unsigned char httpMimeTypeHTML[] = "text/html\n\n" ;              // HTML MIME type
const code unsigned char httpMimeTypeScript[] = "text/plain\n\n" ;           // TEXT MIME type
unsigned char httpMethod[] = "GET /";
/*
 * web page, dividida em 2 partes :
 * Essa página HTML pega o status da placa e cria ela com javascript
 */
const code   unsigned char    *indexPage =                   // Modificar o endereço de IP para a página ser recarregada
"<meta http-equiv='refresh' content='2;url=http://192.168.1.60'>\
<HTML><HEAD><title>Mini Web Server [PIC + ENC28J60]</title>\
<script src=/s></script></HEAD>\
<BODY>\
<h1>Mini Web Server [PIC + ENC28J60]</h1>\
Esta e a requisicao HTTP n.:<script>document.write(REQ)</script><br>\
<a href=/>Recarregar Pagina</a>\
<table width='600px' cellspacing='5' cellpadding='0'>\
<tr><td valign='top' width='10%'>\
<table width='100%' border='1'>\
<tr><th colspan='2'>ADC</th></tr>\
<tr bgcolor='silver'><td>AN0</td><td bgcolor='#66FF66'><script>document.write(AN0)</script></td></tr>\
<tr bgcolor='silver'><td>AN1</td><td bgcolor='#66FF66'><script>document.write(AN1)</script></td></tr>\
</table></td><td width='40%' valign='top'><table width='100%' border='1'>\
<tr><th colspan='2'>PORTB</th></tr><script>";

const code   unsigned char    *indexPage2 =
"var str,i;str=\"\";for(i=0;i<6;i++){str+=\"<tr bgcolor='silver'><td>BOTAO N.\"+i+\"</td>\";\
if(!(PORTB&(1<<i))){str+=\"<td bgcolor='#66FF66'>LIG.\";}\
else {str+=\"<td bgcolor='#FF6666'>DESL.\";}\
str+=\"</td></tr>\";}\
document.write(str) ;\
</script></table></td><td width='50%'>\
<table width='100%' border='1'>\
<tr><th colspan='3'>PORTD</th></tr>\
<script>\
var str,i;str=\"\";\
for(i=0;i<8;i++)\
{str+=\"<tr bgcolor='silver'><td>LED N.\"+i+\"</td>\";\
if(PORTD&(1<<i)){str+=\"<td bgcolor='#66FF66'>LIG.\";}\
else {str+=\"<td bgcolor='#FF6666'>DESL.\";}\
str+=\"</td><td><a href=/t\"+i+\">Alternar</a></td></tr>\";}document.write(str) ;\
</script></table></td></tr></table>\
</BODY></HTML>" ;
/***********************************
 * Varaiveis em RAM
 */
unsigned char   myMacAddr[6] = {0x00, 0x14, 0xA5, 0x76, 0x19, 0x3f} ;   // Endereço MAC
unsigned char   myIpAddr[4]  = {192, 168,  1, 60 } ;                    // Endereço IP
unsigned char   gwIpAddr[4]  = {192, 168,  1,  1 } ;                    // Endereço IP do gateway (router)
unsigned char   ipMask[4]    = {255, 255, 255,  0 } ;                   // Mascara de Rede (por exemplo : 255.255.255.0)
unsigned char   dnsIpAddr[4] = {192, 168,  1,  1 } ;                    // Endereço IP do servidor DNS

unsigned char   getRequest[32] ;                                        // Buffer de requisição HTTP
unsigned char   dyna[29] ;                                              // Buffer para resposta dinamica
unsigned long   httpCounter = 0 ;                                       // Contador de requisições HTTP

/*******************************************
 * Funções
 */
unsigned int    putConstString(const code char *s)
        {
        unsigned int ctr = 0 ;

        while(*s)
                {
                Spi_Ethernet_putByte(*s++) ;
                ctr++ ;
                }
        return(ctr) ;
        }
//#define putConstString  SPI_Ethernet_putConstString

unsigned int    putString(char *s)
        {
        unsigned int ctr = 0 ;

        while(*s)
                {
                Spi_Ethernet_putByte(*s++) ;

                ctr++ ;
                }
        return(ctr) ;
        }

//#define putString  SPI_Ethernet_putString

unsigned int    SPI_Ethernet_UserTCP(unsigned char *remoteHost, unsigned int remotePort, unsigned int localPort, unsigned int reqLength)
        {
        unsigned long    len;            // my reply length
        unsigned int cont;            // my reply length


        if(localPort != 80)                         // I listen only to web request on port 80
                {
                return(0) ;
                }

        // get 10 first bytes only of the request, the rest does not matter here
        for(len = 0 ; len < 32 ; len++)
        {
        getRequest[len] = SPI_Ethernet_getByte() ;
        }
        getRequest[len] = 0 ;
        len = 0;

        if(memcmp(getRequest, httpMethod, 5))       // only GET method is supported here
                {
                return(0) ;
                }

        httpCounter++ ;                             // one more request done

        if(getRequest[5] == 's')                    // if request path name starts with s, store dynamic data in transmit buffer
                {
                // the text string replied by this request can be interpreted as javascript statements
                // by browsers

                len = putConstString(httpHeader) ;              // HTTP header
                len += putConstString(httpMimeTypeScript) ;     // with text MIME type

                // add AN0 value to reply
                WordToStr(ADC_Read(0), dyna) ;
                len += putConstString("var AN0=") ;
                len += putString(dyna) ;
                len += putConstString(";") ;

                // add AN1 value to reply
                WordToStr(ADC_Read(1), dyna) ;
                len += putConstString("var AN1=") ;
                len += putString(dyna) ;
                len += putConstString(";") ;

                // add PORTB value (buttons) to reply
                len += putConstString("var PORTB=") ;
                WordToStr(PORTB, dyna) ;
                len += putString(dyna) ;
                len += putConstString(";") ;

                // add PORTD value (LEDs) to reply
                len += putConstString("var PORTD=") ;
                WordToStr(PORTD, dyna) ;
                len += putString(dyna) ;
                len += putConstString(";") ;

                // add HTTP requests counter to reply
                WordToStr(httpCounter, dyna) ;
                len += putConstString("var REQ=") ;
                len += putString(dyna) ;
                len += putConstString(";") ;
                }
        else if(getRequest[5] == 't')                           // if request path name starts with t, toggle PORTD (LED) bit number that comes after
        {
                unsigned char   bitMask = 0 ;                   // for bit mask

                if(isdigit(getRequest[6]))                      // if 0 <= bit number <= 9, bits 8 & 9 does not exist but does not matter
                {
                   bitMask = getRequest[6] - '0' ;         // convert ASCII to integer
                   bitMask = 1 << bitMask ;                // create bit mask
                   PORTD ^= bitMask ;                      // toggle PORTD with xor operator
                }
        }
        else if((getRequest[5] == 'C')&&(getRequest[6] == '=') )                          // if request path name starts with t, toggle PORTD (LED) bit number that comes after
                {
                    Lcd_Out(1,1,"C:");

                    for(cont=7;cont<=32;cont++)
                    {
                      if (getRequest[cont]==';') break;
                      Lcd_Chr_CP(getRequest[cont]);              // Escreve no display LCD
                    }
                }
        else if((getRequest[5] == 'L')&&(getRequest[6] == '=') )                          // if request path name starts with t, toggle PORTD (LED) bit number that comes after
                {
                    Lcd_Out(2,1,"L:");

                    for(cont=7;cont<=32;cont++)
                    {
                      if (getRequest[cont]==';') break;
                      Lcd_Chr_CP(getRequest[cont]);              // Escreve no display LCD
                    }
                }
        if(len == 0)                                            // what do to by default
                {
                len =  putConstString(httpHeader) ;             // HTTP header
                len += putConstString(httpMimeTypeHTML) ;       // with HTML MIME type
                len += putConstString(indexPage) ;              // HTML page first part
                len += putConstString(indexPage2) ;             // HTML page second part
                }

        return(len) ;                                           // return to the library with the number of bytes to transmit
        }

unsigned int    SPI_Ethernet_UserUDP(unsigned char *remoteHost, unsigned int remotePort, unsigned int destPort, unsigned int reqLength)
        {
        unsigned int    len ;                           // my reply length

        // reply is made of the remote host IP address in human readable format
        ByteToStr(remoteHost[0], dyna) ;                // first IP address byte
        dyna[3] = '.' ;
        ByteToStr(remoteHost[1], dyna + 4) ;            // second
        dyna[7] = '.' ;
        ByteToStr(remoteHost[2], dyna + 8) ;            // third
        dyna[11] = '.' ;
        ByteToStr(remoteHost[3], dyna + 12) ;           // fourth

        dyna[15] = ':' ;                                // add separator

        // then remote host port number
        WordToStr(remotePort, dyna + 16) ;
        dyna[21] = '[' ;
        WordToStr(destPort, dyna + 22) ;
        dyna[27] = ']' ;
        dyna[28] = 0 ;

        // the total length of the request is the length of the dynamic string plus the text of the request
        len = 28 + reqLength;

        // puts the dynamic string into the transmit buffer
        SPI_Ethernet_putBytes(dyna, 28) ;

        // then puts the request string converted into upper char into the transmit buffer
        while(reqLength--)
                {
                SPI_Ethernet_putByte(toupper(SPI_Ethernet_getByte())) ;
                }

        return(len) ;           // back to the library with the length of the UDP reply
        }

/*
 * main entry
 */
void    main()
{
        ADCON1 = 0x0D ;         // ADC convertors will be used with AN0 and AN1
        CMCON  = 0x07 ;         // turn off comparators

        PORTA = 0 ;
        TRISA = 0xff ;          // set PORTA as input for ADC

        PORTB = 0 ;
        TRISB = 0xff ;          // set PORTB as input for buttons

        PORTD = 0 ;
        TRISD = 0 ;             // set PORTD as output
        // Config. LCD no modo 4 bits
        Lcd_Init();                               // Inicializa LCD.

        Lcd_Cmd(_LCD_CLEAR);                      // Apaga display
        Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor

        /*
         * starts ENC28J60 with :
         * reset bit on RC0
         * CS bit on RC1
         * my MAC & IP address
         * full duplex
         */
        SPI1_Init();
        SPI_Rd_Ptr = SPI1_Read;
        SPI_Ethernet_Init(myMacAddr, myIpAddr, Spi_Ethernet_FULLDUPLEX) ;
// dhcp will not be used here, so use preconfigured addresses
        SPI_Ethernet_confNetwork(ipMask, gwIpAddr, dnsIpAddr) ;

        while(1)                            // do forever
                {
                /*
                 * if necessary, test the return value to get error code
                 */
                SPI_Ethernet_doPacket() ;   // process incoming Ethernet packets

                /*
                 * add your stuff here if needed
                 * Spi_Ethernet_doPacket() must be called as often as possible
                 * otherwise packets could be lost
                 */
                }
        }
