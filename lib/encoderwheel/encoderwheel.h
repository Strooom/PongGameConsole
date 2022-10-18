#pragma once

#include "stdint.h"
#include "rotationdirection.h"

class encoderWheel {
  public:
    int32_t getPosition() const;
    void resetPosition();
    rotationDirection getRotationDirection() const;

  private:
    int32_t position{0};
    rotationDirection theDirection{rotationDirection::clockwise};
    uint8_t abSignals{0};
};