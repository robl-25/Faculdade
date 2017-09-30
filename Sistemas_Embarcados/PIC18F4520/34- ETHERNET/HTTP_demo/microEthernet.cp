#line 1 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
#line 63 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
sfr sbit SPI_Ethernet_Rst at LATC.B0;
sfr sbit SPI_Ethernet_CS at LATC.B1;
sfr sbit SPI_Ethernet_Rst_Direction at TRISC.B0;
sfr sbit SPI_Ethernet_CS_Direction at TRISC.B1;
#line 73 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
const code unsigned char httpHeader[] = "HTTP/1.1 200 OK\nContent-type: " ;
const code unsigned char httpMimeTypeHTML[] = "text/html\n\n" ;
const code unsigned char httpMimeTypeScript[] = "text/plain\n\n" ;
unsigned char httpMethod[] = "GET /";
#line 83 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
const code char *indexPage =
#line 105 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
"<meta http-equiv=\"refresh\" content=\"3;url=http://192.168.1.60\"><HTML><HEAD></HEAD><BODY><h1>PIC + ENC28J60 Mini Web Server</h1><a href=/>Reload</a><script src=/s></script><table><tr><td valign=top><table border=1 style=\"font-size:20px ;font-family: terminal ;\"><tr><th colspan=2>ADC</th></tr><tr><td>AN2</td><td><script>document.write(AN2)</script></td></tr><tr><td>AN3</td><td><script>document.write(AN3)</script></td></tr></table></td><td><table border=1 style=\"font-size:20px ;font-family: terminal ;\"><tr><th colspan=2>PORTB</th></tr><script>var str,i;str=\"\";for(i=0;i<8;i++){str+=\"<tr><td bgcolor=pink>BUTTON #\"+i+\"</td>\";if(PORTB&(1<<i)){str+=\"<td bgcolor=red>ON\";}else {str+=\"<td bgcolor=#cccccc>OFF\";}str+=\"</td></tr>\";}document.write(str) ;</script>" ;
#line 122 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
const code char *indexPage2 = "</table></td><td><table border=1 style=\"font-size:20px ;font-family: terminal ;\"><tr><th colspan=3>PORTD</th></tr><script>var str,i;str=\"\";for(i=0;i<8;i++){str+=\"<tr><td bgcolor=yellow>LED #\"+i+\"</td>\";if(PORTD&(1<<i)){str+=\"<td bgcolor=red>ON\";}else {str+=\"<td bgcolor=#cccccc>OFF\";}str+=\"</td><td><a href=/t\"+i+\">Toggle</a></td></tr>\";}document.write(str) ;</script></table></td></tr></table>This is HTTP request #<script>document.write(REQ)</script></BODY></HTML>" ;
#line 127 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
unsigned char myMacAddr[6] = {0x00, 0x14, 0xA5, 0x76, 0x19, 0x3f} ;
unsigned char myIpAddr[4] = {192, 168, 1, 60 } ;
unsigned char gwIpAddr[4] = {192, 168, 1, 6 } ;
unsigned char ipMask[4] = {255, 255, 255, 0 } ;
unsigned char dnsIpAddr[4] = {192, 168, 1, 1 } ;

