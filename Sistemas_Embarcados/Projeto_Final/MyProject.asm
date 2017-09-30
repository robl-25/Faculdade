
_main:

;MyProject.c,68 :: 		void main(){
;MyProject.c,71 :: 		unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
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
	CLRF        main_ucContador_L0+0 
	CLRF        main_ucContador_L0+1 
	MOVLW       100
	MOVWF       main_cooler_L0+0 
	CLRF        main_valorLidoAnt_L0+0 
	CLRF        main_valorLidoAnt_L0+1 
;MyProject.c,80 :: 		TRISB.RB3=1;         // Define o pino RB0 do PORTB como entrada.
	BSF         TRISB+0, 3 
;MyProject.c,81 :: 		TRISB.RB4=1;         // Define o pino RB1 Do PORTB como entrada.
	BSF         TRISB+0, 4 
;MyProject.c,83 :: 		TRISA.RA4=0;         // Define o pino RA4 do PORTA como saida(Seleção Display 3).
	BCF         TRISA+0, 4 
;MyProject.c,84 :: 		TRISA.RA5=0;         // Define o pino RA5 do PORTA como saida(Seleção Display 4).
	BCF         TRISA+0, 5 
;MyProject.c,89 :: 		TRISC = 0;
	CLRF        TRISC+0 
;MyProject.c,90 :: 		TRISB = 0;                        // Define PORTB como saida.
	CLRF        TRISB+0 
;MyProject.c,91 :: 		TRISD = 0;                        // Define PORTD como saida.
	CLRF        TRISD+0 
;MyProject.c,92 :: 		TRISC.RC5 = 0;                    // Define PORTC.RC5 como saida.
	BCF         TRISC+0, 5 
;MyProject.c,93 :: 		TRISE = 0;                        // Define PORTE como saida.
	CLRF        TRISE+0 
;MyProject.c,95 :: 		ADCON0 = 0b00000001;              // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
	MOVLW       1
	MOVWF       ADCON0+0 
;MyProject.c,96 :: 		ADCON1 = 0b00001100;              // Configura todos canais como Digital menos AN0,AN1 E AN2 e REF Interna.
	MOVLW       12
	MOVWF       ADCON1+0 
;MyProject.c,97 :: 		ADCON2 = 0b10111110;              // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
	MOVLW       190
	MOVWF       ADCON2+0 
;MyProject.c,102 :: 		T0CON.T0CS = 0;          // Timer0 operando como temporizador.
	BCF         T0CON+0, 5 
;MyProject.c,103 :: 		T0CON.PSA = 0;           // Prescaler ativado.
	BCF         T0CON+0, 3 
;MyProject.c,104 :: 		T0CON.T0PS2 = 1;         // Define prescaler 1:128.
	BSF         T0CON+0, 2 
;MyProject.c,105 :: 		T0CON.T0PS1 = 1;         // Define prescaler 1:128.
	BSF         T0CON+0, 1 
;MyProject.c,106 :: 		T0CON.T0PS0 = 0;         // Define prescaler 1:128.
	BCF         T0CON+0, 0 
;MyProject.c,107 :: 		T0CON.T08BIT = 0;        // Define contagem no modo 16 bits.
	BCF         T0CON+0, 6 
;MyProject.c,110 :: 		TMR1H = 0x48;            // Carrega o valor alto do número 3036.
	MOVLW       72
	MOVWF       TMR1H+0 
;MyProject.c,111 :: 		TMR1L = 0xE4;            // Carrega o valor baixo do numero 3036.
	MOVLW       228
	MOVWF       TMR1L+0 
;MyProject.c,113 :: 		INTCON.TMR0IF = 0;       // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
	BCF         INTCON+0, 2 
;MyProject.c,114 :: 		T0CON.TMR0ON = 1;        // Liga timer0.
	BSF         T0CON+0, 7 
;MyProject.c,117 :: 		Lcd_Init();                               // Inicializa LCD.
	CALL        _Lcd_Init+0, 0
;MyProject.c,118 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,119 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,121 :: 		Grava_RTC();
	CALL        _Grava_RTC+0, 0
;MyProject.c,122 :: 		GRAUS();                                  // Armazena simbolo de graus.
	CALL        _GRAUS+0, 0
;MyProject.c,123 :: 		PORTC.RC5 = 0;
	BCF         PORTC+0, 5 
;MyProject.c,124 :: 		while(1){// Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main0:
;MyProject.c,125 :: 		if(INTCON.TMR0IF==1){   // Incrementa somente quando existir o overflow do timer 0.
	BTFSS       INTCON+0, 2 
	GOTO        L_main2
;MyProject.c,127 :: 		TMR1H = 0x48;           // Carrega o valor alto do número 3036.
	MOVLW       72
	MOVWF       TMR1H+0 
;MyProject.c,128 :: 		TMR1L = 0xE4;           // Carrega o valor baixo do numero 3036.
	MOVLW       228
	MOVWF       TMR1L+0 
;MyProject.c,130 :: 		INTCON.TMR0IF = 0;        // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
	BCF         INTCON+0, 2 
;MyProject.c,131 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,132 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,134 :: 		LeEEPROM();   // Le e exibe no LCD os ultimos valores da temperatura da EEPROM
	CALL        _LeEEPROM+0, 0
;MyProject.c,135 :: 		delay_ms(500); //Deixa na tela as temperaturas por 0.5 segundos
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	DECFSZ      R11, 1, 1
	BRA         L_main3
	NOP
	NOP
;MyProject.c,137 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,138 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,139 :: 		}
L_main2:
;MyProject.c,142 :: 		if((PORTB.RB3==0)){   // Incrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 3 
	GOTO        L_main4
;MyProject.c,143 :: 		Lcd_Out(2, 11, "LIGA");                  // Escreve mensagem no LCD.
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       11
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,144 :: 		cooler = 'l';
	MOVLW       108
	MOVWF       main_cooler_L0+0 
;MyProject.c,145 :: 		PORTC.RC5 = 1;                            // Liga resistencia de aquecimento.
	BSF         PORTC+0, 5 
;MyProject.c,146 :: 		delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 1
	BRA         L_main5
	DECFSZ      R12, 1, 1
	BRA         L_main5
	NOP
;MyProject.c,147 :: 		}
L_main4:
;MyProject.c,149 :: 		if(cooler == 'l'){
	MOVF        main_cooler_L0+0, 0 
	XORLW       108
	BTFSS       STATUS+0, 2 
	GOTO        L_main6
;MyProject.c,150 :: 		Lcd_Out(2, 11, "LIGA");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       11
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,151 :: 		}
	GOTO        L_main7
L_main6:
;MyProject.c,153 :: 		else if(cooler == 'd'){
	MOVF        main_cooler_L0+0, 0 
	XORLW       100
	BTFSS       STATUS+0, 2 
	GOTO        L_main8
;MyProject.c,154 :: 		Lcd_Out(2, 11, "DESL");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       11
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr3_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr3_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,155 :: 		}
L_main8:
L_main7:
;MyProject.c,158 :: 		if(PORTB.RB4==0){   // Decrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 4 
	GOTO        L_main9
;MyProject.c,159 :: 		Lcd_Out(2, 11, "DESL");  // Escreve mensagem no LCD.
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       11
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr4_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr4_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,160 :: 		PORTC.RC5 = 0;  // Liga resistencia de aquecimento.
	BCF         PORTC+0, 5 
;MyProject.c,161 :: 		delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main10:
	DECFSZ      R13, 1, 1
	BRA         L_main10
	DECFSZ      R12, 1, 1
	BRA         L_main10
	NOP
;MyProject.c,162 :: 		cooler = 'd';
	MOVLW       100
	MOVWF       main_cooler_L0+0 
;MyProject.c,163 :: 		}
L_main9:
;MyProject.c,165 :: 		iLeituraAD = ADC_Read(2);          // Lê Canal AD 2
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _iLeituraAD+0 
	MOVF        R1, 0 
	MOVWF       _iLeituraAD+1 
;MyProject.c,166 :: 		iLeituraAD/=2;                    // Converte valor do sensor LM35
	MOVF        R0, 0 
	MOVWF       _iLeituraAD+0 
	MOVF        R1, 0 
	MOVWF       _iLeituraAD+1 
	RRCF        _iLeituraAD+1, 1 
	RRCF        _iLeituraAD+0, 1 
	BCF         _iLeituraAD+1, 7 
;MyProject.c,167 :: 		Display_LCD();  // Escreve no display lcd o valor
	CALL        _Display_LCD+0, 0
;MyProject.c,168 :: 		Leitura_RTC();  // Efetua leitura de segundo, minuto e horas do DS1307
	CALL        _Leitura_RTC+0, 0
;MyProject.c,169 :: 		WordToStr(iLeituraAD, ucTexto);   // Converte o valor lido no A/D em string
	MOVF        _iLeituraAD+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        _iLeituraAD+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _ucTexto+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_ucTexto+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,170 :: 		Lcd_Out(1,8,ucTexto);             // Imprime no LCD o valor do Duty Cycle.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       8
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _ucTexto+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_ucTexto+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,171 :: 		Lcd_Chr_CP(0);                    // Imprime simbolo de graus.
	CLRF        FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;MyProject.c,172 :: 		Lcd_Chr_CP('C');                  // Unidade.
	MOVLW       67
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;MyProject.c,174 :: 		uiValorLido = iLeituraAD;
	MOVF        _iLeituraAD+0, 0 
	MOVWF       _uiValorLido+0 
	MOVF        _iLeituraAD+1, 0 
	MOVWF       _uiValorLido+1 
;MyProject.c,176 :: 		if(uiValor != iLeituraAD){
	MOVF        main_uiValor_L0+1, 0 
	XORWF       _iLeituraAD+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main27
	MOVF        _iLeituraAD+0, 0 
	XORWF       main_uiValor_L0+0, 0 
L__main27:
	BTFSC       STATUS+0, 2 
	GOTO        L_main11
;MyProject.c,177 :: 		uiValor = iLeituraAD;
	MOVF        _iLeituraAD+0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        _iLeituraAD+1, 0 
	MOVWF       main_uiValor_L0+1 
;MyProject.c,178 :: 		}
L_main11:
;MyProject.c,180 :: 		uiValorADC = ADC_Read(0);     // Lê Canal AD 0
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _uiValorADC+0 
	MOVF        R1, 0 
	MOVWF       _uiValorADC+1 
;MyProject.c,181 :: 		uiValorADC=(uiValorADC*0.24);
	CALL        _word2double+0, 0
	MOVLW       143
	MOVWF       R4 
	MOVLW       194
	MOVWF       R5 
	MOVLW       117
	MOVWF       R6 
	MOVLW       124
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       _uiValorADC+0 
	MOVF        R1, 0 
	MOVWF       _uiValorADC+1 
;MyProject.c,182 :: 		PWM1_Set_Duty(uiValorADC);        // Envia o valor lido de "iLeituraAD" para o módulo CCP1 PWM
	MOVF        R0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;MyProject.c,183 :: 		uiValorADC=(uiValorADC*0.41);     // Converte valor para o duty cycle em %
	MOVF        _uiValorADC+0, 0 
	MOVWF       R0 
	MOVF        _uiValorADC+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVLW       133
	MOVWF       R4 
	MOVLW       235
	MOVWF       R5 
	MOVLW       81
	MOVWF       R6 
	MOVLW       125
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       _uiValorADC+0 
	MOVF        R1, 0 
	MOVWF       _uiValorADC+1 
;MyProject.c,185 :: 		if(uiValorADC > 99){
	MOVLW       0
	MOVWF       R2 
	MOVF        R1, 0 
	SUBWF       R2, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main28
	MOVF        R0, 0 
	SUBLW       99
L__main28:
	BTFSC       STATUS+0, 0 
	GOTO        L_main12
;MyProject.c,186 :: 		uiValorADC = 99;
	MOVLW       99
	MOVWF       _uiValorADC+0 
	MOVLW       0
	MOVWF       _uiValorADC+1 
;MyProject.c,187 :: 		}
L_main12:
;MyProject.c,189 :: 		PORTD = ucMask[uiValorADC%10];              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _uiValorADC+0, 0 
	MOVWF       R0 
	MOVF        _uiValorADC+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;MyProject.c,190 :: 		PORTA.RA5 = 1;                           // Liga o transistor associado ao display 1.
	BSF         PORTA+0, 5 
;MyProject.c,191 :: 		Delay_ms(2);                             // Delay para escrita no display.
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main13:
	DECFSZ      R13, 1, 1
	BRA         L_main13
	DECFSZ      R12, 1, 1
	BRA         L_main13
	NOP
;MyProject.c,192 :: 		PORTA.RA5 = 0;                           // Desliga o transistor associado ao display 1.
	BCF         PORTA+0, 5 
;MyProject.c,193 :: 		uiValorADC/=10;                          // Divide variavel por 10.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _uiValorADC+0, 0 
	MOVWF       R0 
	MOVF        _uiValorADC+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R0, 0 
	MOVWF       _uiValorADC+0 
	MOVF        R1, 0 
	MOVWF       _uiValorADC+1 
;MyProject.c,196 :: 		PORTD = ucMask[uiValorADC%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;MyProject.c,197 :: 		PORTA.RA4 = 1;
	BSF         PORTA+0, 4 
;MyProject.c,198 :: 		Delay_ms(2);
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main14:
	DECFSZ      R13, 1, 1
	BRA         L_main14
	DECFSZ      R12, 1, 1
	BRA         L_main14
	NOP
;MyProject.c,199 :: 		PORTA.RA4 = 0;
	BCF         PORTA+0, 4 
;MyProject.c,200 :: 		uiValorADC/=10;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _uiValorADC+0, 0 
	MOVWF       R0 
	MOVF        _uiValorADC+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R0, 0 
	MOVWF       _uiValorADC+0 
	MOVF        R1, 0 
	MOVWF       _uiValorADC+1 
;MyProject.c,202 :: 		if(uiValorLido > 40){
	MOVLW       0
	MOVWF       R0 
	MOVF        _uiValorLido+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main29
	MOVF        _uiValorLido+0, 0 
	SUBLW       40
L__main29:
	BTFSC       STATUS+0, 0 
	GOTO        L_main15
;MyProject.c,203 :: 		PWM1_Init(5000);      // Inicializa módulo PWM com 5Khz
	BSF         T2CON+0, 0, 0
	BCF         T2CON+0, 1, 0
	MOVLW       99
	MOVWF       PR2+0, 0
	CALL        _PWM1_Init+0, 0
;MyProject.c,204 :: 		PWM1_Start();         // Start PWM
	CALL        _PWM1_Start+0, 0
;MyProject.c,205 :: 		iLeituraAD= ADC_Read(0);          // Lê Canal AD 0
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _iLeituraAD+0 
	MOVF        R1, 0 
	MOVWF       _iLeituraAD+1 
;MyProject.c,206 :: 		iLeituraAD=(iLeituraAD*0.24);     // Converte valor para o duty cycle [255/(1023 pontos do A/D)]
	CALL        _word2double+0, 0
	MOVLW       143
	MOVWF       R4 
	MOVLW       194
	MOVWF       R5 
	MOVLW       117
	MOVWF       R6 
	MOVLW       124
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       _iLeituraAD+0 
	MOVF        R1, 0 
	MOVWF       _iLeituraAD+1 
;MyProject.c,207 :: 		PWM1_Set_Duty(iLeituraAD);   // Envia o valor lido de "uiValorAD" para o módulo CCP1 pwm
	MOVF        R0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;MyProject.c,209 :: 		PORTC.RC1 = 0;
	BCF         PORTC+0, 1 
;MyProject.c,210 :: 		}
	GOTO        L_main16
L_main15:
;MyProject.c,212 :: 		PORTC.RC1 = 1;
	BSF         PORTC+0, 1 
;MyProject.c,213 :: 		PWM1_STOP();
	CALL        _PWM1_Stop+0, 0
;MyProject.c,214 :: 		}
L_main16:
;MyProject.c,216 :: 		if(uiValorLido != valorLidoAnt){
	MOVF        _uiValorLido+1, 0 
	XORWF       main_valorLidoAnt_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main30
	MOVF        main_valorLidoAnt_L0+0, 0 
	XORWF       _uiValorLido+0, 0 
L__main30:
	BTFSC       STATUS+0, 2 
	GOTO        L_main17
;MyProject.c,217 :: 		valorLidoAnt = uiValorLido;
	MOVF        _uiValorLido+0, 0 
	MOVWF       main_valorLidoAnt_L0+0 
	MOVF        _uiValorLido+1, 0 
	MOVWF       main_valorLidoAnt_L0+1 
;MyProject.c,218 :: 		GravaEEPROM(ucContador);
	MOVF        main_ucContador_L0+0, 0 
	MOVWF       FARG_GravaEEPROM_ucContador+0 
	MOVF        main_ucContador_L0+1, 0 
	MOVWF       FARG_GravaEEPROM_ucContador+1 
	CALL        _GravaEEPROM+0, 0
;MyProject.c,219 :: 		ucContador += 3;
	MOVLW       3
	ADDWF       main_ucContador_L0+0, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      main_ucContador_L0+1, 0 
	MOVWF       R2 
	MOVF        R1, 0 
	MOVWF       main_ucContador_L0+0 
	MOVF        R2, 0 
	MOVWF       main_ucContador_L0+1 
;MyProject.c,220 :: 		if(ucContador > 16){
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       R2, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main31
	MOVF        R1, 0 
	SUBLW       16
L__main31:
	BTFSC       STATUS+0, 0 
	GOTO        L_main18
;MyProject.c,221 :: 		ucContador = 0;
	CLRF        main_ucContador_L0+0 
	CLRF        main_ucContador_L0+1 
;MyProject.c,222 :: 		}
L_main18:
;MyProject.c,223 :: 		}
L_main17:
;MyProject.c,224 :: 		}
	GOTO        L_main0
;MyProject.c,225 :: 		}
L_end_main:
	GOTO        $+0
