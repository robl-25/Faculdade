
_main:
;sequencial_led.c,24 :: 		void main()
;sequencial_led.c,29 :: 		trisd = 0;
	CLRF        TRISD+0 
;sequencial_led.c,30 :: 		trisb = 0;
	CLRF        TRISB+0 
;sequencial_led.c,31 :: 		trisc = 0;
	CLRF        TRISC+0 
;sequencial_led.c,32 :: 		ADCON1 = 0b00001111;                // programa pinos de A/D como I/O de uso geral
	MOVLW       15
	MOVWF       ADCON1+0 
;sequencial_led.c,33 :: 		TRISE = 0;                // programa porte como saida
	CLRF        TRISE+0 
;sequencial_led.c,34 :: 		portb=0;
	CLRF        PORTB+0 
;sequencial_led.c,35 :: 		portd=0;
	CLRF        PORTD+0 
;sequencial_led.c,36 :: 		Lcd_Init();                               // Inicializa LCD.
	CALL        _Lcd_Init+0, 0
;sequencial_led.c,37 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;sequencial_led.c,38 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;sequencial_led.c,39 :: 		Lcd_Out(1, 1, "Microgenios");   // escreve texto "Programa LCD" na primeira linha, quarta coluna do LCD
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_sequencial_led+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_sequencial_led+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;sequencial_led.c,40 :: 		Lcd_Out(2, 1, "  PicGenios ");   // escreve texto "Programa LCD" na primeira linha, quarta coluna do LCD
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_sequencial_led+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_sequencial_led+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;sequencial_led.c,41 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main0:
	DECFSZ      R13, 1, 0
	BRA         L_main0
	DECFSZ      R12, 1, 0
	BRA         L_main0
	DECFSZ      R11, 1, 0
	BRA         L_main0
	NOP
	NOP
;sequencial_led.c,45 :: 		while(1)
L_main1:
;sequencial_led.c,47 :: 		portb=~portb;
	COMF        PORTB+0, 1 
;sequencial_led.c,48 :: 		portd=~portd;
	COMF        PORTD+0, 1 
;sequencial_led.c,49 :: 		Delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 0
	BRA         L_main3
	DECFSZ      R12, 1, 0
	BRA         L_main3
	DECFSZ      R11, 1, 0
	BRA         L_main3
	NOP
	NOP
;sequencial_led.c,51 :: 		}
	GOTO        L_main1
;sequencial_led.c,52 :: 		}
	GOTO        $+0
; end of _main
