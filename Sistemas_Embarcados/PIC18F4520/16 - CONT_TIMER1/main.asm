
_interrupt:
;main.c,63 :: 		void interrupt(){
;main.c,64 :: 		if (PIR1.TMR1IF == 1){      // Se o flag de estouro do TIMER1 for igual a 1, então
	BTFSS       PIR1+0, 0 
	GOTO        L_interrupt0
;main.c,65 :: 		PORTB.RB0 = ~PORTB.RB0;  // Inverte o estado do PORTB.RB0.
	BTG         PORTB+0, 0 
;main.c,66 :: 		TMR1L = 0xF5;            // Carrega valor de contagem baixa do TIMER1
	MOVLW       245
	MOVWF       TMR1L+0 
;main.c,67 :: 		TMR1H = 0xFF;            // Carrega valor de contagem alta do TIMER1
	MOVLW       255
	MOVWF       TMR1H+0 
;main.c,68 :: 		PIR1.TMR1IF = 0;         // Seta T0IE, apaga flag de entouro do TIMER0
	BCF         PIR1+0, 0 
;main.c,69 :: 		iReg_timer1++;           // Incrementa contador de Lote.
	INFSNZ      _iReg_timer1+0, 1 
	INCF        _iReg_timer1+1, 1 
;main.c,70 :: 		}
L_interrupt0:
;main.c,71 :: 		}
L__interrupt3:
	RETFIE      1
; end of _interrupt

_main:
;main.c,73 :: 		void main(){
;main.c,74 :: 		TRISB = 0;                        // Define PORTB como saida.
	CLRF        TRISB+0 
;main.c,75 :: 		TRISD = 0;                        // Define PORTD como saida.
	CLRF        TRISD+0 
;main.c,76 :: 		TRISC.RC0 = 1;                    // Define PORTC.RC0 como entrada.
	BSF         TRISC+0, 0 
;main.c,77 :: 		TRISC.RC2 = 0;                    // Define PORTC.RC2 como saida.
	BCF         TRISC+0, 2 
;main.c,78 :: 		TRISE = 0;                        // Define PORTE como saida.
	CLRF        TRISE+0 
;main.c,79 :: 		PORTB = 0;                        // Limpa PORTB.
	CLRF        PORTB+0 
;main.c,81 :: 		ADCON1 = 0x0F;                    // Configura todos canais como Digital.
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,84 :: 		T1CON = 0B10000011; // Liga TIMER1 como Contador em RC0, prescaler 1:1, modo 16bits.
	MOVLW       131
	MOVWF       T1CON+0 
;main.c,86 :: 		TMR1L = 0xF5;       // Carrega valor de contagem baixa do TIMER1
	MOVLW       245
	MOVWF       TMR1L+0 
;main.c,87 :: 		TMR1H = 0xFF;       // Carrega valor de contagem alta do TIMER1
	MOVLW       255
	MOVWF       TMR1H+0 
;main.c,88 :: 		PIE1.TMR1IE = 1;    // Habilita a interrupção do timer1.
	BSF         PIE1+0, 0 
;main.c,89 :: 		PIR1.TMR1IF = 0;    // Apaga flag de estouro do timer1, pois é fundamental para a sinalização do estouro.
	BCF         PIR1+0, 0 
;main.c,90 :: 		T1CON.TMR1ON = 1;   // Liga timer1.
	BSF         T1CON+0, 0 
;main.c,91 :: 		IPR1.TMR1IP = 1;    // Habilita prioridade de interrupção ALTA.
	BSF         IPR1+0, 0 
;main.c,93 :: 		RCON.IPEN = 1;      // Configura 2 niveis de interrupção.
	BSF         RCON+0, 7 
;main.c,94 :: 		INTCON.GIE = 1;     // Habilita as interrupções não-mascaradas.
	BSF         INTCON+0, 7 
;main.c,95 :: 		INTCON.PEIE = 1;    // Habilita as interrupções dos perifericos.
	BSF         INTCON+0, 6 
;main.c,98 :: 		Lcd_Init();                               // Inicializa LCD.
	CALL        _Lcd_Init+0, 0
;main.c,100 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,101 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,102 :: 		Lcd_Out(1, 1, "Qtde Lotes: ");           // Escreve mensagem no LCD.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_main+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_main+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,104 :: 		while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
L_main1:
;main.c,105 :: 		WordToStr(iReg_timer1, ucTexto);  // Converte o valor lido no iReg_timer1 em string
	MOVF        _iReg_timer1+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        _iReg_timer1+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _ucTexto+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_ucTexto+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;main.c,106 :: 		Lcd_Out(2,1,ucTexto);             // Imprime no LCD o valor da RPM.
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _ucTexto+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_ucTexto+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,107 :: 		Lcd_Out_CP(" Pcs");               // Unidade "RPM".
	MOVLW       ?lstr2_main+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(?lstr2_main+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;main.c,109 :: 		}
	GOTO        L_main1
;main.c,110 :: 		}
	GOTO        $+0
; end of _main
