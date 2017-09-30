#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/18 - INT_TIMER_1/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/18 - INT_TIMER_1/main.c"
unsigned int ucContador;

void interrupt(){

 if(PIR1.TMR1IF==1){

 TMR1H = 0x0B;
 TMR1L = 0xDC;

 PIR1.TMR1IF = 0;
 ucContador++;
 PORTD=ucContador;
 }
}

void main(){

 ADCON1 = 0x0F;

 TRISD = 0;

 ucContador=0;



 T1CON.RD16 = 1;
 T1CON.T1CKPS1 = 1;
 T1CON.T1CKPS0 = 1;
 T1CON.TMR1CS = 0;


 TMR1H = 0x0B;
 TMR1L = 0xDC;
 PIE1.TMR1IE = 1;
 PIR1.TMR1IF = 0;
 T1CON.TMR1ON = 1;

 INTCON.GIE = 1;
 INTCON.PEIE = 1;

 while(1);
}
