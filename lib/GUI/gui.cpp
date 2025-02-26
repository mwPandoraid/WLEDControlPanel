#include <TFT_eSPI.h>
#include "gui.h"

GUI::GUI() {
  GUI::tft = new TFT_eSPI();
  GUI::tft->begin();
  GUI::tft->setRotation(3);
  GUI::tft->fillScreen(TFT_BLACK);
}

void GUI::handle(){
  GUI::gui_func_ptr(GUI::tft); //execute code for current window loop
}

void GUI::set_window(void (*func)(TFT_eSPI *)) {
  GUI::gui_func_ptr = func;
}
