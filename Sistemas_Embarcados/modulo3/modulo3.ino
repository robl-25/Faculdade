const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int Botao1 = 2;
const int Botao2 = 3;
const int Botao3 = 4;
const int Buzzer = 10; //O buzzer está colocado no pino 10
int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;
int Tom = 0; //Variavel para armazenar a nota musical

int cont = 0;
void setup() {
  pinMode(Buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(Botao1, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(Botao2, INPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(Botao3, INPUT);
}
unsigned long TempoAtual;
void loop() {
  EstadoBotao1 = digitalRead(Botao1);
  EstadoBotao2 = digitalRead(Botao2);
  EstadoBotao3 = digitalRead(Botao3);
   
  if (EstadoBotao1 && !EstadoBotao2 && !EstadoBotao3) {
    Tom = 100;
    cont++;
    digitalWrite(ledPin1, HIGH);
    delay(200);
     TempoAtual = millis();
  }
  if (EstadoBotao2 && !EstadoBotao1 && !EstadoBotao3) {
    Tom = 200;
    cont++;
    digitalWrite(ledPin2, HIGH);
    delay(200);
     TempoAtual = millis();
  }
  if (EstadoBotao3 && !EstadoBotao2 && !EstadoBotao1) {
    Tom = 500;
    cont++;
    digitalWrite(ledPin3, HIGH);
    delay(200);
     TempoAtual = millis();
  }

  //Lógica de verificação do tempo
  if ((millis() - TempoAtual) >= 2000) { //atraso = 2000
    //tempoAnterior = TempoAtual;    // Salva o tempo atual
    for(int i=0 ; i<cont; i++){
      if (Tom > 0) { //enquanto Tom for maior que zero faça o que esta descrit o baixo:
        digitalWrite(Buzzer, HIGH); // Liga buzzer
        delayMicroseconds(500); // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
        delay(200);
        digitalWrite(Buzzer, LOW); // Desliga buzzer
        delayMicroseconds(500); // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
        delay(200);
     }
    }
    cont=0;
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
  
  /*
  if (Tom > 0) { //enquanto Tom for maior que zero faça o que esta descrit o baixo:
    digitalWrite(Buzzer, HIGH); // Liga buzzer
    delayMicroseconds(Tom); // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
    digitalWrite(Buzzer, LOW); // Desliga buzzer
    delayMicroseconds(Tom); // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
    Tom = 0; // Reseta o Tom para zero, para sair do loop while e nao tocar o som constantemente
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }*/
}
