
_interrupt:
;main.c,40 :: 		void interrupt(){             // Palavra "interrupt" sempre em minuscula.
;main.c,41 :: 		if(PIR1.TMR2IF==1){       // Incrementa somente quando existir o overflow do timer 2.
	BTFSS       PIR1+0, 1 
	GOTO        L_interrupt0
;main.c,43 :: 		TMR2 = 0xFF;           // Carrega o valor alto do número 255.
	MOVLW       255
	MOVWF       TMR2+0 
;main.c,45 :: 		PIR1.TMR2IF = 0;       // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
	BCF         PIR1+0, 1 
;main.c,46 :: 		ucContador++;          // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
	INCF        _ucContador+0, 1 
;main.c,47 :: 		PORTD=ucContador;      // Coloca o valor do Contador no PORTD.
	MOVF        _ucContador+0, 0 
	MOVWF       PORTD+0 
;main.c,48 :: 		}
L_interrupt0:
;main.c,49 :: 		}
L__interrupt3:
	RETFIE      1
; end of _interrupt

_main:
;main.c,51 :: 		void main(){
;main.c,53 :: 		ADCON1 = 0x0F;             // Configura todos os pinos A/D como I/O
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,55 :: 		TRISD = 0;                 // Define todos os pinos Do PORTD como saida.
	CLRF        TRISD+0 
;main.c,57 :: 		ucContador=0;              // Inicializa a variavel com o valor 0.
	CLRF        _ucContador+0 
;main.c,61 :: 		T2CON.T2OUTPS3 = 1;       // Define postscaler 1:16.
	BSF         T2CON+0, 6 
;main.c,62 :: 		T2CON.T2OUTPS2 = 1;       // Define postscaler 1:16.
	BSF         T2CON+0, 5 
;main.c,63 :: 		T2CON.T2OUTPS1 = 1;       // Define postscaler 1:16.
	BSF         T2CON+0, 4 
;main.c,64 :: 		T2CON.T2OUTPS0 = 1;       // Define postscaler 1:16.
	BSF         T2CON+0, 3 
;main.c,65 :: 		T2CON.T2CKPS1  = 1;       // Define prescaler 1:16.
	BSF         T2CON+0, 1 
;main.c,66 :: 		T2CON.T2CKPS0  = 1;       // Define prescaler 1:16.
	BSF         T2CON+0, 0 
;main.c,69 :: 		TMR2 = 0xFF;             // Carrega o valor alto do número 256.
	MOVLW       255
	MOVWF       TMR2+0 
;main.c,71 :: 		PIE1.TMR2IE = 1;         // Habilita a interrupção do timer2.
	BSF         PIE1+0, 1 
;main.c,73 :: 		PIR1.TMR2IF = 0;         // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
	BCF         PIR1+0, 1 
;main.c,74 :: 		T2CON.TMR2ON = 1;        // Liga timer2.
	BSF         T2CON+0, 2 
;main.c,76 :: 		INTCON.GIE = 1;          // Habilita as interrupções não-mascaradas.
	BSF         INTCON+0, 7 
;main.c,77 :: 		INTCON.PEIE = 1;         // Habilita as interrupções dos perifericos.
	BSF         INTCON+0, 6 
;main.c,79 :: 		while(1);
L_main1:
	GOTO        L_main1
;main.c,80 :: 		}
	GOTO        $+0
; end of _main
