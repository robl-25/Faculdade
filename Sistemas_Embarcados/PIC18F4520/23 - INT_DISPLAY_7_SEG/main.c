/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Mostrar contador de 0 a 9999 nos displays de 7 segmentos
                   com varredura utilizando interrupção de TIMER2.
         OBJETIVO: Aprender a utilizar timer para admnistrar varredura dos displays de 7 segmentos.
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
// VARIAVEIS GLOBAIS
   unsigned int  uiContador;   // Variavel de armazenamento do contador.
   unsigned int  uiValor;      // Variavel auxiliar para exibição do contador.
                          //  "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
   unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   /* Variavel do tipo matriz que armazena os valores correspondentes ao numero
   para ser mostrado no display de 7 segmentos */
   
void interrupt(){
    if(PIR2.TMR3IF==1){      // Incrementa somente quando existir o overflow do timer 3.
      // Recarrega o timer3.
      TMR3H = 0x7B;         // Carrega o valor alto.
      TMR3L = 0xDC;         // Carrega o valor baixo.

      PIR2.TMR3IF = 0;      // Limpa o flag de estouro do timer3 para uma nova contagem de tempo.

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
      PIR1.TMR2IF = 0;       // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
    }
}

void main(){
   unsigned char ucStatus_inc; // Variavel de travamento do incremento.
   unsigned char ucStatus_dec; // Variavel de travamento do decremento.

   ADCON1 = 0x0f;       // Configura todos canais como Digital.

   TRISB.RB0=1;         // Define o pino RB0 do PORTB como entrada.
   TRISB.RB1=1;         // Define o pino RB1 Do PORTB como entrada.

   TRISA.RA2=0;         // Define o pino RA2 do PORTA como saida(Seleção Display 1).
   TRISA.RA3=0;         // Define o pino RA3 do PORTA como saida(Seleção Display 2).
   TRISA.RA4=0;         // Define o pino RA4 do PORTA como saida(Seleção Display 3).
   TRISA.RA5=0;         // Define o pino RA5 do PORTA como saida(Seleção Display 4).

   TRISD = 0;           // Define todos os pinos Do PORTD como saida.

   ucStatus_inc=0;      // Inicializa a variavel com o valor 0.
   ucStatus_dec=0;      // Inicializa a variavel com o valor 0.
   uiContador=0;        // Inicializa a variavel com o valor 0.

   // Configuração do Timer3.
                             // Cristal de 8Mhz, ciclo de máquina: 8MHz / 4 = 2Mhz --> 1/2Mhz = 0,5us.
    T3CON.RD16 = 1;          // Habilita a leitura e escrita em um ciclo de 16 bits.
    T3CON.T1CKPS1 = 0;       // Define prescaler 1:1.
    T3CON.T1CKPS0 = 0;       // Define prescaler 1:1.
    T3CON.TMR3CS = 0;        // Clock interno.

    TMR1H = 0x7B;            // Carrega o valor alto.
    TMR1L = 0xDC;            // Carrega o valor baixo.
    PIE2.TMR3IE = 1;         // Habilita a interrupção do timer3.
    PIR2.TMR3IF = 0;         // Apaga flag de estouro do timer3, pois é fundamental para a sinalização do estouro.
    T3CON.TMR3ON = 1;        // Liga timer3.

    INTCON.GIE = 1;          // Habilita as interrupções não-mascaradas.
    INTCON.PEIE = 1;         // Habilita as interrupções dos perifericos.

   while(1){            // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.

      // Le Tecla E Incrementa Contador.
      if((PORTB.RB0==0)&&(ucStatus_inc==0)){   // Incrementa somente uma vez quando a tecla for pressionada.
         ucStatus_inc=1;                       // Variavel de travamento do incremento.
         uiContador++;                         // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
         if(uiContador>9999){
         /* Essa comparação é feita pois nosso valor máximo é 9999. */
            uiContador=9999;
         }
      }
      if((PORTB.RB0==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
         ucStatus_inc=0;
      }
      // Le tecla e decrementa contador.
      if((PORTB.RB1==0)&&(ucStatus_dec==0)){   // Decrementa somente uma vez quando a tecla for pressionada.
         ucStatus_dec=1;                       // Variavel de travamento do decremento.
         uiContador--;                         // Esse operador aritmetico(--) realiza o mesmo que variavel = variavel - 1.
         if(uiContador>9999){
         /* Essa comparação é feita pois ao decrementar variaveis sem sinal o
         valor irá para o valor máximo da variavel que no caso é 65535. */
            uiContador=0;
         }
      }
      if((PORTB.RB1==1)&&(ucStatus_dec==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
         ucStatus_dec=0;
      }
   }
}
