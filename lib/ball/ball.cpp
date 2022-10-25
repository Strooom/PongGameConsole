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

void ball::clearTokens() {
    for (uint8_t i = 0; i < 8; i++) {
        topLeft[i]     = 0;
        topRight[i]    = 0;
        bottomLeft[i]  = 0;
        bottomRight[i] = 0;
    }
}

void ball::setTokensFromPixelCoordinates(uint8_t x, uint8_t y) {
    clearTokens();
    char bitsLeft{0};
    char bitsRight{0};
    if (x == 0) {
        bitsLeft = 0b11000;
    } else if (x == 1) {
        bitsLeft = 0b11100;
    } else if (x == 2) {
        bitsLeft = 0b01110;
    } else if (x == 3) {
        bitsLeft = 0b00111;
    } else if (x == 4) {
        bitsLeft = 0b00011;
    } else if (x == 5) {
        bitsLeft  = 0b00001;
        bitsRight = 0b10000;
    } else if (x == 6) {
        bitsRight = 0b11000;
    } else if (x == 7) {
        bitsRight = 0b11100;
    } else if (x == 8) {
        bitsRight = 0b11100;
    } else if (x == 9) {
        bitsRight = 0b01110;
    } else if (x == 10) {
        bitsRight = 0b00111;
    }

    if (y == 0) {
        bottomLeft[6] = bitsLeft;
        bottomRight[6] = bitsRight;
        bottomLeft[7] = bitsLeft;
        bottomRight[7] = bitsRight;
    } else if (y == 1) {
        bottomLeft[5] = bitsLeft;
        bottomRight[5] = bitsRight;
        bottomLeft[6] = bitsLeft;
        bottomRight[6] = bitsRight;
        bottomLeft[7] = bitsLeft;
        bottomRight[7] = bitsRight;
    } else if (y == 2) {
        bottomLeft[4] = bitsLeft;
        bottomRight[4] = bitsRight;
        bottomLeft[5] = bitsLeft;
        bottomRight[5] = bitsRight;
        bottomLeft[6] = bitsLeft;
        bottomRight[6] = bitsRight;
    } else if (y == 3) {
        bottomLeft[3] = bitsLeft;
        bottomRight[3] = bitsRight;
        bottomLeft[4] = bitsLeft;
        bottomRight[4] = bitsRight;
        bottomLeft[5] = bitsLeft;
        bottomRight[5] = bitsRight;
    } else if (y == 4) {
        bottomLeft[2] = bitsLeft;
        bottomRight[2] = bitsRight;
        bottomLeft[3] = bitsLeft;
        bottomRight[3] = bitsRight;
        bottomLeft[4] = bitsLeft;
        bottomRight[4] = bitsRight;
    } else if (y == 5) {
        bottomLeft[1] = bitsLeft;
        bottomRight[1] = bitsRight;
        bottomLeft[2] = bitsLeft;
        bottomRight[2] = bitsRight;
        bottomLeft[3] = bitsLeft;
        bottomRight[3] = bitsRight;
    } else if (y == 6) {
        bottomLeft[0] = bitsLeft;
        bottomRight[0] = bitsRight;
        bottomLeft[1] = bitsLeft;
        bottomRight[1] = bitsRight;
        bottomLeft[2] = bitsLeft;
        bottomRight[2] = bitsRight;
    } else if (y == 7) {
        bottomLeft[0] = bitsLeft;
        bottomRight[0] = bitsRight;
        bottomLeft[1] = bitsLeft;
        bottomRight[1] = bitsRight;
    } else if (y == 8) {
        topLeft[7] = bitsLeft;
        topRight[7] = bitsRight;
        bottomLeft[1] = bitsLeft;
        bottomRight[1] = bitsRight;
    } else if (y == 9) {
        topLeft[6] = bitsLeft;
        topRight[6] = bitsRight;
        topLeft[7] = bitsLeft;
        topRight[7] = bitsRight;
    } else if (y == 10) {
        topLeft[5] = bitsLeft;
        topRight[5] = bitsRight;
        topLeft[6] = bitsLeft;
        topRight[6] = bitsRight;
        topLeft[7] = bitsLeft;
        topRight[7] = bitsRight;
    } else if (y == 11) {
        topLeft[4] = bitsLeft;
        topRight[4] = bitsRight;
        topLeft[5] = bitsLeft;
        topRight[5] = bitsRight;
        topLeft[6] = bitsLeft;
        topRight[6] = bitsRight;
    } else if (y == 12) {
        topLeft[3] = bitsLeft;
        topRight[3] = bitsRight;
        topLeft[4] = bitsLeft;
        topRight[4] = bitsRight;
        topLeft[5] = bitsLeft;
        topRight[5] = bitsRight;
    } else if (y == 13) {
        topLeft[2] = bitsLeft;
        topRight[2] = bitsRight;
        topLeft[3] = bitsLeft;
        topRight[3] = bitsRight;
        topLeft[4] = bitsLeft;
        topRight[4] = bitsRight;
    } else if (y == 14) {
        topLeft[1] = bitsLeft;
        topRight[1] = bitsRight;
        topLeft[2] = bitsLeft;
        topRight[2] = bitsRight;
        topLeft[3] = bitsLeft;
        topRight[3] = bitsRight;
    } else if (y == 15) {
        topLeft[0] = bitsLeft;
        topRight[0] = bitsRight;
        topLeft[1] = bitsLeft;
        topRight[1] = bitsRight;
        topLeft[2] = bitsLeft;
        topRight[2] = bitsRight;
    } else if (y == 16) {
        topLeft[0] = bitsLeft;
        topRight[0] = bitsRight;
        topLeft[1] = bitsLeft;
        topRight[1] = bitsRight;
    }
}


uint8_t ball::getColFromPixelCoordinate(uint8_t pixelX) {
    if (pixelX < 10) {
        return 0;
    }
    if (pixelX > 118) {
        return 19;
    }
    return ((pixelX - 10) / 6) + 1;
}


uint8_t ball::getRowFromPixelCoordinate(uint8_t pixelY) {
    if (pixelY <= 15) {
        return 3;
    }
    if (pixelY <= 25) {
        return 2;
    }
    if (pixelY <= 35) {
        return 1;
    }
    return 0;
}
