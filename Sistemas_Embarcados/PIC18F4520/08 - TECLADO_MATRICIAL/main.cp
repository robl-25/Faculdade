#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/08 - TECLADO_MATRICIAL/main.c"
#line 39 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/08 - TECLADO_MATRICIAL/main.c"
void main(){

 unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x21,0x03,0x40};
#line 45 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/08 - TECLADO_MATRICIAL/main.c"
 unsigned char ucConverter[] = {12,10,7,4,1,0,8,5,2,11,9,6,3};
#line 49 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/08 - TECLADO_MATRICIAL/main.c"
 unsigned char ucTecla;
 unsigned int uiTeclas;
 unsigned int uiValor;
 unsigned char ucContador;

 ADCON1 = 0x0f;

 TRISB.RB0=0;
 TRISB.RB1=0;
 TRISB.RB2=0;

 TRISA.RA2=0;
 TRISA.RA3=0;
 TRISA.RA4=0;
 TRISA.RA5=0;

 TRISD = 0;

 while(1){
 TRISD=0x0F;
 PORTB.RB0=0;
 Delay_ms(1);
 ucTecla = (((~PORTD)&0x0F));
 PORTB.RB0=1;
 uiTeclas = (unsigned int)(ucTecla&0x0F);

 PORTB.RB1=0;
 Delay_ms(1);
 ucTecla = (((~PORTD)&0x0F));
 PORTB.RB1=1;
 uiTeclas |= (unsigned int)((ucTecla&0x0F)<<4);

 PORTB.RB2=0;
 Delay_ms(1);
 ucTecla = (((~PORTD)&0x0F));
 PORTB.RB2=1;
 uiTeclas |= (unsigned int)((ucTecla&0x0F)<<8);
 uiValor=0;

 for (ucContador=0;ucContador<=12;ucContador++)
 {
 if ((unsigned int)(1<<ucContador)==uiTeclas)
 {
 uiValor = (unsigned int) ucContador + 1 ;
 }
 }

 TRISD=0;


 PORTD = ucMask[ucConverter[uiValor]];
 PORTA.RA5 = 1;
 Delay_ms(2);
 PORTA.RA5 = 0;
 }
}
