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
    
 /* Serial.println(input);
  }
  if(input=='H')
    {
      digitalWrite(9,HIGH);
      
    }
    else if(input=='L')
    {
      digitalWrite(9,LOW);
      
    }
    else if(input=='X')
    {
      digitalWrite(9,HIGH);
      delay(1000);
      digitalWrite(9,LOW);
    }
   */ 
while(Serial.available())
  {
  BTSerial.write(Serial.read());
  }
}
