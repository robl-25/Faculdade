#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int botaoEsquerda = 6;
const int botaoBack = 7;
const int botaoEnter = 8;
const int botaoDireita = 9;

int EstadobotaoEsquerda = 0;
int EstadobotaoEnter = 0;
int EstadobotaoBack = 0;
int EstadobotaoDireita = 0;


int botaoEsquerdaP = 0;
int botaoEnterP = 0;
int botaoBackP = 0;
int botaoDireitaP = 0;

int opcao = 0;
int opcaoMenu = 0;
int subMenu = 0;

String menu[] = {"Opcao 1", "Opcao 2", "Opcao 3", "Opcao 4"};
String subMenu1[] = {"Opcao 1.1", "Opcao 1.2", "Opcao 1.3", "Opcao 1.4"};
String subMenu2[] = {"Opcao 2.1", "Opcao 2.2", "Opcao 2.3", "Opcao 2.4"};
String subMenu3[] = {"Opcao 3.1", "Opcao 3.2", "Opcao 3.3", "Opcao 3.4"};
String subMenu4[] = {"Opcao 4.1", "Opcao 4.2", "Opcao 4.3", "Opcao 4.4"};


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(botaoEsquerda, INPUT);
}
void loop() {

 EstadobotaoEsquerda = digitalRead(botaoEsquerda);
 EstadobotaoDireita = digitalRead(botaoDireita);
 EstadobotaoEnter = digitalRead(botaoEnter);
 EstadobotaoBack = digitalRead(botaoBack);

  Serial.println(opcao);
  //verificador de opcoes

  if(opcao == 0){
    if (opcaoMenu == 0){
      lcd.setCursor(0,0);
      lcd.print(menu[opcao]+" *");
      lcd.setCursor(0,1);
      lcd.print(menu[opcao+1]);
    }
    else if(opcaoMenu == 1){
      lcd.setCursor(0,0);
      lcd.print(subMenu1[opcao]+" *");
      lcd.setCursor(0,1);
      lcd.print(subMenu1[opcao+1]);
    }
    else if(opcaoMenu == 2){
      lcd.setCursor(0,0);
      lcd.print(subMenu2[opcao]+" *");
      lcd.setCursor(0,1);
      lcd.print(subMenu2[opcao+1]);
    }
    else if(opcaoMenu == 3){
      lcd.setCursor(0,0);
      lcd.print(subMenu3[opcao]+" *");
      lcd.setCursor(0,1);
      lcd.print(subMenu3[opcao+1]);
    }
    else if(opcaoMenu == 4){
      lcd.setCursor(0,0);
      lcd.print(subMenu4[opcao]+" *");
      lcd.setCursor(0,1);
      lcd.print(subMenu4[opcao+1]);
    }
    
  }
  else{
    if(opcaoMenu == 0){
      lcd.setCursor(0,0);
      lcd.print(menu[opcao-1]);
      lcd.setCursor(0,1);
      lcd.print(menu[opcao]+" *");
     }
     else if(opcaoMenu == 1){
      lcd.setCursor(0,0);
      lcd.print(subMenu1[opcao-1]);
      lcd.setCursor(0,1);
      lcd.print(subMenu1[opcao]+" *");
     }
     else if(opcaoMenu == 2){
      lcd.setCursor(0,0);
      lcd.print(subMenu2[opcao-1]);
      lcd.setCursor(0,1);
      lcd.print(subMenu2[opcao]+" *");
     }
     else if(opcaoMenu == 3){
      lcd.setCursor(0,0);
      lcd.print(subMenu3[opcao-1]);
      lcd.setCursor(0,1);
      lcd.print(subMenu3[opcao]+" *");
     }
     else if(opcaoMenu == 4){
      lcd.setCursor(0,0);
      lcd.print(subMenu4[opcao-1]);
      lcd.setCursor(0,1);
      lcd.print(subMenu4[opcao]+" *");
     }
  }

 if (EstadobotaoEsquerda == 1){
   botaoEsquerdaP++;
 }
 else{
   botaoEsquerdaP = 0; 
 }

  if (EstadobotaoDireita == 1){
   botaoDireitaP++;
 }
 else{
   botaoDireitaP = 0; 
 }

  if (EstadobotaoEnter == 1){
   botaoEnterP++;
  }
 else{
   botaoEnterP = 0; 
 }

  if (EstadobotaoBack == 1){
   botaoBackP++;
 }
 else{
   botaoBackP = 0; 
 }
 
 if (botaoEsquerdaP == 1){ //soma o status - botao left
  lcd.clear();
  if (opcao == 3){
    opcao = 0;
  }
  else{
    opcao++;
  }
 }
 if (botaoDireitaP == 1){ //volta o status - botao right
  lcd.clear();
  if (opcao == 0){
    opcao = 3;  
  }
  else{
    opcao--;  
  }
 }
 if (botaoEnterP == 1){ //botao enter - entra no prox menu se tiver no menu 0
  if (opcaoMenu == 0){ // entra no menu
    lcd.clear();
    opcaoMenu = opcao+1;
    opcao = 0;
  }
 }
 if (botaoBackP == 1){
  if (opcaoMenu > 0){ // entra no menu
    lcd.clear();
    opcaoMenu = 0;
    opcao = 0;
  }
 }
} 
