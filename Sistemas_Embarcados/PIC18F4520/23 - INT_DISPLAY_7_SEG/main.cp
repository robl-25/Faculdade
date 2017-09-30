#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - INT_DISPLAY_7_SEG/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - INT_DISPLAY_7_SEG/main.c"
 unsigned int uiContador;
 unsigned int uiValor;

 unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
#line 45 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - INT_DISPLAY_7_SEG/main.c"
void interrupt(){
 if(PIR2.TMR3IF==1){

 TMR3H = 0x7B;
 TMR3L = 0xDC;

 PIR2.TMR3IF = 0;

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
 PIR1.TMR2IF = 0;
 }
}

void main(){
 unsigned char ucStatus_inc;
 unsigned char ucStatus_dec;

 ADCON1 = 0x0f;

 TRISB.RB0=1;
 TRISB.RB1=1;

 TRISA.RA2=0;
 TRISA.RA3=0;
 TRISA.RA4=0;
 TRISA.RA5=0;

 TRISD = 0;

 ucStatus_inc=0;
 ucStatus_dec=0;
 uiContador=0;



 T3CON.RD16 = 1;
 T3CON.T1CKPS1 = 0;
 T3CON.T1CKPS0 = 0;
 T3CON.TMR3CS = 0;

 TMR1H = 0x7B;
 TMR1L = 0xDC;
 PIE2.TMR3IE = 1;
 PIR2.TMR3IF = 0;
 T3CON.TMR3ON = 1;

 INTCON.GIE = 1;
 INTCON.PEIE = 1;

 while(1){


 if((PORTB.RB0==0)&&(ucStatus_inc==0)){
 ucStatus_inc=1;
 uiContador++;
 if(uiContador>9999){

 uiContador=9999;
 }
 }
 if((PORTB.RB0==1)&&(ucStatus_inc==1)){
 ucStatus_inc=0;
 }

 if((PORTB.RB1==0)&&(ucStatus_dec==0)){
 ucStatus_dec=1;
 uiContador--;
 if(uiContador>9999){
#line 139 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - INT_DISPLAY_7_SEG/main.c"
 uiContador=0;
 }
 }
 if((PORTB.RB1==1)&&(ucStatus_dec==1)){
 ucStatus_dec=0;
 }
 }
}
