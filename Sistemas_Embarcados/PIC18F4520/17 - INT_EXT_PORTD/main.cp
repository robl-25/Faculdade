#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/16 - INT_EXT_PORTD/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/16 - INT_EXT_PORTD/main.c"
unsigned char ucContador = 0;

void interrupt()
{
 ucContador++;
 PORTD = ucContador;
 INTCON.INT0IF = 0;

}

void main(){
 INTCON2.RBPU = 0;



 TRISB.RB0 = 1;
 TRISD = 0;
 PORTD = 0;

 INTCON = 0b11010001;



 INTCON2.INTEDG0 = 0;
 while(1);
}
