#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/04 - EFEITO_ROTACAO/main.c"
#line 40 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/04 - EFEITO_ROTACAO/main.c"
void main(){
 unsigned char ucByte1;
 unsigned char ucByte2;

 TRISD=0;
 ucByte1 = 128;
 ucByte2 = 1;

 while(1){
 PORTD=(ucByte1|ucByte2);
 ucByte1>>=1;
 ucByte2<<=1;
 if(ucByte1==0){
 ucByte1=128;
 }
 if(ucByte2==0){
 ucByte2=1;
 }
 Delay_ms(50);
 }
}
