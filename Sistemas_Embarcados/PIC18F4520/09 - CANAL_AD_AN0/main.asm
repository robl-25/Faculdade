
_main:
;main.c,39 :: 		void main(){
;main.c,41 :: 		unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
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
;main.c,47 :: 		ADCON0 = 0b10000001;  // Configura conversor A/D para clock de Fosc/64, Canal 0, conversão desligada, A/D ligado.
	MOVLW       129
	MOVWF       ADCON0+0 
;main.c,48 :: 		ADCON1 = 0b11001110;  // Configura resultado justificado a direita, clock de Fosc/64, todos canais como Digital menos AN0 e REF Interna.
	MOVLW       206
	MOVWF       ADCON1+0 
;main.c,50 :: 		TRISA.RA2=0;        // Define O Pino RA2 Do PORTA Como Saida(Seleção Display 1).
	BCF         TRISA+0, 2 
;main.c,51 :: 		TRISA.RA3=0;        // Define O Pino RA3 Do PORTA Como Saida(Seleção Display 2).
	BCF         TRISA+0, 3 
;main.c,52 :: 		TRISA.RA4=0;        // Define O Pino RA4 Do PORTA Como Saida(Seleção Display 3).
	BCF         TRISA+0, 4 
;main.c,53 :: 		TRISA.RA5=0;        // Define O Pino RA5 Do PORTA Como Saida(Seleção Display 4).
	BCF         TRISA+0, 5 
;main.c,55 :: 		TRISD = 0;          // Define Todos Os Pinos Do PORTD Como Saida.
	CLRF        TRISD+0 
;main.c,57 :: 		while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
L_main0:
;main.c,59 :: 		if(ADCON0.GO_DONE==0)
	BTFSC       ADCON0+0, 1 
	GOTO        L_main2
;main.c,61 :: 		uiValorAD= ((ADRESH<<8) | ADRESL);  // Lê valor do A/D.
	MOVF        ADRESH+0, 0 
	MOVWF       main_uiValorAD_L0+1 
	CLRF        main_uiValorAD_L0+0 
	MOVF        ADRESL+0, 0 
	IORWF       main_uiValorAD_L0+0, 1 
	MOVLW       0
	IORWF       main_uiValorAD_L0+1, 1 
;main.c,62 :: 		ADCON0.GO_DONE=1;                   // Inicia conversão A/D.
	BSF         ADCON0+0, 1 
;main.c,63 :: 		}
L_main2:
;main.c,65 :: 		uiValor=uiValorAD;                     // Transfere valor do A/D para variavel auxiliar.
	MOVF        main_uiValorAD_L0+0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        main_uiValorAD_L0+1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,67 :: 		TRISD=0;                               // Define Todos Os Pinos Do PORTD Como Saida.
	CLRF        TRISD+0 
;main.c,70 :: 		PORTD = ucMask[uiValor%10];            // Pega Modulo (Resto) Da Divisão Por 10 E Coloca O Valor No PORTD.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValorAD_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValorAD_L0+1, 0 
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
;main.c,71 :: 		PORTA.RA5 = 1;                         // Liga O Transistor Associado Ao Display 1.
	BSF         PORTA+0, 5 
;main.c,72 :: 		Delay_ms(2);                           // Delay Para Escrita No Display.
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 0
	BRA         L_main3
	DECFSZ      R12, 1, 0
	BRA         L_main3
	NOP
;main.c,73 :: 		PORTA.RA5 = 0;                         // Desliga O Transistor Associado Ao Display 1.
	BCF         PORTA+0, 5 
;main.c,74 :: 		uiValor/=10;                           // Divide Variavel Por 10.
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
;main.c,76 :: 		PORTD = ucMask[uiValor%10];
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
;main.c,77 :: 		PORTA.RA4 = 1;
	BSF         PORTA+0, 4 
;main.c,78 :: 		Delay_ms(2);
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
;main.c,79 :: 		PORTA.RA4 = 0;
	BCF         PORTA+0, 4 
;main.c,80 :: 		uiValor/=10;
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
;main.c,82 :: 		PORTD = ucMask[uiValor%10];
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
;main.c,83 :: 		PORTA.RA3 = 1;
	BSF         PORTA+0, 3 
;main.c,84 :: 		Delay_ms(2);
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
;main.c,85 :: 		PORTA.RA3 = 0;
	BCF         PORTA+0, 3 
;main.c,86 :: 		uiValor/=10;
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
;main.c,88 :: 		PORTD = ucMask[uiValor%10];
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
;main.c,89 :: 		PORTA.RA2 = 1;
	BSF         PORTA+0, 2 
;main.c,90 :: 		Delay_ms(2);
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
;main.c,91 :: 		PORTA.RA2 = 0;
	BCF         PORTA+0, 2 
;main.c,92 :: 		}
	GOTO        L_main0
;main.c,93 :: 		}
	GOTO        $+0
; end of _main
