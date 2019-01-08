int digpin=2;
int pulse=0;
int timetk;
boolean lastpin=LOW;
int rpm;
void counter()
{
  pulse++;
}
  void setup() {

  // put your setup code here, to run once:
pinMode(digpin,INPUT);
timetk=0;
attachInterrupt(digitalPinToInterrupt(lastpin),counter,HIGH);
}

void loop() {
  
 if(millis()-timetk>=1000)
{detachInterrupt(lastpin);
rpm=60*(pulse-1)/2;
timetk=millis();
pulse=0;
}
attachInterrupt(digitalPinToInterrupt(lastpin),counter,CHANGE);
//take input as low always when the hole is find it will read input as high
}
