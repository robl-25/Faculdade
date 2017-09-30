
_main:
;main.c,38 :: 		void main(){
;main.c,39 :: 		unsigned char ucMask[]={'0','1','2','3','4','5','6','7','8','9'} ;
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
;main.c,46 :: 		ADCON1 = 0x0f;      // Configura todos os pinos A/D como I/O
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,48 :: 		TRISB.RB3=1;        // Define o pino RB0 do PORTB como entrada.
	BSF         TRISB+0, 3 
;main.c,49 :: 		TRISB.RB4=1;        // Define o pino RB1 Do PORTB como entrada.
	BSF         TRISB+0, 4 
;main.c,51 :: 		TRISE.RE1=0;        // Define o pino RE1 do PORTE como saida.
	BCF         TRISE+0, 1 
;main.c,52 :: 		TRISE.RE2=0;        // Define o pino RE2 Do PORTE como saida.
	BCF         TRISE+0, 2 
;main.c,54 :: 		TRISA.RA2=0;        // Define o pino RA2 do PORTA como saida(Seleção Display 1).
	BCF         TRISA+0, 2 
;main.c,55 :: 		TRISA.RA3=0;        // Define o pino RA3 do PORTA como saida(Seleção Display 2).
	BCF         TRISA+0, 3 
;main.c,56 :: 		TRISA.RA4=0;        // Define o pino RA4 do PORTA como saida(Seleção Display 3).
	BCF         TRISA+0, 4 
;main.c,57 :: 		TRISA.RA5=0;        // Define o pino RA5 do PORTA como saida(Seleção Display 4).
	BCF         TRISA+0, 5 
;main.c,59 :: 		TRISD = 0;          // Define todos os pinos Do PORTD como saida.
	CLRF        TRISD+0 
;main.c,61 :: 		ucStatus_inc=0;     // Inicializa a variavel com o valor 0.
	CLRF        main_ucStatus_inc_L0+0 
;main.c,62 :: 		ucStatus_dec=0;     // Inicializa a variavel com o valor 0.
	CLRF        main_ucStatus_dec_L0+0 
;main.c,63 :: 		uiContador=0;       // Inicializa a variavel com o valor 0.
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;main.c,68 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,69 :: 		PORTD=0b00110000; // Define que LCD
	MOVLW       48
	MOVWF       PORTD+0 
;main.c,70 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,71 :: 		Delay_us(4100);   // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       11
	MOVWF       R12, 0
	MOVLW       165
	MOVWF       R13, 0
L_main0:
	DECFSZ      R13, 1, 0
	BRA         L_main0
	DECFSZ      R12, 1, 0
	BRA         L_main0
;main.c,72 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,75 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,76 :: 		PORTD=0b00110000; // Define que LCD
	MOVLW       48
	MOVWF       PORTD+0 
;main.c,77 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,78 :: 		Delay_us(100);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       66
	MOVWF       R13, 0
L_main1:
	DECFSZ      R13, 1, 0
	BRA         L_main1
	NOP
;main.c,79 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,82 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,83 :: 		PORTD=0b00110000; // Define que LCD
	MOVLW       48
	MOVWF       PORTD+0 
;main.c,84 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,85 :: 		Delay_us(100);    // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       66
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 0
	BRA         L_main2
	NOP
;main.c,86 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,88 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,89 :: 		PORTD=0b00100000; // Define que LCD 4bits
	MOVLW       32
	MOVWF       PORTD+0 
;main.c,90 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,91 :: 		Delay_us(4100);   // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       11
	MOVWF       R12, 0
	MOVLW       165
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 0
	BRA         L_main3
	DECFSZ      R12, 1, 0
	BRA         L_main3
;main.c,92 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,96 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,97 :: 		PORTD=0b00100000; // Define que LCD 4 bits
	MOVLW       32
	MOVWF       PORTD+0 
;main.c,98 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,99 :: 		Delay_us(100);    // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       66
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 0
	BRA         L_main4
	NOP
;main.c,100 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,103 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,104 :: 		PORTD=0b10000000; // Define que LCD 2 linhas / matriz 7x5
	MOVLW       128
	MOVWF       PORTD+0 
;main.c,105 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,106 :: 		Delay_us(100);    // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       66
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 0
	BRA         L_main5
	NOP
;main.c,107 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,110 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,111 :: 		PORTD=0b00000000; // Define que LCD
	CLRF        PORTD+0 
;main.c,112 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,113 :: 		Delay_us(4100);   // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       11
	MOVWF       R12, 0
	MOVLW       165
	MOVWF       R13, 0
L_main6:
	DECFSZ      R13, 1, 0
	BRA         L_main6
	DECFSZ      R12, 1, 0
	BRA         L_main6
;main.c,114 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,116 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,117 :: 		PORTD=0b11000000; // Define que LCD desliga lcd,cursor
	MOVLW       192
	MOVWF       PORTD+0 
;main.c,118 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,119 :: 		Delay_us(100);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       66
	MOVWF       R13, 0
L_main7:
	DECFSZ      R13, 1, 0
	BRA         L_main7
	NOP
;main.c,120 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,123 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,124 :: 		PORTD=0b00000000; // Define que LCD
	CLRF        PORTD+0 
;main.c,125 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,126 :: 		Delay_us(100);    // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       66
	MOVWF       R13, 0
L_main8:
	DECFSZ      R13, 1, 0
	BRA         L_main8
	NOP
;main.c,127 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,129 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,130 :: 		PORTD=0b00010000; // Limpa LCD
	MOVLW       16
	MOVWF       PORTD+0 
;main.c,131 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,132 :: 		Delay_us(100);    // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       66
	MOVWF       R13, 0
L_main9:
	DECFSZ      R13, 1, 0
	BRA         L_main9
	NOP
;main.c,133 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,135 :: 		while(1){           // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main10:
;main.c,138 :: 		if((PORTB.RB3==0)&&(ucStatus_inc==0)){   // Incrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 3 
	GOTO        L_main14
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main14
L__main65:
;main.c,139 :: 		ucStatus_inc=1;                       // Variavel de travamento do incremento.
	MOVLW       1
	MOVWF       main_ucStatus_inc_L0+0 
;main.c,140 :: 		uiContador++;                         // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
	INFSNZ      main_uiContador_L0+0, 1 
	INCF        main_uiContador_L0+1, 1 
;main.c,141 :: 		if(uiContador>9999){
	MOVF        main_uiContador_L0+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main66
	MOVF        main_uiContador_L0+0, 0 
	SUBLW       15
L__main66:
	BTFSC       STATUS+0, 0 
	GOTO        L_main15
;main.c,143 :: 		uiContador=9999;
	MOVLW       15
	MOVWF       main_uiContador_L0+0 
	MOVLW       39
	MOVWF       main_uiContador_L0+1 
;main.c,144 :: 		}
L_main15:
;main.c,145 :: 		}
L_main14:
;main.c,146 :: 		if((PORTB.RB3==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 3 
	GOTO        L_main18
	MOVF        main_ucStatus_inc_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main18
L__main64:
;main.c,147 :: 		ucStatus_inc=0;
	CLRF        main_ucStatus_inc_L0+0 
;main.c,148 :: 		}
L_main18:
;main.c,150 :: 		if((PORTB.RB4==0)&&(ucStatus_dec==0)){   // Decrementa somente uma vez quando a tecla for pressionada.
	BTFSC       PORTB+0, 4 
	GOTO        L_main21
	MOVF        main_ucStatus_dec_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main21
L__main63:
;main.c,151 :: 		ucStatus_dec=1;                       // Variavel de travamento do decremento.
	MOVLW       1
	MOVWF       main_ucStatus_dec_L0+0 
;main.c,152 :: 		uiContador--;                         // Esse operador aritmetico(--) realiza o mesmo que variavel = variavel - 1.
	MOVLW       1
	SUBWF       main_uiContador_L0+0, 1 
	MOVLW       0
	SUBWFB      main_uiContador_L0+1, 1 
;main.c,153 :: 		if(uiContador>9999){
	MOVF        main_uiContador_L0+1, 0 
	SUBLW       39
	BTFSS       STATUS+0, 2 
	GOTO        L__main67
	MOVF        main_uiContador_L0+0, 0 
	SUBLW       15
L__main67:
	BTFSC       STATUS+0, 0 
	GOTO        L_main22
;main.c,156 :: 		uiContador=0;
	CLRF        main_uiContador_L0+0 
	CLRF        main_uiContador_L0+1 
;main.c,157 :: 		}
L_main22:
;main.c,158 :: 		}
L_main21:
;main.c,159 :: 		if((PORTB.RB4==1)&&(ucStatus_dec==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
	BTFSS       PORTB+0, 4 
	GOTO        L_main25
	MOVF        main_ucStatus_dec_L0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_main25
L__main62:
;main.c,160 :: 		ucStatus_dec=0;
	CLRF        main_ucStatus_dec_L0+0 
;main.c,161 :: 		}
L_main25:
;main.c,163 :: 		uiValor =  uiContador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.
	MOVF        main_uiContador_L0+0, 0 
	MOVWF       main_uiValor_L0+0 
	MOVF        main_uiContador_L0+1, 0 
	MOVWF       main_uiValor_L0+1 
;main.c,166 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,167 :: 		PORTD=0b10000000; // Posiciona cursor na linha1 coluna1.
	MOVLW       128
	MOVWF       PORTD+0 
;main.c,168 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,169 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main26:
	DECFSZ      R13, 1, 0
	BRA         L_main26
	NOP
;main.c,170 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,172 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,173 :: 		PORTD=0b00000000; // Posiciona cursor na linha1 coluna1.
	CLRF        PORTD+0 
;main.c,174 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,175 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main27:
	DECFSZ      R13, 1, 0
	BRA         L_main27
	NOP
;main.c,176 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,179 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,180 :: 		PORTD=('C'& 0xf0);// Escreve Caractere "C" no LCD.
	MOVLW       64
	MOVWF       PORTD+0 
;main.c,181 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,182 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main28:
	DECFSZ      R13, 1, 0
	BRA         L_main28
	NOP
;main.c,183 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,185 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,186 :: 		PORTD=('C'& 0x0f)<<4;// Escreve Caractere "C" no LCD.
	MOVLW       48
	MOVWF       PORTD+0 
;main.c,187 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,188 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main29:
	DECFSZ      R13, 1, 0
	BRA         L_main29
	NOP
;main.c,189 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,192 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,193 :: 		PORTD=0b10000000; // Posiciona cursor na linha1 coluna2.
	MOVLW       128
	MOVWF       PORTD+0 
;main.c,194 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,195 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main30:
	DECFSZ      R13, 1, 0
	BRA         L_main30
	NOP
;main.c,196 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,198 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,199 :: 		PORTD=0b00010000; // Posiciona cursor na linha1 coluna2.
	MOVLW       16
	MOVWF       PORTD+0 
;main.c,200 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,201 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main31:
	DECFSZ      R13, 1, 0
	BRA         L_main31
	NOP
;main.c,202 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,205 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,206 :: 		PORTD=('O'& 0xf0);// Escreve Caractere "O" no LCD.
	MOVLW       64
	MOVWF       PORTD+0 
;main.c,207 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,208 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main32:
	DECFSZ      R13, 1, 0
	BRA         L_main32
	NOP
;main.c,209 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,211 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,212 :: 		PORTD=('O'& 0x0f)<<4;// Escreve Caractere "O" no LCD.
	MOVLW       240
	MOVWF       PORTD+0 
;main.c,213 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,214 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main33:
	DECFSZ      R13, 1, 0
	BRA         L_main33
	NOP
;main.c,215 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,218 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,219 :: 		PORTD=0b10000000; // Posiciona cursor na linha1 coluna3.
	MOVLW       128
	MOVWF       PORTD+0 
;main.c,220 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,221 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main34:
	DECFSZ      R13, 1, 0
	BRA         L_main34
	NOP
;main.c,222 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,224 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,225 :: 		PORTD=0b00100000; // Posiciona cursor na linha1 coluna3.
	MOVLW       32
	MOVWF       PORTD+0 
;main.c,226 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,227 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main35:
	DECFSZ      R13, 1, 0
	BRA         L_main35
	NOP
;main.c,228 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,231 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,232 :: 		PORTD=('N'& 0xf0);// Escreve Caractere "N" no LCD.
	MOVLW       64
	MOVWF       PORTD+0 
;main.c,233 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,234 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main36:
	DECFSZ      R13, 1, 0
	BRA         L_main36
	NOP
;main.c,235 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,237 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,238 :: 		PORTD=('N'& 0x0f)<<4;// Escreve Caractere "N" no LCD.
	MOVLW       224
	MOVWF       PORTD+0 
;main.c,239 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,240 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main37:
	DECFSZ      R13, 1, 0
	BRA         L_main37
	NOP
;main.c,241 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,244 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,245 :: 		PORTD=0b10000000; // Posiciona cursor na linha1 coluna4.
	MOVLW       128
	MOVWF       PORTD+0 
;main.c,246 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,247 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main38:
	DECFSZ      R13, 1, 0
	BRA         L_main38
	NOP
;main.c,248 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,250 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,251 :: 		PORTD=0b00110000; // Posiciona cursor na linha1 coluna4.
	MOVLW       48
	MOVWF       PORTD+0 
;main.c,252 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,253 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main39:
	DECFSZ      R13, 1, 0
	BRA         L_main39
	NOP
;main.c,254 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,257 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,258 :: 		PORTD=('T'& 0xf0);// Escreve Caractere "T" no LCD.
	MOVLW       80
	MOVWF       PORTD+0 
;main.c,259 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,260 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main40:
	DECFSZ      R13, 1, 0
	BRA         L_main40
	NOP
;main.c,261 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,263 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,264 :: 		PORTD=('T'& 0x0f)<<4;// Escreve Caractere "T" no LCD.
	MOVLW       64
	MOVWF       PORTD+0 
;main.c,265 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,266 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main41:
	DECFSZ      R13, 1, 0
	BRA         L_main41
	NOP
;main.c,267 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,270 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,271 :: 		PORTD=0b10000000; // Posiciona cursor na linha1 coluna5.
	MOVLW       128
	MOVWF       PORTD+0 
;main.c,272 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,273 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main42:
	DECFSZ      R13, 1, 0
	BRA         L_main42
	NOP
;main.c,274 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,276 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,277 :: 		PORTD=0b01000000; // Posiciona cursor na linha1 coluna5.
	MOVLW       64
	MOVWF       PORTD+0 
;main.c,278 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,279 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main43:
	DECFSZ      R13, 1, 0
	BRA         L_main43
	NOP
;main.c,280 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,283 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,284 :: 		PORTD=(':'& 0xf0);// Escreve Caractere ":" no LCD.
	MOVLW       48
	MOVWF       PORTD+0 
;main.c,285 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,286 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main44:
	DECFSZ      R13, 1, 0
	BRA         L_main44
	NOP
;main.c,287 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,289 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,290 :: 		PORTD=(':'& 0x0f)<<4;// Escreve Caractere ":" no LCD.
	MOVLW       160
	MOVWF       PORTD+0 
;main.c,291 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,292 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main45:
	DECFSZ      R13, 1, 0
	BRA         L_main45
	NOP
;main.c,293 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,297 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,298 :: 		PORTD=0b11000000; // Posiciona cursor na linha2 coluna4.
	MOVLW       192
	MOVWF       PORTD+0 
;main.c,299 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,300 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main46:
	DECFSZ      R13, 1, 0
	BRA         L_main46
	NOP
;main.c,301 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,303 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,304 :: 		PORTD=0b00110000; // Posiciona cursor na linha2 coluna4.
	MOVLW       48
	MOVWF       PORTD+0 
;main.c,305 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,306 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main47:
	DECFSZ      R13, 1, 0
	BRA         L_main47
	NOP
;main.c,307 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,310 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,312 :: 		PORTD = ((ucMask[uiValor%10])& 0xf0);              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
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
	MOVLW       240
	ANDWF       POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,313 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,314 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main48:
	DECFSZ      R13, 1, 0
	BRA         L_main48
	NOP
;main.c,315 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,317 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,319 :: 		PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
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
	MOVLW       15
	ANDWF       POSTINC0+0, 0 
	MOVWF       R2 
	MOVF        R2, 0 
	MOVWF       R0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	MOVF        R0, 0 
	MOVWF       PORTD+0 
;main.c,320 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,321 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main49:
	DECFSZ      R13, 1, 0
	BRA         L_main49
	NOP
;main.c,322 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,323 :: 		uiValor/=10;                             // Divide variavel por 10.
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
;main.c,326 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,327 :: 		PORTD=0b11000000; // Posiciona cursor na linha2 coluna3.
	MOVLW       192
	MOVWF       PORTD+0 
;main.c,328 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,329 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main50:
	DECFSZ      R13, 1, 0
	BRA         L_main50
	NOP
;main.c,330 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,332 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,333 :: 		PORTD=0b00100000; // Posiciona cursor na linha2 coluna3.
	MOVLW       32
	MOVWF       PORTD+0 
;main.c,334 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,335 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main51:
	DECFSZ      R13, 1, 0
	BRA         L_main51
	NOP
;main.c,336 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,339 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,341 :: 		PORTD = ((ucMask[uiValor%10])& 0xf0);              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
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
	MOVLW       240
	ANDWF       POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,342 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,343 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main52:
	DECFSZ      R13, 1, 0
	BRA         L_main52
	NOP
;main.c,344 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,346 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,348 :: 		PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
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
	MOVLW       15
	ANDWF       POSTINC0+0, 0 
	MOVWF       R2 
	MOVF        R2, 0 
	MOVWF       R0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	MOVF        R0, 0 
	MOVWF       PORTD+0 
;main.c,349 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,350 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main53:
	DECFSZ      R13, 1, 0
	BRA         L_main53
	NOP
;main.c,351 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,352 :: 		uiValor/=10;                             // Divide variavel por 10.
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
;main.c,355 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,356 :: 		PORTD=0b11000000; // Posiciona cursor na linha2 coluna2.
	MOVLW       192
	MOVWF       PORTD+0 
;main.c,357 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,358 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main54:
	DECFSZ      R13, 1, 0
	BRA         L_main54
	NOP
;main.c,359 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,361 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,362 :: 		PORTD=0b00010000; // Posiciona cursor na linha2 coluna2.
	MOVLW       16
	MOVWF       PORTD+0 
;main.c,363 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,364 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main55:
	DECFSZ      R13, 1, 0
	BRA         L_main55
	NOP
;main.c,365 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,368 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,370 :: 		PORTD = ((ucMask[uiValor%10])& 0xf0);              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
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
	MOVLW       240
	ANDWF       POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,371 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,372 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main56:
	DECFSZ      R13, 1, 0
	BRA         L_main56
	NOP
;main.c,373 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,375 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,377 :: 		PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
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
	MOVLW       15
	ANDWF       POSTINC0+0, 0 
	MOVWF       R2 
	MOVF        R2, 0 
	MOVWF       R0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	MOVF        R0, 0 
	MOVWF       PORTD+0 
;main.c,378 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,379 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main57:
	DECFSZ      R13, 1, 0
	BRA         L_main57
	NOP
;main.c,380 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,381 :: 		uiValor/=10;                             // Divide variavel por 10.
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
;main.c,384 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,385 :: 		PORTD=0b11000000; // Posiciona cursor na linha2 coluna1.
	MOVLW       192
	MOVWF       PORTD+0 
;main.c,386 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,387 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main58:
	DECFSZ      R13, 1, 0
	BRA         L_main58
	NOP
;main.c,388 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,390 :: 		PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
	BCF         PORTE+0, 2 
;main.c,391 :: 		PORTD=0b00000000; // Posiciona cursor na linha2 coluna1.
	CLRF        PORTD+0 
;main.c,392 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,393 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main59:
	DECFSZ      R13, 1, 0
	BRA         L_main59
	NOP
;main.c,394 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,397 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,399 :: 		PORTD = ((ucMask[uiValor%10])& 0xf0);              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
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
	MOVLW       240
	ANDWF       POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,400 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,401 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main60:
	DECFSZ      R13, 1, 0
	BRA         L_main60
	NOP
;main.c,402 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,404 :: 		PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
	BSF         PORTE+0, 2 
;main.c,406 :: 		PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
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
	MOVLW       15
	ANDWF       POSTINC0+0, 0 
	MOVWF       R2 
	MOVF        R2, 0 
	MOVWF       R0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R0, 1 
	BCF         R0, 0 
	MOVF        R0, 0 
	MOVWF       PORTD+0 
;main.c,407 :: 		PORTE.RE1 = 1;    // Habilita LCD.
	BSF         PORTE+0, 1 
;main.c,408 :: 		Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
	MOVLW       26
	MOVWF       R13, 0
L_main61:
	DECFSZ      R13, 1, 0
	BRA         L_main61
	NOP
;main.c,409 :: 		PORTE.RE1 = 0;    // Desabilita LCD.
	BCF         PORTE+0, 1 
;main.c,410 :: 		}
	GOTO        L_main10
;main.c,411 :: 		}
	GOTO        $+0
; end of _main
