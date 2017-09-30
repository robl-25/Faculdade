
_main:
;main.c,75 :: 		void main(){
;main.c,76 :: 		TRISA = 0;                                // Define PORTA como saida
	CLRF        TRISA+0 
;main.c,77 :: 		TRISB = 0;                                // Define PORTB como saida
	CLRF        TRISB+0 
;main.c,78 :: 		TRISC = 0;                                // Define PORTC como saida
	CLRF        TRISC+0 
;main.c,79 :: 		TRISD = 0;                                // Define PORTD como saida
	CLRF        TRISD+0 
;main.c,80 :: 		TRISE = 0;                                // Define PORTE como saida
	CLRF        TRISE+0 
;main.c,82 :: 		ADCON1= 0x0F;                             // Torna todos os pinos A/D como I/O de uso geral
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,83 :: 		CMCON = 0X07;                             // Desliga os comparadores.
	MOVLW       7
	MOVWF       CMCON+0 
;main.c,86 :: 		Lcd_Init();                               // Inicializa LCD.
	CALL        _Lcd_Init+0, 0
;main.c,88 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,89 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,90 :: 		Grava_RTC();
	CALL        _Grava_RTC+0, 0
;main.c,92 :: 		while(1){
L_main0:
;main.c,93 :: 		Display_LCD();  // Escreve no display lcd o valor
	CALL        _Display_LCD+0, 0
;main.c,94 :: 		Leitura_RTC();  // Efetua leitura de segundo, minuto e horas do DS1307
	CALL        _Leitura_RTC+0, 0
;main.c,95 :: 		Delay_ms(200);  // Delay de 200 milisegundos
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 0
	BRA         L_main2
	DECFSZ      R12, 1, 0
	BRA         L_main2
	DECFSZ      R11, 1, 0
	BRA         L_main2
;main.c,96 :: 		}
	GOTO        L_main0
;main.c,97 :: 		}
	GOTO        $+0
; end of _main

_Converte_BCD:
;main.c,100 :: 		void Converte_BCD(unsigned char ucLinha, unsigned char ucColuna,unsigned char ucValor) {
;main.c,103 :: 		ucValor1 = (ucValor >> 4  ) + '0';    // Converte o primeiro nibble em BCD e após em string
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
;main.c,104 :: 		Lcd_Chr(ucLinha,ucColuna,ucValor1);   // Escreve caractere no LCD
	MOVF        FARG_Converte_BCD_ucLinha+0, 0 
	MOVWF       FARG_Lcd_Chr_row+0 
	MOVF        FARG_Converte_BCD_ucColuna+0, 0 
	MOVWF       FARG_Lcd_Chr_column+0 
	CALL        _Lcd_Chr+0, 0
;main.c,105 :: 		ucValor2 = (ucValor & 0x0F) + '0';    // Converte o segundo nibble em BCD e após isso, em string
	MOVLW       15
	ANDWF       FARG_Converte_BCD_ucValor+0, 0 
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	MOVLW       48
	ADDWF       FARG_Lcd_Chr_CP_out_char+0, 1 
;main.c,106 :: 		Lcd_Chr_CP(ucValor2);                 // Escreve caractere no LCD
	CALL        _Lcd_Chr_CP+0, 0
;main.c,107 :: 		}
	RETURN      0
; end of _Converte_BCD

_Leitura_RTC:
;main.c,109 :: 		void Leitura_RTC() {          // Rotina de leitura do DS1307
;main.c,110 :: 		I2C1_Start();              // Inicializa comunicação i2c
	CALL        _I2C1_Start+0, 0
;main.c,111 :: 		I2C1_Wr(0xD0);             // End. fixo para DS1307: 1101000X, onde x = 0 é para gravação
	MOVLW       208
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,112 :: 		I2C1_Wr(0);                // End. onde começa a programação do relógio, end dos segundos.
	CLRF        FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,113 :: 		I2C1_Repeated_Start();     // Issue I2C signal repeated start
	CALL        _I2C1_Repeated_Start+0, 0
;main.c,114 :: 		I2C1_Wr(0xD1);             // End. fixo para DS1307: 1101000X, onde x=1 é para leitura
	MOVLW       209
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,115 :: 		ucSegundo = I2C1_Rd(1);    // Lê o primeiro byte(segundos),informa que continua lendo
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucSegundo+0 
;main.c,116 :: 		ucMinuto = I2C1_Rd(1);     // Lê o segundo byte(minutos)
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucMinuto+0 
;main.c,117 :: 		ucHora = I2C1_Rd(1);       // Lê o terceiro byte(horas)
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucHora+0 
;main.c,118 :: 		ucDia_Semana = I2C1_Rd(1);
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucDia_Semana+0 
;main.c,119 :: 		ucDia = I2C1_Rd(1);
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucDia+0 
;main.c,120 :: 		ucMes = I2C1_Rd(1);
	MOVLW       1
	MOVWF       FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucMes+0 
;main.c,121 :: 		ucAno = I2C1_Rd(0);        // Lê o sétimo byte(ano),encerra as leituras de dados
	CLRF        FARG_I2C1_Rd_ack+0 
	CALL        _I2C1_Rd+0, 0
	MOVF        R0, 0 
	MOVWF       _ucAno+0 
;main.c,122 :: 		I2C1_Stop();               // Finaliza comunicação I2C
	CALL        _I2C1_Stop+0, 0
;main.c,123 :: 		}
	RETURN      0
