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
    uint8_t y = 20;
    for (uint8_t x = ball::xMin; x < ball::xMax; x++) {
        theBall.setTokensFromPixelCoordinates(x, y);

        theDisplay.setCGRam(theBall.topLeft, ballTopLeft);
        theDisplay.setCGRam(theBall.topRight, ballTopRight);
        theDisplay.setCGRam(theBall.bottomLeft, ballBottomLeft);
        theDisplay.setCGRam(theBall.bottomRight, ballBottomRight);

        theDisplay.clear();
        theDisplay.refresh();
        theDisplay.writeByteDirect(ballTopLeft, theBall.getBottomRowFromPixelCoordinate(y) - 1, theBall.getLeftColFromPixelCoordinate(x));
        theDisplay.writeByteDirect(ballTopRight, theBall.getBottomRowFromPixelCoordinate(y) - 1, theBall.getLeftColFromPixelCoordinate(x) + 1);
        theDisplay.writeByteDirect(ballBottomLeft, theBall.getBottomRowFromPixelCoordinate(y), theBall.getLeftColFromPixelCoordinate(x));
        theDisplay.writeByteDirect(ballBottomRight, theBall.getBottomRowFromPixelCoordinate(y), theBall.getLeftColFromPixelCoordinate(x) + 1);
        delay(1500);
    }
}

void isr() {
}