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
    uint8_t readAB();
    void update(uint8_t newAB);

  private:
    uint8_t pinA{1};        // which MCU pin connects to encoder output A
    uint8_t pinB{2};        // which MCU pin connects to encoder output B
    uint8_t AB{0};          // value of A and B : 00, 01, 10, 11

    int32_t position{0};
    bool positionChanged{false};
    rotationDirection theDirection{rotationDirection::clockwise};
};