
_main:
;main.c,38 :: 		void main(){
;main.c,39 :: 		TRISB.RB0=1;                  // Define o pino RB0 do PORTB como entrada.
	BSF         TRISB+0, 0 
;main.c,40 :: 		TRISD=0;                      // Define todos os pinos do PORTD como saída.
	CLRF        TRISD+0 
;main.c,41 :: 		while(1){                     // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main0:
;main.c,42 :: 		while(PORTB.RB0==0){       // Enquanto o pino PORTB.RB0 estiver pressionado (igual a 0) , será executado o laço do while.
L_main2:
	BTFSC       PORTB+0, 0 
	GOTO        L_main3
;main.c,43 :: 		PORTD=0;                // Todos os pinos do PORTD em 0.
	CLRF        PORTD+0 
;main.c,44 :: 		Delay_ms(1000);         // Esta função é interna do compilador, portanto o tempo é de 1000ms ou 1 segundo.
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 0
	BRA         L_main4
	DECFSZ      R12, 1, 0
	BRA         L_main4
	DECFSZ      R11, 1, 0
	BRA         L_main4
	NOP
	NOP
;main.c,45 :: 		PORTD=255;              // Todos os pinos do PORTD em 1.
	MOVLW       255
	MOVWF       PORTD+0 
;main.c,46 :: 		Delay_ms(1000);         // Aguarda novamente 1 segundo.
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 0
	BRA         L_main5
	DECFSZ      R12, 1, 0
	BRA         L_main5
	DECFSZ      R11, 1, 0
	BRA         L_main5
	NOP
	NOP
;main.c,47 :: 		}
	GOTO        L_main2
L_main3:
;main.c,48 :: 		}
	GOTO        L_main0
;main.c,49 :: 		}
	GOTO        $+0
; end of _main
