int ledpin=6;
int level=0;
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledpin,HIGH);
if(level<256)
{level=level+51;
analogWrite(ledpin,level);}
else
digitalWrite(ledpin,LOW);
level=0;
delay(2000);
}
