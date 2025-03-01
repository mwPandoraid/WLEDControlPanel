#include <TFT_eSPI.h>
#include "gui.h"

GUI::GUI() {
  GUI::tft.begin();
  GUI::tft.setRotation(3);
  GUI::tft.fillScreen(TFT_BLACK);
}

void GUI::handle(){
  GUI::gui_func_ptr(GUI::tft); //execute code for current window loop
}

void GUI::set_window(func_ptr func) {
  GUI::gui_func_ptr = func;
  GUI::tft.fillScreen(TFT_BLACK); // we want to clear the screen fully when switching
}
