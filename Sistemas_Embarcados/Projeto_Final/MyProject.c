/************************ Configurações do KIT Picgenios ************************
 O projeto mede a temperatura da placa mostrando no LCD junto com a data e hora
 e também uma flag mostrando se o aquecedor está ligado ou desligado. A cada 3s
 o programa é interrompido (pelo estouro do timer0) para mostrar as últimas 
 temperaturas gravadas na memória. As temperaturas são gravadas caso ela seja 
 diferente da temperatura gravada anteriormente. No display de 7 segmentos é
 mostrado a porcentagem da rotação do cooler e o conversor A/D controla essa 
 porcentagem. Os botões RB3 e RB4 ligam e desligam, respectivamente, o aquecedor
 da placa.
 CHAVES DE FUNÇÃO:
  --------------------- ----------------------
 |GLCD\LCD ( 1) = ON   |DIS1     ( 1) = OFF   |
 |RX       ( 2) = ON   |DIS2     ( 2) = OFF   |
 |TX       ( 3) = ON   |DIS3     ( 3) = ON    |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = ON    |
 |REL2     ( 5) = OFF  |INFR     ( 5) = OFF   |
 |SCK      ( 6) = ON   |RESIS    ( 6) = ON    |
 |SDA      ( 7) = ON   |TEMP     ( 7) = ON    |
 |RTC      ( 8) = ON   |VENT     ( 8) = ON    |
 |LED1     ( 9) = OFF  |AN0      ( 9) = ON    |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/

// VARIAVEIS GLOBAIS
unsigned char ucHora;       // Armazena Hora.
unsigned char ucMinuto;     // Armazena Minuto.
unsigned char ucSegundo;    // Armazena Segundo.
unsigned char ucDia;        // Armazena Dia.
unsigned char ucMes;        // Armazena Mes.
unsigned char ucAno;        // Armazena Ano.
unsigned char ucDia_Semana; // Armazena Dia da Semana.
unsigned char ucTexto[10];   // Matriz para armazenamento de texto.
unsigned int iLeituraAD = 0; // Define variável para armazenamento da leitura AD.
char *ucTexto2;              // Ponteiro para leitura de strings.
unsigned int uiValorADC = 0;
unsigned int uiValorLido = 0;

// PROTOTIPOS DE FUNÇÃO
void GRAUS();
void Display_LCD();
void Encontra_Dia_Semana();
void Grava_RTC();
void Leitura_RTC();
void Converte_BCD(unsigned char ucLinha, unsigned char ucColuna,unsigned char ucValor);
void GravaEEPROM(int ucContador);
void LeEEPROM();

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

/*------------- FIM TEMPERATURA ----------- */

