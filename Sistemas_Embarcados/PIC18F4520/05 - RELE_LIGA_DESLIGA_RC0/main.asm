
_main:
;main.c,38 :: 		void main(){
;main.c,39 :: 		TRISC.RC0 = 0;      // Define o pino RC0 do TRISC como saida.
	BCF         TRISC+0, 0 
;main.c,40 :: 		while(1){           // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main0:
;main.c,41 :: 		PORTC.RC0 = 0;   // Pino RC0 do PORTC em 0.
	BCF         PORTC+0, 0 
;main.c,42 :: 		Delay_ms(1000);  // Esta função é interna do compilador, portanto o tempo é de 1000ms ou 1 segundo.
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
;main.c,43 :: 		PORTC.RC0 = 1;   // Pino RC0 do PORTC em 1.
	BSF         PORTC+0, 0 
;main.c,44 :: 		Delay_ms(1000);  // Aguarda novamente 1 segundo.
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
;main.c,45 :: 		}
	GOTO        L_main0
;main.c,46 :: 		}
	GOTO        $+0
; end of _main
