
_interrupt:

;VisualGLCD_picgenios_main.c,78 :: 		void interrupt() {
;VisualGLCD_picgenios_main.c,80 :: 		if( RCIF_bit == 1) {
	BTFSS       RCIF_bit+0, 5 
	GOTO        L_interrupt0
;VisualGLCD_picgenios_main.c,81 :: 		ucRecepcao = UART1_Read(); //protocolo
	CALL        _UART1_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _ucRecepcao+0 
;VisualGLCD_picgenios_main.c,82 :: 		UART1_Write(ucRecepcao);
	MOVF        R0, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;VisualGLCD_picgenios_main.c,83 :: 		RCIF_bit = 0;  //opcional para recepção serial
	BCF         RCIF_bit+0, 5 
;VisualGLCD_picgenios_main.c,84 :: 		}
L_interrupt0:
;VisualGLCD_picgenios_main.c,85 :: 		}
L__interrupt11:
	RETFIE      1
; end of _interrupt

_main:

;VisualGLCD_picgenios_main.c,89 :: 		void main() {
;VisualGLCD_picgenios_main.c,92 :: 		ADCON1 = 0B00001111; //TODOS OS PINOS COMO IO DIGITAL
	MOVLW       15
	MOVWF       ADCON1+0 
;VisualGLCD_picgenios_main.c,93 :: 		TRISD = 0;
	CLRF        TRISD+0 
;VisualGLCD_picgenios_main.c,94 :: 		PORTD = 0;
	CLRF        PORTD+0 
;VisualGLCD_picgenios_main.c,95 :: 		TRISB = 0;
	CLRF        TRISB+0 
;VisualGLCD_picgenios_main.c,96 :: 		PORTB = 0;
	CLRF        PORTB+0 
;VisualGLCD_picgenios_main.c,98 :: 		Start_TP();
	CALL        _Start_TP+0, 0
;VisualGLCD_picgenios_main.c,100 :: 		INTCON.GIEH = 1; //habilitar a chave geral das interrupções
	BSF         INTCON+0, 7 
;VisualGLCD_picgenios_main.c,101 :: 		INTCON.GIEL = 1; //habilitar o vetor de baixa prioridade de interrupção
	BSF         INTCON+0, 6 
;VisualGLCD_picgenios_main.c,102 :: 		RCON.IPEN = 1;  // define 2 level de interrupção PIC18F
	BSF         RCON+0, 7 
;VisualGLCD_picgenios_main.c,104 :: 		RCIF_bit = 0; //flag de sinalização na recepção serial
	BCF         RCIF_bit+0, 5 
;VisualGLCD_picgenios_main.c,105 :: 		RCIP_bit = 1; //alta prioridade de interrupçãos serial
	BSF         RCIP_bit+0, 5 
;VisualGLCD_picgenios_main.c,106 :: 		RCIE_bit = 1; //chave de ligação da interrupção na recepção serial
	BSF         RCIE_bit+0, 5 
;VisualGLCD_picgenios_main.c,107 :: 		UART1_Init(9600);
	MOVLW       51
	MOVWF       SPBRG+0 
	BSF         TXSTA+0, 2, 0
	CALL        _UART1_Init+0, 0
;VisualGLCD_picgenios_main.c,109 :: 		while (1) {
L_main1:
;VisualGLCD_picgenios_main.c,111 :: 		switch(ucRecepcao)
	GOTO        L_main3
;VisualGLCD_picgenios_main.c,113 :: 		case 'A' : {
L_main5:
;VisualGLCD_picgenios_main.c,114 :: 		DrawScreen(&Screen1);
	MOVLW       _Screen1+0
	MOVWF       FARG_DrawScreen_aScreen+0 
	MOVLW       hi_addr(_Screen1+0)
	MOVWF       FARG_DrawScreen_aScreen+1 
	CALL        _DrawScreen+0, 0
;VisualGLCD_picgenios_main.c,115 :: 		ucRecepcao = 0;
	CLRF        _ucRecepcao+0 
;VisualGLCD_picgenios_main.c,116 :: 		do{
L_main6:
;VisualGLCD_picgenios_main.c,117 :: 		Leitura_AN0 = ADC_Read(0);          //0 a 1023
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
;VisualGLCD_picgenios_main.c,118 :: 		Leitura_AN0 = Leitura_AN0 * (128/1023.);
	CALL        _Word2Double+0, 0
	MOVLW       8
	MOVWF       R4 
	MOVLW       32
	MOVWF       R5 
	MOVLW       0
	MOVWF       R6 
	MOVLW       124
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _Double2Word+0, 0
;VisualGLCD_picgenios_main.c,119 :: 		WordToStr(Leitura_AN0, Texto);      //00795
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_Texto_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_Texto_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;VisualGLCD_picgenios_main.c,121 :: 		Texto[5] = '%';
	MOVLW       37
	MOVWF       main_Texto_L0+5 
;VisualGLCD_picgenios_main.c,122 :: 		Texto[6] = 0; //null terminação da cadeia
	CLRF        main_Texto_L0+6 
;VisualGLCD_picgenios_main.c,124 :: 		T6963C_write_text(Texto, 0, 7, T6963C_ROM_MODE_XOR );     //4*(FOSC/4) -> Ciclo maquina = FOSC 0,125us
	MOVLW       main_Texto_L0+0
	MOVWF       FARG_T6963C_write_text_str+0 
	MOVLW       hi_addr(main_Texto_L0+0)
	MOVWF       FARG_T6963C_write_text_str+1 
	CLRF        FARG_T6963C_write_text_x+0 
	MOVLW       7
	MOVWF       FARG_T6963C_write_text_y+0 
	MOVLW       129
	MOVWF       FARG_T6963C_write_text_mode+0 
	CALL        _T6963C_write_text+0, 0
;VisualGLCD_picgenios_main.c,125 :: 		}while(ucRecepcao == 0);
	MOVF        _ucRecepcao+0, 0 
	XORLW       0
	BTFSC       STATUS+0, 2 
	GOTO        L_main6
;VisualGLCD_picgenios_main.c,126 :: 		break;
	GOTO        L_main4
;VisualGLCD_picgenios_main.c,128 :: 		case 'B' : { DrawScreen(&Screen2); ucRecepcao = 0; break; }
L_main9:
	MOVLW       _Screen2+0
	MOVWF       FARG_DrawScreen_aScreen+0 
	MOVLW       hi_addr(_Screen2+0)
	MOVWF       FARG_DrawScreen_aScreen+1 
	CALL        _DrawScreen+0, 0
	CLRF        _ucRecepcao+0 
	GOTO        L_main4
;VisualGLCD_picgenios_main.c,130 :: 		case 'C' : {
L_main10:
;VisualGLCD_picgenios_main.c,131 :: 		T6963C_image(handsOn_PaintEstrela);
	MOVLW       _handsOn_PaintEstrela+0
	MOVWF       FARG_T6963C_image_pic+0 
	MOVLW       hi_addr(_handsOn_PaintEstrela+0)
	MOVWF       FARG_T6963C_image_pic+1 
	MOVLW       higher_addr(_handsOn_PaintEstrela+0)
	MOVWF       FARG_T6963C_image_pic+2 
	CALL        _T6963C_image+0, 0
;VisualGLCD_picgenios_main.c,132 :: 		ucRecepcao = 0;
	CLRF        _ucRecepcao+0 
;VisualGLCD_picgenios_main.c,133 :: 		break;
	GOTO        L_main4
;VisualGLCD_picgenios_main.c,135 :: 		}
L_main3:
	MOVF        _ucRecepcao+0, 0 
	XORLW       65
	BTFSC       STATUS+0, 2 
	GOTO        L_main5
	MOVF        _ucRecepcao+0, 0 
	XORLW       66
	BTFSC       STATUS+0, 2 
	GOTO        L_main9
	MOVF        _ucRecepcao+0, 0 
	XORLW       67
	BTFSC       STATUS+0, 2 
	GOTO        L_main10
L_main4:
;VisualGLCD_picgenios_main.c,136 :: 		}
	GOTO        L_main1
;VisualGLCD_picgenios_main.c,138 :: 		}
	GOTO        $+0
; end of _main
