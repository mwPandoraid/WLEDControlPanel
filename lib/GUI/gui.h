#include <TFT_eSPI.h>

typedef void(*func_ptr)(TFT_eSPI &);

class GUI {
  public:
    TFT_eSPI &tft = *new TFT_eSPI();

    GUI();

    func_ptr gui_func_ptr; 
    void handle();
    void set_window(func_ptr func);
};

extern GUI gui;
