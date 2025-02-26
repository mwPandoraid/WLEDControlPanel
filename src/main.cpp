#include <TFT_eSPI.h>
#include <SPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <pins.h>
#include <Encoder.h>
#include <brightness_menu.h>
#include <gui.h>
#include <peripherals.h>

const uint8_t ENCODER_PIN1 = 21;
const uint8_t ENCODER_PIN2 = 22;
const uint8_t ENCODER_BTN = 4;


//Encoder *rotaryEncoder;
GUI gui = GUI();

int getWLEDBrightness() {
}

void setup() {
  Serial.begin(115200);
  init_encoder(ENCODER_PIN2, ENCODER_PIN1);
  gui.set_window(&brightnessMenuLoop);
  //tft.begin();
  /*tft.setRotation(3);*/
  /*tft.fillScreen(TFT_BLACK);*/
}

void loop () {
  gui.handle();
}
