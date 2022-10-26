#include <Arduino.h>
#include "stdint.h"
#include <unity.h>
#include "ball.h"

void setUp(void) {}           // before test
void tearDown(void) {}        // after test

void test_getBottomRowFromPixelCoordinate() {
    ball theBall;
    TEST_ASSERT_EQUAL_UINT8(3U, theBall.getBottomRowFromPixelCoordinate(ball::yMin));
    TEST_ASSERT_EQUAL_UINT8(3U, theBall.getBottomRowFromPixelCoordinate(15));
    TEST_ASSERT_EQUAL_UINT8(2U, theBall.getBottomRowFromPixelCoordinate(16));
    TEST_ASSERT_EQUAL_UINT8(2U, theBall.getBottomRowFromPixelCoordinate(23));
    TEST_ASSERT_EQUAL_UINT8(1U, theBall.getBottomRowFromPixelCoordinate(24));
    TEST_ASSERT_EQUAL_UINT8(1U, theBall.getBottomRowFromPixelCoordinate(ball::yMax));
}

void test_getLeftColFromPixelCoordinate() {
    ball theBall;
    TEST_ASSERT_EQUAL_UINT8(0U, theBall.getLeftColFromPixelCoordinate(ball::xMin));
    TEST_ASSERT_EQUAL_UINT8(0U, theBall.getLeftColFromPixelCoordinate(9));
    TEST_ASSERT_EQUAL_UINT8(1U, theBall.getLeftColFromPixelCoordinate(10));
    TEST_ASSERT_EQUAL_UINT8(1U, theBall.getLeftColFromPixelCoordinate(15));
}

void test_getPixelOffsetFromCol() {
    ball theBall;
    TEST_ASSERT_EQUAL_UINT8(0U, theBall.getPixelOffsetFromCol(0));
    TEST_ASSERT_EQUAL_UINT8(6U, theBall.getPixelOffsetFromCol(1));
}

void test_getPixelOffsetFromRow() {
    ball theBall;
    TEST_ASSERT_EQUAL_UINT8(0U, theBall.getPixelOffsetFromRow(3));
    TEST_ASSERT_EQUAL_UINT8(9U, theBall.getPixelOffsetFromRow(2));
    TEST_ASSERT_EQUAL_UINT8(18U, theBall.getPixelOffsetFromRow(1));
    TEST_ASSERT_EQUAL_UINT8(27U, theBall.getPixelOffsetFromRow(0));
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_getBottomRowFromPixelCoordinate);
    RUN_TEST(test_getLeftColFromPixelCoordinate);
    RUN_TEST(test_getPixelOffsetFromCol);
    RUN_TEST(test_getPixelOffsetFromRow);
    UNITY_END();
}

void loop() {}