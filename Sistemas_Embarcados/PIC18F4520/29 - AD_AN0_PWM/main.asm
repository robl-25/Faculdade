
_main:
;main.c,38 :: 		void main(){
;main.c,41 :: 		PORTA = 255;
	MOVLW       255
	MOVWF       PORTA+0 
;main.c,42 :: 		TRISA = 255;                 // Configura PORTA pins como entrada
	MOVLW       255
	MOVWF       TRISA+0 
;main.c,44 :: 		ADCON0 = 0b00000001;  // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
	MOVLW       1
	MOVWF       ADCON0+0 
;main.c,45 :: 		ADCON1 = 0b11001110;  // Configura todos canais como Digital menos AN0 e REF Interna.
	MOVLW       206
	MOVWF       ADCON1+0 
;main.c,46 :: 		ADCON2 = 0b10111110;  // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
	MOVLW       190
	MOVWF       ADCON2+0 
;main.c,48 :: 		PWM1_Init(5000);      // Inicializa módulo PWM com 5Khz
	BSF         T2CON+0, 0, 0
	BCF         T2CON+0, 1, 0
	MOVLW       99
	MOVWF       PR2+0, 0
	CALL        _PWM1_Init+0, 0
;main.c,49 :: 		PWM1_Start();         // Start PWM
	CALL        _PWM1_Start+0, 0
;main.c,50 :: 		while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
L_main0:
;main.c,52 :: 		uiValorAD= ADC_Read(0);     // Lê Canal AD 0
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
;main.c,53 :: 		uiValorAD*=0.24;            // Converte valor para o duty cycle
	CALL        _Word2Double+0, 0
	MOVLW       143
	MOVWF       R4 
	MOVLW       194
	MOVWF       R5 
	MOVLW       117
	MOVWF       R6 
	MOVLW       124
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _Double2Word+0, 0
;main.c,54 :: 		PWM1_Set_Duty(uiValorAD);   // Envia o valor lido de "uiValorAD" para o módulo CCP1 pwm
	MOVF        R0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;main.c,56 :: 		}
	GOTO        L_main0
;main.c,57 :: 		}
	GOTO        $+0
; end of _main
