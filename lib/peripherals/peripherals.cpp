#include <Encoder.h>
#include "peripherals.h"

Encoder *rotaryEncoder;

void init_encoder(int ENCODER_PIN1, int ENCODER_PIN2) {
    rotaryEncoder = new Encoder(ENCODER_PIN1, ENCODER_PIN2);
}
