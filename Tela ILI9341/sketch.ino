#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 2
#define TFT_CS 5

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  tft.begin();

  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(3);
  tft.println("Hello Word");

  tft.setCursor(0, 22);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(2);
  tft.println("Eu posso ter cores?");
}

void loop() { }