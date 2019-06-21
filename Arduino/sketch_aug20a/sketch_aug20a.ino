char data;
int ledpin=12;
int key=6;
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
pinMode(key,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write(data);
  if(data==h)
  digitalWrite(ledpin,HIGH);
  if(data==l)
  digitalWrite(ledpin,LOW);
  if(data==k)
  {
    digitalWrite(ledpin,HIGH);
    delay(1000);
    digitalWrite(ledpin,LOW);
  }
    
  }
  

}
