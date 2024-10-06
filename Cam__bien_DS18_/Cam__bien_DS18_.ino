
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C I2C_LCD1(0x27, 16, 2);
byte name0x2[] = { B00010, B00101, B00010, B00000, B00000, B00000, B00000, B00000 };

void setup(void) 
{ 
 I2C_LCD1.init();
 I2C_LCD1.backlight();
 I2C_LCD1.print("Nhiet do mt :");

 Serial.begin(9600); 
//  Start up the library 
 sensors.begin(); 
} 
void loop(void) 
{ 
   I2C_LCD1.setCursor(0,1);
   float tempC = sensors.getTempCByIndex(0);
   float tempC_rounded = round(tempC * 100) / 100;
   I2C_LCD1.print(tempC_rounded);
  //  I2C_LCD1.print(" doC"); 
   sensors.requestTemperatures();

   I2C_LCD1.setCursor(8,1);
   I2C_LCD1.print("do C");
 Serial.println("    "); 
 Serial.print("nhiet do phong : "); 
   Serial.print(tempC_rounded);
   delay(5000); 
 } 
