#include "bat.h"
#include "HD44780.h"

void bat::clearTokens() {
    for (uint8_t i = 0; i < 8; i++) {
        top[i]    = 0;
        bottom[i] = 0;
    }
}

uint8_t bat::getRowFromPixelCoordinate(uint8_t pixelY) {
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

void bat::setTokensFromPixelCoordinate(uint8_t y) {
    clearTokens();
    const char bits{0b11000};

    if (y < 2) {
        y = 2;
    }
    if (y > 15) {
        y = 15;
    }

    if (y == 2) {
        bottom[4] = bits;
        bottom[5] = bits;
        bottom[6] = bits;
        bottom[7] = bits;
        bottom[8] = bits;
    } else if (y == 3) {
        bottom[3] = bits;
        bottom[4] = bits;
        bottom[5] = bits;
        bottom[6] = bits;
        bottom[7] = bits;
    } else if (y == 4) {
        bottom[2] = bits;
        bottom[3] = bits;
        bottom[4] = bits;
        bottom[5] = bits;
        bottom[6] = bits;
    } else if (y == 5) {
        bottom[1] = bits;
        bottom[2] = bits;
        bottom[3] = bits;
        bottom[4] = bits;
        bottom[5] = bits;
    } else if (y == 6) {
        bottom[0] = bits;
        bottom[1] = bits;
        bottom[2] = bits;
        bottom[3] = bits;
        bottom[4] = bits;
    } else if (y == 7) {
        bottom[0] = bits;
        bottom[1] = bits;
        bottom[2] = bits;
        bottom[3] = bits;
    } else if (y == 8) {
        top[7]    = bits;
        bottom[0] = bits;
        bottom[1] = bits;
        bottom[2] = bits;
        bottom[3] = bits;
    } else if (y == 9) {
        top[6]    = bits;
        top[7]    = bits;
        bottom[0] = bits;
        bottom[1] = bits;
        bottom[2] = bits;
    } else if (y == 10) {
        top[5]    = bits;
        top[6]    = bits;
        top[7]    = bits;
        bottom[0] = bits;
        bottom[1] = bits;
    } else if (y == 11) {
        top[4]    = bits;
        top[5]    = bits;
        top[6]    = bits;
        top[7]    = bits;
        bottom[0] = bits;
    } else if (y == 12) {
        top[3] = bits;
        top[4] = bits;
        top[5] = bits;
        top[6] = bits;
        top[7] = bits;
    } else if (y == 13) {
        top[2] = bits;
        top[3] = bits;
        top[4] = bits;
        top[5] = bits;
        top[6] = bits;
    } else if (y == 14) {
        top[1] = bits;
        top[2] = bits;
        top[3] = bits;
        top[4] = bits;
        top[5] = bits;
    } else if (y == 15) {
        top[0] = bits;
        top[1] = bits;
        top[2] = bits;
        top[3] = bits;
        top[4] = bits;
    }
}