unsigned char getRequest[15] ;
unsigned char dyna[29] ;
unsigned long httpCounter = 0 ;
#line 201 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
unsigned int SPI_Ethernet_UserTCP(unsigned char *remoteHost, unsigned int remotePort, unsigned int localPort, unsigned int reqLength, char *canClose)
 {
 unsigned int len;






 if(localPort != 80)
 {
 return(0) ;
 }


 for(len = 0 ; len < 10 ; len++)
 {
 getRequest[len] = SPI_Ethernet_getByte() ;
 }
 getRequest[len] = 0 ;
 len = 0;

 if(memcmp(getRequest, httpMethod, 5))
 {
 return(0) ;
 }

 httpCounter++ ;

 if(getRequest[5] == 's')
 {



 len =  SPI_Ethernet_putConstString (httpHeader) ;
 len +=  SPI_Ethernet_putConstString (httpMimeTypeScript) ;


 WordToStr(ADC_Read(2), dyna) ;
 len +=  SPI_Ethernet_putConstString ("var AN2=") ;
 len +=  SPI_Ethernet_putString (dyna) ;
 len +=  SPI_Ethernet_putConstString (";") ;


 WordToStr(ADC_Read(3), dyna) ;
 len +=  SPI_Ethernet_putConstString ("var AN3=") ;
 len +=  SPI_Ethernet_putString (dyna) ;
 len +=  SPI_Ethernet_putConstString (";") ;


 len +=  SPI_Ethernet_putConstString ("var PORTB=") ;
 WordToStr(PORTB, dyna) ;
 len +=  SPI_Ethernet_putString (dyna) ;
 len +=  SPI_Ethernet_putConstString (";") ;


 len +=  SPI_Ethernet_putConstString ("var PORTD=") ;
 WordToStr(PORTD, dyna) ;
 len +=  SPI_Ethernet_putString (dyna) ;
 len +=  SPI_Ethernet_putConstString (";") ;


 WordToStr(httpCounter, dyna) ;
 len +=  SPI_Ethernet_putConstString ("var REQ=") ;
 len +=  SPI_Ethernet_putString (dyna) ;
 len +=  SPI_Ethernet_putConstString (";") ;
 }
 else if(getRequest[5] == 't')
 {
 unsigned char bitMask = 0 ;

 if(isdigit(getRequest[6]))
 {
 bitMask = getRequest[6] - '0' ;
 bitMask = 1 << bitMask ;
 PORTD ^= bitMask ;
 }
 }

 if(len == 0)
 {
 len =  SPI_Ethernet_putConstString (httpHeader) ;
 len +=  SPI_Ethernet_putConstString (httpMimeTypeHTML) ;
 len +=  SPI_Ethernet_putConstString (indexPage) ;
 len +=  SPI_Ethernet_putConstString (indexPage2) ;
 }

 return(len) ;
 }
#line 301 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
unsigned int SPI_Ethernet_UserUDP(unsigned char *remoteHost, unsigned int remotePort, unsigned int destPort, unsigned int reqLength)
 {
 unsigned int len ;


 ByteToStr(remoteHost[0], dyna) ;
 dyna[3] = '.' ;
 ByteToStr(remoteHost[1], dyna + 4) ;
 dyna[7] = '.' ;
 ByteToStr(remoteHost[2], dyna + 8) ;
 dyna[11] = '.' ;
 ByteToStr(remoteHost[3], dyna + 12) ;

 dyna[15] = ':' ;


 WordToStr(remotePort, dyna + 16) ;
 dyna[21] = '[' ;
 WordToStr(destPort, dyna + 22) ;
 dyna[27] = ']' ;
 dyna[28] = 0 ;


 len = 28 + reqLength;


 SPI_Ethernet_putBytes(dyna, 28) ;


 while(reqLength--)
 {
 SPI_Ethernet_putByte(toupper(SPI_Ethernet_getByte())) ;
 }

 return(len) ;
 }
#line 341 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
void main()
 {
 ADCON1 = 15 ;
 CMCON = 0x07 ;

 PORTA = 0 ;
 TRISA = 0xff ;

 PORTB = 0 ;
 TRISB = 0xff ;

 PORTD = 0 ;
 TRISD = 0 ;
#line 362 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
 SPI1_Init();
 SPI_Rd_Ptr = SPI1_Read;
 SPI_Ethernet_Init(myMacAddr, myIpAddr,  0x01 ) ;


 SPI_Ethernet_confNetwork(ipMask, gwIpAddr, dnsIpAddr) ;

 while(1)
 {
#line 374 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
 SPI_Ethernet_doPacket() ;
#line 381 "C:/Documents and Settings/Administrador/Desktop/microEthernet/microEthernet.c"
 }
 }
