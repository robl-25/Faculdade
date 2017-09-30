
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
;main.c,50 :: 		TRISA.RA2=0;        // Define o pino RA2 do PORTA como saida(Seleção Display 1).
	BCF         TRISA+0, 2 
;main.c,51 :: 		TRISA.RA3=0;        // Define o pino RA3 do PORTA como saida(Seleção Display 2).
	BCF         TRISA+0, 3 
;main.c,52 :: 		TRISA.RA4=0;        // Define o pino RA4 do PORTA como saida(Seleção Display 3).
	BCF         TRISA+0, 4 
;main.c,53 :: 		TRISA.RA5=0;        // Define o pino RA5 do PORTA como saida(Seleção Display 4).
	BCF         TRISA+0, 5 
;main.c,55 :: 		TRISD = 0;          // Define todos os pinos Do PORTD como saida.
	CLRF        TRISD+0 
;main.c,59 :: 		uiContador=0;       // Inicializa a variavel com o valor 0.
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;main.c,63 :: 		T1CON.RD16 = 1;          // Habilita a leitura e escrita em um ciclo de 16 bits.
	BSF         T1CON+0, 7 
;main.c,64 :: 		T1CON.T1CKPS1 = 1;       // Define prescaler 1:8.
	BSF         T1CON+0, 5 
;main.c,65 :: 		T1CON.T1CKPS0 = 1;       // Define prescaler 1:8.
	BSF         T1CON+0, 4 
;main.c,66 :: 		T1CON.TMR1CS = 0;        // Clock interno.
	BCF         T1CON+0, 1 
;main.c,69 :: 		TMR1H = 0x0B;            // Carrega o valor alto do número 3036.
	MOVLW       11
	MOVWF       TMR1H+0 
;main.c,70 :: 		TMR1L = 0xDC;            // Carrega o valor baixo do numero 3036.
	MOVLW       220
	MOVWF       TMR1L+0 
;main.c,72 :: 		PIR1.TMR1IF = 0;         // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
	BCF         PIR1+0, 0 
;main.c,73 :: 		T1CON.TMR1ON = 1;        // Liga timer1.
	BSF         T1CON+0, 0 
;main.c,75 :: 		while(1){           // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main0:
;main.c,78 :: 		if(PIR1.TMR1IF==1){   // Incrementa somente quando existir o overflow do timer 1.
	BTFSS       PIR1+0, 0 
	GOTO        L_main2
;main.c,80 :: 		TMR1H = 0x0B;           // Carrega o valor alto do número 3036.
	MOVLW       11
	MOVWF       TMR1H+0 
;main.c,81 :: 		TMR1L = 0xDC;           // Carrega o valor baixo do numero 3036.
	MOVLW       220
	MOVWF       TMR1L+0 
;main.c,83 :: 		PIR1.TMR1IF = 0;        // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
	BCF         PIR1+0, 0 
;main.c,85 :: 		uiContador++;           // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
	INFSNZ      main_uiContador_L0+0, 1 
	INCF        main_uiContador_L0+1, 1 
;main.c,86 :: 		if(uiContador>9999){
	MOVF        main_uiContador_L0+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main8
	MOVF        main_uiContador_L0+0, 0 
	SUBLW       15
L__main8:
	BTFSC       STATUS+0, 0 
	GOTO        L_main3
;main.c,88 :: 		uiContador=0;
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;main.c,89 :: 		}
L_main3:
;main.c,90 :: 		}
L_main2:
;main.c,92 :: 		uiValor =  uiContador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.
	MOVF        main_uiContador_L0+0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        main_uiContador_L0+1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,95 :: 		PORTD = ucMask[uiValor%10];              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
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
;main.c,96 :: 		PORTA.RA5 = 1;                           // Liga o transistor associado ao display 1.
	BSF         PORTA+0, 5 
;main.c,97 :: 		Delay_ms(2);                             // Delay para escrita no display.
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
;main.c,98 :: 		PORTA.RA5 = 0;                           // Desliga o transistor associado ao display 1.
	BCF         PORTA+0, 5 
;main.c,99 :: 		uiValor/=10;                             // Divide variavel por 10.
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
;main.c,101 :: 		PORTD = ucMask[uiValor%10];
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
;main.c,102 :: 		PORTA.RA4 = 1;
	BSF         PORTA+0, 4 
;main.c,103 :: 		Delay_ms(2);
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
;main.c,104 :: 		PORTA.RA4 = 0;
	BCF         PORTA+0, 4 
;main.c,105 :: 		uiValor/=10;
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
;main.c,107 :: 		PORTD = ucMask[uiValor%10];
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
;main.c,108 :: 		PORTA.RA3 = 1;
	BSF         PORTA+0, 3 
;main.c,109 :: 		Delay_ms(2);
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
;main.c,110 :: 		PORTA.RA3 = 0;
	BCF         PORTA+0, 3 
;main.c,111 :: 		uiValor/=10;
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
;main.c,113 :: 		PORTD = ucMask[uiValor%10];
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
;main.c,114 :: 		PORTA.RA2 = 1;
	BSF         PORTA+0, 2 
;main.c,115 :: 		Delay_ms(2);
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
;main.c,116 :: 		PORTA.RA2 = 0;
	BCF         PORTA+0, 2 
;main.c,117 :: 		}
	GOTO        L_main0
;main.c,118 :: 		}
	GOTO        $+0
; end of _main
