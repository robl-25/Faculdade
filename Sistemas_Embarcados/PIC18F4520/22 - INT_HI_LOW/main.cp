#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - INT_HI_LOW/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - INT_HI_LOW/main.c"
unsigned char ucContador_alta = 0X01;
unsigned char ucContador_baixa = 0X80;

void interrupt()
{

 if(PIR2.TMR3IF==1){

 TMR3H = 0x0B;
 TMR3L = 0xDC;

 PIR2.TMR3IF = 0;
 ucContador_alta <<= 1;
 if (ucContador_alta==0){
 ucContador_alta=0x01;
 }
 PORTD=ucContador_alta;
 }
}

void interrupt_low()
{
 if(PIR1.TMR1IF==1){

 TMR1H = 0x0B;
 TMR1L = 0xDC;

 PIR1.TMR1IF = 0;
 ucContador_baixa>>=1;
 if (ucContador_baixa==0){
 ucContador_baixa=0x80;
 }
 PORTB=ucContador_baixa;
 }
}



void main(){
 TRISB = 0;
 TRISD = 0;
 PORTB = 0;
 PORTD = 0;



 T1CON.RD16 = 1;
 T1CON.T1CKPS1 = 1;
 T1CON.T1CKPS0 = 1;
 T1CON.TMR1CS = 0;

 TMR1H = 0x0B;
 TMR1L = 0xDC;
 PIE1.TMR1IE = 1;
 PIR1.TMR1IF = 0;
 IPR1.TMR1IP = 0;
 T1CON.TMR1ON = 1;



 T3CON.RD16 = 1;
 T3CON.T1CKPS1 = 1;
 T3CON.T1CKPS0 = 0;
 T3CON.TMR3CS = 0;

 TMR1H = 0x0B;
 TMR1L = 0xDC;
 PIE2.TMR3IE = 1;
 PIR2.TMR3IF = 0;
 T3CON.TMR3ON = 1;
 IPR2.TMR3IP = 1;

 RCON.IPEN = 1;

 INTCON.GIEH = 1;
 INTCON.GIEL = 1;

 while(1);
}
