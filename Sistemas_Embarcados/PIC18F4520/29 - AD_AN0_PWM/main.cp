#line 1 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/xx - AD_AN0_PWM/main.c"
#line 38 "C:/Microgenios/Microcontroladores/PIC/Compiladores/MikroC/Programa/PRO/Exemplos/PIC18F4520/xx - AD_AN0_PWM/main.c"
void main(){
 unsigned int uiValorAD;

 PORTA = 255;
 TRISA = 255;

 ADCON0 = 0b00000001;
 ADCON1 = 0b11001110;
 ADCON2 = 0b10111110;

 PWM1_Init(5000);
 PWM1_Start();
 while(1){

 uiValorAD= ADC_Read(0);
 uiValorAD*=0.24;
 PWM1_Set_Duty(uiValorAD);
 Delay_10us;
 }
}
