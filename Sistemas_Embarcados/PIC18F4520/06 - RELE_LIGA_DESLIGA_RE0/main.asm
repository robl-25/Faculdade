
_main:
;main.c,38 :: 		void main(){
;main.c,39 :: 		ADCON1 = 0x0f;      // Configura todos os pinos como I/O
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,40 :: 		TRISE.RE0 = 0;      // Define o pino RE0 do TRISE como saida.
	BCF         TRISE+0, 0 
;main.c,41 :: 		while(1){           // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main0:
;main.c,42 :: 		PORTE.RE0 = 0;   // Pino RE0 do PORTE em 0.
	BCF         PORTE+0, 0 
;main.c,43 :: 		Delay_ms(1000);  // Esta função é interna do compilador, portanto o tempo é de 1000ms ou 1 segundo.
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 0
	BRA         L_main2
	DECFSZ      R12, 1, 0
	BRA         L_main2
	DECFSZ      R11, 1, 0
	BRA         L_main2
	NOP
	NOP
;main.c,44 :: 		PORTE.RE0 = 1;   // Pino RE0 do PORTE em 1.
	BSF         PORTE+0, 0 
;main.c,45 :: 		Delay_ms(1000);  // Aguarda novamente 1 segundo.
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 0
	BRA         L_main3
	DECFSZ      R12, 1, 0
	BRA         L_main3
	DECFSZ      R11, 1, 0
	BRA         L_main3
	NOP
	NOP
;main.c,46 :: 		}
	GOTO        L_main0
;main.c,47 :: 		}
	GOTO        $+0
; end of _main
