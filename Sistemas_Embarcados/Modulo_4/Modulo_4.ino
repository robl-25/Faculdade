
const int PinoPotenciometro = A0;
int ValorPot = 0;
const int LED[] = {2,3,4,5,6,7,8,9,10,11};
const int Buzzer = 12;
int Tom = 0;

void setup() {
  pinMode(Buzzer, OUTPUT);
  for (int x = 0; x < 10; x++) {
    pinMode(LED[x], OUTPUT);
  }
}
void loop() {
  ValorPot = analogRead(PinoPotenciometro);

  for(int i=0; i<10; i++){
    if(i < map(ValorPot, 0, 1023, 0, 10)){
      digitalWrite(LED[i], HIGH);
    }
    else{
      digitalWrite(LED[i], LOW);
    }
  }
  tone(Buzzer, ValorPot);
}
