#pragma once

#include "stdint.h"
#include "rotationdirection.h"

// NOTE : this pulseWheel is not a real quadrature encoder. When monitoring the signals on the scope, I observed that for each step, there is a full pulse on A, 
// and depending on the rotationDirection, B is either low or high during the falling edge of that pulse. Signals return to high afterwards..

class pulseWheel {
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