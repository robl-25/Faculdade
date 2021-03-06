
_main:
;main.c,38 :: 		void main(){
;main.c,40 :: 		unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	MOVLW       63
	MOVWF       main_ucMask_L0+0 
	MOVLW       6
	MOVWF       main_ucMask_L0+1 
	MOVLW       91
	MOVWF       main_ucMask_L0+2 
	MOVLW       79
	MOVWF       main_ucMask_L0+3 
	MOVLW       102
	MOVWF       main_ucMask_L0+4 
	MOVLW       109
	MOVWF       main_ucMask_L0+5 
	MOVLW       125
	MOVWF       main_ucMask_L0+6 
	MOVLW       7
	MOVWF       main_ucMask_L0+7 
	MOVLW       127
	MOVWF       main_ucMask_L0+8 
	MOVLW       111
	MOVWF       main_ucMask_L0+9 
;main.c,48 :: 		ADCON1 = 0x0F;            // Configura todos os pinos A/D como I/O
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,50 :: 		TRISA.RA2=0;        // Define o pino RA2 do PORTA como saida(Sele��o Display 1).
	BCF         TRISA+0, 2 
;main.c,51 :: 		TRISA.RA3=0;        // Define o pino RA3 do PORTA como saida(Sele��o Display 2).
	BCF         TRISA+0, 3 
;main.c,52 :: 		TRISA.RA4=0;        // Define o pino RA4 do PORTA como saida(Sele��o Display 3).
	BCF         TRISA+0, 4 
;main.c,53 :: 		TRISA.RA5=0;        // Define o pino RA5 do PORTA como saida(Sele��o Display 4).
	BCF         TRISA+0, 5 
;main.c,55 :: 		TRISD = 0;          // Define todos os pinos Do PORTD como saida.
	CLRF        TRISD+0 
;main.c,59 :: 		uiContador=0;       // Inicializa a variavel com o valor 0.
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;main.c,63 :: 		T0CON.T0CS = 0;          // Timer0 operando como temporizador.
	BCF         T0CON+0, 5 
;main.c,64 :: 		T0CON.PSA = 0;           // Prescaler ativado.
	BCF         T0CON+0, 3 
;main.c,65 :: 		T0CON.T0PS2 = 1;         // Define prescaler 1:256.
	BSF         T0CON+0, 2 
;main.c,66 :: 		T0CON.T0PS1 = 1;         // Define prescaler 1:256.
	BSF         T0CON+0, 1 
;main.c,67 :: 		T0CON.T0PS0 = 1;         // Define prescaler 1:256.
	BSF         T0CON+0, 0 
;main.c,68 :: 		T0CON.T08BIT = 0;        // Define contagem no modo 16 bits.
	BCF         T0CON+0, 6 
;main.c,70 :: 		TMR0H = 0xE1;            // Carrega o valor alto do n�mero 57723.
	MOVLW       225
	MOVWF       TMR0H+0 
;main.c,71 :: 		TMR0L = 0x7B;            // Carrega o valor baixo do numero 57723.
	MOVLW       123
	MOVWF       TMR0L+0 
;main.c,73 :: 		INTCON.TMR0IF = 0;       // Apaga flag de estouro do timer0, pois � fundamental para a sinaliza��o do estouro.
	BCF         INTCON+0, 2 
;main.c,74 :: 		T0CON.TMR0ON = 1;        // Liga timer0.
	BSF         T0CON+0, 7 
;main.c,76 :: 		while(1){           // Aqui definimos uma condi��o sempre verdadeira como parametro, portanto todo o bloco ser� repetido indefinidamente.
L_main0:
;main.c,79 :: 		if(INTCON.TMR0IF==1){   // Incrementa somente quando existir o overflow do timer 0.
	BTFSS       INTCON+0, 2 
	GOTO        L_main2
;main.c,81 :: 		TMR0H = 0xE1 ;           // Carrega o valor alto do n�mero 57723.
	MOVLW       225
	MOVWF       TMR0H+0 
;main.c,82 :: 		TMR0L = 0x7B;            // Carrega o valor baixo do numero 57723.
	MOVLW       123
	MOVWF       TMR0L+0 
;main.c,84 :: 		INTCON.TMR0IF = 0;       // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
	BCF         INTCON+0, 2 
;main.c,86 :: 		uiContador++;            // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
	INFSNZ      main_uiContador_L0+0, 1 
	INCF        main_uiContador_L0+1, 1 
;main.c,87 :: 		if(uiContador>9999){
	MOVF        main_uiContador_L0+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main8
	MOVF        main_uiContador_L0+0, 0 
	SUBLW       15
L__main8:
	BTFSC       STATUS+0, 0 
	GOTO        L_main3
;main.c,89 :: 		uiContador=0;
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;main.c,90 :: 		}
L_main3:
;main.c,91 :: 		}
L_main2:
;main.c,93 :: 		uiValor =  uiContador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.
	MOVF        main_uiContador_L0+0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        main_uiContador_L0+1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,96 :: 		PORTD = ucMask[uiValor%10];              // Pega modulo (resto) da divis�o por 10 e coloca o valor no PORTD.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiContador_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiContador_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,97 :: 		PORTA.RA5 = 1;                           // Liga o transistor associado ao display 1.
	BSF         PORTA+0, 5 
;main.c,98 :: 		Delay_ms(2);                             // Delay para escrita no display.
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 0
	BRA         L_main4
	DECFSZ      R12, 1, 0
	BRA         L_main4
	NOP
;main.c,99 :: 		PORTA.RA5 = 0;                           // Desliga o transistor associado ao display 1.
	BCF         PORTA+0, 5 
;main.c,100 :: 		uiValor/=10;                             // Divide variavel por 10.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,102 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,103 :: 		PORTA.RA4 = 1;
	BSF         PORTA+0, 4 
;main.c,104 :: 		Delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 0
	BRA         L_main5
	DECFSZ      R12, 1, 0
	BRA         L_main5
	NOP
;main.c,105 :: 		PORTA.RA4 = 0;
	BCF         PORTA+0, 4 
;main.c,106 :: 		uiValor/=10;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,108 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,109 :: 		PORTA.RA3 = 1;
	BSF         PORTA+0, 3 
;main.c,110 :: 		Delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main6:
	DECFSZ      R13, 1, 0
	BRA         L_main6
	DECFSZ      R12, 1, 0
	BRA         L_main6
	NOP
;main.c,111 :: 		PORTA.RA3 = 0;
	BCF         PORTA+0, 3 
;main.c,112 :: 		uiValor/=10;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,114 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,115 :: 		PORTA.RA2 = 1;
	BSF         PORTA+0, 2 
;main.c,116 :: 		Delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main7:
	DECFSZ      R13, 1, 0
	BRA         L_main7
	DECFSZ      R12, 1, 0
	BRA         L_main7
	NOP
;main.c,117 :: 		PORTA.RA2 = 0;
	BCF         PORTA+0, 2 
;main.c,118 :: 		}
	GOTO        L_main0
;main.c,119 :: 		}
	GOTO        $+0
; end of _main
