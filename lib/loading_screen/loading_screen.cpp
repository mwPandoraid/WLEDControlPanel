#include <gui.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include "loading_screen.h"

extern GUI gui;

void loadingMenuLoop(TFT_eSPI &tft) {
  String connectingText = "Connecting...";
  tft.setFreeFont(&FreeSansBold12pt7b);
  int16_t connectingTextWidth = tft.textWidth(connectingText);

  tft.setCursor((tft.width() - connectingTextWidth) / 2, tft.height() - 15);
  tft.print(connectingText);
  // function for handling this gets called only once within setup(), therefore we can use a while loop here
  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    drawSpinnerFrame(tft, i);
    Serial.println(WiFi.status());
    if(i == 360) {
      i = 0;
    } else {
      i += 5;
    }
    if(WiFi.status() == 1) {
      ESP.restart();
    }
  }
}

void drawSpinnerFrame(TFT_eSPI &tft, int start_angle) {
  tft.drawArc(160, 120, 80, 71, 0, start_angle, 0xBDF7, TFT_BLACK, true); 
  tft.drawArc(160, 120, 80, 71, start_angle, start_angle + 40, TFT_ORANGE, TFT_BLACK, true);  
  tft.drawArc(160, 120, 80, 71, start_angle + 40, 360, 0xBDF7, TFT_BLACK, true);
}
