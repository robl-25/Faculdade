
_main:
;main.c,37 :: 		void main(){           // Fun��o principal de qualquer programa escrito na linguagem C.
;main.c,38 :: 		TRISB=0;            // Define todos os pinos do PORTB como sa�da.
	CLRF        TRISB+0 
;main.c,39 :: 		while(1){           // Aqui definimos uma condi��o sempre verdadeira como parametro, portanto todo o bloco ser� repetido indefinidamente.
L_main0:
;main.c,40 :: 		PORTB=0;         // Todos os pinos do PORTB em 0.
	CLRF        PORTB+0 
;main.c,41 :: 		Delay_ms(1000);  // Esta fun��o � interna do compilador, portanto o tempo � de 1000ms ou 1 segundo.
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
;main.c,42 :: 		PORTB=255;       // Todos os pinos do PORTB em 1.
	MOVLW       255
	MOVWF       PORTB+0 
;main.c,43 :: 		Delay_ms(1000);  // Aguarda novamente 1 segundo.
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
;main.c,44 :: 		}
	GOTO        L_main0
;main.c,45 :: 		}
	GOTO        $+0
; end of _main
