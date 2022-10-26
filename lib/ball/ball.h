#pragma once
#include "stdint.h"

class ball {
  public:
    float getXPosition() const;
    float getYPosition() const;
    void updatePosition();

    char topLeft[8]{0};        // 4 custom characters are used to draw a 3*3 pixel ball
    char topRight[8]{0};
    char bottomLeft[8]{0};
    char bottomRight[8]{0};

    void setTokensFromPixelCoordinates(uint8_t x, uint8_t y);

    static constexpr uint8_t xMin{1};         // minimum X-coordinate of the ball, as ball is 3*3 pixels, the center is minimum at x = 1
    static constexpr uint8_t xMax{45};        // maximum X-coordinate of the ball : 8 chars with 5 pixels each, 1 pixel between chars 7 * (5+1) + 5 = 47, index is 0-46, 3*3 px so max index is 45
    static constexpr uint8_t yMin{1};         // minimum Y-coordinate of the ball, as ball is 3*3 pixels, the center is minimum at y = 1
    static constexpr uint8_t yMax{33};        // maximum Y-coordinate of the ball : 4 chars with 8 pixels each, 1 pixel between chars 3 * (8+1) + 8 = 35, index is 0-34, 3*3 px so max index is 33

    uint8_t getBottomRowFromPixelCoordinate(uint8_t pixelY);        // translate a display pixel coordinate x into character coordinate = column
    uint8_t getLeftColFromPixelCoordinate(uint8_t pixelX);          // translate a display pixel coordinate y into character coordinate = row
    uint8_t getPixelOffsetFromCol(uint8_t col);
    uint8_t getPixelOffsetFromRow(uint8_t row);

  private:
    float xPosition{0};
    float yPosition{0};
    float xSpeed{0};
    float ySpeed{0};

    void clearTokens();

};