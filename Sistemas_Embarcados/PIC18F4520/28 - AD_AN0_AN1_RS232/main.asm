
_main:
;main.c,28 :: 		void main(){
;main.c,30 :: 		unsigned char ucHexa[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	MOVLW       ?ICSmain_ucHexa_L0+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(?ICSmain_ucHexa_L0+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(?ICSmain_ucHexa_L0+0)
	MOVWF       TBLPTRU 
	MOVLW       main_ucHexa_L0+0
	MOVWF       FSR1L 
	MOVLW       hi_addr(main_ucHexa_L0+0)
	MOVWF       FSR1H 
	MOVLW       16
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
;main.c,37 :: 		ADCON0 = 0b00000001;         // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
	MOVLW       1
	MOVWF       ADCON0+0 
;main.c,38 :: 		ADCON1 = 0b11001110;         // Configura todos canais como Digital menos AN0 e REF Interna.
	MOVLW       206
	MOVWF       ADCON1+0 
;main.c,39 :: 		ADCON2 = 0b10111110;         // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
	MOVLW       190
	MOVWF       ADCON2+0 
;main.c,41 :: 		TRISD = 0;                   // Define Todos Os Pinos Do PORTD Como Saida.
	CLRF        TRISD+0 
;main.c,42 :: 		PORTD = 0;
	CLRF        PORTD+0 
;main.c,44 :: 		UART1_Init(9600);            // Utiliza bibliotecas do compilador para configuração da RS232.
	MOVLW       51
	MOVWF       SPBRG+0 
	BSF         TXSTA+0, 2, 0
	CALL        _UART1_Init+0, 0
;main.c,46 :: 		while(1){ // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
L_main0:
;main.c,48 :: 		uiValorAD= ADC_Read(0);                    // Lê Canal AD 0.
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;main.c,52 :: 		ucBuffer[3] = ucHexa[uiValorAD%16];        // Pega Valor Hexadecimal Menos Significativo.
	MOVLW       16
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucHexa_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucHexa_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       main_ucBuffer_L0+3 
;main.c,53 :: 		uiValorAD/=16;
	MOVF        main_uiValorAD_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValorAD_L0+1, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;main.c,54 :: 		ucBuffer[2] = ucHexa[uiValorAD%16];
	MOVLW       16
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucHexa_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucHexa_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       main_ucBuffer_L0+2 
;main.c,55 :: 		uiValorAD/=16;
	MOVF        main_uiValorAD_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValorAD_L0+1, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;main.c,56 :: 		ucBuffer[1] = ucHexa[uiValorAD%16];
	MOVLW       16
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucHexa_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucHexa_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       main_ucBuffer_L0+1 
;main.c,57 :: 		uiValorAD/=16;
	MOVF        main_uiValorAD_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValorAD_L0+1, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;main.c,58 :: 		ucBuffer[0] = ucHexa[uiValorAD%16];        // Pega Valor Hexadecimal Mais Significativo.
	MOVLW       16
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucHexa_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucHexa_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       main_ucBuffer_L0+0 
;main.c,61 :: 		UART1_Write(0x02);                         // Inicio de Frame de dados.
	MOVLW       2
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,62 :: 		UART1_Write('A');                          // Dados informando qual canal será enviado.
	MOVLW       65
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,63 :: 		UART1_Write('N');
	MOVLW       78
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,64 :: 		UART1_Write('0');
	MOVLW       48
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,65 :: 		UART1_Write('=');
	MOVLW       61
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,66 :: 		UART1_Write(ucBuffer[0]);                  // Dados enviando hexadecimal do mais significativo para o menos significativo.
	MOVF        main_ucBuffer_L0+0, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,67 :: 		UART1_Write(ucBuffer[1]);
	MOVF        main_ucBuffer_L0+1, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,68 :: 		UART1_Write(ucBuffer[2]);
	MOVF        main_ucBuffer_L0+2, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,69 :: 		UART1_Write(ucBuffer[3]);
	MOVF        main_ucBuffer_L0+3, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,70 :: 		UART1_Write(0x04);                         // Fim de Frame de dados.
	MOVLW       4
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,72 :: 		uiValorAD= ADC_Read(1);                    // Lê Canal AD 1.
	MOVLW       1
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;main.c,76 :: 		ucBuffer[3] = ucHexa[uiValorAD%16];
	MOVLW       16
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucHexa_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucHexa_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       main_ucBuffer_L0+3 
;main.c,77 :: 		uiValorAD/=16;
	MOVF        main_uiValorAD_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValorAD_L0+1, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;main.c,78 :: 		ucBuffer[2] = ucHexa[uiValorAD%16];
	MOVLW       16
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucHexa_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucHexa_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       main_ucBuffer_L0+2 
;main.c,79 :: 		uiValorAD/=16;
	MOVF        main_uiValorAD_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValorAD_L0+1, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;main.c,80 :: 		ucBuffer[1] = ucHexa[uiValorAD%16];
	MOVLW       16
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucHexa_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucHexa_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       main_ucBuffer_L0+1 
;main.c,81 :: 		uiValorAD/=16;
	MOVF        main_uiValorAD_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValorAD_L0+1, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	MOVF        R0, 0 
	MOVWF       main_uiValorAD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValorAD_L0+1 
;main.c,82 :: 		ucBuffer[0] = ucHexa[uiValorAD%16];
	MOVLW       16
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucHexa_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucHexa_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       main_ucBuffer_L0+0 
;main.c,85 :: 		UART1_Write(0x02);                         // Inicio de Frame de dados
	MOVLW       2
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,86 :: 		UART1_Write('A');                          // Dados informando qual canal será enviado.
	MOVLW       65
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,87 :: 		UART1_Write('N');
	MOVLW       78
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,88 :: 		UART1_Write('1');
	MOVLW       49
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,89 :: 		UART1_Write('=');
	MOVLW       61
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,90 :: 		UART1_Write(ucBuffer[0]);                  // Dados enviando hexadecimal do mais significativo para o menos significativo.
	MOVF        main_ucBuffer_L0+0, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,91 :: 		UART1_Write(ucBuffer[1]);
	MOVF        main_ucBuffer_L0+1, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,92 :: 		UART1_Write(ucBuffer[2]);
	MOVF        main_ucBuffer_L0+2, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,93 :: 		UART1_Write(ucBuffer[3]);
	MOVF        main_ucBuffer_L0+3, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,94 :: 		UART1_Write(0x04);                         // Fim de Frame de dados
	MOVLW       4
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;main.c,95 :: 		Delay_ms(100);                             // Pausa de 100ms.
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
;main.c,96 :: 		}
	GOTO        L_main0
;main.c,97 :: 		}
	GOTO        $+0
; end of _main
