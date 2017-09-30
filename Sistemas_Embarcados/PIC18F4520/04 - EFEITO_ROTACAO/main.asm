
_main:
;main.c,40 :: 		void main(){
;main.c,44 :: 		TRISD=0;                      // Define todos os pinos do PORTD como saída.
	CLRF        TRISD+0 
;main.c,45 :: 		ucByte1 = 128;                // Definimos que o bit7 de ucByte1 será 1 (1000 0000).
	MOVLW       128
	MOVWF       R2 
;main.c,46 :: 		ucByte2 = 1;                  // Definimos que o bit0 de ucByte2 será 1 (0000 0001).
	MOVLW       1
	MOVWF       R3 
;main.c,48 :: 		while(1){                     // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
L_main0:
;main.c,49 :: 		PORTD=(ucByte1|ucByte2);   // Aqui unimos os valores de ucByte1 e ucByte2 (EX:(1000 0000)|(0000 0001) é igual a (1000 0001)).
	MOVF        R3, 0 
	IORWF       R2, 0 
	MOVWF       PORTD+0 
;main.c,50 :: 		ucByte1>>=1;               // Rotacionamos os bits de ucByte1 para a direita (EX: O Valor (1000 0000) rotacionado a direita é igual a (0100 0000)).
	MOVF        R2, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	BCF         R1, 7 
	MOVF        R1, 0 
	MOVWF       R2 
;main.c,51 :: 		ucByte2<<=1;               // Rotacionamos os bits de ucByte1 para a direita (EX: O Valor (1000 0000) rotacionado a direita é igual a (0100 0000)).
	RLCF        R3, 1 
	BCF         R3, 0 
;main.c,52 :: 		if(ucByte1==0){            // Verificamos de já houve a rotação completa do bit.
	MOVF        R1, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main2
;main.c,53 :: 		ucByte1=128;            // Carregamos novamente ucByte1 com o valor inicial.
	MOVLW       128
	MOVWF       R2 
;main.c,54 :: 		}
L_main2:
;main.c,55 :: 		if(ucByte2==0){            // Verificamos de já houve a rotação completa do bit.
	MOVF        R3, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main3
;main.c,56 :: 		ucByte2=1;              // Carregamos novamente ucByte2 com o valor inicial.
	MOVLW       1
	MOVWF       R3 
;main.c,57 :: 		}
L_main3:
;main.c,58 :: 		Delay_ms(50);               // Esta função é interna do compilador, portanto o tempo é de 50ms ou 0.05 segundo.
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       221
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 0
	BRA         L_main4
	DECFSZ      R12, 1, 0
	BRA         L_main4
	NOP
	NOP
;main.c,59 :: 		}
	GOTO        L_main0
;main.c,60 :: 		}
	GOTO        $+0
; end of _main