; end of _main

_GRAUS:

;MyProject.c,226 :: 		void GRAUS() {
;MyProject.c,229 :: 		Lcd_Cmd(64);
	MOVLW       64
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,230 :: 		for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
	CLRF        GRAUS_i_L0+0 
L_GRAUS19:
	MOVF        GRAUS_i_L0+0, 0 
	SUBLW       7
	BTFSS       STATUS+0, 0 
	GOTO        L_GRAUS20
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
	GOTO        L_GRAUS19
L_GRAUS20:
;MyProject.c,231 :: 		}
L_end_GRAUS:
	RETURN      0
; end of _GRAUS

_GravaEEPROM:

;MyProject.c,233 :: 		void GravaEEPROM(int ucContador){
;MyProject.c,236 :: 		EEPROM_Write(ucContador,0x30+uiValorLido/10);   // Grava na EEPROM valores de 0 a 10 em ASCII.
	MOVF        FARG_GravaEEPROM_ucContador+0, 0 
	MOVWF       FARG_EEPROM_Write_address+0 
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _uiValorLido+0, 0 
	MOVWF       R0 
	MOVF        _uiValorLido+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R0, 0 
	ADDLW       48
	MOVWF       FARG_EEPROM_Write_data_+0 
	CALL        _EEPROM_Write+0, 0
;MyProject.c,237 :: 		uiaux = uiValorLido%10;  //Divide por 10
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _uiValorLido+0, 0 
	MOVWF       R0 
	MOVF        _uiValorLido+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
;MyProject.c,239 :: 		EEPROM_Write(ucContador+1,0x30+uiaux);   // Grava na EEPROM valores de 0 a 10 em ASCII.
	MOVF        FARG_GravaEEPROM_ucContador+0, 0 
	ADDLW       1
	MOVWF       FARG_EEPROM_Write_address+0 
	MOVF        R0, 0 
	ADDLW       48
	MOVWF       FARG_EEPROM_Write_data_+0 
	CALL        _EEPROM_Write+0, 0
;MyProject.c,240 :: 		}
L_end_GravaEEPROM:
	RETURN      0
