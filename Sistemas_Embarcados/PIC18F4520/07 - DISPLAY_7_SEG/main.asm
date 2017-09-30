
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
;main.c,49 :: 		ADCON1 = 0x0f;       // Configura todos canais como Digital.
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,51 :: 		TRISB.RB0=1;         // Define o pino RB0 do PORTB como entrada.
	BSF         TRISB+0, 0 
;main.c,52 :: 		TRISB.RB1=1;         // Define o pino RB1 Do PORTB como entrada.
	BSF         TRISB+0, 1 
;main.c,54 :: 		TRISA.RA2=0;         // Define o pino RA2 do PORTA como saida(Seleção Display 1).
	BCF         TRISA+0, 2 
;main.c,55 :: 		TRISA.RA3=0;         // Define o pino RA3 do PORTA como saida(Seleção Display 2).
	BCF         TRISA+0, 3 
;main.c,56 :: 		TRISA.RA4=0;         // Define o pino RA4 do PORTA como saida(Seleção Display 3).
	BCF         TRISA+0, 4 
;main.c,57 :: 		TRISA.RA5=0;         // Define o pino RA5 do PORTA como saida(Seleção Display 4).
	BCF         TRISA+0, 5 
;main.c,59 :: 		TRISD = 0;           // Define todos os pinos Do PORTD como saida.
	CLRF        TRISD+0 
;main.c,61 :: 		ucStatus_inc=0;      // Inicializa a variavel com o valor 0.
	CLRF        main_ucStatus_inc_L0+0 
;main.c,62 :: 		ucStatus_dec=0;      // Inicializa a variavel com o valor 0.
	CLRF        main_ucStatus_dec_L0+0 
;main.c,63 :: 		uiContador=0;        // Inicializa a variavel com o valor 0.
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;main.c,65 :: 		while(1){            // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main0:
;main.c,68 :: 		if((PORTB.RB0==0)&&(ucStatus_inc==0)){   // Incrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 0 
	GOTO        L_main4
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main4
L__main23:
;main.c,69 :: 		ucStatus_inc=1;                       // Variavel de travamento do incremento.
	MOVLW       1
	MOVWF       main_ucStatus_inc_L0+0 
;main.c,70 :: 		uiContador++;                         // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
	INFSNZ      main_uiContador_L0+0, 1 
	INCF        main_uiContador_L0+1, 1 
;main.c,71 :: 		if(uiContador>9999){
	MOVF        main_uiContador_L0+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main24
	MOVF        main_uiContador_L0+0, 0 
	SUBLW       15
L__main24:
	BTFSC       STATUS+0, 0 
	GOTO        L_main5
;main.c,73 :: 		uiContador=9999;
	MOVLW       15
	MOVWF       main_uiContador_L0+0 
	MOVLW       39
	MOVWF       main_uiContador_L0+1 
;main.c,74 :: 		}
L_main5:
;main.c,75 :: 		}
L_main4:
;main.c,76 :: 		if((PORTB.RB0==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 0 
	GOTO        L_main8
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main8
L__main22:
;main.c,77 :: 		ucStatus_inc=0;
	CLRF        main_ucStatus_inc_L0+0 
;main.c,78 :: 		}
L_main8:
;main.c,80 :: 		if((PORTB.RB1==0)&&(ucStatus_dec==0)){   // Decrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 1 
	GOTO        L_main11
	MOVF        main_ucStatus_dec_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main11
L__main21:
;main.c,81 :: 		ucStatus_dec=1;                       // Variavel de travamento do decremento.
	MOVLW       1
	MOVWF       main_ucStatus_dec_L0+0 
;main.c,82 :: 		uiContador--;                         // Esse operador aritmetico(--) realiza o mesmo que variavel = variavel - 1.
	MOVLW       1
	SUBWF       main_uiContador_L0+0, 1 
	MOVLW       0
	SUBWFB      main_uiContador_L0+1, 1 
;main.c,83 :: 		if(uiContador>9999){
	MOVF        main_uiContador_L0+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main25
	MOVF        main_uiContador_L0+0, 0 
	SUBLW       15
L__main25:
	BTFSC       STATUS+0, 0 
	GOTO        L_main12
;main.c,86 :: 		uiContador=0;
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;main.c,87 :: 		}
L_main12:
;main.c,88 :: 		}
L_main11:
;main.c,89 :: 		if((PORTB.RB1==1)&&(ucStatus_dec==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 1 
	GOTO        L_main15
	MOVF        main_ucStatus_dec_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main15
L__main20:
;main.c,90 :: 		ucStatus_dec=0;
	CLRF        main_ucStatus_dec_L0+0 
;main.c,91 :: 		}
L_main15:
;main.c,93 :: 		uiValor =  uiContador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.
	MOVF        main_uiContador_L0+0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        main_uiContador_L0+1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,96 :: 		PORTD = ucMask[uiValor%10];              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
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
L_main16:
	DECFSZ      R13, 1, 0
	BRA         L_main16
	DECFSZ      R12, 1, 0
	BRA         L_main16
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
L_main17:
	DECFSZ      R13, 1, 0
	BRA         L_main17
	DECFSZ      R12, 1, 0
	BRA         L_main17
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
L_main18:
	DECFSZ      R13, 1, 0
	BRA         L_main18
	DECFSZ      R12, 1, 0
	BRA         L_main18
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
L_main19:
	DECFSZ      R13, 1, 0
	BRA         L_main19
	DECFSZ      R12, 1, 0
	BRA         L_main19
	NOP
;main.c,117 :: 		PORTA.RA2 = 0;
	BCF         PORTA+0, 2 
;main.c,118 :: 		}
	GOTO        L_main0
;main.c,119 :: 		}
	GOTO        $+0
; end of _main
