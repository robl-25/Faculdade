/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: TIMER 1 como Contador.
         OBJETIVO: Aprender a utilizar o TIMER1 como contador.
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
 |REL2     ( 5) = OFF  |INFR     ( 5) = ON    |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = OFF  |AN0      ( 9) = OFF   |
 |LED2     (10) = ON   |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
OBS:
- HABILITAR BIBLIOTECA LCD.
- HABILITAR BIBLIOTECA CONVERSIONS.

SIMULAÇÃO DE PULSOS PELO GIRO MANUAL DA VENTOINHA.
********************************************************************************
*/

// VARIAVEIS GLOBAIS
unsigned char ucTexto[10];     // Matriz para armazenamento de texto.
unsigned int iReg_timer1 = 0;  // Armazena a qtde de lotes.

// CONFIGURAÇÃO DOS PINOS DO LCD.
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;

// DIREÇÃO DOS PINOS.
sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;

void interrupt(){
   if (PIR1.TMR1IF == 1){      // Se o flag de estouro do TIMER1 for igual a 1, então
      PORTB.RB0 = ~PORTB.RB0;  // Inverte o estado do PORTB.RB0.
      TMR1L = 0xF5;            // Carrega valor de contagem baixa do TIMER1
      TMR1H = 0xFF;            // Carrega valor de contagem alta do TIMER1
      PIR1.TMR1IF = 0;         // Seta T0IE, apaga flag de entouro do TIMER0
      iReg_timer1++;           // Incrementa contador de Lote.
   }
}

void main(){
   TRISB = 0;                        // Define PORTB como saida.
   TRISD = 0;                        // Define PORTD como saida.
   TRISC.RC0 = 1;                    // Define PORTC.RC0 como entrada.
   TRISC.RC2 = 0;                    // Define PORTC.RC2 como saida.
   TRISE = 0;                        // Define PORTE como saida.
   PORTB = 0;                        // Limpa PORTB.
   
   ADCON1 = 0x0F;                    // Configura todos canais como Digital.

   // Timer 1
   T1CON = 0B10000011; // Liga TIMER1 como Contador em RC0, prescaler 1:1, modo 16bits.
   // Carregamentp do timer para estouro em 10 pulsos.
   TMR1L = 0xF5;       // Carrega valor de contagem baixa do TIMER1
   TMR1H = 0xFF;       // Carrega valor de contagem alta do TIMER1
   PIE1.TMR1IE = 1;    // Habilita a interrupção do timer1.
   PIR1.TMR1IF = 0;    // Apaga flag de estouro do timer1, pois é fundamental para a sinalização do estouro.
   T1CON.TMR1ON = 1;   // Liga timer1.
   IPR1.TMR1IP = 1;    // Habilita prioridade de interrupção ALTA.

   RCON.IPEN = 1;      // Configura 2 niveis de interrupção.
   INTCON.GIE = 1;     // Habilita as interrupções não-mascaradas.
   INTCON.PEIE = 1;    // Habilita as interrupções dos perifericos.

   // Config. LCD no modo 4 bits
   Lcd_Init();                              // Inicializa LCD.

   Lcd_Cmd(_LCD_CLEAR);                     // Apaga display.
   Lcd_Cmd(_LCD_CURSOR_OFF);                // Desliga cursor.
   Lcd_Out(1, 1, "Qtde Lotes: ");           // Escreve mensagem no LCD.

   while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
      WordToStr(iReg_timer1, ucTexto);  // Converte o valor lido no iReg_timer1 em string
      Lcd_Out(2,1,ucTexto);             // Imprime no LCD o valor da RPM.
      Lcd_Out_CP(" Pcs");               // Unidade "RPM".
      Delay_10us;
   }
}
