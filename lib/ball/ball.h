#pragma once
#include "stdint.h"

class ball {
  public:
    float getXPosition() const;
    float getYPosition() const;
    void updatePosition();

  private:
    float xPosition{0};
    float yPosition{0};
    float xSpeed{0};
    float ySpeed{0};
};