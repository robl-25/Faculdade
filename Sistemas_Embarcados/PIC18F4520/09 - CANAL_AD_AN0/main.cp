#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/09 - CANAL_AD_AN0/main.c"
#line 39 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/09 - CANAL_AD_AN0/main.c"
void main(){

 unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
#line 44 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/09 - CANAL_AD_AN0/main.c"
 unsigned int uiValorAD;
 unsigned int uiValor;

 ADCON0 = 0b10000001;
 ADCON1 = 0b11001110;

 TRISA.RA2=0;
 TRISA.RA3=0;
 TRISA.RA4=0;
 TRISA.RA5=0;

 TRISD = 0;

 while(1){

 if(ADCON0.GO_DONE==0)
 {
 uiValorAD= ((ADRESH<<8) | ADRESL);
 ADCON0.GO_DONE=1;
 }

 uiValor=uiValorAD;

 TRISD=0;


 PORTD = ucMask[uiValor%10];
 PORTA.RA5 = 1;
 Delay_ms(2);
 PORTA.RA5 = 0;
 uiValor/=10;

 PORTD = ucMask[uiValor%10];
 PORTA.RA4 = 1;
 Delay_ms(2);
 PORTA.RA4 = 0;
 uiValor/=10;

 PORTD = ucMask[uiValor%10];
 PORTA.RA3 = 1;
 Delay_ms(2);
 PORTA.RA3 = 0;
 uiValor/=10;

 PORTD = ucMask[uiValor%10];
 PORTA.RA2 = 1;
 Delay_ms(2);
 PORTA.RA2 = 0;
 }
}
