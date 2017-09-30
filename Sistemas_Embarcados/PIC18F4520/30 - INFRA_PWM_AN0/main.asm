
_interrupt:
;main.c,67 :: 		void interrupt(){
;main.c,68 :: 		if (INTCON.TMR0IF == 1){    // Se o flag de estouro do TIMER0 for igual a 1, então
	BTFSS       INTCON+0, 2 
	GOTO        L_interrupt0
;main.c,69 :: 		PORTB.RB0 = ~PORTB.RB0;  // Inverte o estado do PORTB.RB0.
	BTG         PORTB+0, 0 
;main.c,70 :: 		TMR0L = 0X7B;                  // Carrega valores de contagem
	MOVLW       123
	MOVWF       TMR0L+0 
;main.c,71 :: 		TMR0H = 0XE1;                  // Carrega valores de contagem
	MOVLW       225
	MOVWF       TMR0H+0 
;main.c,72 :: 		INTCON.TMR0IF = 0;             // Seta T0IE, apaga flag de entouro do TIMER0
	BCF         INTCON+0, 2 
;main.c,73 :: 		iReg_timer1 = TMR1L*(60/7);    // Pega valor lido do timer1 e multiplica por 60 para saber rotação por minuto.
	MOVLW       3
	MOVWF       R0 
	MOVF        TMR1L+0, 0 
	MOVWF       _iReg_timer1+0 
	MOVLW       0
	MOVWF       _iReg_timer1+1 
	MOVF        R0, 0 
L__interrupt4:
	BZ          L__interrupt5
	RLCF        _iReg_timer1+0, 1 
	BCF         _iReg_timer1+0, 0 
	RLCF        _iReg_timer1+1, 1 
	ADDLW       255
	GOTO        L__interrupt4
L__interrupt5:
;main.c,75 :: 		TMR1L = 0;                     // Limpa contador.
	CLRF        TMR1L+0 
;main.c,76 :: 		}
L_interrupt0:
;main.c,77 :: 		}
L__interrupt3:
	RETFIE      1
; end of _interrupt

