#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/11 - DISPLAY_LCD_4_BITS/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/11 - DISPLAY_LCD_4_BITS/main.c"
void main(){
 unsigned char ucMask[]={'0','1','2','3','4','5','6','7','8','9'} ;

 unsigned char ucStatus_inc;
 unsigned char ucStatus_dec;
 unsigned int uiContador;
 unsigned int uiValor;

 ADCON1 = 0x0f;

 TRISB.RB3=1;
 TRISB.RB4=1;

 TRISE.RE1=0;
 TRISE.RE2=0;

 TRISA.RA2=0;
 TRISA.RA3=0;
 TRISA.RA4=0;
 TRISA.RA5=0;

 TRISD = 0;

 ucStatus_inc=0;
 ucStatus_dec=0;
 uiContador=0;




 PORTE.RE2 = 0;
 PORTD=0b00110000;
 PORTE.RE1 = 1;
 Delay_us(4100);
 PORTE.RE1 = 0;


 PORTE.RE2 = 0;
 PORTD=0b00110000;
 PORTE.RE1 = 1;
 Delay_us(100);
 PORTE.RE1 = 0;


 PORTE.RE2 = 0;
 PORTD=0b00110000;
 PORTE.RE1 = 1;
 Delay_us(100);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b00100000;
 PORTE.RE1 = 1;
 Delay_us(4100);
 PORTE.RE1 = 0;



 PORTE.RE2 = 0;
 PORTD=0b00100000;
 PORTE.RE1 = 1;
 Delay_us(100);
 PORTE.RE1 = 0;


 PORTE.RE2 = 0;
 PORTD=0b10000000;
 PORTE.RE1 = 1;
 Delay_us(100);
 PORTE.RE1 = 0;


 PORTE.RE2 = 0;
 PORTD=0b00000000;
 PORTE.RE1 = 1;
 Delay_us(4100);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b11000000;
 PORTE.RE1 = 1;
 Delay_us(100);
 PORTE.RE1 = 0;


 PORTE.RE2 = 0;
 PORTD=0b00000000;
 PORTE.RE1 = 1;
 Delay_us(100);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b00010000;
 PORTE.RE1 = 1;
 Delay_us(100);
 PORTE.RE1 = 0;

 while(1){


 if((PORTB.RB3==0)&&(ucStatus_inc==0)){
 ucStatus_inc=1;
 uiContador++;
 if(uiContador>9999){

 uiContador=9999;
 }
 }
 if((PORTB.RB3==1)&&(ucStatus_inc==1)){
 ucStatus_inc=0;
 }

 if((PORTB.RB4==0)&&(ucStatus_dec==0)){
 ucStatus_dec=1;
 uiContador--;
 if(uiContador>9999){
#line 156 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/11 - DISPLAY_LCD_4_BITS/main.c"
 uiContador=0;
 }
 }
 if((PORTB.RB4==1)&&(ucStatus_dec==1)){
 ucStatus_dec=0;
 }

 uiValor = uiContador;


 PORTE.RE2 = 0;
 PORTD=0b10000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b00000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 1;
 PORTD=('C'& 0xf0);
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;
 PORTD=('C'& 0x0f)<<4;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 0;
 PORTD=0b10000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b00010000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 1;
 PORTD=('O'& 0xf0);
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;
 PORTD=('O'& 0x0f)<<4;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 0;
 PORTD=0b10000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b00100000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 1;
 PORTD=('N'& 0xf0);
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;
 PORTD=('N'& 0x0f)<<4;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 0;
 PORTD=0b10000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b00110000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 1;
 PORTD=('T'& 0xf0);
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;
 PORTD=('T'& 0x0f)<<4;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 0;
 PORTD=0b10000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b01000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 1;
 PORTD=(':'& 0xf0);
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;
 PORTD=(':'& 0x0f)<<4;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;



 PORTE.RE2 = 0;
 PORTD=0b11000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b00110000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 1;

 PORTD = ((ucMask[uiValor%10])& 0xf0);
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;

 PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;
 uiValor/=10;


 PORTE.RE2 = 0;
 PORTD=0b11000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b00100000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 1;

 PORTD = ((ucMask[uiValor%10])& 0xf0);
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;

 PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;
 uiValor/=10;


 PORTE.RE2 = 0;
 PORTD=0b11000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b00010000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 1;

 PORTD = ((ucMask[uiValor%10])& 0xf0);
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;

 PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;
 uiValor/=10;


 PORTE.RE2 = 0;
 PORTD=0b11000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b00000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;


 PORTE.RE2 = 1;

 PORTD = ((ucMask[uiValor%10])& 0xf0);
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;

 PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;
 }
}
