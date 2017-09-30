/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Pisca-Pisca no PORTD.
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
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/
// Varaiveis Globais
unsigned char ucContador = 0;

void interrupt()           // Palavra "interrupt" sempre em minuscula.
{
   ucContador++;            // Incrementa valor na variavel contador.
   PORTD = ucContador;      // Coloca valor da variavel no PORTD.
   INTCON.INT0IF = 0;       // Limpa o flag sinalizador de interrupção externa INT0
                            // temos que apagar esse flag para que uma nova interrupção ocorra
}

void main(){           // Função principal de qualquer programa escrito na linguagem C.
   INTCON2.RBPU = 0;   // Programa o resistor de pull-up interno do PIC
                       // caso não venhamos a colocar resistores de pull-up externos
                       // temos que habilitar esse bit. (lembre-se que é habilitado em 0)

   TRISB.RB0 = 1;      // Configura pino RB0 como entrada
   TRISD = 0;          // Configura PORTD como saida
   PORTD = 0;          // Desliga todos os pinos do PORTD

   INTCON = 0b11010001; //habilita interrupção geral
         //habilita interrupção de periféricos
         //habilita interrupção externa INT0
         //resseta bit sinalizador da interrupção EXTERNA INT0
   INTCON2.INTEDG0 = 0;    //aciona interrupção por borda de descida
   while(1); // Loop infinito.
}
