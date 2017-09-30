#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - EEPROM_INTERNA/main.c"
#line 42 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - EEPROM_INTERNA/main.c"
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

unsigned char ucContador;

void main(){
 TRISB = 0;
 TRISD = 0;
 TRISE = 0;

 ADCON1 = 0x0F;


 Lcd_Init();

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);


 Lcd_Out(1,1,"Escr. na EEPROM");
 for(ucContador=0;ucContador<16;ucContador++){
 EEPROM_Write(ucContador,0x30+ucContador);
 Delay_ms(100);
 }

 Lcd_Out(1,1,"Lido da EEPROM ");
 for(ucContador=0;ucContador<16;ucContador++){
 Lcd_Chr(2,ucContador+1,EEPROM_Read(ucContador));
 Delay_ms(100);
 }

 while(1){};
}
