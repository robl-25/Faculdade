
_main:
;main.c,39 :: 		void main(){
;main.c,41 :: 		unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x21,0x03,0x40};
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
	MOVLW       33
	MOVWF       main_ucMask_L0+10 
	MOVLW       3
	MOVWF       main_ucMask_L0+11 
	MOVLW       64
	MOVWF       main_ucMask_L0+12 
;main.c,45 :: 		unsigned char ucConverter[] = {12,10,7,4,1,0,8,5,2,11,9,6,3};
	MOVLW       12
	MOVWF       main_ucConverter_L0+0 
	MOVLW       10
	MOVWF       main_ucConverter_L0+1 
	MOVLW       7
	MOVWF       main_ucConverter_L0+2 
	MOVLW       4
	MOVWF       main_ucConverter_L0+3 
	MOVLW       1
	MOVWF       main_ucConverter_L0+4 
	CLRF        main_ucConverter_L0+5 
	MOVLW       8
	MOVWF       main_ucConverter_L0+6 
	MOVLW       5
	MOVWF       main_ucConverter_L0+7 
	MOVLW       2
	MOVWF       main_ucConverter_L0+8 
	MOVLW       11
	MOVWF       main_ucConverter_L0+9 
	MOVLW       9
	MOVWF       main_ucConverter_L0+10 
	MOVLW       6
	MOVWF       main_ucConverter_L0+11 
	MOVLW       3
	MOVWF       main_ucConverter_L0+12 
;main.c,54 :: 		ADCON1 = 0x0f;      // Configura Todos Os Pinos A/D Como I/O
	MOVLW       15
	MOVWF       ADCON1+0 
;main.c,56 :: 		TRISB.RB0=0;        // Define o pino RB0 do PORTB como saida(Coluna1).
	BCF         TRISB+0, 0 
;main.c,57 :: 		TRISB.RB1=0;        // Define o pino RB1 do PORTB como saida(Coluna2).
	BCF         TRISB+0, 1 
;main.c,58 :: 		TRISB.RB2=0;        // Define o pino RB2 do PORTB como saida(Coluna3).
	BCF         TRISB+0, 2 
;main.c,60 :: 		TRISA.RA2=0;        // Define O Pino RA2 Do PORTA Como Saida(Seleção Display 1).
	BCF         TRISA+0, 2 
;main.c,61 :: 		TRISA.RA3=0;        // Define O Pino RA3 Do PORTA Como Saida(Seleção Display 2).
	BCF         TRISA+0, 3 
;main.c,62 :: 		TRISA.RA4=0;        // Define O Pino RA4 Do PORTA Como Saida(Seleção Display 3).
	BCF         TRISA+0, 4 
;main.c,63 :: 		TRISA.RA5=0;        // Define O Pino RA5 Do PORTA Como Saida(Seleção Display 4).
	BCF         TRISA+0, 5 
;main.c,65 :: 		TRISD = 0;          // Define Todos Os Pinos Do PORTD Como Saida.
	CLRF        TRISD+0 
;main.c,67 :: 		while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
L_main0:
;main.c,68 :: 		TRISD=0x0F;      // Define Todos Os Pinos De 0 A 3 Do PORTD Como Entrada E Pinos De 4 A 7 Do PORTD Como Saida.
	MOVLW       15
	MOVWF       TRISD+0 
;main.c,69 :: 		PORTB.RB0=0;     // Liga Coluna 1
	BCF         PORTB+0, 0 
;main.c,70 :: 		Delay_ms(1);     // Aguarda 1ms Para Fazer A Leitura Das Teclas.
	MOVLW       3
	MOVWF       R12, 0
	MOVLW       151
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 0
	BRA         L_main2
	DECFSZ      R12, 1, 0
	BRA         L_main2
	NOP
	NOP
;main.c,71 :: 		ucTecla = (((~PORTD)&0x0F)); // Com O Operador Lógico Bit A Bit "&", Podemos Ler Somente Os Pinos Que Nos Interessam, No Caso Os Pinos De RD0 A RD3
	COMF        PORTD+0, 0 
	MOVWF       R4 
	MOVLW       15
	ANDWF       R4, 0 
	MOVWF       R4 
	CLRF        R5 
	MOVLW       0
	ANDWF       R5, 1 
;main.c,72 :: 		PORTB.RB0=1;     // Desliga Coluna 1
	BSF         PORTB+0, 0 
;main.c,73 :: 		uiTeclas = (unsigned int)(ucTecla&0x0F);
	MOVLW       15
	ANDWF       R4, 0 
	MOVWF       R4 
	CLRF        R5 
	MOVLW       0
	ANDWF       R5, 1 
	MOVLW       0
	MOVWF       R5 
;main.c,75 :: 		PORTB.RB1=0;
	BCF         PORTB+0, 1 
;main.c,76 :: 		Delay_ms(1);
	MOVLW       3
	MOVWF       R12, 0
	MOVLW       151
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 0
	BRA         L_main3
	DECFSZ      R12, 1, 0
	BRA         L_main3
	NOP
	NOP
;main.c,77 :: 		ucTecla = (((~PORTD)&0x0F));
	COMF        PORTD+0, 0 
	MOVWF       R0 
	MOVLW       15
	ANDWF       R0, 1 
