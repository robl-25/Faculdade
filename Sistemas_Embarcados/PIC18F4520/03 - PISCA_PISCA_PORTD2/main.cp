#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/03 - PISCA_PISCA_PORTD2/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/03 - PISCA_PISCA_PORTD2/main.c"
void main(){
 TRISB.RB0=1;
 TRISD=0;
 while(1){
 while(PORTB.RB0==0){
 PORTD=0;
 Delay_ms(1000);
 PORTD=255;
 Delay_ms(1000);
 }
 }
}
