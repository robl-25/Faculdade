#line 1 "G:/Mari/Faculdade/Sistemas_Embarcados/Projeto_Final/MyProject.c"
#line 27 "G:/Mari/Faculdade/Sistemas_Embarcados/Projeto_Final/MyProject.c"
unsigned char ucHora;
unsigned char ucMinuto;
unsigned char ucSegundo;
unsigned char ucDia;
unsigned char ucMes;
unsigned char ucAno;
unsigned char ucDia_Semana;
unsigned char ucTexto[10];
unsigned int iLeituraAD = 0;
char *ucTexto2;
unsigned int uiValorADC = 0;
unsigned int uiValorLido = 0;


void GRAUS();
void Display_LCD();
void Encontra_Dia_Semana();
void Grava_RTC();
void Leitura_RTC();
void Converte_BCD(unsigned char ucLinha, unsigned char ucColuna,unsigned char ucValor);
void GravaEEPROM(int ucContador);
void LeEEPROM();


sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;


sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;



void main(){


 unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
#line 74 "G:/Mari/Faculdade/Sistemas_Embarcados/Projeto_Final/MyProject.c"
 unsigned int uiValor;
 int ucContador = 0;
 char cooler = 'd';
 int uiValorADCAnt = 0;
 int valorLidoAnt = 0;

 TRISB.RB3=1;
 TRISB.RB4=1;

 TRISA.RA4=0;
 TRISA.RA5=0;




 TRISC = 0;
 TRISB = 0;
 TRISD = 0;
 TRISC.RC5 = 0;
 TRISE = 0;

 ADCON0 = 0b00000001;
 ADCON1 = 0b00001100;
 ADCON2 = 0b10111110;




 T0CON.T0CS = 0;
 T0CON.PSA = 0;
 T0CON.T0PS2 = 1;
 T0CON.T0PS1 = 1;
 T0CON.T0PS0 = 0;
 T0CON.T08BIT = 0;


 TMR1H = 0x48;
 TMR1L = 0xE4;

 INTCON.TMR0IF = 0;
 T0CON.TMR0ON = 1;


 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);

 Grava_RTC();
 GRAUS();
 PORTC.RC5 = 0;
 while(1){
 if(INTCON.TMR0IF==1){

 TMR1H = 0x48;
 TMR1L = 0xE4;

 INTCON.TMR0IF = 0;
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);

 LeEEPROM();
 delay_ms(500);

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 }


 if((PORTB.RB3==0)){
 Lcd_Out(2, 11, "LIGA");
 cooler = 'l';
 PORTC.RC5 = 1;
 delay_ms(2);
 }

 if(cooler == 'l'){
 Lcd_Out(2, 11, "LIGA");
 }

 else if(cooler == 'd'){
 Lcd_Out(2, 11, "DESL");
 }


 if(PORTB.RB4==0){
 Lcd_Out(2, 11, "DESL");
 PORTC.RC5 = 0;
 delay_ms(2);
 cooler = 'd';
 }

 iLeituraAD = ADC_Read(2);
 iLeituraAD/=2;
 Display_LCD();
 Leitura_RTC();
 WordToStr(iLeituraAD, ucTexto);
 Lcd_Out(1,8,ucTexto);
 Lcd_Chr_CP(0);
 Lcd_Chr_CP('C');

 uiValorLido = iLeituraAD;

 if(uiValor != iLeituraAD){
 uiValor = iLeituraAD;
 }

 uiValorADC = ADC_Read(0);
 uiValorADC=(uiValorADC*0.24);
 PWM1_Set_Duty(uiValorADC);
 uiValorADC=(uiValorADC*0.41);

 if(uiValorADC > 99){
 uiValorADC = 99;
 }

 PORTD = ucMask[uiValorADC%10];
 PORTA.RA5 = 1;
 Delay_ms(2);
 PORTA.RA5 = 0;
 uiValorADC/=10;


 PORTD = ucMask[uiValorADC%10];
 PORTA.RA4 = 1;
 Delay_ms(2);
 PORTA.RA4 = 0;
 uiValorADC/=10;

 if(uiValorLido > 40){
 PWM1_Init(5000);
 PWM1_Start();
 iLeituraAD= ADC_Read(0);
 iLeituraAD=(iLeituraAD*0.24);
 PWM1_Set_Duty(iLeituraAD);
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
 const char character[] = {7,5,7,0,0,0,0,0};
 Lcd_Cmd(64);
 for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
}

void GravaEEPROM(int ucContador){
 int uiaux;

 EEPROM_Write(ucContador,0x30+uiValorLido/10);
 uiaux = uiValorLido%10;

 EEPROM_Write(ucContador+1,0x30+uiaux);
}

void LeEEPROM(){
 int ucContador;
 Lcd_Out(1,1,"Lido da EEPROM ");
 for(ucContador=0;ucContador<15;ucContador++){
 Lcd_Chr(2,ucContador+1,EEPROM_Read(ucContador));
 Delay_ms(100);
 }
}


void Converte_BCD(unsigned char ucLinha, unsigned char ucColuna,unsigned char ucValor) {
 unsigned char ucValor1, ucValor2;

 ucValor1 = (ucValor >> 4 ) + '0';
 Lcd_Chr(ucLinha,ucColuna,ucValor1);
 ucValor2 = (ucValor & 0x0F) + '0';
 Lcd_Chr_CP(ucValor2);
}

void Leitura_RTC() {
 I2C1_Start();
 I2C1_Wr(0xD0);
 I2C1_Wr(0);
 I2C1_Repeated_Start();
 I2C1_Wr(0xD1);
 ucSegundo = I2C1_Rd(1);
 ucMinuto = I2C1_Rd(1);
 ucHora = I2C1_Rd(1);
 ucDia_Semana = I2C1_Rd(1);
 ucDia = I2C1_Rd(1);
 ucMes = I2C1_Rd(1);
 ucAno = I2C1_Rd(0);
 I2C1_Stop();
}

void Grava_RTC(){
 I2C1_Init(100000);
 I2C1_Start();
 I2C1_Wr(0xD0);
 I2C1_Wr(0);
 I2C1_Wr(0x00);
 I2C1_Wr(0x00);
 I2C1_Wr(0x21);
 I2C1_Wr(0x04);
 I2C1_Wr(0x07);
 I2C1_Wr(0x17);
 I2C1_Stop();
}

void Display_LCD() {

 Converte_BCD(1,1,ucHora);
 Lcd_Chr_CP(':');
 Converte_BCD(1,4,ucMinuto);
 Lcd_Chr_CP(':');
 Converte_BCD(1,7,ucSegundo);

 Converte_BCD(2,1,ucDia);
 Lcd_Chr_CP('/');
 Converte_BCD(2,4,ucMes);
 Lcd_Chr_CP('/');
 Converte_BCD(2,7,ucAno);
}
