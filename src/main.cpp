#include <Arduino.h>
#include "encoderwheel.h"
#include "HD44780.h"

encoderWheel theWheel;
// HD44780 theDisplay(displayType::Type20X4, 0x28);

void setup() {
    Serial.begin(115200);
    Serial.flush();
    Serial.println("Pong Game Console");
    theWheel.initialize();
    //    theDisplay.initialize();
}

void loop() {
    if (theWheel.positionHasChanged()) {
        Serial.println(theWheel.getPosition());
    }
}

void isr() {
    theWheel.update();
}