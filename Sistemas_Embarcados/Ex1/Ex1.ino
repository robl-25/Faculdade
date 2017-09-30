#include <EEPROM.h>
int address = 0;
byte value;
int addr = 0;

void setup() {
    Serial.begin(9600);
    for(int i = 0 ; i < EEPROM.length() ; i++) {
        EEPROM.write(i, 0);
    }
}

void loop() {
    int val = 255;
    EEPROM.write(addr, val);
    addr = addr + 1;
    if (addr == EEPROM.length()) {
      addr = 0;
    }
    
    value = EEPROM.read(address);
  
    Serial.print(address);
    Serial.print("\t");
    Serial.print(value, DEC);
    Serial.println();
    address = address + 1;
    if (address == EEPROM.length()) {
      address = 0;
    }
  
    delay(5);
}
