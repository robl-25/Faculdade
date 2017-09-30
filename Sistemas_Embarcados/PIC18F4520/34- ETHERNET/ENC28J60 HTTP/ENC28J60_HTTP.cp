#line 1 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
#line 51 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
sfr sbit SPI_Ethernet_Rst at PORTC.B0;
sfr sbit SPI_Ethernet_CS at PORTC.B1;
sfr sbit SPI_Ethernet_Rst_Direction at TRISC.B0;
sfr sbit SPI_Ethernet_CS_Direction at TRISC.B1;


sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;


sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;
#line 75 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
const code unsigned char httpHeader[] = "HTTP/1.1 200 OK\nContent-type: " ;
const code unsigned char httpMimeTypeHTML[] = "text/html\n\n" ;
const code unsigned char httpMimeTypeScript[] = "text/plain\n\n" ;
unsigned char httpMethod[] = "GET /";
#line 83 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
const code unsigned char *indexPage =
#line 98 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
"<meta http-equiv='refresh' content='2;url=http://192.168.1.60'><HTML><HEAD><title>Mini Web Server [PIC + ENC28J60]</title><script src=/s></script></HEAD><BODY><h1>Mini Web Server [PIC + ENC28J60]</h1>Esta e a requisicao HTTP n.:<script>document.write(REQ)</script><br><a href=/>Recarregar Pagina</a><table width='600px' cellspacing='5' cellpadding='0'><tr><td valign='top' width='10%'><table width='100%' border='1'><tr><th colspan='2'>ADC</th></tr><tr bgcolor='silver'><td>AN0</td><td bgcolor='#66FF66'><script>document.write(AN0)</script></td></tr><tr bgcolor='silver'><td>AN1</td><td bgcolor='#66FF66'><script>document.write(AN1)</script></td></tr></table></td><td width='40%' valign='top'><table width='100%' border='1'><tr><th colspan='2'>PORTB</th></tr><script>";

const code unsigned char *indexPage2 =
#line 117 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
"var str,i;str=\"\";for(i=0;i<6;i++){str+=\"<tr bgcolor='silver'><td>BOTAO N.\"+i+\"</td>\";if(!(PORTB&(1<<i))){str+=\"<td bgcolor='#66FF66'>LIG.\";}else {str+=\"<td bgcolor='#FF6666'>DESL.\";}str+=\"</td></tr>\";}document.write(str) ;</script></table></td><td width='50%'><table width='100%' border='1'><tr><th colspan='3'>PORTD</th></tr><script>var str,i;str=\"\";for(i=0;i<8;i++){str+=\"<tr bgcolor='silver'><td>LED N.\"+i+\"</td>\";if(PORTD&(1<<i)){str+=\"<td bgcolor='#66FF66'>LIG.\";}else {str+=\"<td bgcolor='#FF6666'>DESL.\";}str+=\"</td><td><a href=/t\"+i+\">Alternar</a></td></tr>\";}document.write(str) ;</script></table></td></tr></table></BODY></HTML>" ;
#line 121 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
unsigned char myMacAddr[6] = {0x00, 0x14, 0xA5, 0x76, 0x19, 0x3f} ;
unsigned char myIpAddr[4] = {192, 168, 1, 60 } ;
unsigned char gwIpAddr[4] = {192, 168, 1, 1 } ;
unsigned char ipMask[4] = {255, 255, 255, 0 } ;
unsigned char dnsIpAddr[4] = {192, 168, 1, 1 } ;

unsigned char getRequest[32] ;
unsigned char dyna[29] ;
unsigned long httpCounter = 0 ;
#line 134 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
unsigned int putConstString(const code char *s)
 {
 unsigned int ctr = 0 ;

 while(*s)
 {
 Spi_Ethernet_putByte(*s++) ;
 ctr++ ;
 }
 return(ctr) ;
 }


unsigned int putString(char *s)
 {
 unsigned int ctr = 0 ;

 while(*s)
 {
 Spi_Ethernet_putByte(*s++) ;

 ctr++ ;
 }
 return(ctr) ;
 }



unsigned int SPI_Ethernet_UserTCP(unsigned char *remoteHost, unsigned int remotePort, unsigned int localPort, unsigned int reqLength)
 {
 unsigned long len;
 unsigned int cont;


 if(localPort != 80)
 {
 return(0) ;
 }


 for(len = 0 ; len < 32 ; len++)
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



 len = putConstString(httpHeader) ;
 len += putConstString(httpMimeTypeScript) ;


 WordToStr(ADC_Read(0), dyna) ;
 len += putConstString("var AN0=") ;
 len += putString(dyna) ;
 len += putConstString(";") ;


 WordToStr(ADC_Read(1), dyna) ;
 len += putConstString("var AN1=") ;
 len += putString(dyna) ;
 len += putConstString(";") ;


 len += putConstString("var PORTB=") ;
 WordToStr(PORTB, dyna) ;
 len += putString(dyna) ;
 len += putConstString(";") ;


 len += putConstString("var PORTD=") ;
 WordToStr(PORTD, dyna) ;
 len += putString(dyna) ;
 len += putConstString(";") ;


 WordToStr(httpCounter, dyna) ;
 len += putConstString("var REQ=") ;
 len += putString(dyna) ;
 len += putConstString(";") ;
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
 else if((getRequest[5] == 'C')&&(getRequest[6] == '=') )
 {
 Lcd_Out(1,1,"C:");

 for(cont=7;cont<=32;cont++)
 {
 if (getRequest[cont]==';') break;
 Lcd_Chr_CP(getRequest[cont]);
 }
 }
 else if((getRequest[5] == 'L')&&(getRequest[6] == '=') )
 {
 Lcd_Out(2,1,"L:");

 for(cont=7;cont<=32;cont++)
 {
 if (getRequest[cont]==';') break;
 Lcd_Chr_CP(getRequest[cont]);
 }
 }
 if(len == 0)
 {
 len = putConstString(httpHeader) ;
 len += putConstString(httpMimeTypeHTML) ;
 len += putConstString(indexPage) ;
 len += putConstString(indexPage2) ;
 }

 return(len) ;
 }

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
#line 308 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
void main()
{
 ADCON1 = 0x0D ;
 CMCON = 0x07 ;

 PORTA = 0 ;
 TRISA = 0xff ;

 PORTB = 0 ;
 TRISB = 0xff ;

 PORTD = 0 ;
 TRISD = 0 ;

 Lcd_Init();

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
#line 334 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
 SPI1_Init();
 SPI_Rd_Ptr = SPI1_Read;
 SPI_Ethernet_Init(myMacAddr, myIpAddr,  0x01 ) ;

 SPI_Ethernet_confNetwork(ipMask, gwIpAddr, dnsIpAddr) ;

 while(1)
 {
#line 345 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
 SPI_Ethernet_doPacket() ;
#line 352 "S:/Microgenios Arquivos/Arquivos de CDs/CD microEthernet/Exemplos de Programas/MikroC PRO for PIC/PIC18F4520/ENC28J60 HTTP/ENC28J60_HTTP.c"
 }
 }
