#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/17 - INT_TIMER_0/main.c"
#line 39 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/17 - INT_TIMER_0/main.c"
unsigned char ucContador;

void interrupt(){

 if(INTCON.TMR0IF==1){

 TMR0H = 0xE1 ;
 TMR0L = 0x7B;

 INTCON.TMR0IF = 0;
 ucContador++;
 PORTD=ucContador;
 }
}


void main(){

 ADCON1 = 0x0F;

 TRISD = 0;

 ucContador=0;



 T0CON.T0CS = 0;
 T0CON.PSA = 0;
 T0CON.T0PS2 = 1;
 T0CON.T0PS1 = 1;
 T0CON.T0PS0 = 1;
 T0CON.T08BIT = 0;

 TMR0H = 0xE1;
 TMR0L = 0x7B;
 INTCON.TMR0IE = 1;
 INTCON.TMR0IF = 0;
 T0CON.TMR0ON = 1;
 INTCON.GIE = 1;
 INTCON.PEIE = 1;

 while(1);
}
