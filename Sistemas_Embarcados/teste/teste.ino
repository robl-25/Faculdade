#define DIG 3

const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int Botao1 = 2;
const int Botao2 = 3;
const int Botao3 = 4;
int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;
char senha[DIG];
char senhaCorreta[DIG] = {'d', 'm', 'a'}; //verDe, verMelho, Amarelo
int cont;

void setup(){
    Serial.begin(9600);
    pinMode(ledPin1, OUTPUT);
    pinMode(Botao1, INPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(Botao2, INPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(Botao3, INPUT);
    cont = 0;
}
void loop(){

      if(cont == DIG){
          int i, ok = 0;
  
          Serial.println("Saiu da leitura");
          for(i=0; i<DIG; i++){
              Serial.print(senha[i]);
              if(senha[i] == senhaCorreta[i]){
                  ok++;
              }
          }
          if(ok == DIG){
            delay(100);
            digitalWrite(ledPin1,LOW);
            digitalWrite(ledPin2,LOW);
            digitalWrite(ledPin3,LOW);
            delay(100);
            digitalWrite(ledPin1,HIGH);
            digitalWrite(ledPin2,HIGH);
            digitalWrite(ledPin3,HIGH);
            delay(100);
          }
          else{
              cont = 0;
          }
        }
      if(cont > 3){
          cont = 0;
      }
      
      EstadoBotao1 = digitalRead(Botao1);
      EstadoBotao2 = digitalRead(Botao2);
      EstadoBotao3 = digitalRead(Botao3);
      
      if (EstadoBotao1 == HIGH){
          digitalWrite(ledPin1, HIGH);
          delay(100);
          senha[cont] = 'm';
          delay(100);
          cont++;
          delay(100);
      }
      else{
          digitalWrite(ledPin1, LOW);
      }
      if (EstadoBotao2 == HIGH){
          digitalWrite(ledPin3, HIGH);
          delay(100);
          senha[cont] = 'a';
          delay(100);
          cont++;
          delay(100);
      }
      else{
          digitalWrite(ledPin3, LOW);
      }
      if (EstadoBotao3 == HIGH){
          digitalWrite(ledPin2, HIGH);
          delay(100);
          senha[cont] = 'd';
          delay(100);
          cont++;
          delay(100);
      }
      else{
          digitalWrite(ledPin2, LOW);
      }
}


