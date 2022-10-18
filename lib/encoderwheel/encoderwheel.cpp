#include "encoderwheel.h"

int32_t encoderWheel::getPosition() const {
    return position;
}

rotationDirection encoderWheel::getRotationDirection() const {
    return theDirection;
}

void encoderWheel::resetPosition() {
    position = 0;
}
