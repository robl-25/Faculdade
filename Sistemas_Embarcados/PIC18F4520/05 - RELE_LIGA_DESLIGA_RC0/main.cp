#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/05 - RELE_LIGA_DESLIGA_RC0/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/05 - RELE_LIGA_DESLIGA_RC0/main.c"
void main(){
 TRISC.RC0 = 0;
 while(1){
 PORTC.RC0 = 0;
 Delay_ms(1000);
 PORTC.RC0 = 1;
 Delay_ms(1000);
 }
}
