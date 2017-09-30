/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Utilizar a interrupção do timer1 para incrementar contador
                   de 0 a 255 a cada 250ms e mostrar no PORTD.
         OBJETIVO: Aprender a utilizar a interrupção do timer.
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
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/
//Variaveis Globais
unsigned int  ucContador;   // Variavel de armazenamento do contador.

void interrupt(){           // Palavra "interrupt" sempre em minuscula.
    // Incrementa Contador.
    if(PIR1.TMR1IF==1){     // Incrementa somente quando existir o overflow do timer 1.
       // Recarrega o timer1.
       TMR1H = 0x0B;           // Carrega o valor alto do número 3036.
       TMR1L = 0xDC;           // Carrega o valor baixo do numero 3036.

       PIR1.TMR1IF = 0;        // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
       ucContador++;           // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
       PORTD=ucContador;       // Coloca o valor do Contador no PORTD.
    }
}

void main(){

   ADCON1 = 0x0F;            // Configura todos os pinos A/D como I/O

   TRISD = 0;                // Define todos os pinos Do PORTD como saida.

   ucContador=0;             // Inicializa a variavel com o valor 0.

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
    T1CON.TMR1ON = 1;        // Liga timer1.

    INTCON.GIE = 1;          // Habilita as interrupções não-mascaradas.
    INTCON.PEIE = 1;         // Habilita as interrupções dos perifericos.

    while(1);
}
