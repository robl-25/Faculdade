/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
* PROGRAMA EXEMPLO: Mostrar contador de 0 a 9999 nos displays de LCD em 4 bits.*
*         OBJETIVO: Aprender a utilizar LCD alfanumerico em configuração de 4  *
*                   bits PORTD[4..7], LCD pinos [D4..D7].                      *
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
 |GLCD\LCD ( 1) = ON   |DIS1     ( 1) = OFF   |
 |RX       ( 2) = OFF  |DIS2     ( 2) = OFF   |
 |TX       ( 3) = OFF  |DIS3     ( 3) = OFF   |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = OFF   |
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
   unsigned char ucMask[]={'0','1','2','3','4','5','6','7','8','9'} ;
   
   unsigned char ucStatus_inc; // Variavel de travamento do incremento.
   unsigned char ucStatus_dec; // Variavel de travamento do decremento.
   unsigned int  uiContador;   // Variavel de armazenamento do contador.
   unsigned int  uiValor;      // Variavel auxiliar para exibição do contador.

   ADCON1 = 0x0f;      // Configura todos os pinos A/D como I/O

   TRISB.RB3=1;        // Define o pino RB0 do PORTB como entrada.
   TRISB.RB4=1;        // Define o pino RB1 Do PORTB como entrada.

   TRISE.RE1=0;        // Define o pino RE1 do PORTE como saida.
   TRISE.RE2=0;        // Define o pino RE2 Do PORTE como saida.

   TRISA.RA2=0;        // Define o pino RA2 do PORTA como saida(Seleção Display 1).
   TRISA.RA3=0;        // Define o pino RA3 do PORTA como saida(Seleção Display 2).
   TRISA.RA4=0;        // Define o pino RA4 do PORTA como saida(Seleção Display 3).
   TRISA.RA5=0;        // Define o pino RA5 do PORTA como saida(Seleção Display 4).

   TRISD = 0;          // Define todos os pinos Do PORTD como saida.

   ucStatus_inc=0;     // Inicializa a variavel com o valor 0.
   ucStatus_dec=0;     // Inicializa a variavel com o valor 0.
   uiContador=0;       // Inicializa a variavel com o valor 0.


   //Inicializa LCD Alfanumérico de 2x16
   //Manda byte
   PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
   PORTD=0b00110000; // Define que LCD
   PORTE.RE1 = 1;    // Habilita LCD.
   Delay_us(4100);   // Delay para o LCD assimilar o comando.(40 us)
   PORTE.RE1 = 0;    // Desabilita LCD.

   //Manda byte
   PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
   PORTD=0b00110000; // Define que LCD
   PORTE.RE1 = 1;    // Habilita LCD.
   Delay_us(100);     // Delay para o LCD assimilar o comando.(40 us)
   PORTE.RE1 = 0;    // Desabilita LCD.

   //Manda byte
   PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
   PORTD=0b00110000; // Define que LCD
   PORTE.RE1 = 1;    // Habilita LCD.
   Delay_us(100);    // Delay para o LCD assimilar o comando.(40 us)
   PORTE.RE1 = 0;    // Desabilita LCD.

   PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
   PORTD=0b00100000; // Define que LCD 4bits
   PORTE.RE1 = 1;    // Habilita LCD.
   Delay_us(4100);   // Delay para o LCD assimilar o comando.(40 us)
   PORTE.RE1 = 0;    // Desabilita LCD.

   //Inicia LCD
   //Manda nibble alto
   PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
   PORTD=0b00100000; // Define que LCD 4 bits
   PORTE.RE1 = 1;    // Habilita LCD.
   Delay_us(100);    // Delay para o LCD assimilar o comando.(40 us)
   PORTE.RE1 = 0;    // Desabilita LCD.

   //Manda nibble baixo
   PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
   PORTD=0b10000000; // Define que LCD 2 linhas / matriz 7x5
   PORTE.RE1 = 1;    // Habilita LCD.
   Delay_us(100);    // Delay para o LCD assimilar o comando.(40 us)
   PORTE.RE1 = 0;    // Desabilita LCD.

   //Manda nibble alto
   PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
   PORTD=0b00000000; // Define que LCD
   PORTE.RE1 = 1;    // Habilita LCD.
   Delay_us(4100);   // Delay para o LCD assimilar o comando.(40 us)
   PORTE.RE1 = 0;    // Desabilita LCD.
   //Manda nibble baixo
   PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
   PORTD=0b11000000; // Define que LCD desliga lcd,cursor
   PORTE.RE1 = 1;    // Habilita LCD.
   Delay_us(100);     // Delay para o LCD assimilar o comando.(40 us)
   PORTE.RE1 = 0;    // Desabilita LCD.

   //Manda nibble alto
   PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
   PORTD=0b00000000; // Define que LCD
   PORTE.RE1 = 1;    // Habilita LCD.
   Delay_us(100);    // Delay para o LCD assimilar o comando.(40 us)
   PORTE.RE1 = 0;    // Desabilita LCD.
   //Manda nibble baixo
   PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
   PORTD=0b00010000; // Limpa LCD
   PORTE.RE1 = 1;    // Habilita LCD.
   Delay_us(100);    // Delay para o LCD assimilar o comando.(40 us)
   PORTE.RE1 = 0;    // Desabilita LCD.

   while(1){           // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.

      // Le Tecla E Incrementa Contador.
      if((PORTB.RB3==0)&&(ucStatus_inc==0)){   // Incrementa somente uma vez quando a tecla for pressionada.
         ucStatus_inc=1;                       // Variavel de travamento do incremento.
         uiContador++;                         // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
         if(uiContador>9999){
         /* Essa comparação é feita pois nosso valor máximo é 9999. */
            uiContador=9999;
         }
      }
      if((PORTB.RB3==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
         ucStatus_inc=0;
      }
      // Le tecla e decrementa contador.
      if((PORTB.RB4==0)&&(ucStatus_dec==0)){   // Decrementa somente uma vez quando a tecla for pressionada.
         ucStatus_dec=1;                       // Variavel de travamento do decremento.
         uiContador--;                         // Esse operador aritmetico(--) realiza o mesmo que variavel = variavel - 1.
         if(uiContador>9999){
         /* Essa comparação é feita pois ao decrementar variaveis sem sinal o
         valor irá para o valor máximo da variavel que no caso é 65535. */
            uiContador=0;
         }
      }
      if((PORTB.RB4==1)&&(ucStatus_dec==1)){   // Volta a disponibilizar a opção de incremento quando a tecla for solta.
         ucStatus_dec=0;
      }

      uiValor =  uiContador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.
      // Envia Texto ao LCD "CONT:"
      // Manda 1 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b10000000; // Posiciona cursor na linha1 coluna1.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      // Manda 2 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b00000000; // Posiciona cursor na linha1 coluna1.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      // Manda 1 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      PORTD=('C'& 0xf0);// Escreve Caractere "C" no LCD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      // Manda 2 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      PORTD=('C'& 0x0f)<<4;// Escreve Caractere "C" no LCD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      // Manda 1 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b10000000; // Posiciona cursor na linha1 coluna2.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      // Manda 2 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b00010000; // Posiciona cursor na linha1 coluna2.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      // Manda 1 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      PORTD=('O'& 0xf0);// Escreve Caractere "O" no LCD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      // Manda 2 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      PORTD=('O'& 0x0f)<<4;// Escreve Caractere "O" no LCD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      // Manda 1 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b10000000; // Posiciona cursor na linha1 coluna3.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      // Manda 2 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b00100000; // Posiciona cursor na linha1 coluna3.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      // Manda 1 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      PORTD=('N'& 0xf0);// Escreve Caractere "N" no LCD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      // Manda 2 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      PORTD=('N'& 0x0f)<<4;// Escreve Caractere "N" no LCD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      // Manda 1 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b10000000; // Posiciona cursor na linha1 coluna4.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      // Manda 2 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b00110000; // Posiciona cursor na linha1 coluna4.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      // Manda 1 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      PORTD=('T'& 0xf0);// Escreve Caractere "T" no LCD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      // Manda 2 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      PORTD=('T'& 0x0f)<<4;// Escreve Caractere "T" no LCD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      // Manda 1 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b10000000; // Posiciona cursor na linha1 coluna5.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      // Manda 2 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b01000000; // Posiciona cursor na linha1 coluna5.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      // Manda 1 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      PORTD=(':'& 0xf0);// Escreve Caractere ":" no LCD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      // Manda 2 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      PORTD=(':'& 0x0f)<<4;// Escreve Caractere ":" no LCD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      //Mostra Contador
      //Manda 1 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b11000000; // Posiciona cursor na linha2 coluna4.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      //Manda 2 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b00110000; // Posiciona cursor na linha2 coluna4.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      //Manda 1 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      // Mostra valor da unidade.
      PORTD = ((ucMask[uiValor%10])& 0xf0);              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      //Manda 2 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      // Mostra valor da unidade.
      PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      uiValor/=10;                             // Divide variavel por 10.

      //Manda 1 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b11000000; // Posiciona cursor na linha2 coluna3.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      //Manda 2 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b00100000; // Posiciona cursor na linha2 coluna3.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      //Manda 1 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      // Mostra valor da unidade.
      PORTD = ((ucMask[uiValor%10])& 0xf0);              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
       PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      //Manda 2 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      // Mostra valor da unidade.
      PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      uiValor/=10;                             // Divide variavel por 10.

      //Manda 1 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b11000000; // Posiciona cursor na linha2 coluna2.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      //Manda 2 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b00010000; // Posiciona cursor na linha2 coluna2.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      //Manda 1 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      // Mostra valor da unidade.
      PORTD = ((ucMask[uiValor%10])& 0xf0);              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
       PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      //Manda 2 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      // Mostra valor da unidade.
      PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      uiValor/=10;                             // Divide variavel por 10.

      //Manda 1 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b11000000; // Posiciona cursor na linha2 coluna1.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      //Manda 2 nibble
      PORTE.RE2 = 0;    // Define se é comando(0) ou dado(1).(COMANDO)
      PORTD=0b00000000; // Posiciona cursor na linha2 coluna1.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.

      //Manda 1 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      // Mostra valor da unidade.
      PORTD = ((ucMask[uiValor%10])& 0xf0);              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
      //Manda 2 nibble
      PORTE.RE2 = 1;    // Define se é comando(0) ou dado(1).(DADO)
      // Mostra valor da unidade.
      PORTD = ((ucMask[uiValor%10])& 0x0f)<<4;              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
      PORTE.RE1 = 1;    // Habilita LCD.
      Delay_us(40);     // Delay para o LCD assimilar o comando.(40 us)
      PORTE.RE1 = 0;    // Desabilita LCD.
   }
}
