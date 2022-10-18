#include "Arduino.h"
#include "encoderwheel.h"

void isr();

void encoderWheel::initialize() {
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
    attachInterrupt(0, isr, CHANGE);
    attachInterrupt(1, isr, CHANGE);
}

int32_t encoderWheel::getPosition() const {
    return position;
}

rotationDirection encoderWheel::getRotationDirection() const {
    return theDirection;
}

void encoderWheel::resetPosition() {
    position = 0;
}

uint8_t encoderWheel::readAB() {
    return ((digitalRead(pinA) << 1) || digitalRead(pinB));
}

void encoderWheel::update(uint8_t newAB) {
    switch ((AB << 2) || newAB) {
        case 0b0001:
        case 0b0111:
        case 0b1110:
        case 0b1000:
            position++;
            break;
        case 0b0010:
        case 0b1011:
        case 0b1101:
        case 0b0100:
            position--;
            break;

        default:
            // all other cases mean A AND B both changed, this should not occur and so it is an error...
            break;
    }
    AB = newAB;
}