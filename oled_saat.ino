#include <virtuabotixRTC.h>
#include <OLED_I2C.h>
int CLK_PIN = 6;
int DAT_PIN = 7;
int RST_PIN = 8;
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
OLED  myOLED(SDA, SCL, 8);

void setup() {
 myOLED.begin();
 myOLED.setFont(SmallFont);
 myRTC.setDS1302Time(0, 3, 19, 0, 12, 11, 2023);
}
void loop() {

 myRTC.updateTime();
myOLED.clrScr();
 myOLED.setFont(SmallFont);  
 myOLED.print("Tarih / Zaman" ,20 ,0);
 myOLED.setFont(MediumNumbers);
 myOLED.printNumI(myRTC.hours, 10 , 16);
 myOLED.setFont(SmallFont);  
 myOLED.print(":", 40, 24);
 myOLED.setFont(MediumNumbers);
 myOLED.printNumI(myRTC.minutes, 50 , 16);
 myOLED.setFont(SmallFont);  
 myOLED.print(":", 80, 24);
 myOLED.setFont(MediumNumbers);
 myOLED.printNumI(myRTC.seconds, 90 , 16);
 myOLED.setFont(SmallFont);
 myOLED.printNumI(myRTC.dayofmonth, 20 , 40);
 myOLED.setFont(SmallFont);  
 myOLED.print("/", 35, 40);
 myOLED.setFont(SmallFont);
 myOLED.printNumI(myRTC.month, 45 , 40);
 myOLED.setFont(SmallFont);  
 myOLED.print("/", 60, 40);
 myOLED.setFont(SmallFont);
 myOLED.printNumI(myRTC.year, 70 , 40);  
 myOLED.update();
delay(1000);

}
