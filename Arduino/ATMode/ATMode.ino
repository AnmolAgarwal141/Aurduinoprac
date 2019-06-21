#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10,11);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
BTSerial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
while(BTSerial.available())
  {
  Serial.write(BTSerial.read());  
  
  }
while(Serial.available())
  {
  BTSerial.write(Serial.read());
  }
}
