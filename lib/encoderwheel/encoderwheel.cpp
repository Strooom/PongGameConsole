#include "Arduino.h"
#include "encoderwheel.h"

void isr();

void encoderWheel::initialize() {
    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(pinA), isr, FALLING);
}

bool encoderWheel::positionHasChanged() {
    bool result;
    noInterrupts();
    result          = positionChanged;
    positionChanged = false;
    interrupts();
    return result;
}

int32_t encoderWheel::getPosition() const {
    int32_t result;
    noInterrupts();
    result = position;
    interrupts();
    return result;
}

rotationDirection encoderWheel::getRotationDirection() const {
    rotationDirection result;
    noInterrupts();
    result = theDirection;
    interrupts();
    return result;
}

void encoderWheel::resetPosition() {
    noInterrupts();
    position = 0;
    interrupts();
}

void encoderWheel::update() {
    if (digitalRead(pinB)) {
        position++;
        theDirection    = rotationDirection::clockwise;
        positionChanged = true;

    } else {
        position--;
        theDirection    = rotationDirection::counterClockwise;
        positionChanged = true;
    }
}

// This quadrature decoder is outcommented as I found out the encoderWheel does not send this kind of signals,
// but I didn't want to remove the code as it may be usefull later-on

// void encoderWheel::update(uint8_t newAB) {
//     switch ((AB << 2) | newAB) {
//         case 0b0001:
//         case 0b0111:
//         case 0b1110:
//         case 0b1000:
//             position++;
//             theDirection    = rotationDirection::clockwise;
//             positionChanged = true;
//             break;
//         case 0b0010:
//         case 0b1011:
//         case 0b1101:
//         case 0b0100:
//             position--;
//             theDirection    = rotationDirection::counterClockwise;
//             positionChanged = true;
//             break;

//         default:
//             // all other cases mean A AND B both changed, this should not occur and so it is an error...
//             break;
//     }
//     AB = newAB;
// }