#line 1 "C:/Documents and Settings/Administrador/Meus documentos/Projeto_softwares/pic 18f/teste/sequencial.c"

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

void delay (unsigned char tempo)
{
 for(;tempo!=0;tempo--);
}

void main(){


 unsigned char seq, seq1, sent, sent1,a;
 trisd = 0;
 trisb = 0;
 trisc = 0;
 ADCON1 = 0b00001111;
 TRISE = 0;
 portb=0;
 portd=0;
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1, 1, "Microgenios");
 Lcd_Out(2, 1, "  PicGenios ");
 delay_ms(1000);
 portc.f2 = 1;

 seq=0x01;
 seq1=0x08;


 sent=0;
 sent1=0;


 while(1){



 Portd=seq;


 if(sent==0){ seq<<=1;


 if(seq==0x80) sent=1;
 }

 else{ seq>>=1;


 if(seq==0x01) sent=0;
 }


 for(a=0;a!=30;a++) delay(250);



 Portb=seq1;


 if(sent1==0){ seq1<<=1;


 if(seq1==0x80) sent1=1;
 }

 else{ seq1>>=1;


 if(seq1==0x01) sent1=0;
 }


 for(a=0;a!=30;a++) delay(250);

}
 }