void main(){
/*-----------------------DISPLAY --------------------------*/
  //  "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
   unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
    /* Variavel do tipo matriz que armazena os valores correspondentes ao numero
   para ser mostrado no display de 7 segmentos */
    unsigned int  uiValor;      // Variavel auxiliar para exibição do contador.
    int ucContador = 0;
    char cooler = 'd';
    int uiValorADCAnt = 0;
    int valorLidoAnt = 0;

   TRISB.RB3=1;         // Define o pino RB0 do PORTB como entrada.
   TRISB.RB4=1;         // Define o pino RB1 Do PORTB como entrada.
   
   TRISA.RA4=0;         // Define o pino RA4 do PORTA como saida(Seleção Display 3).
   TRISA.RA5=0;         // Define o pino RA5 do PORTA como saida(Seleção Display 4).

 /* ---------------------- FIM DISPLAY --------------------- */

/*------------------------ TEMPERATURA --------------------- */
   TRISC = 0;
   TRISB = 0;                        // Define PORTB como saida.
   TRISD = 0;                        // Define PORTD como saida.
   TRISC.RC5 = 0;                    // Define PORTC.RC5 como saida.
   TRISE = 0;                        // Define PORTE como saida.

   ADCON0 = 0b00000001;              // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
   ADCON1 = 0b00001100;              // Configura todos canais como Digital menos AN0,AN1 E AN2 e REF Interna.
   ADCON2 = 0b10111110;              // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
 /* --------------------- FIM TEMPERATURA ----------------- */

   // Configuração do Timer0.
   // Cristal de 8Mhz, ciclo de máquina: 8MHz / 4 = 2Mhz --> 1/2Mhz = 0,5us.
   T0CON.T0CS = 0;          // Timer0 operando como temporizador.
   T0CON.PSA = 0;           // Prescaler ativado.
   T0CON.T0PS2 = 1;         // Define prescaler 1:128.
   T0CON.T0PS1 = 1;         // Define prescaler 1:128.
   T0CON.T0PS0 = 0;         // Define prescaler 1:128.
   T0CON.T08BIT = 0;        // Define contagem no modo 16 bits.
   // tempo * 10^6 us = 0,5 * 128 * (65535 - x)
   // Valor para 3s.
   TMR1H = 0x48;            // Carrega o valor alto do número 3036.
   TMR1L = 0xE4;            // Carrega o valor baixo do numero 3036.

   INTCON.TMR0IF = 0;       // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
   T0CON.TMR0ON = 1;        // Liga timer0.

   // Config. LCD no modo 4 bits
   Lcd_Init();                               // Inicializa LCD.
   Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
   Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
   
   Grava_RTC();
   GRAUS();                                  // Armazena simbolo de graus.
   PORTC.RC5 = 0;
   while(1){// Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
      if(INTCON.TMR0IF==1){   // Incrementa somente quando existir o overflow do timer 0.
         // Recarrega o timer0.
         TMR1H = 0x48;           // Carrega o valor alto do número 3036.
         TMR1L = 0xE4;           // Carrega o valor baixo do numero 3036.

         INTCON.TMR0IF = 0;        // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
         Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
         Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
         
         LeEEPROM();   // Le e exibe no LCD os ultimos valores da temperatura da EEPROM
         delay_ms(500); //Deixa na tela as temperaturas por 0.5 segundos
         
         Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
         Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
      }
      
      // Le Tecla.
      if((PORTB.RB3==0)){   // Incrementa somente uma vez quando a tecla for pressionada.
         Lcd_Out(2, 11, "LIGA");                  // Escreve mensagem no LCD.
         cooler = 'l';
         PORTC.RC5 = 1;                            // Liga resistencia de aquecimento.
         delay_ms(2);
      }

      if(cooler == 'l'){
        Lcd_Out(2, 11, "LIGA");
      }

      else if(cooler == 'd'){
        Lcd_Out(2, 11, "DESL");
      }

      // Le tecla e decrementa contador.
      if(PORTB.RB4==0){   // Decrementa somente uma vez quando a tecla for pressionada.
         Lcd_Out(2, 11, "DESL");  // Escreve mensagem no LCD.
         PORTC.RC5 = 0;  // Liga resistencia de aquecimento.
         delay_ms(2);
         cooler = 'd';
      }

      iLeituraAD = ADC_Read(2);          // Lê Canal AD 2
      iLeituraAD/=2;                    // Converte valor do sensor LM35
      Display_LCD();  // Escreve no display lcd o valor
      Leitura_RTC();  // Efetua leitura de segundo, minuto e horas do DS1307
      WordToStr(iLeituraAD, ucTexto);   // Converte o valor lido no A/D em string
      Lcd_Out(1,8,ucTexto);             // Imprime no LCD o valor do Duty Cycle.
      Lcd_Chr_CP(0);                    // Imprime simbolo de graus.
      Lcd_Chr_CP('C');                  // Unidade.

     uiValorLido = iLeituraAD;

     if(uiValor != iLeituraAD){
       uiValor = iLeituraAD;
     }

      uiValorADC = ADC_Read(0);     // Lê Canal AD 0
      uiValorADC=(uiValorADC*0.24);
      PWM1_Set_Duty(uiValorADC);        // Envia o valor lido de "iLeituraAD" para o módulo CCP1 PWM
      uiValorADC=(uiValorADC*0.41);     // Converte valor para o duty cycle em %

      if(uiValorADC > 99){
       uiValorADC = 99;
      }
      // Mostra valor da unidade.
      PORTD = ucMask[uiValorADC%10];              // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
      PORTA.RA5 = 1;                           // Liga o transistor associado ao display 1.
      Delay_ms(2);                             // Delay para escrita no display.
      PORTA.RA5 = 0;                           // Desliga o transistor associado ao display 1.
      uiValorADC/=10;                          // Divide variavel por 10.
      
      // Mostra valor da dezena.
      PORTD = ucMask[uiValorADC%10];
      PORTA.RA4 = 1;
      Delay_ms(2);
      PORTA.RA4 = 0;
      uiValorADC/=10;

      if(uiValorLido > 40){
        PWM1_Init(5000);      // Inicializa módulo PWM com 5Khz
        PWM1_Start();         // Start PWM
        iLeituraAD= ADC_Read(0);          // Lê Canal AD 0
        iLeituraAD=(iLeituraAD*0.24);     // Converte valor para o duty cycle [255/(1023 pontos do A/D)]
        PWM1_Set_Duty(iLeituraAD);   // Envia o valor lido de "uiValorAD" para o módulo CCP1 pwm
        Delay_10us;
        PORTC.RC1 = 0;
      }
      else{
        PORTC.RC1 = 1;
        PWM1_STOP();
      }

      if(uiValorLido != valorLidoAnt){
        valorLidoAnt = uiValorLido;
        GravaEEPROM(ucContador);
        ucContador += 3;
        if(ucContador > 16){
          ucContador = 0;
        }
      }
   }
}
void GRAUS() {
  char i;
  const char character[] = {7,5,7,0,0,0,0,0};   // ARMAZENA SIMBOLO DE GRAUS.
  Lcd_Cmd(64);
  for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
}

