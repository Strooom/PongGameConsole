#pragma once
#include "stdint.h"

class ball {
  public:
    float getXPosition() const;
    float getYPosition() const;
    void updatePosition();

    char topLeft[8]{0};                                  // 4 custom characters are used to draw a 3*3 pixel ball
    char topRight[8]{0};
    char bottomLeft[8]{0};
    char bottomRight[8]{0};

    void setTokensFromPixelCoordinates(uint8_t x, uint8_t y);
  
  private:
    float xPosition{0};
    float yPosition{0};
    float xSpeed{0};
    float ySpeed{0};

    void clearTokens();
    uint8_t getRowFromPixelCoordinate(uint8_t pixelY);        // translate a display pixel coordinate x into character coordinate = column
    uint8_t getColFromPixelCoordinate(uint8_t pixelX);        // translate a display pixel coordinate y into character coordinate = row
};