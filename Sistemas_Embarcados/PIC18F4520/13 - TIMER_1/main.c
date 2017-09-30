/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Utilizar timer1 para incrementar contador de 0 a 9999.
         OBJETIVO: Aprender a utilizar varredura de port´s do Pic para
                   escrita nos display de 7 segmentos.
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
 |LED1     ( 9) = OFF  |AN0      ( 9) = OFF   |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/

void main(){
                          //  "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
   unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   /* Variavel do tipo matriz que armazena os valores correspondentes ao numero
   para ser mostrado no display de 7 segmentos */
   unsigned char ucStatus_inc; // Variavel de travamento do incremento.
   unsigned char ucStatus_dec; // Variavel de travamento do decremento.
   unsigned int  uiContador;   // Variavel de armazenamento do contador.
   unsigned int  uiValor;      // Variavel auxiliar para exibição do contador.

   ADCON1 = 0x0F;            // Configura todos os pinos A/D como I/O

   TRISA.RA2=0;        // Define o pino RA2 do PORTA como saida(Seleção Display 1).
   TRISA.RA3=0;        // Define o pino RA3 do PORTA como saida(Seleção Display 2).
   TRISA.RA4=0;        // Define o pino RA4 do PORTA como saida(Seleção Display 3).
   TRISA.RA5=0;        // Define o pino RA5 do PORTA como saida(Seleção Display 4).

   TRISD = 0;          // Define todos os pinos Do PORTD como saida.

   ucStatus_inc=0;     // Inicializa a variavel com o valor 0.
   ucStatus_dec=0;     // Inicializa a variavel com o valor 0.
   uiContador=0;       // Inicializa a variavel com o valor 0.

   // Configuração do Timer0.
                            // Cristal de 8Mhz, ciclo de máquina: 8MHz / 4 = 2Mhz --> 1/2Mhz = 0,5us.
   T1CON.RD16 = 1;          // Habilita a leitura e escrita em um ciclo de 16 bits.
   T1CON.T1CKPS1 = 1;       // Define prescaler 1:8.
   T1CON.T1CKPS0 = 1;       // Define prescaler 1:8.
   T1CON.TMR1CS = 0;        // Clock interno.

   // Valor para 250 ms.
   TMR1H = 0x0B;            // Carrega o valor alto do número 3036.
   TMR1L = 0xDC;            // Carrega o valor baixo do numero 3036.

   PIR1.TMR1IF = 0;         // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
   T1CON.TMR1ON = 1;        // Liga timer1.

   while(1){           // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.

      // Incrementa Contador.
      if(PIR1.TMR1IF==1){   // Incrementa somente quando existir o overflow do timer 1.
         // Recarrega o timer0.
         TMR1H = 0x0B;           // Carrega o valor alto do número 3036.
         TMR1L = 0xDC;           // Carrega o valor baixo do numero 3036.

         PIR1.TMR1IF = 0;        // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
         ucStatus_inc=1;         // Variavel de travamento do incremento.
         uiContador++;           // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
         if(uiContador>9999){
         /* Essa comparação é feita pois nosso valor máximo é 9999. */
            uiContador=0;
         }
      }

      uiValor =  uiContador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.

      // Mostra valor da unidade.
      PORTD = ucMask[uiValor%10];              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
      PORTA.RA5 = 1;                           // Liga o transistor associado ao display 1.
      Delay_ms(2);                             // Delay para escrita no display.
      PORTA.RA5 = 0;                           // Desliga o transistor associado ao display 1.
      uiValor/=10;                             // Divide variavel por 10.
      // Mostra valor da dezena.
      PORTD = ucMask[uiValor%10];
      PORTA.RA4 = 1;
      Delay_ms(2);
      PORTA.RA4 = 0;
      uiValor/=10;
      // Mostra valor da centena.
      PORTD = ucMask[uiValor%10];
      PORTA.RA3 = 1;
      Delay_ms(2);
      PORTA.RA3 = 0;
      uiValor/=10;
      // Mostra valor do milhar.
      PORTD = ucMask[uiValor%10];
      PORTA.RA2 = 1;
      Delay_ms(2);
      PORTA.RA2 = 0;
   }
}
