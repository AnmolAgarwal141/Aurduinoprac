int ledpin1=6;
int ledpin2=8;
int ledpin3=13;
int b[20];
boolean k;
String input;
int a;
int d;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin1,OUTPUT);
pinMode(ledpin2,OUTPUT);
pinMode(ledpin3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//    digitalWrite(ledpin1,LOW);
//    digitalWrite(ledpin2,LOW);
//    digitalWrite(ledpin3,LOW);  
 d=0;

 if(Serial.available()>0)
       {  
        input =Serial.readString();
        
        for(int i=0;input[i]!='\0';i++)
        {
         if(input[i-1]==':')
             { a=int(input[i])-'0';
               b[d]=b[d]*10+a;  
             }  
         if(input[i]==';')    
          { 
          d++;
          b[d]=0;
          }
         }
            for(int i=0;i<2;i++)
    {
      for(int j=0;j<2-i;j++)
      {
        if(b[j]>b[j+1])
        {
          int temp=b[j];
          b[j]=b[j+1];
          b[j+1]=temp;
        }
      }
    }
    Serial.print(b[0]);
    Serial.print(" ");
    Serial.print(b[1]-b[0]);
    Serial.print(" ");
    Serial.println(b[2]-b[1]);
    digitalWrite(ledpin1,HIGH);
    digitalWrite(ledpin2,HIGH);
    digitalWrite(ledpin3,HIGH);
    delay(b[0]*1000);
    digitalWrite(ledpin1,LOW);
    delay((b[1]-b[0])*1000);
    digitalWrite(ledpin2,LOW);
    delay((b[2]-b[1])*1000);  
    digitalWrite(ledpin3,LOW);   

       }
}