; end of _Leitura_RTC

_Grava_RTC:
;main.c,125 :: 		void Grava_RTC(){
;main.c,126 :: 		I2C1_Init(100000);     // Iniciliza I2C com frequencia de 100KHz
	MOVLW       20
	MOVWF       SSPADD+0 
	CALL        _I2C1_Init+0, 0
;main.c,127 :: 		I2C1_Start();          // Inicializa a comunicação I2c
	CALL        _I2C1_Start+0, 0
;main.c,128 :: 		I2C1_Wr(0xD0);         // End. fixo para DS1307: 1101000X, onde x = 0 é para gravação
	MOVLW       208
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,129 :: 		I2C1_Wr(0);            // End. onde começa a programação do relógio, end. dos segundos.
	CLRF        FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,130 :: 		I2C1_Wr(0x04);         // Inicializa com 04 segundos.
	MOVLW       4
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,131 :: 		I2C1_Wr(0x12);         // Inicializa com 12 minutos.
	MOVLW       18
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,132 :: 		I2C1_Wr(0x09);         // Inicializa com 09:00hs (formato 24 horas).
	MOVLW       9
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,133 :: 		I2C1_Wr(0x03);         // Inicializa com terça
	MOVLW       3
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,134 :: 		I2C1_Wr(0x15);         // Inicializa com dia 15
	MOVLW       21
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,135 :: 		I2C1_Wr(0x07);         // Inicializa com mês 07
	MOVLW       7
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,136 :: 		I2C1_Wr(0x09);         // Inicializa com ano 09
	MOVLW       9
	MOVWF       FARG_I2C1_Wr_data_+0 
	CALL        _I2C1_Wr+0, 0
;main.c,137 :: 		I2C1_Stop();           // Finaliza comunicação I2C
	CALL        _I2C1_Stop+0, 0
;main.c,138 :: 		}
	RETURN      0
; end of _Grava_RTC

