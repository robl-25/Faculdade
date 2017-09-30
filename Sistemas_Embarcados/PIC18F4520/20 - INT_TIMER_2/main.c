/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Utilizar a interrupção do timer2 para incrementar contador
                   de 0 a 255 a cada 32 ms e mostrar no PORTD.
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
unsigned char  ucContador;   // Variavel de armazenamento do contador.

void interrupt(){             // Palavra "interrupt" sempre em minuscula.
    if(PIR1.TMR2IF==1){       // Incrementa somente quando existir o overflow do timer 2.
       // Recarrega o timer2.
       TMR2 = 0xFF;           // Carrega o valor alto do número 255.

       PIR1.TMR2IF = 0;       // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
       ucContador++;          // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
       PORTD=ucContador;      // Coloca o valor do Contador no PORTD.
    }
}

void main(){

   ADCON1 = 0x0F;             // Configura todos os pinos A/D como I/O

   TRISD = 0;                 // Define todos os pinos Do PORTD como saida.

   ucContador=0;              // Inicializa a variavel com o valor 0.

   // Configuração do Timer2.
                              // Cristal de 8Mhz, ciclo de máquina: 8MHz / 4 = 2Mhz --> 1/2Mhz = 0,5us.
    T2CON.T2OUTPS3 = 1;       // Define postscaler 1:16.
    T2CON.T2OUTPS2 = 1;       // Define postscaler 1:16.
    T2CON.T2OUTPS1 = 1;       // Define postscaler 1:16.
    T2CON.T2OUTPS0 = 1;       // Define postscaler 1:16.
    T2CON.T2CKPS1  = 1;       // Define prescaler 1:16.
    T2CON.T2CKPS0  = 1;       // Define prescaler 1:16.

    // Valor para 2 ms aproximadamente.
    TMR2 = 0xFF;             // Carrega o valor alto do número 256.

    PIE1.TMR2IE = 1;         // Habilita a interrupção do timer2.

    PIR1.TMR2IF = 0;         // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
    T2CON.TMR2ON = 1;        // Liga timer2.

    INTCON.GIE = 1;          // Habilita as interrupções não-mascaradas.
    INTCON.PEIE = 1;         // Habilita as interrupções dos perifericos.

    while(1);
}
