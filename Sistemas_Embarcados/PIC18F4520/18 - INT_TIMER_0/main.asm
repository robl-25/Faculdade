
_interrupt:
;main.c,41 :: 		void interrupt(){               // Palavra "interrupt" sempre em minuscula.
;main.c,43 :: 		if(INTCON.TMR0IF==1){       // Incrementa somente quando existir o overflow do timer 0.
	BTFSS       INTCON+0, 2 
	GOTO        L_interrupt0
;main.c,45 :: 		TMR0H = 0xE1 ;           // Carrega o valor alto do número 57723.
	MOVLW       225
	MOVWF       TMR0H+0 
;main.c,46 :: 		TMR0L = 0x7B;            // Carrega o valor baixo do numero 57723.
	MOVLW       123
	MOVWF       TMR0L+0 
;main.c,48 :: 		INTCON.TMR0IF = 0;       // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
	BCF         INTCON+0, 2 
;main.c,49 :: 		ucContador++;            // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
	INCF        _ucContador+0, 1 
;main.c,50 :: 		PORTD=ucContador;        // Coloca o valor do Contador no PORTD.
	MOVF        _ucContador+0, 0 
	MOVWF       PORTD+0 
;main.c,51 :: 		}
L_interrupt0:
;main.c,52 :: 		}
L__interrupt3:
	RETFIE      1
; end of _interrupt

_main:
;main.c,55 :: 		void main(){
;main.c,57 :: 		ADCON1 = 0x0F;           // Configura todos os pinos A/D como I/O
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,59 :: 		TRISD = 0;               // Define todos os pinos Do PORTD como saida.
	CLRF        TRISD+0 
;main.c,61 :: 		ucContador=0;            // Inicializa a variavel com o valor 0.
	CLRF        _ucContador+0 
;main.c,65 :: 		T0CON.T0CS = 0;          // Timer0 operando como temporizador.
	BCF         T0CON+0, 5 
;main.c,66 :: 		T0CON.PSA = 0;           // Prescaler ativado.
	BCF         T0CON+0, 3 
;main.c,67 :: 		T0CON.T0PS2 = 1;         // Define prescaler 1:256.
	BSF         T0CON+0, 2 
;main.c,68 :: 		T0CON.T0PS1 = 1;         // Define prescaler 1:256.
	BSF         T0CON+0, 1 
;main.c,69 :: 		T0CON.T0PS0 = 1;         // Define prescaler 1:256.
	BSF         T0CON+0, 0 
;main.c,70 :: 		T0CON.T08BIT = 0;        // Define contagem no modo 16 bits.
	BCF         T0CON+0, 6 
;main.c,72 :: 		TMR0H = 0xE1;            // Carrega o valor alto do número 57723.
	MOVLW       225
	MOVWF       TMR0H+0 
;main.c,73 :: 		TMR0L = 0x7B;            // Carrega o valor baixo do numero 57723.
	MOVLW       123
	MOVWF       TMR0L+0 
;main.c,74 :: 		INTCON.TMR0IE = 1;       // Habilita interrupção do timer0.
	BSF         INTCON+0, 5 
;main.c,75 :: 		INTCON.TMR0IF = 0;       // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
	BCF         INTCON+0, 2 
;main.c,76 :: 		T0CON.TMR0ON = 1;        // Liga timer0.
	BSF         T0CON+0, 7 
;main.c,77 :: 		INTCON.GIE = 1;          // Habilita as interrupções não-mascaradas.
	BSF         INTCON+0, 7 
;main.c,78 :: 		INTCON.PEIE = 1;         // Habilita as interrupções dos perifericos.
	BSF         INTCON+0, 6 
;main.c,80 :: 		while(1);
L_main1:
	GOTO        L_main1
;main.c,81 :: 		}
	GOTO        $+0
; end of _main