void GravaEEPROM(int ucContador){
  int uiaux;
  // Grava o valor da dezena
  EEPROM_Write(ucContador,0x30+uiValorLido/10);   // Grava na EEPROM valores de 0 a 10 em ASCII.
  uiaux = uiValorLido%10;  //Divide por 10
  // Grava o valor da unidade
  EEPROM_Write(ucContador+1,0x30+uiaux);   // Grava na EEPROM valores de 0 a 10 em ASCII.
}

void LeEEPROM(){
  int ucContador;
  Lcd_Out(1,1,"Lido da EEPROM ");      // Mostra o estado no LCD.
  for(ucContador=0;ucContador<15;ucContador++){
      Lcd_Chr(2,ucContador+1,EEPROM_Read(ucContador));      // Le na EEPROM valores .
      Delay_ms(100);
   }
}

// Rotina de conversão de dados para BCD
void Converte_BCD(unsigned char ucLinha, unsigned char ucColuna,unsigned char ucValor) {
  unsigned char ucValor1, ucValor2;

  ucValor1 = (ucValor >> 4  ) + '0';    // Converte o primeiro nibble em BCD e após em string
  Lcd_Chr(ucLinha,ucColuna,ucValor1);   // Escreve caractere no LCD
  ucValor2 = (ucValor & 0x0F) + '0';    // Converte o segundo nibble em BCD e após isso, em string
  Lcd_Chr_CP(ucValor2);                 // Escreve caractere no LCD
}

void Leitura_RTC() {          // Rotina de leitura do DS1307
   I2C1_Start();              // Inicializa comunicação i2c
   I2C1_Wr(0xD0);             // End. fixo para DS1307: 1101000X, onde x = 0 é para gravação
   I2C1_Wr(0);                // End. onde começa a programação do relógio, end dos segundos.
   I2C1_Repeated_Start();     // Issue I2C signal repeated start
   I2C1_Wr(0xD1);             // End. fixo para DS1307: 1101000X, onde x=1 é para leitura
   ucSegundo = I2C1_Rd(1);    // Lê o primeiro byte(segundos),informa que continua lendo
   ucMinuto = I2C1_Rd(1);     // Lê o segundo byte(minutos)
   ucHora = I2C1_Rd(1);       // Lê o terceiro byte(horas)
   ucDia_Semana = I2C1_Rd(1);
   ucDia = I2C1_Rd(1);
   ucMes = I2C1_Rd(1);
   ucAno = I2C1_Rd(0);        // Lê o sétimo byte(ano),encerra as leituras de dados
   I2C1_Stop();               // Finaliza comunicação I2C
}

void Grava_RTC(){
   I2C1_Init(100000);     // Iniciliza I2C com frequencia de 100KHz
   I2C1_Start();          // Inicializa a comunicação I2c
   I2C1_Wr(0xD0);         // End. fixo para DS1307: 1101000X, onde x = 0 é para gravação
   I2C1_Wr(0);            // End. onde começa a programação do relógio, end. dos segundos.
   I2C1_Wr(0x00);         // Inicializa com 00 segundos.
   I2C1_Wr(0x00);         // Inicializa com 00 minutos.
   I2C1_Wr(0x21);         // Inicializa com 21:00hs (formato 24 horas).
   I2C1_Wr(0x04);         // Inicializa com dia 04
   I2C1_Wr(0x07);         // Inicializa com mês 07
   I2C1_Wr(0x17);         // Inicializa com ano 17
   I2C1_Stop();           // Finaliza comunicação I2C
}

void Display_LCD() {
   //Lcd_Out(1,1,"(Hora)");
   Converte_BCD(1,1,ucHora);     // Conversão da variável horas para BCD
   Lcd_Chr_CP(':');              // Escreve no display LCD
   Converte_BCD(1,4,ucMinuto);  // Conversão da variável minuto para BCD
   Lcd_Chr_CP(':');              // Escreve no display LCD
   Converte_BCD(1,7,ucSegundo); // Conversão da variável segundo para BCD
   //Lcd_Out(2,1,"(Data)");
   Converte_BCD(2,1,ucDia);      // Conversão da variável dia para BCD
   Lcd_Chr_CP('/');              // Escreve no display LCD
   Converte_BCD(2,4,ucMes);     // Conversão da variável mes para BCD
   Lcd_Chr_CP('/');              // Escreve no display LCD
   Converte_BCD(2,7,ucAno);     // Conversão da variável ano para BCD
}