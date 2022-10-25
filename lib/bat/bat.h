#pragma once
#include "stdint.h"

class bat {
  public:
    float getYPosition() const;
    void updatePosition();

    char top[8]{0};
    char bottom[8]{0};

    void setTokensFromPixelCoordinate(uint8_t y);
    uint8_t getRowFromPixelCoordinate(uint8_t pixelY);

  private:
    void clearTokens();
    float yPosition{0};
    float ySpeed{0};
};