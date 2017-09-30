#line 1 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
#line 1 "s:/microgenios arquivos/arquivos de cds/cd kit picgenios/exemplos de programas/linguagem c - mikroc pro/pic18f4520/32 - glcd t6963c/__t6963c.h"
#line 165 "s:/microgenios arquivos/arquivos de cds/cd kit picgenios/exemplos de programas/linguagem c - mikroc pro/pic18f4520/32 - glcd t6963c/__t6963c.h"
void T6963C_init(unsigned int w, unsigned char h, unsigned char fntW);
void T6963C_writeData(unsigned char mydata);
void T6963C_writeCommand(unsigned char mydata);
void T6963C_setPtr(unsigned int addr, unsigned char t);
void T6963C_waitReady(void);
void T6963C_fill(unsigned char mydata, unsigned int start, unsigned int len);
void T6963C_dot(int x, int y, unsigned char color);
void T6963C_write_char(unsigned char c, unsigned char x, unsigned char y, unsigned char mode);
void T6963C_write_text(unsigned char *str, unsigned char x, unsigned char y, unsigned char mode);
void T6963C_line(int px0, int py0, int px1, int py1, unsigned char pcolor);
void T6963C_rectangle(int x0, int y0, int x1, int y1, unsigned char pcolor);
void T6963C_box(int x0, int y0, int x1, int y1, unsigned char pcolor);
void T6963C_circle(int x, int y, long r, unsigned char pcolor);
void T6963C_image(const char *pic);
void T6963C_sprite(unsigned char px, unsigned char py, const char *pic, unsigned char sx, unsigned char sy);
void T6963C_set_cursor(unsigned char x, unsigned char y);
#line 185 "s:/microgenios arquivos/arquivos de cds/cd kit picgenios/exemplos de programas/linguagem c - mikroc pro/pic18f4520/32 - glcd t6963c/__t6963c.h"
extern sfr char T6963C_dataPort;
extern sfr char T6963C_cntlPort;

extern unsigned int T6963C_grWidth;
extern unsigned int T6963C_grHeight;
extern unsigned int T6963C_txtCols;

extern unsigned int T6963C_fontWidth;
extern unsigned int T6963C_grHomeAddr;
extern unsigned int T6963C_textHomeAddr;
extern unsigned int T6963C_grMemSize;
extern unsigned int T6963C_txtMemSize;

extern sfr sbit T6963C_cntlwr;
extern sfr sbit T6963C_cntlrd;
extern sfr sbit T6963C_cntlcd;
extern sfr sbit T6963C_cntlrst;

extern unsigned char T6963C_display;
#line 4 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
char T6963C_dataPort at PORTD;

sbit T6963C_ctrlwr at RC2_bit;
sbit T6963C_ctrlrd at RC1_bit;
sbit T6963C_ctrlcd at RC0_bit;
sbit T6963C_ctrlrst at RC4_bit;
sbit T6963C_ctrlwr_Direction at TRISC2_bit;
sbit T6963C_ctrlrd_Direction at TRISC1_bit;
sbit T6963C_ctrlcd_Direction at TRISC0_bit;
sbit T6963C_ctrlrst_Direction at TRISC4_bit;


sbit T6963C_ctrlce at RC3_bit;
sbit T6963C_ctrlfs at RC6_bit;
sbit T6963C_ctrlmd at RC5_bit;
sbit T6963C_ctrlce_Direction at TRISC3_bit;
sbit T6963C_ctrlfs_Direction at TRISC6_bit;
sbit T6963C_ctrlmd_Direction at TRISC5_bit;
#line 28 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
const code char mikroe_bmp[];
const code char einstein[];


