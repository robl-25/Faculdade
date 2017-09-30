
_interrupt:
;main.c,41 :: 		void interrupt()               // Palavra "interrupt" sempre em minuscula.
;main.c,44 :: 		if(PIR2.TMR3IF==1){        // Executa somente quando existir o overflow do timer 3.
	BTFSS       PIR2+0, 1 
	GOTO        L_interrupt0
;main.c,46 :: 		TMR3H = 0x0B;           // Carrega o valor alto do número 3036.
	MOVLW       11
	MOVWF       TMR3H+0 
;main.c,47 :: 		TMR3L = 0xDC;           // Carrega o valor baixo do numero 3036.
	MOVLW       220
	MOVWF       TMR3L+0 
;main.c,49 :: 		PIR2.TMR3IF = 0;        // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
	BCF         PIR2+0, 1 
;main.c,50 :: 		ucContador_alta <<= 1; // Esse operador BITWISE(<<) realiza o mesmo que variavel = variavel * 2.
	MOVF        _ucContador_alta+0, 0 
	MOVWF       R1 
	RLCF        R1, 1 
	BCF         R1, 0 
	MOVF        R1, 0 
	MOVWF       _ucContador_alta+0 
;main.c,51 :: 		if (ucContador_alta==0){
	MOVF        R1, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt1
;main.c,52 :: 		ucContador_alta=0x01;
	MOVLW       1
	MOVWF       _ucContador_alta+0 
;main.c,53 :: 		}
L_interrupt1:
;main.c,54 :: 		PORTD=ucContador_alta; // Coloca o valor do Contador no PORTD.
	MOVF        _ucContador_alta+0, 0 
	MOVWF       PORTD+0 
;main.c,55 :: 		}
L_interrupt0:
;main.c,56 :: 		}
L__interrupt6:
	RETFIE      1
; end of _interrupt

_interrupt_low:
	MOVWF       ___Low_saveWREG+0 
	MOVF        STATUS+0, 0 
	MOVWF       ___Low_saveSTATUS+0 
	MOVF        BSR+0, 0 
	MOVWF       ___Low_saveBSR+0 
;main.c,58 :: 		void interrupt_low()              // Palavra "interrupt_low" sempre em minuscula.
;main.c,60 :: 		if(PIR1.TMR1IF==1){           // Executa somente quando existir o overflow do timer 1.
	BTFSS       PIR1+0, 0 
	GOTO        L_interrupt_low2
;main.c,62 :: 		TMR1H = 0x0B;              // Carrega o valor alto do número 3036.
	MOVLW       11
	MOVWF       TMR1H+0 
;main.c,63 :: 		TMR1L = 0xDC;              // Carrega o valor baixo do numero 3036.
	MOVLW       220
	MOVWF       TMR1L+0 
;main.c,65 :: 		PIR1.TMR1IF = 0;           // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
	BCF         PIR1+0, 0 
;main.c,66 :: 		ucContador_baixa>>=1;      // Esse operador BITWISE(>>) realiza o mesmo que variavel = variavel / 2.
	MOVF        _ucContador_baixa+0, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	BCF         R1, 7 
	MOVF        R1, 0 
	MOVWF       _ucContador_baixa+0 
;main.c,67 :: 		if (ucContador_baixa==0){
	MOVF        R1, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_interrupt_low3
;main.c,68 :: 		ucContador_baixa=0x80;
	MOVLW       128
	MOVWF       _ucContador_baixa+0 
;main.c,69 :: 		}
L_interrupt_low3:
;main.c,70 :: 		PORTB=ucContador_baixa;    // Coloca o valor do Contador no PORTD.
	MOVF        _ucContador_baixa+0, 0 
	MOVWF       PORTB+0 
;main.c,71 :: 		}
L_interrupt_low2:
;main.c,72 :: 		}
L__interrupt_low7:
	MOVF        ___Low_saveBSR+0, 0 
	MOVWF       BSR+0 
	MOVF        ___Low_saveSTATUS+0, 0 
	MOVWF       STATUS+0 
	SWAPF       ___Low_saveWREG+0, 1 
	SWAPF       ___Low_saveWREG+0, 0 
	RETFIE      0
; end of _interrupt_low

