int ledpin=6;
String input;
int a;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
         int b=0;
         if(Serial.available()>0)
       { 
         input =Serial.readString();
         for(int i=0;input[i]!='\0';i++)
             { a=int(input[i])-'0';
                b=b*10+a; 
             }          
      digitalWrite(ledpin,HIGH);
      Serial.println(b);
      delay(b*1000);
       }

    digitalWrite(ledpin,LOW);
}

