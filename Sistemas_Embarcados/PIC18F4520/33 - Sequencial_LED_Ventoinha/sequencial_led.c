/*********************************************************************
Centro de tecnologia Microgenios
Placa: Kit PICGenios
Programa: Led sequencial PORTB e PORTD
C
*/

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
//Rotina para aguardar tempo proporcional ao valor passado como argumento
void main()
{

     //variaveis com a seqüência a ser exteriorizada e o sentido de deslocamento
     unsigned char seq, seq1, sent, sent1,a;
     trisd = 0;
     trisb = 0;
     trisc = 0;
     ADCON1 = 0b00001111;                // programa pinos de A/D como I/O de uso geral
     TRISE = 0;                // programa porte como saida
     portb=0;
     portd=0;
     Lcd_Init();                               // Inicializa LCD.
     Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
     Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
     Lcd_Out(1, 1, "Microgenios");   // escreve texto "Programa LCD" na primeira linha, quarta coluna do LCD
     Lcd_Out(2, 1, "  PicGenios ");   // escreve texto "Programa LCD" na primeira linha, quarta coluna do LCD
     delay_ms(1000);


     //Loop Infinito
     while(1)
     {
         portb=~portb;
         portd=~portd;
         Delay_ms(1000);

     }
}
