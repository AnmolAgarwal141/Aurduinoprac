#include<Wire.h>

void setup() {
  // put your setup code here, to run once:
Wire.begin();
Serial.begin(9600);
writeTo(0x76,0xF3,8);
}
void writeTo(int DEVICE,byte address,byte val)
{
  Wire.beginTransmission(DEVICE);
  Wire.write(address);
  Wire.write(val);
  Wire.endTransmission();
  
}
void loop()
{ 
  unsigned int b1[24];
  unsigned int data[8];
  for (int i = 0; i < 24; i++)
  {
    Wire.beginTransmission(0x76);
    Wire.write((136 + i));
    Wire.endTransmission();
    Wire.requestFrom(0x76, 1);
    if (Wire.available() == 1)
    {
      b1[i] = Wire.read();
    }
  }

  unsigned short dig_T1 = (b1[0] & 0xFF) + (b1[1] & 0xFF) * 256;
  short dig_T2 = b1[2] + (b1[3] * 256);
  short dig_T3 = b1[4] + (b1[5] * 256);
  unsigned short dig_P1 = int(b1[6] & 0xFF) + (int(b1[7] & 0xFF) * 256);
  short dig_P2 = b1[8] + (b1[9] * 256);
  short dig_P3 = b1[10] + (b1[11] * 256);
  short dig_P4 = b1[12] + (b1[13] * 256);
  short dig_P5 = b1[14] + (b1[15] * 256);
  short dig_P6 = b1[16] + (b1[17] * 256);
  short dig_P7 = b1[18] + (b1[19] * 256);
  short dig_P8 = b1[20] + (b1[21] * 256);
  short dig_P9 = b1[22] + (b1[23] * 256);

writeTo(0x76,0xF4,87);
writeTo(0x76,0xF5,16);

  for (int i = 0; i < 6; i++)
  {
    Wire.beginTransmission(0x76);
    Wire.write((247 + i));
    Wire.endTransmission();
    Wire.requestFrom(0x76, 1);
    if (Wire.available() == 1)
    {
      data[i] = Wire.read();
    }
  }
  signed long adc_p = (((long)(data[0]&0xFF)*65536)+((long)(data[1]&0xFF)*256)+(long)(data[2]&0xF0))/ 16;
 long adc_t = (((long)(data[3] & 0xFF) * 65536) + ((long)(data[4] & 0xFF) * 256) + (long)(data[5] & 0xF0)) / 16;
   Serial.println(adc_p);
   Serial.println(adc_t);
   /*
  double var1 = (((double)adc_t) / 16384.0 -((double)dig_T1) / 1024.0)*((double)dig_T2);
  double var2 = ((((double)adc_t) / 131072.0 - ((double)dig_T1) / 8192.0) *(((double)adc_t) / 131072.0 - ((double)dig_T1) / 8192.0)) * ((double)dig_T3);
  double t_fine = (long)(var1 + var2);
  double cTemp = (var1 + var2) / 5120.0;

  // Pressure offset calculations
  var1 = ((double)t_fine / 2.0) - 64000.0;
  var2 = var1 * var1 * ((double)dig_P6) / 32768.0;
  var2 = var2 + var1 * ((double)dig_P5) * 2.0;
  var2 = (var2 / 4.0) + (((double)dig_P4) * 65536.0);
  var1 = (((double) dig_P3) * var1 * var1 / 524288.0 + ((double) dig_P2) * var1) / 524288.0;
  var1 = (1.0 + var1 / 32768.0) * ((double)dig_P1);
  double p = 1048576.0 - (double)adc_p;
  p = (p - (var2 / 4096.0)) * 6250.0 / var1;
  var1 = ((double) dig_P9) * p * p / 2147483648.0;
  var2 = p * ((double) dig_P8) / 32768.0;
  double pressure = (p + (var1 + var2 + ((double)dig_P7)) / 16.0) / 100;

  Serial.print("Pressure : ");
  Serial.print(pressure);
  Serial.println(" hPa");
  Serial.print("Temperature in Celsius : ");
  Serial.print(cTemp);
  Serial.println(" C");*/
  delay(1000);
}

