#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/02 - PISCA_PISCA_PORTD1/main.c"
#line 37 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/02 - PISCA_PISCA_PORTD1/main.c"
void main(){
 TRISD=0;
 while(1){
 PORTD=0;
 Delay_ms(1000);
 PORTD=255;
 Delay_ms(1000);
 }
}
