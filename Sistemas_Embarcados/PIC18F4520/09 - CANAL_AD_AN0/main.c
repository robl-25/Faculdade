/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Leitura do canal A/D AN0 e mostrar a representação nos
                   displays de 7 segmentos.
         OBJETIVO: Aprender a utilizar varredura de port´s do pic para escrita
                   nos displays de 7 segmentos.
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
 |GLCD\LCD ( 1) = OFF  |DIS1     ( 1) = ON    |
 |RX       ( 2) = OFF  |DIS2     ( 2) = ON    |
 |TX       ( 3) = OFF  |DIS3     ( 3) = ON    |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = ON    |
 |REL2     ( 5) = OFF  |INFR     ( 5) = OFF   |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = OFF  |AN0      ( 9) = ON    |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/

void main(){
                          //  "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
   unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   /* Variavel Do Tipo Matriz Que Armazena Os Valores Correspondentes Ao Numero
   Para Ser Mostrado No Display De 7 Segmentos */
   unsigned int  uiValorAD;     // Variavel que armazena o valor do A/D.
   unsigned int  uiValor;       // Variavel Auxiliar Para Mostrar No Display.

   ADCON0 = 0b10000001;  // Configura conversor A/D para clock de Fosc/64, Canal 0, conversão desligada, A/D ligado.
   ADCON1 = 0b11001110;  // Configura resultado justificado a direita, clock de Fosc/64, todos canais como Digital menos AN0 e REF Interna.

   TRISA.RA2=0;        // Define O Pino RA2 Do PORTA Como Saida(Seleção Display 1).
   TRISA.RA3=0;        // Define O Pino RA3 Do PORTA Como Saida(Seleção Display 2).
   TRISA.RA4=0;        // Define O Pino RA4 Do PORTA Como Saida(Seleção Display 3).
   TRISA.RA5=0;        // Define O Pino RA5 Do PORTA Como Saida(Seleção Display 4).

   TRISD = 0;          // Define Todos Os Pinos Do PORTD Como Saida.

   while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.

      if(ADCON0.GO_DONE==0)
      {
         uiValorAD= ((ADRESH<<8) | ADRESL);  // Lê valor do A/D.
         ADCON0.GO_DONE=1;                   // Inicia conversão A/D.
      }

      uiValor=uiValorAD;                     // Transfere valor do A/D para variavel auxiliar.

      TRISD=0;                               // Define Todos Os Pinos Do PORTD Como Saida.

      // Mostra Valor Da Unidade
      PORTD = ucMask[uiValor%10];            // Pega Modulo (Resto) Da Divisão Por 10 E Coloca O Valor No PORTD.
      PORTA.RA5 = 1;                         // Liga O Transistor Associado Ao Display 1.
      Delay_ms(2);                           // Delay Para Escrita No Display.
      PORTA.RA5 = 0;                         // Desliga O Transistor Associado Ao Display 1.
      uiValor/=10;                           // Divide Variavel Por 10.
      // Mostra Valor Da Dezena
      PORTD = ucMask[uiValor%10];
      PORTA.RA4 = 1;
      Delay_ms(2);
      PORTA.RA4 = 0;
      uiValor/=10;
      // Mostra Valor Da Centena
      PORTD = ucMask[uiValor%10];
      PORTA.RA3 = 1;
      Delay_ms(2);
      PORTA.RA3 = 0;
      uiValor/=10;
      // Mostra Valor Do Milhar
      PORTD = ucMask[uiValor%10];
      PORTA.RA2 = 1;
      Delay_ms(2);
      PORTA.RA2 = 0;
   }
}