_Encontra_Dia_Semana:
;main.c,140 :: 		void Encontra_Dia_Semana() {
;main.c,141 :: 		switch (ucDia_Semana) {
	GOTO        L_Encontra_Dia_Semana3
;main.c,142 :: 		case 01: ucTexto = "DOMINGO"; break; // Caso dias_semana = 01 então..
L_Encontra_Dia_Semana5:
	MOVLW       ?lstr1_main+0
	MOVWF       _ucTexto+0 
	MOVLW       hi_addr(?lstr1_main+0)
	MOVWF       _ucTexto+1 
	GOTO        L_Encontra_Dia_Semana4
;main.c,143 :: 		case 02: ucTexto = "SEGUNDA"; break; // Caso dias_semana = 02 então..
L_Encontra_Dia_Semana6:
	MOVLW       ?lstr2_main+0
	MOVWF       _ucTexto+0 
	MOVLW       hi_addr(?lstr2_main+0)
	MOVWF       _ucTexto+1 
	GOTO        L_Encontra_Dia_Semana4
;main.c,144 :: 		case 03: ucTexto = "TERCA";   break; // Caso dias_semana = 03 então..
L_Encontra_Dia_Semana7:
	MOVLW       ?lstr3_main+0
	MOVWF       _ucTexto+0 
	MOVLW       hi_addr(?lstr3_main+0)
	MOVWF       _ucTexto+1 
	GOTO        L_Encontra_Dia_Semana4
;main.c,145 :: 		case 04: ucTexto = "QUARTA";  break; // Caso dias_semana = 04 então..
L_Encontra_Dia_Semana8:
	MOVLW       ?lstr4_main+0
	MOVWF       _ucTexto+0 
	MOVLW       hi_addr(?lstr4_main+0)
	MOVWF       _ucTexto+1 
	GOTO        L_Encontra_Dia_Semana4
;main.c,146 :: 		case 05: ucTexto = "QUINTA";  break; // Caso dias_semana = 05 então..
L_Encontra_Dia_Semana9:
	MOVLW       ?lstr5_main+0
	MOVWF       _ucTexto+0 
	MOVLW       hi_addr(?lstr5_main+0)
	MOVWF       _ucTexto+1 
	GOTO        L_Encontra_Dia_Semana4
;main.c,147 :: 		case 06: ucTexto = "SEXTA";   break; // Caso dias_semana = 06 então..
L_Encontra_Dia_Semana10:
	MOVLW       ?lstr6_main+0
	MOVWF       _ucTexto+0 
	MOVLW       hi_addr(?lstr6_main+0)
	MOVWF       _ucTexto+1 
	GOTO        L_Encontra_Dia_Semana4
;main.c,148 :: 		default: ucTexto = "SABADO";         // Se não for nenhum desses então...
L_Encontra_Dia_Semana11:
	MOVLW       ?lstr7_main+0
	MOVWF       _ucTexto+0 
	MOVLW       hi_addr(?lstr7_main+0)
	MOVWF       _ucTexto+1 
;main.c,149 :: 		}
	GOTO        L_Encontra_Dia_Semana4
L_Encontra_Dia_Semana3:
	MOVF        _ucDia_Semana+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_Encontra_Dia_Semana5
	MOVF        _ucDia_Semana+0, 0 
	XORLW       2
	BTFSC       STATUS+0, 2 
	GOTO        L_Encontra_Dia_Semana6
	MOVF        _ucDia_Semana+0, 0 
	XORLW       3
	BTFSC       STATUS+0, 2 
	GOTO        L_Encontra_Dia_Semana7
	MOVF        _ucDia_Semana+0, 0 
	XORLW       4
	BTFSC       STATUS+0, 2 
	GOTO        L_Encontra_Dia_Semana8
	MOVF        _ucDia_Semana+0, 0 
	XORLW       5
	BTFSC       STATUS+0, 2 
	GOTO        L_Encontra_Dia_Semana9
	MOVF        _ucDia_Semana+0, 0 
	XORLW       6
	BTFSC       STATUS+0, 2 
	GOTO        L_Encontra_Dia_Semana10
	GOTO        L_Encontra_Dia_Semana11
L_Encontra_Dia_Semana4:
;main.c,150 :: 		}
	RETURN      0
; end of _Encontra_Dia_Semana

_Display_LCD:
;main.c,152 :: 		void Display_LCD() {
;main.c,153 :: 		Lcd_Out(1,1,"(Hora)");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr8_main+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr8_main+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,154 :: 		Converte_BCD(1,7,ucHora);     // Conversão da variável horas para BCD
	MOVLW       1
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       7
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucHora+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;main.c,155 :: 		Lcd_Chr_CP(':');              // Escreve no display LCD
	MOVLW       58
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;main.c,156 :: 		Converte_BCD(1,10,ucMinuto);  // Conversão da variável minuto para BCD
	MOVLW       1
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       10
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucMinuto+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;main.c,157 :: 		Lcd_Chr_CP(':');              // Escreve no display LCD
	MOVLW       58
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;main.c,158 :: 		Converte_BCD(1,13,ucSegundo); // Conversão da variável segundo para BCD
	MOVLW       1
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       13
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucSegundo+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;main.c,159 :: 		Lcd_Out(2,1,"(Data)");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr9_main+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr9_main+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,160 :: 		Converte_BCD(2,7,ucDia);      // Conversão da variável dia para BCD
	MOVLW       2
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       7
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucDia+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;main.c,161 :: 		Lcd_Chr_CP('/');              // Escreve no display LCD
	MOVLW       47
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;main.c,162 :: 		Converte_BCD(2,10,ucMes);     // Conversão da variável mes para BCD
	MOVLW       2
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       10
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucMes+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;main.c,163 :: 		Lcd_Chr_CP('/');              // Escreve no display LCD
	MOVLW       47
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;main.c,164 :: 		Converte_BCD(2,13,ucAno);     // Conversão da variável ano para BCD
	MOVLW       2
	MOVWF       FARG_Converte_BCD_ucLinha+0 
	MOVLW       13
	MOVWF       FARG_Converte_BCD_ucColuna+0 
	MOVF        _ucAno+0, 0 
	MOVWF       FARG_Converte_BCD_ucValor+0 
	CALL        _Converte_BCD+0, 0
;main.c,165 :: 		Encontra_Dia_Semana();
	CALL        _Encontra_Dia_Semana+0, 0
;main.c,166 :: 		Lcd_Out(3,1,ucTexto);         // Mostra dia da semana
	MOVLW       3
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVF        _ucTexto+0, 0 
	MOVWF       FARG_Lcd_Out_text+0 
	MOVF        _ucTexto+1, 0 
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,167 :: 		}
	RETURN      0
; end of _Display_LCD
