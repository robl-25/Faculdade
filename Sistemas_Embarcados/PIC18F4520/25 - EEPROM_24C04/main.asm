
_main:
;main.c,63 :: 		void main(){
;main.c,64 :: 		TRISB = 0;                        // Define PORTB como saida.
	CLRF        TRISB+0 
;main.c,65 :: 		TRISD = 0;                        // Define PORTD como saida.
	CLRF        TRISD+0 
;main.c,66 :: 		TRISE = 0;                        // Define PORTE como saida.
	CLRF        TRISE+0 
;main.c,68 :: 		ADCON1 = 0x0F;                    // Configura todos canais como Digital.
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,71 :: 		Lcd_Init();                               // Inicializa LCD.
	CALL        _Lcd_Init+0, 0
;main.c,73 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,74 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,77 :: 		Lcd_Out(1,1,"Escr. na 24C04");      // Mostra o estado no LCD.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_main+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_main+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,78 :: 		for(ucContador=0;ucContador<16;ucContador++){
	CLRF        _ucContador+0 
L_main0:
	MOVLW       16
	SUBWF       _ucContador+0, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_main1
;main.c,79 :: 		Escrita_24C04(ucContador,0x30+ucContador);   // Grava na EEPROM valores de 0 a 10 em ASCII.
	MOVF        _ucContador+0, 0 
	MOVWF       FARG_Escrita_24C04_ucEndereco+0 
	MOVF        _ucContador+0, 0 
	ADDLW       48
	MOVWF       FARG_Escrita_24C04_ucValor+0 
	CALL        _Escrita_24C04+0, 0
;main.c,80 :: 		Delay_ms(100);
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
;main.c,78 :: 		for(ucContador=0;ucContador<16;ucContador++){
	INCF        _ucContador+0, 1 
;main.c,81 :: 		}
	GOTO        L_main0
L_main1:
;main.c,83 :: 		Lcd_Out(1,1,"Lido da 24C04 ");      // Mostra o estado no LCD.
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_main+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_main+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,84 :: 		for(ucContador=0;ucContador<16;ucContador++){
	CLRF        _ucContador+0 
L_main4:
	MOVLW       16
	SUBWF       _ucContador+0, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_main5
;main.c,85 :: 		Lcd_Chr(2,ucContador+1,Leitura_24C04(ucContador));      // Le na EEPROM valores .
	MOVF        _ucContador+0, 0 
	MOVWF       FARG_Leitura_24C04_ucEndereco+0 
	CALL        _Leitura_24C04+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_Lcd_Chr_out_char+0 
	MOVLW       2
	MOVWF       FARG_Lcd_Chr_row+0 
	MOVF        _ucContador+0, 0 
	ADDLW       1
	MOVWF       FARG_Lcd_Chr_column+0 
	CALL        _Lcd_Chr+0, 0
;main.c,86 :: 		Delay_ms(100);
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
;main.c,84 :: 		for(ucContador=0;ucContador<16;ucContador++){
	INCF        _ucContador+0, 1 
;main.c,87 :: 		}
	GOTO        L_main4
L_main5:
;main.c,89 :: 		while(1){};
L_main8:
	GOTO        L_main8
;main.c,90 :: 		}
	GOTO        $+0
; end of _main

_Escrita_24C04:
;main.c,93 :: 		void Escrita_24C04(unsigned char ucEndereco,unsigned char ucValor)
;main.c,95 :: 		I2C1_Init(100000);             // Freqüência de clock
	MOVLW       20
	MOVWF       SSPADD+0 
	CALL        _I2C1_Init+0, 0
;main.c,96 :: 		I2C1_Start();                  // Start no barramento i2c
	CALL        _I2C1_Start+0, 0
;main.c,97 :: 		I2C1_Wr(0xA0);                 // Endereço da memória no hardware do kit (w = 0)
	MOVLW       160
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,98 :: 		I2C1_Wr(ucEndereco);           // Endereço da eeprom onde será salvo o dado
	MOVF        FARG_Escrita_24C04_ucEndereco+0, 0 
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,99 :: 		I2C1_Wr(ucValor);              // Escreve valor da variável 'ucValor' na 24c04
	MOVF        FARG_Escrita_24C04_ucValor+0, 0 
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,100 :: 		I2C1_Stop();                   // Finaliza a comunicação I2C
	CALL        _I2C1_Stop+0, 0
;main.c,102 :: 		}
	RETURN      0
; end of _Escrita_24C04

_Leitura_24C04:
;main.c,104 :: 		unsigned char Leitura_24C04(unsigned char ucEndereco)
;main.c,108 :: 		I2C1_Start();                 // start no barramento i2c
	CALL        _I2C1_Start+0, 0
;main.c,109 :: 		I2C1_Wr(0xA0);                // endereço da memória no hardware do kit (w = 0)
	MOVLW       160
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,110 :: 		I2C1_Wr(ucEndereco);          // endereço da eeprom onde será lido o byte
	MOVF        FARG_Leitura_24C04_ucEndereco+0, 0 
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,111 :: 		I2C1_Repeated_Start();        // re-start no barramento
	CALL        _I2C1_Repeated_Start+0, 0
;main.c,112 :: 		I2C1_Wr(0xA1);                // endereço da memória no hardware do kit (w = 1)
	MOVLW       161
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,113 :: 		ucLeitura = I2C1_Rd(0u);      // Lê o byte
	CLRF        FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       Leitura_24C04_ucLeitura_L0+0 
;main.c,114 :: 		I2C1_Stop();                  // finaliza a comunicação I2C
	CALL        _I2C1_Stop+0, 0
;main.c,115 :: 		return(ucLeitura);            // Retorna Valor da leitura.
	MOVF        Leitura_24C04_ucLeitura_L0+0, 0 
	MOVWF       R0 
;main.c,116 :: 		}
	RETURN      0
; end of _Leitura_24C04
