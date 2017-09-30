
_interrupt:
;main.c,45 :: 		void interrupt(){
;main.c,46 :: 		if(PIR2.TMR3IF==1){      // Incrementa somente quando existir o overflow do timer 3.
	BTFSS       PIR2+0, 1 
	GOTO        L_interrupt0
;main.c,48 :: 		TMR3H = 0x7B;         // Carrega o valor alto.
	MOVLW       123
	MOVWF       TMR3H+0 
;main.c,49 :: 		TMR3L = 0xDC;         // Carrega o valor baixo.
	MOVLW       220
	MOVWF       TMR3L+0 
;main.c,51 :: 		PIR2.TMR3IF = 0;      // Limpa o flag de estouro do timer3 para uma nova contagem de tempo.
	BCF         PIR2+0, 1 
;main.c,53 :: 		uiValor =  uiContador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.
	MOVF        _uiContador+0, 0 
	MOVWF       _uiValor+0 
	MOVF        _uiContador+1, 0 
	MOVWF       _uiValor+1 
;main.c,56 :: 		PORTD = ucMask[uiValor%10];              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _uiContador+0, 0 
	MOVWF       R0 
	MOVF        _uiContador+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       _ucMask+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(_ucMask+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,57 :: 		PORTA.RA5 = 1;                           // Liga o transistor associado ao display 1.
	BSF         PORTA+0, 5 
;main.c,58 :: 		Delay_ms(2);                             // Delay para escrita no display.
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_interrupt1:
	DECFSZ      R13, 1, 0
	BRA         L_interrupt1
	DECFSZ      R12, 1, 0
	BRA         L_interrupt1
	NOP
;main.c,59 :: 		PORTA.RA5 = 0;                           // Desliga o transistor associado ao display 1.
	BCF         PORTA+0, 5 
;main.c,60 :: 		uiValor/=10;                             // Divide variavel por 10.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _uiValor+0, 0 
	MOVWF       R0 
	MOVF        _uiValor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R0, 0 
	MOVWF       _uiValor+0 
	MOVF        R1, 0 
	MOVWF       _uiValor+1 
;main.c,62 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       _ucMask+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(_ucMask+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,63 :: 		PORTA.RA4 = 1;
	BSF         PORTA+0, 4 
;main.c,64 :: 		Delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_interrupt2:
	DECFSZ      R13, 1, 0
	BRA         L_interrupt2
	DECFSZ      R12, 1, 0
	BRA         L_interrupt2
	NOP
;main.c,65 :: 		PORTA.RA4 = 0;
	BCF         PORTA+0, 4 
;main.c,66 :: 		uiValor/=10;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _uiValor+0, 0 
	MOVWF       R0 
	MOVF        _uiValor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R0, 0 
	MOVWF       _uiValor+0 
	MOVF        R1, 0 
	MOVWF       _uiValor+1 
;main.c,68 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       _ucMask+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(_ucMask+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,69 :: 		PORTA.RA3 = 1;
	BSF         PORTA+0, 3 
;main.c,70 :: 		Delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_interrupt3:
	DECFSZ      R13, 1, 0
	BRA         L_interrupt3
	DECFSZ      R12, 1, 0
	BRA         L_interrupt3
	NOP
;main.c,71 :: 		PORTA.RA3 = 0;
	BCF         PORTA+0, 3 
;main.c,72 :: 		uiValor/=10;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _uiValor+0, 0 
	MOVWF       R0 
	MOVF        _uiValor+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R0, 0 
	MOVWF       _uiValor+0 
	MOVF        R1, 0 
	MOVWF       _uiValor+1 
;main.c,74 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       _ucMask+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(_ucMask+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,75 :: 		PORTA.RA2 = 1;
	BSF         PORTA+0, 2 
;main.c,76 :: 		Delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_interrupt4:
	DECFSZ      R13, 1, 0
	BRA         L_interrupt4
	DECFSZ      R12, 1, 0
	BRA         L_interrupt4
	NOP
;main.c,77 :: 		PORTA.RA2 = 0;
	BCF         PORTA+0, 2 
;main.c,78 :: 		PIR1.TMR2IF = 0;       // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
	BCF         PIR1+0, 1 
;main.c,79 :: 		}
L_interrupt0:
;main.c,80 :: 		}
L__interrupt25:
	RETFIE      1
; end of _interrupt

_main:
;main.c,82 :: 		void main(){
;main.c,86 :: 		ADCON1 = 0x0f;       // Configura todos canais como Digital.
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,88 :: 		TRISB.RB0=1;         // Define o pino RB0 do PORTB como entrada.
	BSF         TRISB+0, 0 
;main.c,89 :: 		TRISB.RB1=1;         // Define o pino RB1 Do PORTB como entrada.
	BSF         TRISB+0, 1 
;main.c,91 :: 		TRISA.RA2=0;         // Define o pino RA2 do PORTA como saida(Seleção Display 1).
	BCF         TRISA+0, 2 
;main.c,92 :: 		TRISA.RA3=0;         // Define o pino RA3 do PORTA como saida(Seleção Display 2).
	BCF         TRISA+0, 3 
;main.c,93 :: 		TRISA.RA4=0;         // Define o pino RA4 do PORTA como saida(Seleção Display 3).
	BCF         TRISA+0, 4 
;main.c,94 :: 		TRISA.RA5=0;         // Define o pino RA5 do PORTA como saida(Seleção Display 4).
	BCF         TRISA+0, 5 
;main.c,96 :: 		TRISD = 0;           // Define todos os pinos Do PORTD como saida.
	CLRF        TRISD+0 
;main.c,98 :: 		ucStatus_inc=0;      // Inicializa a variavel com o valor 0.
	CLRF        R1 
;main.c,99 :: 		ucStatus_dec=0;      // Inicializa a variavel com o valor 0.
	CLRF        R2 
;main.c,100 :: 		uiContador=0;        // Inicializa a variavel com o valor 0.
	CLRF        _uiContador+0 
	CLRF        _uiContador+1 
;main.c,104 :: 		T3CON.RD16 = 1;          // Habilita a leitura e escrita em um ciclo de 16 bits.
	BSF         T3CON+0, 7 
;main.c,105 :: 		T3CON.T1CKPS1 = 0;       // Define prescaler 1:1.
	BCF         T3CON+0, 5 
;main.c,106 :: 		T3CON.T1CKPS0 = 0;       // Define prescaler 1:1.
	BCF         T3CON+0, 4 
;main.c,107 :: 		T3CON.TMR3CS = 0;        // Clock interno.
	BCF         T3CON+0, 1 
;main.c,109 :: 		TMR1H = 0x7B;            // Carrega o valor alto.
	MOVLW       123
	MOVWF       TMR1H+0 
;main.c,110 :: 		TMR1L = 0xDC;            // Carrega o valor baixo.
	MOVLW       220
	MOVWF       TMR1L+0 
;main.c,111 :: 		PIE2.TMR3IE = 1;         // Habilita a interrupção do timer3.
	BSF         PIE2+0, 1 
;main.c,112 :: 		PIR2.TMR3IF = 0;         // Apaga flag de estouro do timer3, pois é fundamental para a sinalização do estouro.
	BCF         PIR2+0, 1 
;main.c,113 :: 		T3CON.TMR3ON = 1;        // Liga timer3.
	BSF         T3CON+0, 0 
;main.c,115 :: 		INTCON.GIE = 1;          // Habilita as interrupções não-mascaradas.
	BSF         INTCON+0, 7 
;main.c,116 :: 		INTCON.PEIE = 1;         // Habilita as interrupções dos perifericos.
	BSF         INTCON+0, 6 
;main.c,118 :: 		while(1){            // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main5:
;main.c,121 :: 		if((PORTB.RB0==0)&&(ucStatus_inc==0)){   // Incrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 0 
	GOTO        L_main9
	MOVF        R1, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main9
L__main24:
;main.c,122 :: 		ucStatus_inc=1;                       // Variavel de travamento do incremento.
	MOVLW       1
	MOVWF       R1 
;main.c,123 :: 		uiContador++;                         // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
	INFSNZ      _uiContador+0, 1 
	INCF        _uiContador+1, 1 
;main.c,124 :: 		if(uiContador>9999){
	MOVF        _uiContador+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main26
	MOVF        _uiContador+0, 0 
	SUBLW       15
L__main26:
	BTFSC       STATUS+0, 0 
	GOTO        L_main10
;main.c,126 :: 		uiContador=9999;
	MOVLW       15
	MOVWF       _uiContador+0 
	MOVLW       39
	MOVWF       _uiContador+1 
;main.c,127 :: 		}
L_main10:
;main.c,128 :: 		}
L_main9:
;main.c,129 :: 		if((PORTB.RB0==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 0 
	GOTO        L_main13
	MOVF        R1, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main13
L__main23:
;main.c,130 :: 		ucStatus_inc=0;
	CLRF        R1 
;main.c,131 :: 		}
L_main13:
;main.c,133 :: 		if((PORTB.RB1==0)&&(ucStatus_dec==0)){   // Decrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 1 
	GOTO        L_main16
	MOVF        R2, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main16
L__main22:
;main.c,134 :: 		ucStatus_dec=1;                       // Variavel de travamento do decremento.
	MOVLW       1
	MOVWF       R2 
;main.c,135 :: 		uiContador--;                         // Esse operador aritmetico(--) realiza o mesmo que variavel = variavel - 1.
	MOVLW       1
	SUBWF       _uiContador+0, 1 
	MOVLW       0
	SUBWFB      _uiContador+1, 1 
;main.c,136 :: 		if(uiContador>9999){
	MOVF        _uiContador+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main27
	MOVF        _uiContador+0, 0 
	SUBLW       15
L__main27:
	BTFSC       STATUS+0, 0 
	GOTO        L_main17
;main.c,139 :: 		uiContador=0;
	CLRF        _uiContador+0 
	CLRF        _uiContador+1 
;main.c,140 :: 		}
L_main17:
;main.c,141 :: 		}
L_main16:
;main.c,142 :: 		if((PORTB.RB1==1)&&(ucStatus_dec==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 1 
	GOTO        L_main20
	MOVF        R2, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main20
L__main21:
;main.c,143 :: 		ucStatus_dec=0;
	CLRF        R2 
;main.c,144 :: 		}
L_main20:
;main.c,145 :: 		}
	GOTO        L_main5
;main.c,146 :: 		}
	GOTO        $+0
; end of _main
