
#include <EEPROM.h>
int parteInteira;
int j=1;
int parteDecimal;
float parteDecimal2;
float numero;
float media;
float total=0;
const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
int inte=0;
void setup(){
Serial.begin(9600);
analogReference(INTERNAL1V1);
//Se estiver usando Arduino Mega, use INTERNAL1V1
//se estiver usando Arduino Leonardo, remova esta linha pois o Leonardo não aceita
//este comando
}
void loop(){
  if(inte == 0){
    for(int i=0;i<40;i++){
      ADClido = analogRead(LM35);
      temperatura = ADClido * 0.1075268817; //no Leonardo use 0.4887585532
      Serial.print("temperatura[");
      Serial.print(j);
      Serial.print("] = ");
      Serial.println(temperatura);
    
      parteInteira = (int) temperatura;
      parteDecimal = (int) ((temperatura-parteInteira)*100);
      EEPROM.write(i, parteInteira);
      i++;
      EEPROM.write(i, parteDecimal);
      j++;
      delay(500);
    }
    j=1;
    for(int i=0;i<40;i++){
      parteInteira = EEPROM.read(i);
      i++;
      parteDecimal = EEPROM.read(i);
      parteDecimal2=(float)parteDecimal/100;
      numero = parteInteira +parteDecimal2;
      Serial.print("leitura[");
      Serial.print(j);
      Serial.print("] = ");
      Serial.println(numero);
       j++;
    }
    j=1;
inte = 1;
  }
    
  else{}

}
