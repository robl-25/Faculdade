#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/10 - DISPLAY_LCD_8_BITS/main.c"
#line 37 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/10 - DISPLAY_LCD_8_BITS/main.c"
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
 PORTD=0b00111000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 Delay_ms(15);

 PORTE.RE2 = 0;
 PORTD=0b00111000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 Delay_ms(15);

 PORTE.RE2 = 0;
 PORTD=0b00001100;
 PORTE.RE1 = 1;
 Delay_us(1600);
 PORTE.RE1 = 0;

 Delay_ms(15);

 PORTE.RE2 = 0;
 PORTD=0b00000001;
 PORTE.RE1 = 1;
 Delay_us(1600);
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
#line 117 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/10 - DISPLAY_LCD_8_BITS/main.c"
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

 PORTE.RE2 = 1;
 PORTD='C';
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b10000001;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;
 PORTD='O';
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b10000010;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;
 PORTD='N';
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b10000011;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;
 PORTD='T';
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b10000100;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;
 PORTD=':';
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b11000011;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;

 PORTD = ucMask[uiValor%10];
 uiValor/=10;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b11000010;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;

 PORTD = ucMask[uiValor%10];
 uiValor/=10;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b11000001;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;

 PORTD = ucMask[uiValor%10];
 uiValor/=10;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 0;
 PORTD=0b11000000;
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;

 PORTE.RE2 = 1;

 PORTD = ucMask[uiValor%10];
 PORTE.RE1 = 1;
 Delay_us(40);
 PORTE.RE1 = 0;
 }
}
