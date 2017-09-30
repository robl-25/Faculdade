/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Leitura do canal A/D AN0 e AN1 e envio RS232.
         OBJETIVO: Aprender a transmitir os dados pela RS232.
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
 |RX       ( 2) = ON   |DIS2     ( 2) = OFF   |
 |TX       ( 3) = ON   |DIS3     ( 3) = OFF   |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = OFF   |
 |REL2     ( 5) = OFF  |INFR     ( 5) = OFF   |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = OFF  |AN0      ( 9) = ON    |
 |LED2     (10) = OFF  |AN1      (10) = ON    |
  --------------------- ----------------------
********************************************************************************
*/

void main(){
   // Matriz de caractere em hexa.
   unsigned char ucHexa[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
   unsigned char ucBuffer[4];   // Base para conversão em Hexadecimal.

   unsigned int  uiValorAD;     // Variavel que armazena o valor do A/D.

   unsigned char ucCount;       // Auxiliar de contagem.

   ADCON0 = 0b00000001;         // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
   ADCON1 = 0b11001110;         // Configura todos canais como Digital menos AN0 e REF Interna.
   ADCON2 = 0b10111110;         // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.

   TRISD = 0;                   // Define Todos Os Pinos Do PORTD Como Saida.
   PORTD = 0;
   
   UART1_Init(9600);            // Utiliza bibliotecas do compilador para configuração da RS232.
   
   while(1){ // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
   
      uiValorAD= ADC_Read(0);                    // Lê Canal AD 0.
      
      // Converte para hexadecimal.

      ucBuffer[3] = ucHexa[uiValorAD%16];        // Pega Valor Hexadecimal Menos Significativo.
      uiValorAD/=16;
      ucBuffer[2] = ucHexa[uiValorAD%16];
      uiValorAD/=16;
      ucBuffer[1] = ucHexa[uiValorAD%16];
      uiValorAD/=16;
      ucBuffer[0] = ucHexa[uiValorAD%16];        // Pega Valor Hexadecimal Mais Significativo.

      
      UART1_Write(0x02);                         // Inicio de Frame de dados.
      UART1_Write('A');                          // Dados informando qual canal será enviado.
      UART1_Write('N');
      UART1_Write('0');
      UART1_Write('=');
      UART1_Write(ucBuffer[0]);                  // Dados enviando hexadecimal do mais significativo para o menos significativo.
      UART1_Write(ucBuffer[1]);
      UART1_Write(ucBuffer[2]);
      UART1_Write(ucBuffer[3]);
      UART1_Write(0x04);                         // Fim de Frame de dados.
      
      uiValorAD= ADC_Read(1);                    // Lê Canal AD 1.

      // Converte para hexadecimal.

      ucBuffer[3] = ucHexa[uiValorAD%16];
      uiValorAD/=16;
      ucBuffer[2] = ucHexa[uiValorAD%16];
      uiValorAD/=16;
      ucBuffer[1] = ucHexa[uiValorAD%16];
      uiValorAD/=16;
      ucBuffer[0] = ucHexa[uiValorAD%16];


      UART1_Write(0x02);                         // Inicio de Frame de dados
      UART1_Write('A');                          // Dados informando qual canal será enviado.
      UART1_Write('N');
      UART1_Write('1');
      UART1_Write('=');
      UART1_Write(ucBuffer[0]);                  // Dados enviando hexadecimal do mais significativo para o menos significativo.
      UART1_Write(ucBuffer[1]);
      UART1_Write(ucBuffer[2]);
      UART1_Write(ucBuffer[3]);
      UART1_Write(0x04);                         // Fim de Frame de dados
      Delay_ms(100);                             // Pausa de 100ms.
   }
}
