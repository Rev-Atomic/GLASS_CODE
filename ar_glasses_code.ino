include<SoftwareSerial.h>
SoftwareSerial Serial1(10, 11);

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
String str = "";
byte h = 0;
byte m = 0;
byte S = 0;
String dmy, time, network, battery, inNumber, s;
byte centerX = 24;
byte centerY = 39;
byte Radius = 24;

double RAD = 3.141592 / 180;
double LR = 89.99;

void showTimeAnalog(int center_x, int center_y, double pl1, double pl2, double pl3)
{
  double x1, x2, y1, y2;
  x1 = center_x + (Radius * pl1) * cos((6 * pl3 + LR) * RAD);
  y1 = center_y + (Radius * pl1) * sin((6 * pl3 + LR) * RAD);
  x2 = center_x + (Radius * pl2) * cos((6 * pl3 - LR) * RAD);
  y2 = center_y + (Radius * pl2) * sin((6 * pl3 - LR) * RAD);
  display.drawLine((int)x1, (int)y1, (int)x2, (int)y2, WHITE);
}

void digitalClock()
{
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(60, 20);
  display.println(dmy);
  display.setTextSize(2);
  display.setCursor(60, 30);
  display.println(time);
  display.display();
  delay(2000);
}

void Battery()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 0);
  display.print("Bat:");
  display.print(battery);
  display.print("%");
  display.drawRect(14, 20, 80, 40, WHITE);
  display.drawRect(94, 30, 10, 20, WHITE);
  display.fillRect(14, 20, (int)(8 * (battery.toInt()) / 10), 40, WHITE);
  display.display();
  delay(2000);
}

void Network()
{
  display.clearDisplay();
  display.drawLine(5, 15, 25, 15, WHITE);
  display.drawLine(5, 15, 14, 30, WHITE);
  display.drawLine(25, 15, 17, 30, WHITE);
  display.fillRect(14, 15, 4, 40, WHITE);
  int net = network.toInt() / 20;
  int x1 = 24, y1 = 50, x2 = 4, y2 = 5;
  for (int i = 1; i <= net; i++)
  {
    display.fillRect(x1, y1, x2, y2, WHITE);
    x1 += 10;
    y1 -= 5;
    y2 += 10;
    y2 -= 5;
  }
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(80, 34);
  display.print(network);
  display.setTextSize(1);
  display.setCursor(117, 44);
  display.println("%");
  display.display();
  delay(2000);
}

void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  Serial1.begin(9600);
  Serial1.println("System Ready");
}

void loop(){
  Serial1.println("1234");
  delay(1000);
  while (Serial1.available() > 0){
    char ch = Serial1.read();
    str += ch;
    if (ch == '$'){
      dmy = str.substring(str.indexOf("#") + 1, str.indexOf(" "));
      time = str.substring(str.indexOf(" ") + 1, str.indexOf(",") - 3);
      network = str.substring(str.indexOf(",") + 1, str.indexOf(",,"));
      battery = str.substring(str.indexOf(",,") + 2, str.indexOf(",,,"));
      inNumber = str.substring(str.indexOf(",,,") + 3, str.indexOf("$"));
      s = time.substring(time.indexOf(" ") + 1, time.indexOf(" ") + 3);
      h = s.toInt();
      s = time.substring(time.indexOf(" ") + 4, time.indexOf(" ") + 6);
      m = s.toInt();
      s = time.substring(time.indexOf(" ") + 7, time.indexOf(" ") + 9);
      S = s.toInt();
      str = "";}
  }
  display.clearDisplay();
  display.drawCircle(centerX, centerY, Radius, WHITE);
  showTimeAnalog(centerX, centerY, 0.1, 0.5, h * 5 + (int)(m * 5 / 60));
  showTimeAnalog(centerX, centerY, 0.1, 0.78, m);
  // showTimePin(centerX, centerY, 0.1, 0.9, S);
  digitalClock();
  Battery();
  Network();
}
