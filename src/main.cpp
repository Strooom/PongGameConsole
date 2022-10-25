#include <Arduino.h>
#include "ball.h"
#include "bat.h"
#include "pulsewheel.h"
#include "HD44780.h"
#include "runtimer.h"

constexpr uint8_t ballTopLeft{0U};            // 4 custom characters are used to draw a 3*3 pixel ball, over
constexpr uint8_t ballTopRight{1U};           //
constexpr uint8_t ballBottomLeft{2U};         //
constexpr uint8_t ballBottomRight{3U};        //
constexpr uint8_t batTop{6};                  // 2 custom characters are used to draw a 3*5 pixel bat
constexpr uint8_t batBottom{7};               //

intervalTimer theTimer;
ball theBall;
bat theBat;
// pulseWheel theWheel;
HD44780 theDisplay(displayType::Type20X4, 0x27);

void setup() {
    Serial.begin(115200);
    Serial.flush();
    Serial.print("\nPong Game Console\n");
    theDisplay.initialize();
    theTimer.start(1000);
    theDisplay.print("Line 0", 0, 11);
    theDisplay.print("Line 1", 1, 11);
    theDisplay.print("Line 2", 2, 11);
    theDisplay.print("Line 3", 3, 11);
    theDisplay.refresh();
}

void loop() {
    for (uint8_t testY = 1; testY < 16; testY++) {
        theBat.setTokensFromPixelCoordinate(testY);
        theDisplay.setCGRam(theBat.top, batTop);
        theDisplay.setCGRam(theBat.bottom, batBottom);
        theDisplay.writeByteDirect(batTop, 0, 10);
        theDisplay.writeByteDirect(batBottom, 1, 10);
        delay(20);
    }
}

void isr() {
}