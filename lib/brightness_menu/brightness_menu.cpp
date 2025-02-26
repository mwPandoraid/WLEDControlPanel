#include <TFT_eSPI.h>
#include <brightness_menu.h>
#include <Encoder.h>
#include <peripherals.h>
#include <gui.h>

#define CIRCLE_X 160    // Center X position
#define CIRCLE_Y 120    // Center Y position
#define CIRCLE_RADIUS 80
#define BACKGROUND_COLOR 0xBDF7  // Brighter gray color
#define PROGRESS_COLOR 0x07E0    // Green color
#define TEXT_SIZE 3
#define CIRCLE_THICKNESS 9

extern Encoder *rotaryEncoder;

int currPosition = 0;
int brightness = 0;

long debounceDelay = 40;

long lastDebounceTime = 0;

void brightnessMenuLoop(TFT_eSPI *tft) {
  int newPosition = rotaryEncoder->read() / 4;
  if(newPosition > currPosition && millis() - lastDebounceTime > debounceDelay) {
    brightness = min(100, brightness + 2);
    brightnessMenu(tft, brightness, false);
    Serial.println("draw on that thang");
    lastDebounceTime = millis();
  } else if (newPosition < currPosition && millis() - lastDebounceTime > debounceDelay) {
    brightness = max(0, brightness - 2);
    brightnessMenu(tft, brightness, true);
    lastDebounceTime = millis();
  }
  currPosition = newPosition;
  delay(40);
}

void brightnessMenu(TFT_eSPI *tft, int value, bool clear) {
  uint32_t endAngle = (value * 360) / 100;
  tft->drawArc(CIRCLE_X, CIRCLE_Y, CIRCLE_RADIUS, CIRCLE_RADIUS - CIRCLE_THICKNESS, endAngle, 360, BACKGROUND_COLOR, TFT_BLACK, true);  
  tft->drawArc(CIRCLE_X, CIRCLE_Y, CIRCLE_RADIUS, CIRCLE_RADIUS - CIRCLE_THICKNESS, 0, endAngle, TFT_ORANGE, TFT_BLACK, true);

  tft->setTextSize(1);
  tft->setTextColor(TFT_WHITE, TFT_BLACK);
  tft->setFreeFont(&FreeSansBold18pt7b);

  String percentText = String(value) + "%";

  int16_t textWidth = tft->textWidth(percentText);
  int16_t textHeight = tft->fontHeight();

  int16_t textX = CIRCLE_X - (textWidth / 2);
  int16_t textY = CIRCLE_Y - (textHeight / 4);

  int16_t clearWidth = textWidth + 24;  // Add small padding
  int16_t clearHeight = textHeight + 36;  // Add small padding
  int16_t clearX = CIRCLE_X - (clearWidth / 2);
  int16_t clearY = CIRCLE_Y - (clearHeight / 2);

  tft->setCursor(textX, textY);
  tft->fillRect(clearX, clearY, clearWidth, clearHeight, TFT_BLACK);
  tft->print(percentText);
}
