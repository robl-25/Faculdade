#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/31 - SENSOR_TEMP/main.c"
#line 46 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/31 - SENSOR_TEMP/main.c"
unsigned char ucTexto[10];
unsigned int iLeituraAD = 0;

void GRAUS();


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

void main(){
 TRISB = 0;
 TRISD = 0;
 TRISC.RC5 = 0;
 TRISC.RC1 = 0;
 TRISE = 0;
 PORTB = 0;


 ADCON0 = 0b00000001;
 ADCON1 = 0b00001100;
 ADCON2 = 0b10111110;


 Lcd_Init();

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1, 1, "TEMP: ");
 PORTC.RC5 = 1;
 GRAUS();
 while(1){
 iLeituraAD= ADC_Read(2);
 iLeituraAD/=2;
 WordToStr(iLeituraAD, ucTexto);
 Lcd_Out(1,8,ucTexto);
 Lcd_Chr_CP(0);
 Lcd_Chr_CP('C');
 Delay_ms(100);
 PORTC.RC1 = ~PORTC.RC1;
 }
}

void GRAUS() {
 char i;
 const char character[] = {7,5,7,0,0,0,0,0};
 Lcd_Cmd(64);
 for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
}
