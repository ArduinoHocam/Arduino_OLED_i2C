
//ARDUINO HOCAM i2C 0.96 inch OLED EKRAN KULLANIMI

#include <OLED_I2C.h>
extern uint8_t SmallFont[];
extern uint8_t dnm[];
extern uint8_t ytb[];
extern uint8_t logoo[];
extern uint8_t abone[];
OLED  myOLED(SDA, SCL, 8);
void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
  myOLED.setFont(SmallFont);
}

void loop() {
  loading();
  myOLED.clrScr();
  logo();

  youtube();
  invertt();
  for (int i = 128; i >= -40; i--)
  {
    myOLED.print("www.youtube.com/ArduinoHocam", i, 56);
    delay(5);
    myOLED.update();
  }
  delay(1000);
  myOLED.clrScr();
  aboneOl();

}
void logo()
{
  myOLED.drawBitmap(25, 0, logoo, 96, 64);
  myOLED.update();
  invertt();

  myOLED.clrScr();

}
void aboneOl()
{
  myOLED.drawBitmap(0, 0, abone, 123, 64);
  myOLED.update();
  invertt();
  delay(1000);
  myOLED.update();
  myOLED.clrScr();

}
void invertt()
{
  myOLED.invert(true);
  delay(400);
  myOLED.invert(false);
  delay(400);
  myOLED.invert(true);
  delay(400);
  myOLED.invert(false);
}
void youtube()
{
  myOLED.drawBitmap(35, 0, ytb, 55, 55);

  for (int k = 79; k <= 87; k++)
  {
    for (int i = 47; i <= 55; i++) {

      myOLED.clrPixel(k, i);

    }
  }

  myOLED.update();
}



void loading()
{
  myOLED.clrScr();

  myOLED.drawRoundRect(20, 20, 100, 40);

  myOLED.print("LOADING", 40, 45);

  for (int i = 21; i <= 99; i++)
  {
    myOLED.drawLine(i, 20, i, 40);
    myOLED.update();
    delay(10);
  }
}

