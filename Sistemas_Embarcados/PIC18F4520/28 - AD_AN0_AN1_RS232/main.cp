#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - AD_AN0_AN1_RS232/main.c"
#line 28 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/XX - AD_AN0_AN1_RS232/main.c"
void main(){

 unsigned char ucHexa[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
 unsigned char ucBuffer[4];

 unsigned int uiValorAD;

 unsigned char ucCount;

 ADCON0 = 0b00000001;
 ADCON1 = 0b11001110;
 ADCON2 = 0b10111110;

 TRISD = 0;
 PORTD = 0;

 UART1_Init(9600);

 while(1){

 uiValorAD= ADC_Read(0);



 ucBuffer[3] = ucHexa[uiValorAD%16];
 uiValorAD/=16;
 ucBuffer[2] = ucHexa[uiValorAD%16];
 uiValorAD/=16;
 ucBuffer[1] = ucHexa[uiValorAD%16];
 uiValorAD/=16;
 ucBuffer[0] = ucHexa[uiValorAD%16];


 UART1_Write(0x02);
 UART1_Write('A');
 UART1_Write('N');
 UART1_Write('0');
 UART1_Write('=');
 UART1_Write(ucBuffer[0]);
 UART1_Write(ucBuffer[1]);
 UART1_Write(ucBuffer[2]);
 UART1_Write(ucBuffer[3]);
 UART1_Write(0x04);

 uiValorAD= ADC_Read(1);



 ucBuffer[3] = ucHexa[uiValorAD%16];
 uiValorAD/=16;
 ucBuffer[2] = ucHexa[uiValorAD%16];
 uiValorAD/=16;
 ucBuffer[1] = ucHexa[uiValorAD%16];
 uiValorAD/=16;
 ucBuffer[0] = ucHexa[uiValorAD%16];


 UART1_Write(0x02);
 UART1_Write('A');
 UART1_Write('N');
 UART1_Write('1');
 UART1_Write('=');
 UART1_Write(ucBuffer[0]);
 UART1_Write(ucBuffer[1]);
 UART1_Write(ucBuffer[2]);
 UART1_Write(ucBuffer[3]);
 UART1_Write(0x04);
 Delay_ms(100);
 }
}
