/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Interrupção de timer0 Pisca PORTB e Interrupção de timer1 Pisca PORTD
         OBJETIVO: Aprender a utilizar a interrupção externa INT0 para
                   incrementar uma unidade no PORTD.
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
 |RX       ( 2) = OFF  |DIS2     ( 2) = OFF   |
 |TX       ( 3) = OFF  |DIS3     ( 3) = OFF   |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = OFF   |
 |REL2     ( 5) = OFF  |INFR     ( 5) = OFF   |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = ON   |AN0      ( 9) = OFF   |
 |LED2     (10) = ON   |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/
// Varaiveis Globais
unsigned char ucContador_alta = 0X01;
unsigned char ucContador_baixa = 0X80;

void interrupt()               // Palavra "interrupt" sempre em minuscula.
{

    if(PIR2.TMR3IF==1){        // Executa somente quando existir o overflow do timer 3.
       // Recarrega o timer3.
       TMR3H = 0x0B;           // Carrega o valor alto do número 3036.
       TMR3L = 0xDC;           // Carrega o valor baixo do numero 3036.

       PIR2.TMR3IF = 0;        // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
       ucContador_alta <<= 1;  // Esse operador BITWISE(<<) realiza o mesmo que variavel = variavel * 2.
       if (ucContador_alta==0){
          ucContador_alta=0x01;
       }
       PORTD=ucContador_alta; // Coloca o valor do Contador no PORTD.
    }
}

void interrupt_low()              // Palavra "interrupt_low" sempre em minuscula.
{
    if(PIR1.TMR1IF==1){           // Executa somente quando existir o overflow do timer 1.
       // Recarrega o timer1.
       TMR1H = 0x0B;              // Carrega o valor alto do número 3036.
       TMR1L = 0xDC;              // Carrega o valor baixo do numero 3036.

       PIR1.TMR1IF = 0;           // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
       ucContador_baixa>>=1;      // Esse operador BITWISE(>>) realiza o mesmo que variavel = variavel / 2.
       if (ucContador_baixa==0){
          ucContador_baixa=0x80;
       }
       PORTB=ucContador_baixa;    // Coloca o valor do Contador no PORTD.
    }
}



void main(){           // Função principal de qualquer programa escrito na linguagem C.
   TRISB = 0;          // Configura PORTB como saida.
   TRISD = 0;          // Configura PORTD como saida.
   PORTB = 0;          // Desliga todos os pinos do PORTB.
   PORTD = 0;          // Desliga todos os pinos do PORTD.
   
   // Configuração do Timer1.
                             // Cristal de 8Mhz, ciclo de máquina: 8MHz / 4 = 2Mhz --> 1/2Mhz = 0,5us.
   T1CON.RD16 = 1;          // Habilita a leitura e escrita em um ciclo de 16 bits.
   T1CON.T1CKPS1 = 1;       // Define prescaler 1:8.
   T1CON.T1CKPS0 = 1;       // Define prescaler 1:8.
   T1CON.TMR1CS = 0;        // Clock interno.
   // Valor para 250 ms.
   TMR1H = 0x0B;            // Carrega o valor alto do número 3036.
   TMR1L = 0xDC;            // Carrega o valor baixo do numero 3036.
   PIE1.TMR1IE = 1;         // Habilita a interrupção do timer1.
   PIR1.TMR1IF = 0;         // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
   IPR1.TMR1IP = 0;         // Habilita prioridade de interrupção baixa.
   T1CON.TMR1ON = 1;        // Liga timer1.
   
   // Configuração do Timer3.
                             // Cristal de 8Mhz, ciclo de máquina: 8MHz / 4 = 2Mhz --> 1/2Mhz = 0,5us.
   T3CON.RD16 = 1;          // Habilita a leitura e escrita em um ciclo de 16 bits.
   T3CON.T1CKPS1 = 1;       // Define prescaler 1:4.
   T3CON.T1CKPS0 = 0;       // Define prescaler 1:4.
   T3CON.TMR3CS = 0;        // Clock interno.

   TMR1H = 0x0B;            // Carrega o valor alto do número 3036.
   TMR1L = 0xDC;            // Carrega o valor baixo do numero 3036.
   PIE2.TMR3IE = 1;         // Habilita a interrupção do timer3.
   PIR2.TMR3IF = 0;         // Apaga flag de estouro do timer3, pois é fundamental para a sinalização do estouro.
   T3CON.TMR3ON = 1;        // Liga timer3.
   IPR2.TMR3IP = 1;         // Habilita prioridade de interrupção alta.
   
   RCON.IPEN = 1;           // 2 Niveis de prioridade de interrupçâo.

   INTCON.GIEH = 1;    // Habilita todas interrupções e o vetor de alta prioridade.
   INTCON.GIEL = 1;    // Habilita o vetor de baixa prioridade.

   while(1); // Loop infinito.
}
