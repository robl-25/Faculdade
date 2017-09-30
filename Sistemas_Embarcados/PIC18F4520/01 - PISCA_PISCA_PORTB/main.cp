#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/01 - PISCA_PISCA_PORTB/main.c"
#line 37 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/01 - PISCA_PISCA_PORTB/main.c"
void main(){
 TRISB=0;
 while(1){
 PORTB=0;
 Delay_ms(1000);
 PORTB=255;
 Delay_ms(1000);
 }
}