void main() {
 char txt1[] = " EINSTEIN WOULD HAVE LIKED mE";
 char txt[] = " GLCD LIBRARY DEMO, WELCOME !";

 unsigned char panel;
 unsigned int i;
 unsigned char curs;
 unsigned int cposx, cposy;

 TRISA0_bit = 1;
 TRISA1_bit = 1;
 TRISA2_bit = 1;
 TRISA3_bit = 1;
 TRISA4_bit = 1;

 T6963C_ctrlce_Direction = 0;
 T6963C_ctrlce = 0;
 T6963C_ctrlfs_Direction = 0;
 T6963C_ctrlfs = 0;
 T6963C_ctrlmd_Direction = 0;
 T6963C_ctrlmd = 0;




 T6963C_init(240, 128, 8);
#line 62 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
  T6963C_display. F3  = 1; T6963C_writeCommand(T6963C_display) ;
  T6963C_display. F2  = 1; T6963C_writeCommand(T6963C_display) ;

 panel = 0;
 i = 0;
 curs = 0;
 cposx = cposy = 0;
#line 72 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 T6963C_write_text(txt, 0, 0,  0b10000001 );
 T6963C_write_text(txt1, 0, 15,  0b10000001 );
#line 78 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
  T6963C_writeCommand( 0b10100111  | (8 & 0b00000111)) ;
 T6963C_set_cursor(0, 0);
  T6963C_display. F1  = 0; T6963C_writeCommand(T6963C_display) ;
#line 85 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 T6963C_rectangle(0, 0, 239, 127,  0b1000 );
 T6963C_rectangle(20, 20, 219, 107,  0b1000 );
 T6963C_rectangle(40, 40, 199, 87,  0b1000 );
 T6963C_rectangle(60, 60, 179, 67,  0b1000 );
#line 93 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 T6963C_line(0, 0, 239, 127,  0b1000 );
 T6963C_line(0, 127, 239, 0,  0b1000 );
#line 99 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 T6963C_box(0, 0, 239, 8,  0b1000 );
 T6963C_box(0, 119, 239, 127,  0b1000 );
#line 105 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 T6963C_circle(120, 64, 10,  0b1000 );
 T6963C_circle(120, 64, 30,  0b1000 );
 T6963C_circle(120, 64, 50,  0b1000 );
 T6963C_circle(120, 64, 70,  0b1000 );
 T6963C_circle(120, 64, 90,  0b1000 );
 T6963C_circle(120, 64, 110,  0b1000 );
 T6963C_circle(120, 64, 130,  0b1000 );

 T6963C_sprite(76, 4, einstein, 88, 119);

  T6963C_grHomeAddr = (T6963C_grMemSize + T6963C_txtMemSize)  * 1 ;



 for(;;) {
#line 123 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 if(RA0_bit) {
  T6963C_display. F3  = 1; T6963C_writeCommand(T6963C_display) ;
  T6963C_display. F2  = 0; T6963C_writeCommand(T6963C_display) ;
 Delay_ms(300);
 }
#line 132 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 else if(RA1_bit) {
 panel++;
 panel &= 1;
  T6963C_setPtr( (T6963C_grMemSize + T6963C_txtMemSize)  * panel, 0b01000010 ) ;
 Delay_ms(300);
 }
#line 142 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 else if(RA2_bit) {
  T6963C_display. F3  = 0; T6963C_writeCommand(T6963C_display) ;
  T6963C_display. F2  = 1; T6963C_writeCommand(T6963C_display) ;
 Delay_ms(300);
 }
#line 151 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 else if(RA3_bit) {
  T6963C_display. F3  = 1; T6963C_writeCommand(T6963C_display) ;
  T6963C_display. F2  = 1; T6963C_writeCommand(T6963C_display) ;
 Delay_ms(300);
 }
#line 160 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 else if(RA4_bit) {
 curs++;
 if(curs == 3) curs = 0;
 switch(curs) {
 case 0:

  T6963C_display. F1  = 0; T6963C_writeCommand(T6963C_display) ;
 break;
 case 1:

  T6963C_display. F1  = 1; T6963C_writeCommand(T6963C_display) ;
  T6963C_display. F0  = 1; T6963C_writeCommand(T6963C_display) ;
 break;
 case 2:

  T6963C_display. F1  = 1; T6963C_writeCommand(T6963C_display) ;
  T6963C_display. F0  = 0; T6963C_writeCommand(T6963C_display) ;
 break;
 }
 Delay_ms(300);
 }
#line 185 "S:/Microgenios Arquivos/Arquivos de CDs/CD Kit PICgenios/Exemplos de Programas/Linguagem C - MikroC PRO/PIC18F4520/32 - GLCD T6963C/GLCD_T6963C.c"
 cposx++;
 if(cposx == T6963C_txtCols) {
 cposx = 0;
 cposy++;
 if(cposy == T6963C_grHeight /  8 ) {
 cposy = 0;
 }
 }
 T6963C_set_cursor(cposx, cposy);

 Delay_ms(100);
 }
}
