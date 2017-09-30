#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - SEND_RECEIVE_RS232/main.c"
#line 28 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - SEND_RECEIVE_RS232/main.c"
void main(){

 unsigned char ucRead;

 ADCON0 = 0b00000001;
 ADCON1 = 0b11001110;
 ADCON2 = 0b10111110;

 TRISD = 0;
 PORTD = 0;

 UART1_Init(9600);

 while(1){
 if(UART1_Data_Ready()){
 ucRead = UART1_Read();
 UART1_Write(ucRead);
 }
 Delay_ms(100);
 }
}
