#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - CONT_TIMER1/main.c"
#line 44 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - CONT_TIMER1/main.c"
unsigned char ucTexto[10];
unsigned int iReg_timer1 = 0;


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

void interrupt(){
 if (PIR1.TMR1IF == 1){
 PORTB.RB0 = ~PORTB.RB0;
 TMR1L = 0xF5;
 TMR1H = 0xFF;
 PIR1.TMR1IF = 0;
 iReg_timer1++;
 }
}

void main(){
 TRISB = 0;
 TRISD = 0;
 TRISC.RC0 = 1;
 TRISC.RC2 = 0;
 TRISE = 0;
 PORTB = 0;

 ADCON1 = 0x0F;


 T1CON = 0B10000011;

 TMR1L = 0xF5;
 TMR1H = 0xFF;
 PIE1.TMR1IE = 1;
 PIR1.TMR1IF = 0;
 T1CON.TMR1ON = 1;
 IPR1.TMR1IP = 1;

 RCON.IPEN = 1;
 INTCON.GIE = 1;
 INTCON.PEIE = 1;


 Lcd_Init();

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1, 1, "Qtde Lotes: ");

 while(1){
 WordToStr(iReg_timer1, ucTexto);
 Lcd_Out(2,1,ucTexto);
 Lcd_Out_CP(" Pcs");
 Delay_10us;
 }
}