; end of _GravaEEPROM

_LeEEPROM:

;MyProject.c,242 :: 		void LeEEPROM(){
;MyProject.c,244 :: 		Lcd_Out(1,1,"Lido da EEPROM ");      // Mostra o estado no LCD.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr5_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr5_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,245 :: 		for(ucContador=0;ucContador<15;ucContador++){
	CLRF        LeEEPROM_ucContador_L0+0 
	CLRF        LeEEPROM_ucContador_L0+1 
L_LeEEPROM22:
	MOVLW       128
	XORWF       LeEEPROM_ucContador_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__LeEEPROM35
	MOVLW       15
	SUBWF       LeEEPROM_ucContador_L0+0, 0 
L__LeEEPROM35:
	BTFSC       STATUS+0, 0 
	GOTO        L_LeEEPROM23
;MyProject.c,246 :: 		Lcd_Chr(2,ucContador+1,EEPROM_Read(ucContador));      // Le na EEPROM valores .
	MOVF        LeEEPROM_ucContador_L0+0, 0 
	MOVWF       FARG_EEPROM_Read_address+0 
	CALL        _EEPROM_Read+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_Lcd_Chr_out_char+0 
	MOVLW       2
	MOVWF       FARG_Lcd_Chr_row+0 
	MOVF        LeEEPROM_ucContador_L0+0, 0 
	ADDLW       1
	MOVWF       FARG_Lcd_Chr_column+0 
	CALL        _Lcd_Chr+0, 0
;MyProject.c,247 :: 		Delay_ms(100);
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       4
	MOVWF       R12, 0
	MOVLW       186
	MOVWF       R13, 0
L_LeEEPROM25:
	DECFSZ      R13, 1, 1
	BRA         L_LeEEPROM25
	DECFSZ      R12, 1, 1
	BRA         L_LeEEPROM25
	DECFSZ      R11, 1, 1
	BRA         L_LeEEPROM25
	NOP
;MyProject.c,245 :: 		for(ucContador=0;ucContador<15;ucContador++){
	INFSNZ      LeEEPROM_ucContador_L0+0, 1 
	INCF        LeEEPROM_ucContador_L0+1, 1 
;MyProject.c,248 :: 		}
	GOTO        L_LeEEPROM22
L_LeEEPROM23:
;MyProject.c,249 :: 		}
L_end_LeEEPROM:
	RETURN      0
