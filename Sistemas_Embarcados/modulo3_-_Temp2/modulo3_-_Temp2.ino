const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
const int LED[] = {
 2,3,4,5,6,7,8,9,10,11};
void setup(){
  Serial.begin(9600);
 analogReference(INTERNAL1V1); //No Mega, use INTERNAL1V1, no Leonardo remova essa linha
 for(int x = 0; x < 10; x++){
 pinMode(LED[x], OUTPUT);
 }
}
void loop(){
 ADClido = analogRead(LM35);
 temperatura = ADClido * 0.1075268817204301; //no Leonardo use 0.4887585532
 Serial.println(temperatura);
 if(temperatura > 25.50){
 digitalWrite(LED[0], HIGH);
 }
 else{
 digitalWrite(LED[0], LOW);
 }
 if(temperatura > 25.75){
 digitalWrite(LED[1], HIGH);
 }
 else{
 digitalWrite(LED[1], LOW);
 }
 if(temperatura > 26){
 digitalWrite(LED[2], HIGH);
 }
 else{
 digitalWrite(LED[2], LOW);
 }
 if(temperatura > 26.25){
 digitalWrite(LED[3], HIGH);
 }
 else{
 digitalWrite(LED[3], LOW);
 }
 if(temperatura > 26.50){
 digitalWrite(LED[4], HIGH);
 }
 else{
 digitalWrite(LED[4], LOW);
 }
 if(temperatura > 26.75){
 digitalWrite(LED[5], HIGH);
 }
 else{
 digitalWrite(LED[5], LOW);
 }
 if(temperatura > 27){
 digitalWrite(LED[6], HIGH);
 }
 else{
 digitalWrite(LED[6], LOW);
 }
 if(temperatura > 27.25){
 digitalWrite(LED[7], HIGH);
 }
 else{
 digitalWrite(LED[7], LOW);
 }
 if(temperatura > 27.50){
 digitalWrite(LED[8], HIGH);
 }
 else{
 digitalWrite(LED[8], LOW);
 }
 if(temperatura > 27.75){
 digitalWrite(LED[9], HIGH);
 }
 else{
 digitalWrite(LED[9], LOW);
 }
 if(temperatura > 28){
      delay(200);
      int i;
      for(i=0; i<10; i++){
          digitalWrite(LED[i], LOW);
      }
      for(i=0; i<9; i++){
          digitalWrite(LED[i], HIGH);
          digitalWrite(LED[i+1], HIGH);
          delay(200);
          digitalWrite(LED[i], LOW);
          digitalWrite(LED[i+1], LOW);
      }
      for(i=9; i>-1; i--){
          digitalWrite(LED[i], HIGH);
          digitalWrite(LED[i-1], HIGH);
          delay(200);
          digitalWrite(LED[i], LOW);
          digitalWrite(LED[i-1], LOW);
      }
 }
}
