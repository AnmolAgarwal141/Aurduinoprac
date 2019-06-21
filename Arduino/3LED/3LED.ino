int ledpin[]={6,8,13};
int b[20];
boolean k;
String input;
int a;
int d;
int min1;
int min2,r,t,y;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin[0],OUTPUT);
pinMode(ledpin[1],OUTPUT);
pinMode(ledpin[2],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 

 if(Serial.available()>0)
       { d=0;
 b[0]=0; 
        input =Serial.readString();
        
        for(int i=0;input[i]!='\0';i++)
        {
         if(input[i]>='0'&&input[i]<='9')
             { a=int(input[i])-'0';
               b[d]=b[d]*10+a;  
             }  
         if(input[i]==';')    
          { 
          d++;
          b[d]=0;
          }
         }         
 
    if(b[0]!=b[1]&&b[1]!=b[2]&&b[0]!=b[2])
    {
           min1 = b[0];
           r=0;
    for (int i = 0; i < 3; i++)
    {
        if (b[i] < min1)
        {
            min1=b[i];
            r=i;
        }
     }
     t=0;
       min2 = 1000;
    for (int i = 0; i < 3; i++) 
    {
        if (b[i] <min2 && b[i]> min1)
           { min2 = b[i];
            t=i;
           }
    }
        for(int i=0;i<3;i++)
        {
          if(i!=r&&i!=t)
          y=i;
        }
           Serial.print(b[r]);
    Serial.print(" ");
    Serial.print(b[t]-b[r]);
    Serial.print(" ");
    Serial.println(b[y]-b[t]);
    digitalWrite(ledpin[0],HIGH);
    digitalWrite(ledpin[1],HIGH);
    digitalWrite(ledpin[2],HIGH);
    delay(b[r]*1000);
    digitalWrite(ledpin[r],LOW);
    delay((b[t]-b[r])*1000);
    digitalWrite(ledpin[t],LOW);
    delay((b[y]-b[t])*1000);  
    digitalWrite(ledpin[y],LOW); 
    }
    else if((b[0]==b[1]||b[1]==b[2]||b[0]==b[2])&&(b[0]!=b[1]!=b[2]))
    {  min1 = b[0];
           r=0;
    for (int i = 0; i < 3; i++)
    {
        if (b[i] < min1)
        {
            min1=b[i];
            r=i;
        }
     }
     t=0;
       min2 = 1000;
    for (int i = 0; i < 3; i++) 
    {  if(i!=r)
       { if (b[i] <=min2 && b[i]>= min1)
           { min2 = b[i];
            t=i;
           }
       }
    }
        for(int i=0;i<3;i++)
        {
          if(i!=r&&i!=t)
          y=i;
        }
    
           Serial.print(b[r]);
    Serial.print(" ");
    Serial.print(b[t]-b[r]);
    Serial.print(" ");
    Serial.println(b[y]-b[t]);
    digitalWrite(ledpin[0],HIGH);
    digitalWrite(ledpin[1],HIGH);
    digitalWrite(ledpin[2],HIGH);
    delay(b[r]*1000);
    digitalWrite(ledpin[r],LOW);
    delay((b[t]-b[r])*1000);
    digitalWrite(ledpin[t],LOW);
    delay((b[y]-b[t])*1000);  
    digitalWrite(ledpin[y],LOW); 
    }
    else
    {r=0;t=1;y=2;
   
    Serial.print(b[r]);
    Serial.print(" ");
    Serial.print(b[t]-b[r]);
    Serial.print(" ");
    Serial.println(b[y]-b[t]);
    digitalWrite(ledpin[0],HIGH);
    digitalWrite(ledpin[1],HIGH);
    digitalWrite(ledpin[2],HIGH);
    delay(b[r]*1000);
    digitalWrite(ledpin[r],LOW);
    delay((b[t]-b[r])*1000);
    digitalWrite(ledpin[t],LOW);
    delay((b[y]-b[t])*1000);  
    digitalWrite(ledpin[y],LOW);  
       }
     
   
}}
//          if(input[i]>='0'&&input[i]<='9')