; end of _LeEEPROM

_Converte_BCD:

;MyProject.c,252 :: 		void Converte_BCD(unsigned char ucLinha, unsigned char ucColuna,unsigned char ucValor) {
;MyProject.c,255 :: 		ucValor1 = (ucValor >> 4  ) + '0';    // Converte o primeiro nibble em BCD e após em string
	MOVF        FARG_Converte_BCD_ucValor+0, 0 
	MOVWF       FARG_Lcd_Chr_out_char+0 
	RRCF        FARG_Lcd_Chr_out_char+0, 1 
	BCF         FARG_Lcd_Chr_out_char+0, 7 
	RRCF        FARG_Lcd_Chr_out_char+0, 1 
	BCF         FARG_Lcd_Chr_out_char+0, 7 
	RRCF        FARG_Lcd_Chr_out_char+0, 1 
	BCF         FARG_Lcd_Chr_out_char+0, 7 
	RRCF        FARG_Lcd_Chr_out_char+0, 1 
	BCF         FARG_Lcd_Chr_out_char+0, 7 
	MOVLW       48
	ADDWF       FARG_Lcd_Chr_out_char+0, 1 
;MyProject.c,256 :: 		Lcd_Chr(ucLinha,ucColuna,ucValor1);   // Escreve caractere no LCD
	MOVF        FARG_Converte_BCD_ucLinha+0, 0 
	MOVWF       FARG_Lcd_Chr_row+0 
	MOVF        FARG_Converte_BCD_ucColuna+0, 0 
	MOVWF       FARG_Lcd_Chr_column+0 
	CALL        _Lcd_Chr+0, 0
;MyProject.c,257 :: 		ucValor2 = (ucValor & 0x0F) + '0';    // Converte o segundo nibble em BCD e após isso, em string
	MOVLW       15
	ANDWF       FARG_Converte_BCD_ucValor+0, 0 
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	MOVLW       48
	ADDWF       FARG_Lcd_Chr_CP_out_char+0, 1 
;MyProject.c,258 :: 		Lcd_Chr_CP(ucValor2);                 // Escreve caractere no LCD
	CALL        _Lcd_Chr_CP+0, 0
;MyProject.c,259 :: 		}
L_end_Converte_BCD:
	RETURN      0
