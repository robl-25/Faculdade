#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/19 - INT_TIMER_2/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/19 - INT_TIMER_2/main.c"
unsigned char ucContador;

void interrupt(){
 if(PIR1.TMR2IF==1){

 TMR2 = 0xFF;

 PIR1.TMR2IF = 0;
 ucContador++;
 PORTD=ucContador;
 }
}

void main(){

 ADCON1 = 0x0F;

 TRISD = 0;

 ucContador=0;



 T2CON.T2OUTPS3 = 1;
 T2CON.T2OUTPS2 = 1;
 T2CON.T2OUTPS1 = 1;
 T2CON.T2OUTPS0 = 1;
 T2CON.T2CKPS1 = 1;
 T2CON.T2CKPS0 = 1;


 TMR2 = 0xFF;

 PIE1.TMR2IE = 1;

 PIR1.TMR2IF = 0;
 T2CON.TMR2ON = 1;

 INTCON.GIE = 1;
 INTCON.PEIE = 1;

 while(1);
}