;main.c,78 :: 		PORTB.RB1=1;
	BSF         PORTB+0, 1 
;main.c,79 :: 		uiTeclas |= (unsigned int)((ucTecla&0x0F)<<4);
	MOVLW       15
	ANDWF       R0, 0 
	MOVWF       R3 
	MOVLW       4
	MOVWF       R2 
	MOVF        R3, 0 
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVF        R2, 0 
L__main10:
	BZ          L__main11
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R1, 1 
	ADDLW       255
	GOTO        L__main10
L__main11:
	MOVF        R0, 0 
	IORWF       R4, 1 
	MOVF        R1, 0 
	IORWF       R5, 1 
;main.c,81 :: 		PORTB.RB2=0;
	BCF         PORTB+0, 2 
;main.c,82 :: 		Delay_ms(1);
	MOVLW       3
	MOVWF       R12, 0
	MOVLW       151
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 0
	BRA         L_main4
	DECFSZ      R12, 1, 0
	BRA         L_main4
	NOP
	NOP
;main.c,83 :: 		ucTecla = (((~PORTD)&0x0F));
	COMF        PORTD+0, 0 
	MOVWF       R0 
	MOVLW       15
	ANDWF       R0, 1 
;main.c,84 :: 		PORTB.RB2=1;
	BSF         PORTB+0, 2 
;main.c,85 :: 		uiTeclas |= (unsigned int)((ucTecla&0x0F)<<8);
	MOVLW       15
	ANDWF       R0, 0 
	MOVWF       R3 
	MOVF        R3, 0 
	MOVWF       R1 
	CLRF        R0 
	MOVF        R0, 0 
	IORWF       R4, 1 
	MOVF        R1, 0 
	IORWF       R5, 1 
;main.c,86 :: 		uiValor=0;
	CLRF        R6 
	CLRF        R7 
;main.c,88 :: 		for (ucContador=0;ucContador<=12;ucContador++)
	CLRF        R8 
L_main5:
	MOVF        R8, 0 
	SUBLW       12
	BTFSS       STATUS+0, 0 
	GOTO        L_main6
;main.c,90 :: 		if ((unsigned int)(1<<ucContador)==uiTeclas)      // (1<<Variavel) Igual A 2 Elevado A Um Expoente
	MOVF        R8, 0 
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	MOVLW       0
	MOVWF       R2 
	MOVF        R0, 0 
L__main12:
	BZ          L__main13
	RLCF        R1, 1 
	BCF         R1, 0 
	RLCF        R2, 1 
	ADDLW       255
	GOTO        L__main12
L__main13:
	MOVF        R2, 0 
	XORWF       R5, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main14
	MOVF        R4, 0 
	XORWF       R1, 0 
L__main14:
	BTFSS       STATUS+0, 2 
	GOTO        L_main8
;main.c,92 :: 		uiValor = (unsigned int) ucContador + 1 ;      // Coloca O Conteudo Da Variavel Do Contador Na Varaivel Auxiliar.
	MOVF        R8, 0 
	MOVWF       R6 
	MOVLW       0
	MOVWF       R7 
	INFSNZ      R6, 1 
	INCF        R7, 1 
;main.c,93 :: 		}
L_main8:
;main.c,88 :: 		for (ucContador=0;ucContador<=12;ucContador++)
	INCF        R8, 1 
;main.c,94 :: 		}
	GOTO        L_main5
L_main6:
;main.c,96 :: 		TRISD=0;                                   // Define Todos Os Pinos Do PORTD Como Saida.
	CLRF        TRISD+0 
;main.c,99 :: 		PORTD = ucMask[ucConverter[uiValor]];      // Mostra caractere correspondente
	MOVLW       main_ucConverter_L0+0
	ADDWF       R6, 0 
	MOVWF       FSR2L 
	MOVLW       hi_addr(main_ucConverter_L0+0)
	ADDWFC      R7, 0 
	MOVWF       FSR2H 
	MOVLW       main_ucMask_L0+0
	MOVWF       FSR0L 
	MOVLW       hi_addr(main_ucMask_L0+0)
	MOVWF       FSR0H 
	MOVF        POSTINC2+0, 0 
	ADDWF       FSR0L, 1 
	BTFSC       STATUS+0, 0 
	INCF        FSR0H, 1 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
;main.c,100 :: 		PORTA.RA5 = 1;                             // Liga O Transistor Associado Ao Display 1.
	BSF         PORTA+0, 5 
;main.c,101 :: 		Delay_ms(2);                               // Delay Para Escrita No Display.
	MOVLW       6
	MOVWF       R12, 0
	MOVLW       48
	MOVWF       R13, 0
L_main9:
	DECFSZ      R13, 1, 0
	BRA         L_main9
	DECFSZ      R12, 1, 0
	BRA         L_main9
	NOP
;main.c,102 :: 		PORTA.RA5 = 0;                             // Desliga O Transistor Associado Ao Display 1.
	BCF         PORTA+0, 5 
;main.c,103 :: 		}
	GOTO        L_main0
;main.c,104 :: 		}
	GOTO        $+0
; end of _main