; end of _Converte_BCD

_Leitura_RTC:

;MyProject.c,261 :: 		void Leitura_RTC() {          // Rotina de leitura do DS1307
;MyProject.c,262 :: 		I2C1_Start();              // Inicializa comunicação i2c
	CALL        _I2C1_Start+0, 0
;MyProject.c,263 :: 		I2C1_Wr(0xD0);             // End. fixo para DS1307: 1101000X, onde x = 0 é para gravação
	MOVLW       208
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,264 :: 		I2C1_Wr(0);                // End. onde começa a programação do relógio, end dos segundos.
	CLRF        FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,265 :: 		I2C1_Repeated_Start();     // Issue I2C signal repeated start
	CALL        _I2C1_Repeated_Start+0, 0
;MyProject.c,266 :: 		I2C1_Wr(0xD1);             // End. fixo para DS1307: 1101000X, onde x=1 é para leitura
	MOVLW       209
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,267 :: 		ucSegundo = I2C1_Rd(1);    // Lê o primeiro byte(segundos),informa que continua lendo
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucSegundo+0 
;MyProject.c,268 :: 		ucMinuto = I2C1_Rd(1);     // Lê o segundo byte(minutos)
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucMinuto+0 
;MyProject.c,269 :: 		ucHora = I2C1_Rd(1);       // Lê o terceiro byte(horas)
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucHora+0 
;MyProject.c,270 :: 		ucDia_Semana = I2C1_Rd(1);
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucDia_Semana+0 
;MyProject.c,271 :: 		ucDia = I2C1_Rd(1);
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucDia+0 
;MyProject.c,272 :: 		ucMes = I2C1_Rd(1);
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucMes+0 
;MyProject.c,273 :: 		ucAno = I2C1_Rd(0);        // Lê o sétimo byte(ano),encerra as leituras de dados
	CLRF        FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucAno+0 
;MyProject.c,274 :: 		I2C1_Stop();               // Finaliza comunicação I2C
	CALL        _I2C1_Stop+0, 0
;MyProject.c,275 :: 		}
L_end_Leitura_RTC:
	RETURN      0
