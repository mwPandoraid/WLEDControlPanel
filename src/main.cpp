#include <TFT_eSPI.h>
#include <SPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <pins.h>
#include <Encoder.h>
#include <brightness_menu.h>
#include <loading_screen.h>
#include <gui.h>
#include <peripherals.h>
#include <ArduinoOTA.h>

const uint8_t ENCODER_PIN1 = 21;
const uint8_t ENCODER_PIN2 = 22;
const uint8_t ENCODER_BTN = 4;

const char* ssid = "PLAY internet 2.4GHz_6EF2";
const char* password = "internetskr123";
const char* wledHost = "192.168.100.250";

GUI gui;
//Encoder *rotaryEncoder;
int getWLEDBrightness() {
}

void setup() {
  Serial.begin(115200);
  init_encoder(ENCODER_PIN2, ENCODER_PIN1);
  gui.set_window(&loadingMenuLoop);
  WiFi.disconnect();
  WiFi.begin(ssid, password);
  gui.handle();
  ArduinoOTA.onEnd([](){
    delay(1000);
    ESP.restart(); 
  });
  ArduinoOTA.begin();
  gui.set_window(&brightnessMenuLoop);
  //tft.begin();
  /*tft.setRotation(3);*/
  /*tft.fillScreen(TFT_BLACK);*/
}

void loop () {
  gui.handle();
  ArduinoOTA.handle();
}
