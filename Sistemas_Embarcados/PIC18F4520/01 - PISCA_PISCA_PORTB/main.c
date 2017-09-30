/*
               Microgenios Solu��es Eletr�nicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Pisca-Pisca no PORTB.
         OBJETIVO: Aprender a utilizar o PORTB do PIC como saida.
            AUTOR: Fabio Mulero.[fabio@microgenios.com.br]
********************************************************************************
 MICROCONTROLADOR: PIC18F4520.
 http://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf

 PLACA DE DESENVOLVIMENTO: KIT PICgenios - PIC18F
 http://www.microgenios.com.br/news/index.php?option=com_content&task=view&id=88&Itemid=134

 SOFTWARE: MikroC PRO for PIC
 http://www.mikroe.com/en/compilers/mikroc/pro/pic/

************************ Configura��es do KIT Picgenios ************************
 CRISTAL: 8Mhz.

 CHAVES DE FUN��O:
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

void main(){           // Fun��o principal de qualquer programa escrito na linguagem C.
   TRISB=0;            // Define todos os pinos do PORTB como sa�da.
   while(1){           // Aqui definimos uma condi��o sempre verdadeira como parametro, portanto todo o bloco ser� repetido indefinidamente.
      PORTB=0;         // Todos os pinos do PORTB em 0.
      Delay_ms(1000);  // Esta fun��o � interna do compilador, portanto o tempo � de 1000ms ou 1 segundo.
      PORTB=255;       // Todos os pinos do PORTB em 1.
      Delay_ms(1000);  // Aguarda novamente 1 segundo.
   }
}
