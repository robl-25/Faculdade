
_delay:
;sequencial.c,17 :: 		void delay (unsigned char tempo)
;sequencial.c,19 :: 		for(;tempo!=0;tempo--);
L_delay0:
	MOVF        FARG_delay_tempo+0, 0 
	XORLW       0
	BTFSC       STATUS+0, 2 
	GOTO        L_delay1
	DECF        FARG_delay_tempo+0, 1 
	GOTO        L_delay0
L_delay1:
;sequencial.c,20 :: 		}
	RETURN      0
; end of _delay

_main:
;sequencial.c,22 :: 		void main(){
;sequencial.c,26 :: 		trisd = 0;
	CLRF        TRISD+0 
;sequencial.c,27 :: 		trisb = 0;
	CLRF        TRISB+0 
;sequencial.c,28 :: 		trisc = 0;
	CLRF        TRISC+0 
;sequencial.c,29 :: 		ADCON1 = 0b00001111;                // programa pinos de A/D como I/O de uso geral
	MOVLW       15
	MOVWF       ADCON1+0 
;sequencial.c,30 :: 		TRISE = 0;                // programa porte como saida
	CLRF        TRISE+0 
;sequencial.c,31 :: 		portb=0;
	CLRF        PORTB+0 
;sequencial.c,32 :: 		portd=0;
	CLRF        PORTD+0 
;sequencial.c,33 :: 		Lcd_Init();                               // Inicializa LCD.
	CALL        _Lcd_Init+0, 0
;sequencial.c,34 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;sequencial.c,35 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;sequencial.c,36 :: 		Lcd_Out(1, 1, "Microgenios");   // escreve texto "Programa LCD" na primeira linha, quarta coluna do LCD
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_sequencial+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_sequencial+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;sequencial.c,37 :: 		Lcd_Out(2, 1, "  PicGenios ");   // escreve texto "Programa LCD" na primeira linha, quarta coluna do LCD
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_sequencial+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_sequencial+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;sequencial.c,38 :: 		delay_ms(1000);
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
;sequencial.c,39 :: 		portc.f2 = 1;
	BSF         PORTC+0, 2 
;sequencial.c,41 :: 		seq=0x01;
	MOVLW       1
	MOVWF       main_seq_L0+0 
;sequencial.c,42 :: 		seq1=0x08;
	MOVLW       8
	MOVWF       main_seq1_L0+0 
;sequencial.c,45 :: 		sent=0;
	CLRF        main_sent_L0+0 
;sequencial.c,46 :: 		sent1=0;
	CLRF        main_sent1_L0+0 
;sequencial.c,49 :: 		while(1){
L_main4:
;sequencial.c,53 :: 		Portd=seq;
	MOVF        main_seq_L0+0, 0 
	MOVWF       PORTD+0 
;sequencial.c,56 :: 		if(sent==0){ seq<<=1;
	MOVF        main_sent_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main6
	MOVF        main_seq_L0+0, 0 
	MOVWF       R1 
	RLCF        R1, 1 
	BCF         R1, 0 
	MOVF        R1, 0 
	MOVWF       main_seq_L0+0 
;sequencial.c,59 :: 		if(seq==0x80) sent=1;
	MOVF        R1, 0 
	XORLW       128
	BTFSS       STATUS+0, 2 
	GOTO        L_main7
	MOVLW       1
	MOVWF       main_sent_L0+0 
L_main7:
;sequencial.c,60 :: 		}
	GOTO        L_main8
L_main6:
;sequencial.c,62 :: 		else{ seq>>=1;
	MOVF        main_seq_L0+0, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	BCF         R1, 7 
	MOVF        R1, 0 
	MOVWF       main_seq_L0+0 
;sequencial.c,65 :: 		if(seq==0x01) sent=0;
	MOVF        R1, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main9
	CLRF        main_sent_L0+0 
L_main9:
;sequencial.c,66 :: 		}
L_main8:
;sequencial.c,69 :: 		for(a=0;a!=30;a++) delay(250);
	CLRF        main_a_L0+0 
L_main10:
	MOVF        main_a_L0+0, 0 
	XORLW       30
	BTFSC       STATUS+0, 2 
	GOTO        L_main11
	MOVLW       250
	MOVWF       FARG_delay_tempo+0 
	CALL        _delay+0, 0
	INCF        main_a_L0+0, 1 
	GOTO        L_main10
L_main11:
;sequencial.c,73 :: 		Portb=seq1;
	MOVF        main_seq1_L0+0, 0 
	MOVWF       PORTB+0 
;sequencial.c,76 :: 		if(sent1==0){ seq1<<=1;
	MOVF        main_sent1_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main13
	MOVF        main_seq1_L0+0, 0 
	MOVWF       R1 
	RLCF        R1, 1 
	BCF         R1, 0 
	MOVF        R1, 0 
	MOVWF       main_seq1_L0+0 
;sequencial.c,79 :: 		if(seq1==0x80) sent1=1;
	MOVF        R1, 0 
	XORLW       128
	BTFSS       STATUS+0, 2 
	GOTO        L_main14
	MOVLW       1
	MOVWF       main_sent1_L0+0 
L_main14:
;sequencial.c,80 :: 		}
	GOTO        L_main15
L_main13:
;sequencial.c,82 :: 		else{ seq1>>=1;
	MOVF        main_seq1_L0+0, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	BCF         R1, 7 
	MOVF        R1, 0 
	MOVWF       main_seq1_L0+0 
;sequencial.c,85 :: 		if(seq1==0x01) sent1=0;
	MOVF        R1, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main16
	CLRF        main_sent1_L0+0 
L_main16:
;sequencial.c,86 :: 		}
L_main15:
;sequencial.c,89 :: 		for(a=0;a!=30;a++) delay(250);
	CLRF        main_a_L0+0 
L_main17:
	MOVF        main_a_L0+0, 0 
	XORLW       30
	BTFSC       STATUS+0, 2 
	GOTO        L_main18
	MOVLW       250
	MOVWF       FARG_delay_tempo+0 
	CALL        _delay+0, 0
	INCF        main_a_L0+0, 1 
	GOTO        L_main17
L_main18:
;sequencial.c,91 :: 		}
	GOTO        L_main4
;sequencial.c,92 :: 		}
	GOTO        $+0
; end of _main
