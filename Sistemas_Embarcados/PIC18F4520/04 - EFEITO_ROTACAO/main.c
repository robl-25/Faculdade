/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Efeito Rotação de leds no PORTD
         OBJETIVO: Aprender a utilizar tres novos operadores, o operador
                   lógico OU ("|"), o operador de rotacionamento de bits à
                   direita (">>") e o operador de rotacionamento de bits à
                   esquerda (">>"), que detalharemos a seguir.
            AUTOR: Fabio Mulero.[fabio@microgenios.com.br]
********************************************************************************
 MICROCONTROLADOR: PIC18F4520.
 http://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf

 PLACA DE DESENVOLVIMENTO: KIT PICgenios - PIC18F
 http://www.microgenios.com.br/news/index.php?option=com_content&task=view&id=88&Itemid=134

 SOFTWARE: MikroC PRO for PIC
 http://www.mikroe.com/en/compilers/mikroc/pro/pic/

************************ Configurações do KIT Picgenios ************************
 CRISTAL: 8Mhz.

 CHAVES DE FUNÇÃO:
  --------------------- ----------------------
 |GLCD\LCD ( 1) = OFF  |DIS1     ( 1) = OFF   |
 |RX       ( 2) = OFF  |DIS2     ( 2) = OFF   |
 |TX       ( 3) = OFF  |DIS3     ( 3) = OFF   |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = OFF   |
 |REL2     ( 5) = OFF  |INFR     ( 5) = OFF   |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = OFF  |AN0      ( 9) = OFF   |
 |LED2     (10) = ON   |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/

void main(){
   unsigned char ucByte1;        // Aqui estamos declarando duas variaveis locais para uso no programa.
   unsigned char ucByte2;        // Convencionaremos que todas as variaveis "unsigned char" terão o prefixo "uc".

   TRISD=0;                      // Define todos os pinos do PORTD como saída.
   ucByte1 = 128;                // Definimos que o bit7 de ucByte1 será 1 (1000 0000).
   ucByte2 = 1;                  // Definimos que o bit0 de ucByte2 será 1 (0000 0001).

   while(1){                     // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
      PORTD=(ucByte1|ucByte2);   // Aqui unimos os valores de ucByte1 e ucByte2 (EX:(1000 0000)|(0000 0001) é igual a (1000 0001)).
      ucByte1>>=1;               // Rotacionamos os bits de ucByte1 para a direita (EX: O Valor (1000 0000) rotacionado a direita é igual a (0100 0000)).
      ucByte2<<=1;               // Rotacionamos os bits de ucByte1 para a direita (EX: O Valor (1000 0000) rotacionado a direita é igual a (0100 0000)).
      if(ucByte1==0){            // Verificamos de já houve a rotação completa do bit.
         ucByte1=128;            // Carregamos novamente ucByte1 com o valor inicial.
      }
      if(ucByte2==0){            // Verificamos de já houve a rotação completa do bit.
         ucByte2=1;              // Carregamos novamente ucByte2 com o valor inicial.
      }
     Delay_ms(50);               // Esta função é interna do compilador, portanto o tempo é de 50ms ou 0.05 segundo.
   }
}
