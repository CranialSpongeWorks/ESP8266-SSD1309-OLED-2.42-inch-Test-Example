/*
ESP8266 SSD1309 2.42" I2C 4pin
Board: LOLIN (WEMOS) D1 Mini

YouTube channel: https://www.youtube.com/channel/UCa7gEQFFMiGWg_gpVLeJT2Q
GitHub: https://github.com/CranialSpongeWorks/ESP8266-SSD1309-OLED-2.42-inch-Test-Example

STM32 library for working with OLEDs based on SSD1306, supports I2C and 4-wire SPI.
It also works with SH1106, SH1107 and SSD1309 which are compatible with SSD1306.

*/

#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// Declaration for an SH1106 display connected to I2C (SCL=D1, SDA=D2 pins)
#define SCREEN_ADDRESS 0x3C //< See datasheet for Address; 0x3C for 128x64
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SH1106G oled = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1, 400000, 100000);

void setup() {   // put your setup code here, to run once:
  //Initialize serial and wait for port to open:
	Serial.begin(115200); //setup Serial Monitor
  while (!Serial) {
    delay(500);// wait for serial port to connect
  }
  delay(500);

  oled.begin(0x3C, true); // Address 0x3C default
  oled.setContrast(255); oled.setTextWrap(true);
  oled.setTextSize(1); oled.setTextColor(SH110X_WHITE); oled.display();
  delay(2000);
}

void loop() { // put your main code here, to run repeatedly:
  oled.clearDisplay();
  oled.setCursor(0,0);
  oled.setTextSize(2); 
  oled.println("2.42 inch");
  oled.setTextSize(1); 
  oled.println("SSD1309 I2C IIC OLED");
  oled.setTextSize(2); 
  oled.println(__TIME__);
  oled.setTextSize(1); 
  oled.println(__DATE__);
  oled.display();
  delay(1000);
}

//end