; end of _Leitura_RTC

_Grava_RTC:

;MyProject.c,277 :: 		void Grava_RTC(){
;MyProject.c,278 :: 		I2C1_Init(100000);     // Iniciliza I2C com frequencia de 100KHz
	MOVLW       20
	MOVWF       SSPADD+0 
	CALL        _I2C1_Init+0, 0
;MyProject.c,279 :: 		I2C1_Start();          // Inicializa a comunicação I2c
	CALL        _I2C1_Start+0, 0
;MyProject.c,280 :: 		I2C1_Wr(0xD0);         // End. fixo para DS1307: 1101000X, onde x = 0 é para gravação
	MOVLW       208
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,281 :: 		I2C1_Wr(0);            // End. onde começa a programação do relógio, end. dos segundos.
	CLRF        FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,282 :: 		I2C1_Wr(0x00);         // Inicializa com 00 segundos.
	CLRF        FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,283 :: 		I2C1_Wr(0x00);         // Inicializa com 00 minutos.
	CLRF        FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,284 :: 		I2C1_Wr(0x21);         // Inicializa com 21:00hs (formato 24 horas).
	MOVLW       33
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,285 :: 		I2C1_Wr(0x04);         // Inicializa com dia 04
	MOVLW       4
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,286 :: 		I2C1_Wr(0x07);         // Inicializa com mês 07
	MOVLW       7
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,287 :: 		I2C1_Wr(0x17);         // Inicializa com ano 17
	MOVLW       23
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;MyProject.c,288 :: 		I2C1_Stop();           // Finaliza comunicação I2C
	CALL        _I2C1_Stop+0, 0
;MyProject.c,289 :: 		}
L_end_Grava_RTC:
	RETURN      0
