#pragma once

#include "stdint.h"
#include "rotationdirection.h"

class encoderWheel {
  public:
    void initialize();
    bool positionHasChanged();
    int32_t getPosition() const;
    void resetPosition();
    rotationDirection getRotationDirection() const;
    void update();

  private:
    uint8_t pinA{2};        // which MCU pin connects to encoder output A
    uint8_t pinB{3};        // which MCU pin connects to encoder output B

    int32_t position{0};
    bool positionChanged{false};
    rotationDirection theDirection{rotationDirection::clockwise};
};