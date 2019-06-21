#include<Wire.h>
#define TO_READ (6)
byte buff[TO_READ];
char str[512];
void setup() {
  // put your setup code here, to run once:
Wire.begin();
Serial.begin(9600);
writeTo(0x53,0x2D,0);
writeTo(0x53,0x2D,16);
writeTo(0x53,0x2D,8);
writeTo(0x53,0x31,3);
}
void writeTo(int DEVICE,byte address,byte val)
{
  Wire.beginTransmission(DEVICE);
  Wire.write(address);
  Wire.write(val);
  Wire.endTransmission();
  
}

void loop() {
  // put your main code here, to run repeatedly:
int regAddress=0x32;
int x,y,z;
readFrom(0x53,regAddress,TO_READ,buff);
x=(((int)buff[1])<<8)|buff[0];
y=(((int)buff[3])<<8)|buff[2];
z=(((int)buff[5])<<8)|buff[4];
sprintf(str,"%d %d %d",x,y,z);
Serial.print(str);
Serial.write(byte(10));
delay(100);
}
void readFrom(int DEVICE,byte address,int num,byte buff[])
{
  Wire.beginTransmission(DEVICE);
  Wire.write(address);
  Wire.endTransmission();
  Wire.beginTransmission(DEVICE);
  Wire.requestFrom(DEVICE,num);
  int i=0;
  while(Wire.available())
  {buff[i]=Wire.read();
  i++;}
  Wire.endTransmission();
}
