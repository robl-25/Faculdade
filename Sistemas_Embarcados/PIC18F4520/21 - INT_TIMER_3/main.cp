#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/20 - INT_TIMER_3/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/20 - INT_TIMER_3/main.c"
unsigned int ucContador;

void interrupt(){
 if(PIR2.TMR3IF==1){

 TMR3H = 0x0B;
 TMR3L = 0xDC;

 PIR2.TMR3IF = 0;
 ucContador++;
 PORTD=ucContador;
 }
}

void main(){
 ADCON1 = 0x0F;

 TRISD = 0;

 ucContador=0;



 T3CON.RD16 = 1;
 T3CON.T1CKPS1 = 1;
 T3CON.T1CKPS0 = 1;
 T3CON.TMR3CS = 0;


 TMR1H = 0x0B;
 TMR1L = 0xDC;
 PIE2.TMR3IE = 1;
 PIR2.TMR3IF = 0;
 T3CON.TMR3ON = 1;

 INTCON.GIE = 1;
 INTCON.PEIE = 1;

 while(1);
}