_main:
;main.c,76 :: 		void main(){           // Função principal de qualquer programa escrito na linguagem C.
;main.c,77 :: 		TRISB = 0;          // Configura PORTB como saida.
	CLRF        TRISB+0 
;main.c,78 :: 		TRISD = 0;          // Configura PORTD como saida.
	CLRF        TRISD+0 
;main.c,79 :: 		PORTB = 0;          // Desliga todos os pinos do PORTB.
	CLRF        PORTB+0 
;main.c,80 :: 		PORTD = 0;          // Desliga todos os pinos do PORTD.
	CLRF        PORTD+0 
;main.c,84 :: 		T1CON.RD16 = 1;          // Habilita a leitura e escrita em um ciclo de 16 bits.
	BSF         T1CON+0, 7 
;main.c,85 :: 		T1CON.T1CKPS1 = 1;       // Define prescaler 1:8.
	BSF         T1CON+0, 5 
;main.c,86 :: 		T1CON.T1CKPS0 = 1;       // Define prescaler 1:8.
	BSF         T1CON+0, 4 
;main.c,87 :: 		T1CON.TMR1CS = 0;        // Clock interno.
	BCF         T1CON+0, 1 
;main.c,89 :: 		TMR1H = 0x0B;            // Carrega o valor alto do número 3036.
	MOVLW       11
	MOVWF       TMR1H+0 
;main.c,90 :: 		TMR1L = 0xDC;            // Carrega o valor baixo do numero 3036.
	MOVLW       220
	MOVWF       TMR1L+0 
;main.c,91 :: 		PIE1.TMR1IE = 1;         // Habilita a interrupção do timer1.
	BSF         PIE1+0, 0 
;main.c,92 :: 		PIR1.TMR1IF = 0;         // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
	BCF         PIR1+0, 0 
;main.c,93 :: 		IPR1.TMR1IP = 0;         // Habilita prioridade de interrupção baixa.
	BCF         IPR1+0, 0 
;main.c,94 :: 		T1CON.TMR1ON = 1;        // Liga timer1.
	BSF         T1CON+0, 0 
;main.c,98 :: 		T3CON.RD16 = 1;          // Habilita a leitura e escrita em um ciclo de 16 bits.
	BSF         T3CON+0, 7 
;main.c,99 :: 		T3CON.T1CKPS1 = 1;       // Define prescaler 1:4.
	BSF         T3CON+0, 5 
;main.c,100 :: 		T3CON.T1CKPS0 = 0;       // Define prescaler 1:4.
	BCF         T3CON+0, 4 
;main.c,101 :: 		T3CON.TMR3CS = 0;        // Clock interno.
	BCF         T3CON+0, 1 
;main.c,103 :: 		TMR1H = 0x0B;            // Carrega o valor alto do número 3036.
	MOVLW       11
	MOVWF       TMR1H+0 
;main.c,104 :: 		TMR1L = 0xDC;            // Carrega o valor baixo do numero 3036.
	MOVLW       220
	MOVWF       TMR1L+0 
;main.c,105 :: 		PIE2.TMR3IE = 1;         // Habilita a interrupção do timer3.
	BSF         PIE2+0, 1 
;main.c,106 :: 		PIR2.TMR3IF = 0;         // Apaga flag de estouro do timer3, pois é fundamental para a sinalização do estouro.
	BCF         PIR2+0, 1 
;main.c,107 :: 		T3CON.TMR3ON = 1;        // Liga timer3.
	BSF         T3CON+0, 0 
;main.c,108 :: 		IPR2.TMR3IP = 1;         // Habilita prioridade de interrupção alta.
	BSF         IPR2+0, 1 
;main.c,110 :: 		RCON.IPEN = 1;           // 2 Niveis de prioridade de interrupçâo.
	BSF         RCON+0, 7 
;main.c,112 :: 		INTCON.GIEH = 1;    // Habilita todas interrupções e o vetor de alta prioridade.
	BSF         INTCON+0, 7 
;main.c,113 :: 		INTCON.GIEL = 1;    // Habilita o vetor de baixa prioridade.
	BSF         INTCON+0, 6 
;main.c,115 :: 		while(1); // Loop infinito.
L_main4:
	GOTO        L_main4
;main.c,116 :: 		}
	GOTO        $+0
; end of _main
