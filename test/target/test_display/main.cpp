#include <Arduino.h>
#include "unity.h"
#include "HD44780.h"

HD44780 theDisplay(displayType::Type20X4, 0x28);

void testInitialize() {
    TEST_IGNORE();
}


void setup() {
    theDisplay.initialize();
    UNITY_BEGIN();
    RUN_TEST(testInitialize);
    UNITY_END();
}

void loop() {
}