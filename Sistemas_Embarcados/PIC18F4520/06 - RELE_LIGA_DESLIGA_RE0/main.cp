#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/06 - RELE_LIGA_DESLIGA_RE0/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/06 - RELE_LIGA_DESLIGA_RE0/main.c"
void main(){
 ADCON1 = 0x0f;
 TRISE.RE0 = 0;
 while(1){
 PORTE.RE0 = 0;
 Delay_ms(1000);
 PORTE.RE0 = 1;
 Delay_ms(1000);
 }
}
