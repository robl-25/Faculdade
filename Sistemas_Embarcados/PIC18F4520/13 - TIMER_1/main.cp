#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/13 - TIMER_1/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/13 - TIMER_1/main.c"
void main(){

 unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
#line 43 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/13 - TIMER_1/main.c"
 unsigned char ucStatus_inc;
 unsigned char ucStatus_dec;
 unsigned int uiContador;
 unsigned int uiValor;

 ADCON1 = 0x0F;

 TRISA.RA2=0;
 TRISA.RA3=0;
 TRISA.RA4=0;
 TRISA.RA5=0;

 TRISD = 0;

 ucStatus_inc=0;
 ucStatus_dec=0;
 uiContador=0;



 T1CON.RD16 = 1;
 T1CON.T1CKPS1 = 1;
 T1CON.T1CKPS0 = 1;
 T1CON.TMR1CS = 0;


 TMR1H = 0x0B;
 TMR1L = 0xDC;

 PIR1.TMR1IF = 0;
 T1CON.TMR1ON = 1;

 while(1){


 if(PIR1.TMR1IF==1){

 TMR1H = 0x0B;
 TMR1L = 0xDC;

 PIR1.TMR1IF = 0;
 ucStatus_inc=1;
 uiContador++;
 if(uiContador>9999){

 uiContador=0;
 }
 }

 uiValor = uiContador;


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