_main:
;main.c,79 :: 		void main(){
;main.c,80 :: 		TRISB = 0;                        // Define PORTB como saida.
	CLRF        TRISB+0 
;main.c,81 :: 		TRISD = 0;                        // Define PORTD como saida.
	CLRF        TRISD+0 
;main.c,82 :: 		TRISC.RC0 = 1;                    // Define PORTC.RC0 como entrada.
	BSF         TRISC+0, 0 
;main.c,83 :: 		TRISC.RC2 = 0;                    // Define PORTC.RC2 como saida.
	BCF         TRISC+0, 2 
;main.c,84 :: 		TRISE = 0;                        // Define PORTE como saida.
	CLRF        TRISE+0 
;main.c,85 :: 		PORTB = 0;                        // Limpa PORTB.
	CLRF        PORTB+0 
;main.c,88 :: 		INTCON.GIEH = 1;   // Habilita as interrupções e a interrupção de alta prioridade.
	BSF         INTCON+0, 7 
;main.c,89 :: 		INTCON.GIEL = 1;   // Habilita as interrupções e a interrupção de baixa prioridade
	BSF         INTCON+0, 6 
;main.c,90 :: 		RCON.IPEN = 1;     // Configura 2 niveis de interrupção.
	BSF         RCON+0, 7 
;main.c,93 :: 		INTCON.TMR0IF = 0;
	BCF         INTCON+0, 2 
;main.c,94 :: 		INTCON2.TMR0IP = 1;
	BSF         INTCON2+0, 2 
;main.c,95 :: 		INTCON.TMR0IE = 1;
	BSF         INTCON+0, 5 
;main.c,97 :: 		T0CON = 0B10000100; // Configura timer modo 16 bits, com prescaler
	MOVLW       132
	MOVWF       T0CON+0 
;main.c,98 :: 		TMR0L = 0X7B;       // Carrega valores de contagem
	MOVLW       123
	MOVWF       TMR0L+0 
;main.c,99 :: 		TMR0H = 0XE1;       // Carrega valores de contagem
	MOVLW       225
	MOVWF       TMR0H+0 
;main.c,100 :: 		INTCON.TMR0IF = 0;  // Apaga flag de estouro do TIMER0
	BCF         INTCON+0, 2 
;main.c,103 :: 		T1CON = 0B10000011; // Liga TIMER1 como Contador em RC0, prescaler 1:1, modo 16bits.
	MOVLW       131
	MOVWF       T1CON+0 
;main.c,104 :: 		TMR1L = 0;          // Carrega valor de contagem baixa do TIMER1
	CLRF        TMR1L+0 
;main.c,105 :: 		TMR1H = 0;          // Carrega valor de contagem alta do TIMER1
	CLRF        TMR1H+0 
;main.c,106 :: 		PIR1.TMR1IF = 0;    // Apaga flag de estouro do TIMER1
	BCF         PIR1+0, 0 
;main.c,108 :: 		ADCON0 = 0b00000001;              // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
	MOVLW       1
	MOVWF       ADCON0+0 
;main.c,109 :: 		ADCON1 = 0b00001110;              // Configura todos canais como Digital menos AN0 e REF Interna.
	MOVLW       14
	MOVWF       ADCON1+0 
;main.c,110 :: 		ADCON2 = 0b10111110;              // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
	MOVLW       190
	MOVWF       ADCON2+0 
;main.c,113 :: 		Lcd_Init();                               // Inicializa LCD.
	CALL        _Lcd_Init+0, 0
;main.c,115 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,116 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,117 :: 		Lcd_Out(1, 1, "Duty Cycle: ");            // Escreve mensagem no LCD.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_main+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_main+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,119 :: 		PWM1_Init(5000);                  // Inicializa módulo PWM com 5Khz
	BSF         T2CON+0, 0, 0
	BCF         T2CON+0, 1, 0
	MOVLW       99
	MOVWF       PR2+0, 0
	CALL        _PWM1_Init+0, 0
;main.c,120 :: 		PWM1_Set_Duty(255);               // Seta o Duty-cycle do PWM em 100%.
	MOVLW       255
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;main.c,121 :: 		PWM1_Start();                     // Inicia PWM.
	CALL        _PWM1_Start+0, 0
;main.c,123 :: 		while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
L_main1:
;main.c,124 :: 		iLeituraAD= ADC_Read(0);          // Lê Canal AD 0
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _iLeituraAD+0 
	MOVF        R1, 0 
	MOVWF       _iLeituraAD+1 
;main.c,125 :: 		iLeituraAD=(iLeituraAD*0.24);     // Converte valor para o duty cycle [255/(1023 pontos do A/D)]
	CALL        _Word2Double+0, 0
	MOVLW       143
	MOVWF       R4 
	MOVLW       194
	MOVWF       R5 
	MOVLW       117
	MOVWF       R6 
	MOVLW       124
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _Double2Word+0, 0
	MOVF        R0, 0 
	MOVWF       _iLeituraAD+0 
	MOVF        R1, 0 
	MOVWF       _iLeituraAD+1 
;main.c,126 :: 		PWM1_Set_Duty(iLeituraAD);        // Envia o valor lido de "iLeituraAD" para o módulo CCP1 PWM
	MOVF        R0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;main.c,127 :: 		iLeituraAD=(iLeituraAD*0.41);     // Converte valor para o duty cycle em %
	MOVF        _iLeituraAD+0, 0 
	MOVWF       R0 
	MOVF        _iLeituraAD+1, 0 
	MOVWF       R1 
	CALL        _Word2Double+0, 0
	MOVLW       133
	MOVWF       R4 
	MOVLW       235
	MOVWF       R5 
	MOVLW       81
	MOVWF       R6 
	MOVLW       125
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _Double2Word+0, 0
	MOVF        R0, 0 
	MOVWF       _iLeituraAD+0 
	MOVF        R1, 0 
	MOVWF       _iLeituraAD+1 
;main.c,128 :: 		WordToStr(iLeituraAD, ucTexto);   // Converte o valor lido no A/D em string
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _ucTexto+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_ucTexto+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;main.c,129 :: 		Lcd_Out(1,11,ucTexto);            // Imprime no LCD o valor do Duty Cycle.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       11
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _ucTexto+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_ucTexto+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,132 :: 		WordToStr(iReg_timer1, ucTexto);  // Converte o valor lido no iReg_timer1 em string
	MOVF        _iReg_timer1+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        _iReg_timer1+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _ucTexto+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_ucTexto+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;main.c,133 :: 		Lcd_Out(2,1,ucTexto);             // Imprime no LCD o valor da RPM.
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _ucTexto+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_ucTexto+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,134 :: 		Lcd_Out_CP(" RPM");               // Unidade "RPM".
	MOVLW       ?lstr2_main+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(?lstr2_main+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;main.c,136 :: 		}
	GOTO        L_main1
;main.c,137 :: 		}
	GOTO        $+0
; end of _main
