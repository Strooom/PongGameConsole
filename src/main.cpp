#include <Arduino.h>
#include "encoderwheel.h"
#include "HD44780.h"

encoderWheel theWheel;
//HD44780 theDisplay(displayType::Type20X4, 0x28);

void setup() {
    theWheel.initialize();
//    theDisplay.initialize();
}

void loop() {
    if (theWheel.positionHasChanged())
    {
        
    }
}

void isr() {
    theWheel.update(theWheel.readAB());
}