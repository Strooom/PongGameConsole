#include "ball.h"

float ball::getXPosition() const {
    return xPosition;
}

float ball::getYPosition() const {
    return yPosition;
}

void ball::updatePosition() {
    xPosition = xPosition + xSpeed;
    yPosition = yPosition + ySpeed;
    // TODO : need to inverse x or y speed when the ball hits the wall..
}
