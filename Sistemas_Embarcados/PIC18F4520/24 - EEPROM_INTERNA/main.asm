
_main:
;main.c,59 :: 		void main(){
;main.c,60 :: 		TRISB = 0;                        // Define PORTB como saida.
	CLRF        TRISB+0 
;main.c,61 :: 		TRISD = 0;                        // Define PORTD como saida.
	CLRF        TRISD+0 
;main.c,62 :: 		TRISE = 0;                        // Define PORTE como saida.
	CLRF        TRISE+0 
;main.c,64 :: 		ADCON1 = 0x0F;                    // Configura todos canais como Digital.
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,67 :: 		Lcd_Init();                               // Inicializa LCD.
	CALL        _Lcd_Init+0, 0
;main.c,69 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,70 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,73 :: 		Lcd_Out(1,1,"Escr. na EEPROM");      // Mostra o estado no LCD.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_main+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_main+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,74 :: 		for(ucContador=0;ucContador<16;ucContador++){
	CLRF        _ucContador+0 
L_main0:
	MOVLW       16
	SUBWF       _ucContador+0, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_main1
;main.c,75 :: 		EEPROM_Write(ucContador,0x30+ucContador);   // Grava na EEPROM valores de 0 a 10 em ASCII.
	MOVF        _ucContador+0, 0 
	MOVWF       FARG_EEPROM_Write_address+0 
	MOVF        _ucContador+0, 0 
	ADDLW       48
	MOVWF       FARG_EEPROM_Write_data_+0 
	CALL        _EEPROM_Write+0, 0
;main.c,76 :: 		Delay_ms(100);
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       4
	MOVWF       R12, 0
	MOVLW       186
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 0
	BRA         L_main3
	DECFSZ      R12, 1, 0
	BRA         L_main3
	DECFSZ      R11, 1, 0
	BRA         L_main3
	NOP
;main.c,74 :: 		for(ucContador=0;ucContador<16;ucContador++){
	INCF        _ucContador+0, 1 
;main.c,77 :: 		}
	GOTO        L_main0
L_main1:
;main.c,79 :: 		Lcd_Out(1,1,"Lido da EEPROM ");      // Mostra o estado no LCD.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_main+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_main+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,80 :: 		for(ucContador=0;ucContador<16;ucContador++){
	CLRF        _ucContador+0 
L_main4:
	MOVLW       16
	SUBWF       _ucContador+0, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_main5
;main.c,81 :: 		Lcd_Chr(2,ucContador+1,EEPROM_Read(ucContador));      // Le na EEPROM valores .
	MOVF        _ucContador+0, 0 
	MOVWF       FARG_EEPROM_Read_address+0 
	CALL        _EEPROM_Read+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_Lcd_Chr_out_char+0 
	MOVLW       2
	MOVWF       FARG_Lcd_Chr_row+0 
	MOVF        _ucContador+0, 0 
	ADDLW       1
	MOVWF       FARG_Lcd_Chr_column+0 
	CALL        _Lcd_Chr+0, 0
;main.c,82 :: 		Delay_ms(100);
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       4
	MOVWF       R12, 0
	MOVLW       186
	MOVWF       R13, 0
L_main7:
	DECFSZ      R13, 1, 0
	BRA         L_main7
	DECFSZ      R12, 1, 0
	BRA         L_main7
	DECFSZ      R11, 1, 0
	BRA         L_main7
	NOP
;main.c,80 :: 		for(ucContador=0;ucContador<16;ucContador++){
	INCF        _ucContador+0, 1 
;main.c,83 :: 		}
	GOTO        L_main4
L_main5:
;main.c,85 :: 		while(1){};
L_main8:
	GOTO        L_main8
;main.c,86 :: 		}
	GOTO        $+0
; end of _main