; end of _Grava_RTC

_Display_LCD:

;MyProject.c,291 :: 		void Display_LCD() {
;MyProject.c,293 :: 		Converte_BCD(1,1,ucHora);     // Conversão da variável horas para BCD
	MOVLW       1
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       1
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucHora+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;MyProject.c,294 :: 		Lcd_Chr_CP(':');              // Escreve no display LCD
	MOVLW       58
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;MyProject.c,295 :: 		Converte_BCD(1,4,ucMinuto);  // Conversão da variável minuto para BCD
	MOVLW       1
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       4
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucMinuto+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;MyProject.c,296 :: 		Lcd_Chr_CP(':');              // Escreve no display LCD
	MOVLW       58
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;MyProject.c,297 :: 		Converte_BCD(1,7,ucSegundo); // Conversão da variável segundo para BCD
	MOVLW       1
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       7
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucSegundo+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;MyProject.c,299 :: 		Converte_BCD(2,1,ucDia);      // Conversão da variável dia para BCD
	MOVLW       2
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       1
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucDia+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;MyProject.c,300 :: 		Lcd_Chr_CP('/');              // Escreve no display LCD
	MOVLW       47
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;MyProject.c,301 :: 		Converte_BCD(2,4,ucMes);     // Conversão da variável mes para BCD
	MOVLW       2
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       4
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucMes+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;MyProject.c,302 :: 		Lcd_Chr_CP('/');              // Escreve no display LCD
	MOVLW       47
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;MyProject.c,303 :: 		Converte_BCD(2,7,ucAno);     // Conversão da variável ano para BCD
	MOVLW       2
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       7
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucAno+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;MyProject.c,304 :: 		}
L_end_Display_LCD:
	RETURN      0
; end of _Display_LCD
