
_main:
;main.c,37 :: 		void main(){
;main.c,38 :: 		unsigned char ucMask[]={'0','1','2','3','4','5','6','7','8','9'} ;
	MOVLW       48
	MOVWF       main_ucMask_L0+0 
	MOVLW       49
	MOVWF       main_ucMask_L0+1 
	MOVLW       50
	MOVWF       main_ucMask_L0+2 
	MOVLW       51
	MOVWF       main_ucMask_L0+3 
	MOVLW       52
	MOVWF       main_ucMask_L0+4 
	MOVLW       53
	MOVWF       main_ucMask_L0+5 
	MOVLW       54
	MOVWF       main_ucMask_L0+6 
	MOVLW       55
	MOVWF       main_ucMask_L0+7 
	MOVLW       56
	MOVWF       main_ucMask_L0+8 
	MOVLW       57
	MOVWF       main_ucMask_L0+9 
;main.c,45 :: 		ADCON1 = 0x0f;      // Configura todos os pinos A/D como I/O
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,47 :: 		TRISB.RB3=1;        // Define o pino RB0 do PORTB como entrada.
	BSF         TRISB+0, 3 
;main.c,48 :: 		TRISB.RB4=1;        // Define o pino RB1 Do PORTB como entrada.
	BSF         TRISB+0, 4 
;main.c,50 :: 		TRISE.RE1=0;        // Define o pino RE1 do PORTE como saida.
	BCF         TRISE+0, 1 
;main.c,51 :: 		TRISE.RE2=0;        // Define o pino RE2 Do PORTE como saida.
	BCF         TRISE+0, 2 
;main.c,53 :: 		TRISA.RA2=0;        // Define o pino RA2 do PORTA como saida(Seleção Display 1).
	BCF         TRISA+0, 2 
;main.c,54 :: 		TRISA.RA3=0;        // Define o pino RA3 do PORTA como saida(Seleção Display 2).
	BCF         TRISA+0, 3 
;main.c,55 :: 		TRISA.RA4=0;        // Define o pino RA4 do PORTA como saida(Seleção Display 3).
	BCF         TRISA+0, 4 
;main.c,56 :: 		TRISA.RA5=0;        // Define o pino RA5 do PORTA como saida(Seleção Display 4).
	BCF         TRISA+0, 5 
;main.c,58 :: 		TRISD = 0;          // Define todos os pinos Do PORTD como saida.
	CLRF        TRISD+0 
;main.c,60 :: 		ucStatus_inc=0;     // Inicializa a variavel com o valor 0.
	CLRF        main_ucStatus_inc_L0+0 
;main.c,61 :: 		ucStatus_dec=0;     // Inicializa a variavel com o valor 0.
	CLRF        main_ucStatus_dec_L0+0 
;main.c,62 :: 		uiContador=0;       // Inicializa a variavel com o valor 0.
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;main.c,66 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,67 :: 		PORTD=0b00111000; // Define que LCD 2 linhas / matriz 7x5
	MOVLW       56
	MOVWF       PORTD+0 
;main.c,68 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,69 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main0:
	DECFSZ      R13, 1, 0
	BRA         L_main0
	NOP
;main.c,70 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,72 :: 		Delay_ms(15);
	MOVLW       39
	MOVWF       R12, 0
	MOVLW       245
	MOVWF       R13, 0
L_main1:
	DECFSZ      R13, 1, 0
	BRA         L_main1
	DECFSZ      R12, 1, 0
	BRA         L_main1
;main.c,74 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,75 :: 		PORTD=0b00111000; // Define que LCD 2 linhas / matriz 7x5
	MOVLW       56
	MOVWF       PORTD+0 
;main.c,76 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,77 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 0
	BRA         L_main2
	NOP
;main.c,78 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,80 :: 		Delay_ms(15);
	MOVLW       39
	MOVWF       R12, 0
	MOVLW       245
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 0
	BRA         L_main3
	DECFSZ      R12, 1, 0
	BRA         L_main3
;main.c,82 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,83 :: 		PORTD=0b00001100; // Liga display / desliga cursor.
	MOVLW       12
	MOVWF       PORTD+0 
;main.c,84 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,85 :: 		Delay_us(1600);   // Delay para o LCD assimilar o comando.(1.6 ms)
	MOVLW       5
	MOVWF       R12, 0
	MOVLW       38
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 0
	BRA         L_main4
	DECFSZ      R12, 1, 0
	BRA         L_main4
	NOP
;main.c,86 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,88 :: 		Delay_ms(15);
	MOVLW       39
	MOVWF       R12, 0
	MOVLW       245
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 0
	BRA         L_main5
	DECFSZ      R12, 1, 0
	BRA         L_main5
;main.c,90 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,91 :: 		PORTD=0b00000001; // Limpa LCD.
	MOVLW       1
	MOVWF       PORTD+0 
;main.c,92 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,93 :: 		Delay_us(1600);   // Delay para o LCD assimilar o comando.(1.6 ms)
	MOVLW       5
	MOVWF       R12, 0
	MOVLW       38
	MOVWF       R13, 0
L_main6:
	DECFSZ      R13, 1, 0
	BRA         L_main6
	DECFSZ      R12, 1, 0
	BRA         L_main6
	NOP
;main.c,94 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,96 :: 		while(1){           // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main7:
;main.c,99 :: 		if((PORTB.RB3==0)&&(ucStatus_inc==0)){   // Incrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 3 
	GOTO        L_main11
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main11
L__main44:
;main.c,100 :: 		ucStatus_inc=1;                       // Variavel de travamento do incremento.
	MOVLW       1
	MOVWF       main_ucStatus_inc_L0+0 
;main.c,101 :: 		uiContador++;                         // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
	INFSNZ      main_uiContador_L0+0, 1 
	INCF        main_uiContador_L0+1, 1 
;main.c,102 :: 		if(uiContador>9999){
	MOVF        main_uiContador_L0+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main45
	MOVF        main_uiContador_L0+0, 0 
	SUBLW       15
L__main45:
	BTFSC       STATUS+0, 0 
	GOTO        L_main12
;main.c,104 :: 		uiContador=9999;
	MOVLW       15
	MOVWF       main_uiContador_L0+0 
	MOVLW       39
	MOVWF       main_uiContador_L0+1 
;main.c,105 :: 		}
L_main12:
;main.c,106 :: 		}
L_main11:
;main.c,107 :: 		if((PORTB.RB3==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 3 
	GOTO        L_main15
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main15
L__main43:
;main.c,108 :: 		ucStatus_inc=0;
	CLRF        main_ucStatus_inc_L0+0 
;main.c,109 :: 		}
L_main15:
;main.c,111 :: 		if((PORTB.RB4==0)&&(ucStatus_dec==0)){   // Decrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 4 
	GOTO        L_main18
	MOVF        main_ucStatus_dec_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main18
L__main42:
;main.c,112 :: 		ucStatus_dec=1;                       // Variavel de travamento do decremento.
	MOVLW       1
	MOVWF       main_ucStatus_dec_L0+0 
;main.c,113 :: 		uiContador--;                         // Esse operador aritmetico(--) realiza o mesmo que variavel = variavel - 1.
	MOVLW       1
	SUBWF       main_uiContador_L0+0, 1 
	MOVLW       0
	SUBWFB      main_uiContador_L0+1, 1 
;main.c,114 :: 		if(uiContador>9999){
	MOVF        main_uiContador_L0+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main46
	MOVF        main_uiContador_L0+0, 0 
	SUBLW       15
L__main46:
	BTFSC       STATUS+0, 0 
	GOTO        L_main19
;main.c,117 :: 		uiContador=0;
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;main.c,118 :: 		}
L_main19:
;main.c,119 :: 		}
L_main18:
;main.c,120 :: 		if((PORTB.RB4==1)&&(ucStatus_dec==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 4 
	GOTO        L_main22
	MOVF        main_ucStatus_dec_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main22
L__main41:
;main.c,121 :: 		ucStatus_dec=0;
	CLRF        main_ucStatus_dec_L0+0 
;main.c,122 :: 		}
L_main22:
;main.c,124 :: 		uiValor =  uiContador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.
	MOVF        main_uiContador_L0+0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        main_uiContador_L0+1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,126 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,127 :: 		PORTD=0b10000000; // Posiciona cursor na linha1 coluna1.
	MOVLW       128
	MOVWF       PORTD+0 
;main.c,128 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,129 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main23:
	DECFSZ      R13, 1, 0
	BRA         L_main23
	NOP
;main.c,130 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,132 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,133 :: 		PORTD='C';        // Escreve Caractere "C" no LCD.
	MOVLW       67
	MOVWF       PORTD+0 
;main.c,134 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,135 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main24:
	DECFSZ      R13, 1, 0
	BRA         L_main24
	NOP
;main.c,136 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,138 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,139 :: 		PORTD=0b10000001; // Posiciona cursor na linha1 coluna2.
	MOVLW       129
	MOVWF       PORTD+0 
;main.c,140 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,141 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main25:
	DECFSZ      R13, 1, 0
	BRA         L_main25
	NOP
;main.c,142 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,144 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,145 :: 		PORTD='O';        // Escreve Caractere "O" no LCD.
	MOVLW       79
	MOVWF       PORTD+0 
;main.c,146 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,147 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main26:
	DECFSZ      R13, 1, 0
	BRA         L_main26
	NOP
;main.c,148 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,150 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,151 :: 		PORTD=0b10000010; // Posiciona cursor na linha1 coluna3.
	MOVLW       130
	MOVWF       PORTD+0 
;main.c,152 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,153 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main27:
	DECFSZ      R13, 1, 0
	BRA         L_main27
	NOP
;main.c,154 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,156 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,157 :: 		PORTD='N';        // Escreve Caractere "N" no LCD.
	MOVLW       78
	MOVWF       PORTD+0 
;main.c,158 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,159 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main28:
	DECFSZ      R13, 1, 0
	BRA         L_main28
	NOP
;main.c,160 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,162 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,163 :: 		PORTD=0b10000011; // Posiciona cursor na linha1 coluna4.
	MOVLW       131
	MOVWF       PORTD+0 
;main.c,164 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,165 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main29:
	DECFSZ      R13, 1, 0
	BRA         L_main29
	NOP
;main.c,166 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,168 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,169 :: 		PORTD='T';        // Escreve Caractere "T" no LCD.
	MOVLW       84
	MOVWF       PORTD+0 
;main.c,170 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,171 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main30:
	DECFSZ      R13, 1, 0
	BRA         L_main30
	NOP
;main.c,172 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,174 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,175 :: 		PORTD=0b10000100; // Posiciona cursor na linha1 coluna5.
	MOVLW       132
	MOVWF       PORTD+0 
;main.c,176 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,177 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main31:
	DECFSZ      R13, 1, 0
	BRA         L_main31
	NOP
;main.c,178 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,180 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,181 :: 		PORTD=':';        // Escreve Caractere "T" no LCD.
	MOVLW       58
	MOVWF       PORTD+0 
;main.c,182 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,183 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main32:
	DECFSZ      R13, 1, 0
	BRA         L_main32
	NOP
;main.c,184 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,186 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,187 :: 		PORTD=0b11000011; // Posiciona cursor na linha2 coluna4.
	MOVLW       195
	MOVWF       PORTD+0 
;main.c,188 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,189 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main33:
	DECFSZ      R13, 1, 0
	BRA         L_main33
	NOP
;main.c,190 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,192 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,194 :: 		PORTD = ucMask[uiValor%10];              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,195 :: 		uiValor/=10;                             // Divide variavel por 10.
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,196 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,197 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main34:
	DECFSZ      R13, 1, 0
	BRA         L_main34
	NOP
;main.c,198 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,200 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,201 :: 		PORTD=0b11000010; // Posiciona cursor na linha1 coluna8.
	MOVLW       194
	MOVWF       PORTD+0 
;main.c,202 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,203 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main35:
	DECFSZ      R13, 1, 0
	BRA         L_main35
	NOP
;main.c,204 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,206 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,208 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,209 :: 		uiValor/=10;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,210 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,211 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main36:
	DECFSZ      R13, 1, 0
	BRA         L_main36
	NOP
;main.c,212 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,214 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,215 :: 		PORTD=0b11000001; // Posiciona cursor na linha1 coluna7.
	MOVLW       193
	MOVWF       PORTD+0 
;main.c,216 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,217 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main37:
	DECFSZ      R13, 1, 0
	BRA         L_main37
	NOP
;main.c,218 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,220 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,222 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,223 :: 		uiValor/=10;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        R1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,224 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,225 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main38:
	DECFSZ      R13, 1, 0
	BRA         L_main38
	NOP
;main.c,226 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,228 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,229 :: 		PORTD=0b11000000; // Posiciona cursor na linha1 coluna6.
	MOVLW       192
	MOVWF       PORTD+0 
;main.c,230 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,231 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main39:
	DECFSZ      R13, 1, 0
	BRA         L_main39
	NOP
;main.c,232 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,234 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,236 :: 		PORTD = ucMask[uiValor%10];
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        main_uiValor_L0+0, 0 
	MOVWF       R0 
	MOVF        main_uiValor_L0+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       main_ucMask_L0+0
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucMask_L0+0)
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,237 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,238 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main40:
	DECFSZ      R13, 1, 0
	BRA         L_main40
	NOP
;main.c,239 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,240 :: 		}
	GOTO        L_main7
;main.c,241 :: 		}
	GOTO        $+0
; end of _main
