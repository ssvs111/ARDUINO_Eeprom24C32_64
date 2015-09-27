#include <Wire.h>
#include <Eeprom24C32_64.h>
static Eeprom24C32_64 AT24C32(0x57);
unsigned int  moneyCoin = 35799;
unsigned long  money = 0;
unsigned long  mo = 869647496;
byte inputBytes[94] = { 0 };
byte outputBytes[94] = { 0 };

void setup()
{
  for (byte i = 0; i < 94; i++) {
    inputBytes[i] = i + 33;
  }
  Serial.begin(9600);
  AT24C32.initialize();

  Serial.println("Write bytes to EEPROM memory...");
  AT24C32.writeEE(0, inputBytes);
  AT24C32.writeEE(200, mo);
  

  Serial.println("Read bytes from EEPROM memory...");
  
  AT24C32.readEE(0, outputBytes);
  
  Serial.println("Read bytes:");
  for (byte i = 0; i < 94; i++) {

    Serial.write(outputBytes[i]);
    Serial.print(" ");
  }
  Serial.println("");

  Serial.println("");
  AT24C32.readEE(200, money);
  
  Serial.println(money);
}


void loop() {}
