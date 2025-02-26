#include <TFT_eSPI.h>


class GUI {
  public:
    TFT_eSPI *tft;

    GUI();

    void (*gui_func_ptr)(TFT_eSPI *);
    void handle();
    void set_window(void(*func)(TFT_eSPI *));
};
