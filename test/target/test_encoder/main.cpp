#include <Arduino.h>
#include "unity.h"
#include "encoderwheel.h"

pulseWheel theWheel;

void isr() {
}

void testInitialize() {
    TEST_ASSERT_EQUAL_INT32(0, theWheel.getPosition());
}

void testIncrementDecrement() {
    theWheel.update(0b01);
    TEST_ASSERT_EQUAL_INT32(1, theWheel.getPosition());
    TEST_ASSERT_EQUAL_INT32(rotationDirection::clockwise, theWheel.getRotationDirection());
    theWheel.update(0b11);
    TEST_ASSERT_EQUAL_INT32(2, theWheel.getPosition());
    theWheel.update(0b10);
    TEST_ASSERT_EQUAL_INT32(3, theWheel.getPosition());
    theWheel.update(0b00);
    TEST_ASSERT_EQUAL_INT32(4, theWheel.getPosition());
    theWheel.update(0b10);
    TEST_ASSERT_EQUAL_INT32(3, theWheel.getPosition());
    TEST_ASSERT_EQUAL_INT32(rotationDirection::counterClockwise, theWheel.getRotationDirection());
    theWheel.update(0b11);
    TEST_ASSERT_EQUAL_INT32(2, theWheel.getPosition());
    theWheel.update(0b01);
    TEST_ASSERT_EQUAL_INT32(1, theWheel.getPosition());
    theWheel.update(0b00);
    TEST_ASSERT_EQUAL_INT32(0, theWheel.getPosition());
}

void setup() {
    theWheel.initialize();
    UNITY_BEGIN();
    RUN_TEST(testInitialize);
    RUN_TEST(testIncrementDecrement);
    UNITY_END();
}

void loop() {
}