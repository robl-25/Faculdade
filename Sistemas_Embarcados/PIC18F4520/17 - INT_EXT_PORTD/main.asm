
_interrupt:
;main.c,40 :: 		void interrupt()           // Palavra "interrupt" sempre em minuscula.
;main.c,42 :: 		ucContador++;            // Incrementa valor na variavel contador.
	INCF        _ucContador+0, 1 
;main.c,43 :: 		PORTD = ucContador;      // Coloca valor da variavel no PORTD.
	MOVF        _ucContador+0, 0 
	MOVWF       PORTD+0 
;main.c,44 :: 		INTCON.INT0IF = 0;       // Limpa o flag sinalizador de interrupção externa INT0
	BCF         INTCON+0, 1 
;main.c,46 :: 		}
L__interrupt2:
	RETFIE      1
; end of _interrupt

_main:
;main.c,48 :: 		void main(){           // Função principal de qualquer programa escrito na linguagem C.
;main.c,49 :: 		INTCON2.RBPU = 0;   // Programa o resistor de pull-up interno do PIC
	BCF         INTCON2+0, 7 
;main.c,53 :: 		TRISB.RB0 = 1;      // Configura pino RB0 como entrada
	BSF         TRISB+0, 0 
;main.c,54 :: 		TRISD = 0;          // Configura PORTD como saida
	CLRF        TRISD+0 
;main.c,55 :: 		PORTD = 0;          // Desliga todos os pinos do PORTD
	CLRF        PORTD+0 
;main.c,57 :: 		INTCON = 0b11010001; //habilita interrupção geral
	MOVLW       209
	MOVWF       INTCON+0 
;main.c,61 :: 		INTCON2.INTEDG0 = 0;    //aciona interrupção por borda de descida
	BCF         INTCON2+0, 6 
;main.c,62 :: 		while(1); // Loop infinito.
L_main0:
	GOTO        L_main0
;main.c,63 :: 		}
	GOTO        $+0
; end of _main
