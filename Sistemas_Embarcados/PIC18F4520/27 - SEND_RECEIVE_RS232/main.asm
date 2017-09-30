
_main:
;main.c,28 :: 		void main(){
;main.c,32 :: 		ADCON0 = 0b00000001;         // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
	MOVLW       1
	MOVWF       ADCON0+0 
;main.c,33 :: 		ADCON1 = 0b11001110;         // Configura todos canais como Digital menos AN0 e REF Interna.
	MOVLW       206
	MOVWF       ADCON1+0 
;main.c,34 :: 		ADCON2 = 0b10111110;         // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
	MOVLW       190
	MOVWF       ADCON2+0 
;main.c,36 :: 		TRISD = 0;                   // Define Todos Os Pinos Do PORTD Como Saida.
	CLRF        TRISD+0 
;main.c,37 :: 		PORTD = 0;
	CLRF        PORTD+0 
;main.c,39 :: 		UART1_Init(9600);            // Utiliza bibliotecas do compilador para configuração da RS232.
	MOVLW       51
	MOVWF       SPBRG+0 
	BSF         TXSTA+0, 2, 0
	CALL        _UART1_Init+0, 0
;main.c,41 :: 		while(1){ // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
L_main0:
;main.c,42 :: 		if(UART1_Data_Ready()){
	CALL        _UART1_Data_Ready+0, 0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main2
;main.c,43 :: 		ucRead = UART1_Read(); // Lê o dado da serial.
	CALL        _UART1_Read+0, 0
;main.c,44 :: 		UART1_Write(ucRead);   // Reenvia pela serial.
	MOVF        R0, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,45 :: 		}
L_main2:
;main.c,46 :: 		Delay_ms(100);            // Pausa de 100ms.
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       4
	MOVWF       R12, 0
	MOVLW       186
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 0
	BRA         L_main3
	DECFSZ      R12, 1, 0
	BRA         L_main3
	DECFSZ      R11, 1, 0
	BRA         L_main3
	NOP
;main.c,47 :: 		}
	GOTO        L_main0
;main.c,48 :: 		}
	GOTO        $+0
; end of _main
