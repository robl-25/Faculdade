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

void delay (unsigned char tempo)
{
   for(;tempo!=0;tempo--);
}

void main(){

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
  portc.f2 = 1;
   //Inicilizando sequencia - 1º Led aceso
   seq=0x01;
   seq1=0x08;

   //Inicializando sentido (de Portx.f0 para Portx.f7)
   sent=0;
   sent1=0;

   //Loop Infinito
   while(1){


 		//Coloca a sequencia atual em P2
 		Portd=seq;

 		//Se sentido de Portx.0 a Portx.7 translação para esquerda
 		if(sent==0){ seq<<=1;

 		  				 //Se o último Led ficará aceso, inverte sentido
 		  				 if(seq==0x80) sent=1;
 		  				 }
 		  	//Caso contrário rotação para direita
 		  	else{ seq>>=1;

 		  				 //Se o primeiro Led ficará aceso, inverte sentido
 		  				 if(seq==0x01) sent=0;
 		  				 }

  //Aguarda algum tempo
 	for(a=0;a!=30;a++) delay(250);

  		//Coloca a sequencia atual em P2

 		Portb=seq1;

 		//Se sentido de P2.0 a P2.7 translação para esquerda
 		if(sent1==0){ seq1<<=1;

 		  				 //Se o último Led ficará aceso, inverte sentido
 		  				 if(seq1==0x80) sent1=1;
 		  				 }
 		  	//Caso contrário rotação para direita
 		  	else{ seq1>>=1;

 		  				 //Se o primeiro Led ficará aceso, inverte sentido                    oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
 		  				 if(seq1==0x01) sent1=0;
 		  				 }

  //Aguarda algum tempo
 	for(a=0;a!=30;a++) delay(250);

}
  }

