
_main:
;main.c,67 :: 		void main(){
;main.c,68 :: 		TRISB = 0;                        // Define PORTB como saida.
	CLRF        TRISB+0 
;main.c,69 :: 		TRISD = 0;                        // Define PORTD como saida.
	CLRF        TRISD+0 
;main.c,70 :: 		TRISC.RC5 = 0;                    // Define PORTC.RC5 como saida.
	BCF         TRISC+0, 5 
;main.c,71 :: 		TRISC.RC1 = 0;                    // Define PORTC.RC1 como saida.
	BCF         TRISC+0, 1 
;main.c,72 :: 		TRISE = 0;                        // Define PORTE como saida.
	CLRF        TRISE+0 
;main.c,73 :: 		PORTB = 0;                        // Limpa PORTB.
	CLRF        PORTB+0 
;main.c,76 :: 		ADCON0 = 0b00000001;              // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
	MOVLW       1
	MOVWF       ADCON0+0 
;main.c,77 :: 		ADCON1 = 0b00001100;              // Configura todos canais como Digital menos AN0,AN1 E AN2 e REF Interna.
	MOVLW       12
	MOVWF       ADCON1+0 
;main.c,78 :: 		ADCON2 = 0b10111110;              // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
	MOVLW       190
	MOVWF       ADCON2+0 
;main.c,81 :: 		Lcd_Init();                               // Inicializa LCD.
	CALL        _Lcd_Init+0, 0
;main.c,83 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,84 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,85 :: 		Lcd_Out(1, 1, "TEMP: ");                  // Escreve mensagem no LCD.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_main+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_main+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,86 :: 		PORTC.RC5 = 1;                            // Liga resistencia de aquecimento.
	BSF         PORTC+0, 5 
;main.c,87 :: 		GRAUS();                                  // Armazena simbolo de graus.
	CALL        _GRAUS+0, 0
;main.c,88 :: 		while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
L_main0:
;main.c,89 :: 		iLeituraAD= ADC_Read(2);          // Lê Canal AD 2
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _iLeituraAD+0 
	MOVF        R1, 0 
	MOVWF       _iLeituraAD+1 
;main.c,90 :: 		iLeituraAD/=2;                    // Converte valor do sensor LM35
	MOVF        R0, 0 
	MOVWF       R2 
	MOVF        R1, 0 
	MOVWF       R3 
	RRCF        R3, 1 
	RRCF        R2, 1 
	BCF         R3, 7 
	MOVF        R2, 0 
	MOVWF       _iLeituraAD+0 
	MOVF        R3, 0 
	MOVWF       _iLeituraAD+1 
;main.c,91 :: 		WordToStr(iLeituraAD, ucTexto);   // Converte o valor lido no A/D em string
	MOVF        R2, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R3, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _ucTexto+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_ucTexto+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;main.c,92 :: 		Lcd_Out(1,8,ucTexto);             // Imprime no LCD o valor do Duty Cycle.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       8
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _ucTexto+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_ucTexto+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,93 :: 		Lcd_Chr_CP(0);                    // Imprime simbolo de graus.
	CLRF        FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;main.c,94 :: 		Lcd_Chr_CP('C');                  // Unidade.
	MOVLW       67
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;main.c,95 :: 		Delay_ms(100);                    // Delay de 0,1 segundo.
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       4
	MOVWF       R12, 0
	MOVLW       186
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 0
	BRA         L_main2
	DECFSZ      R12, 1, 0
	BRA         L_main2
	DECFSZ      R11, 1, 0
	BRA         L_main2
	NOP
;main.c,96 :: 		PORTC.RC1 = ~PORTC.RC1;           // Alterna som do buzzer.
	BTG         PORTC+0, 1 
;main.c,97 :: 		}
	GOTO        L_main0
;main.c,98 :: 		}
	GOTO        $+0
; end of _main

_GRAUS:
;main.c,100 :: 		void GRAUS() {
;main.c,103 :: 		Lcd_Cmd(64);
	MOVLW       64
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,104 :: 		for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
	CLRF        GRAUS_i_L0+0 
L_GRAUS3:
	MOVF        GRAUS_i_L0+0, 0 
	SUBLW       7
	BTFSS       STATUS+0, 0 
	GOTO        L_GRAUS4
	MOVLW       GRAUS_character_L0+0
	ADDWF       GRAUS_i_L0+0, 0 
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(GRAUS_character_L0+0)
	MOVWF       TBLPTRH 
	MOVLW       0
	ADDWFC      TBLPTRH, 1 
	MOVLW       higher_addr(GRAUS_character_L0+0)
	MOVWF       TBLPTRU 
	MOVLW       0
	ADDWFC      TBLPTRU, 1 
	TBLRD*+
	MOVFF       TABLAT+0, FARG_Lcd_Chr_CP_out_char+0
	CALL        _Lcd_Chr_CP+0, 0
	INCF        GRAUS_i_L0+0, 1 
	GOTO        L_GRAUS3
L_GRAUS4:
;main.c,105 :: 		}
	RETURN      0
; end of _GRAUS
