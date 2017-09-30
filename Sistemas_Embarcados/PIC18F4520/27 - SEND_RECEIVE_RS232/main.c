/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Leitura e envio RS232.
         OBJETIVO: Aprender a ler e transmitir os dados pela RS232.
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
 |LED1     ( 9) = OFF  |AN0      ( 9) = OFF   |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/

void main(){

   unsigned char ucRead;        // Variavel para armazenar o dado lido.

   ADCON0 = 0b00000001;         // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
   ADCON1 = 0b11001110;         // Configura todos canais como Digital menos AN0 e REF Interna.
   ADCON2 = 0b10111110;         // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.

   TRISD = 0;                   // Define Todos Os Pinos Do PORTD Como Saida.
   PORTD = 0;
   
   UART1_Init(9600);            // Utiliza bibliotecas do compilador para configuração da RS232.
   
   while(1){ // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
      if(UART1_Data_Ready()){
         ucRead = UART1_Read(); // Lê o dado da serial.
         UART1_Write(ucRead);   // Reenvia pela serial.
      }
      Delay_ms(100);            // Pausa de 100ms.
    }
}
