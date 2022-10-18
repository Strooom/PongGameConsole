#include <Arduino.h>
#include "unity.h"
#include "HD44780.h"

HD44780 theDisplay(displayType::Type20X4, 0x28);

void setup() {
    theDisplay.initialize();
}

void loop() {
}