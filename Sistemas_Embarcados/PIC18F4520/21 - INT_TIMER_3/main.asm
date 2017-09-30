
_interrupt:
;main.c,40 :: 		void interrupt(){            // Palavra "interrupt" sempre em minuscula.
;main.c,41 :: 		if(PIR2.TMR3IF==1){      // Incrementa somente quando existir o overflow do timer 1.
	BTFSS       PIR2+0, 1 
	GOTO        L_interrupt0
;main.c,43 :: 		TMR3H = 0x0B;         // Carrega o valor alto do número 3036.
	MOVLW       11
	MOVWF       TMR3H+0 
;main.c,44 :: 		TMR3L = 0xDC;         // Carrega o valor baixo do numero 3036.
	MOVLW       220
	MOVWF       TMR3L+0 
;main.c,46 :: 		PIR2.TMR3IF = 0;      // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
	BCF         PIR2+0, 1 
;main.c,47 :: 		ucContador++;         // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
	INFSNZ      _ucContador+0, 1 
	INCF        _ucContador+1, 1 
;main.c,48 :: 		PORTD=ucContador;     // Coloca o valor do Contador no PORTD.
	MOVF        _ucContador+0, 0 
	MOVWF       PORTD+0 
;main.c,49 :: 		}
L_interrupt0:
;main.c,50 :: 		}
L__interrupt3:
	RETFIE      1
; end of _interrupt

_main:
;main.c,52 :: 		void main(){
;main.c,53 :: 		ADCON1 = 0x0F;            // Configura todos os pinos A/D como I/O
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,55 :: 		TRISD = 0;                // Define todos os pinos Do PORTD como saida.
	CLRF        TRISD+0 
;main.c,57 :: 		ucContador=0;             // Inicializa a variavel com o valor 0.
	CLRF        _ucContador+0 
	CLRF        _ucContador+1 
;main.c,61 :: 		T3CON.RD16 = 1;          // Habilita a leitura e escrita em um ciclo de 16 bits.
	BSF         T3CON+0, 7 
;main.c,62 :: 		T3CON.T1CKPS1 = 1;       // Define prescaler 1:8.
	BSF         T3CON+0, 5 
;main.c,63 :: 		T3CON.T1CKPS0 = 1;       // Define prescaler 1:8.
	BSF         T3CON+0, 4 
;main.c,64 :: 		T3CON.TMR3CS = 0;        // Clock interno.
	BCF         T3CON+0, 1 
;main.c,67 :: 		TMR1H = 0x0B;            // Carrega o valor alto do número 3036.
	MOVLW       11
	MOVWF       TMR1H+0 
;main.c,68 :: 		TMR1L = 0xDC;            // Carrega o valor baixo do numero 3036.
	MOVLW       220
	MOVWF       TMR1L+0 
;main.c,69 :: 		PIE2.TMR3IE = 1;         // Habilita a interrupção do timer3.
	BSF         PIE2+0, 1 
;main.c,70 :: 		PIR2.TMR3IF = 0;         // Apaga flag de estouro do timer3, pois é fundamental para a sinalização do estouro.
	BCF         PIR2+0, 1 
;main.c,71 :: 		T3CON.TMR3ON = 1;        // Liga timer3.
	BSF         T3CON+0, 0 
;main.c,73 :: 		INTCON.GIE = 1;          // Habilita as interrupções não-mascaradas.
	BSF         INTCON+0, 7 
;main.c,74 :: 		INTCON.PEIE = 1;         // Habilita as interrupções dos perifericos.
	BSF         INTCON+0, 6 
;main.c,76 :: 		while(1);
L_main1:
	GOTO        L_main1
;main.c,77 :: 		}
	GOTO        $+0
; end of _main
