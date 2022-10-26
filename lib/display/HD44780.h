// #############################################################################
// ### Library for LCD based on Hitachi HD44780                              ###
// ### https://github.com/Strooom/HD44780                                    ###
// ### Author(s) : Pascal Roobrouck - @strooom                               ###
// ### License : https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode ###
// ### June 2018                                                             ###
// #############################################################################

#ifndef HD44780_h
#define HD44780_h

#include <stdint.h>        // included so 'uint8_t' etc. are defined

#define RS 0x01        // LCD Register Select is on I2C bit 0
#define RW 0x02        // LCD ReadWrite is on I2C bit 1
#define E 0x04         // LCD Enable (E) is on I2C bit 2
#define BL 0x08        // LCD backlight is on I2C bit 3
// The LCD 4-bit Databus (D4-D7) is on I2C bits 4 - 7

enum class displayType : uint16_t        // Enumeration of possible types. MSByte is nmbr of colums / charsPerLine, LSByte is nmbr of lines
{
    Type16X1 = 0x1001,
    Type16X2 = 0x1002,
    Type16X4 = 0x1004,
    Type20X2 = 0x1402,
    Type20X4 = 0x1404,
    Type40X2 = 0x2802
};        // If you want to add more types, you need to add support for them in the refresh() member function.

// HD44780 Instruction Set : see https://github.com/Strooom/HD44780/blob/master/extras/HD44780%20LCD/SEIKO%20LCD%20User%20Manual.pdf

enum class HD44780Instruction : uint8_t {
    clearDisplay       = 0x01,
    cursorHome         = 0x02,
    entryModeSet       = 0x04,
    onOffControl       = 0x80,
    cursorDisplayShift = 0x10,
    functionSet        = 0x20,
    CGRAMaddressSet    = 0x40,
    DDRAMaddressSet    = 0x80,
    nmbrInstructions
};

enum class HD44780EntryModeShift : uint8_t {
    noShift = 0x00,
    shift   = 0x01
};

enum class HD44780EntryModeDirection : uint8_t {
    decrement = 0x00,
    increment = 0x02
};

enum class HD44780OnOffCtrlDisplay : uint8_t {
    off = 0x00,
    on  = 0x04
};

enum class HD44780OnOffCtrlCursor : uint8_t {
    cursorOff = 0x00,
    cursorOn  = 0x02
};

enum class HD44780OnOffCtrlCursorBlink : uint8_t {
    cursorBlinkOff = 0x00,
    cursorBlinkOn  = 0x01
};

enum class HD44780CursorDisplayShift : uint8_t {
    moveCursor   = 0x00,
    shiftDisplay = 0x08
};

enum class HD44780CursorDisplayShiftDirection : uint8_t {
    left  = 0x00,
    right = 0x04
};

enum class HD44780FunctionSetDataLength : uint8_t {
    fourBit  = 0x00,
    eightBit = 0x10
};

enum class HD44780FunctionSetNumberOfLines : uint8_t {
    oneLine  = 0x00,
    twoLines = 0x08
};

enum class HD44780FunctionSetFont : uint8_t {
    font5x8  = 0x00,
    font5x10 = 0x04
};

class HD44780 {
  public:
    HD44780(displayType theDisplayType, uint8_t I2CAddress);        // Constructor for specific displayType at specific I2C address
    ~HD44780();                                                     // Destructor
    void initialize();                                              // Initialize the display
    void clear(uint8_t theChar = 0x20);                             // clear the complete displayData MCU RAM

    void print(char* string, uint8_t row, uint8_t col);                           // copies the string into the displayData - needs a call to refresh() to actually transfer it to the display
    void writeArray(char* data, uint8_t length, uint8_t row, uint8_t col);        // copies an array (could contain 0x00) of length to the displayData
    void writeByte(char data, uint8_t row, uint8_t col);                          // copies a single byte to the displayData
    void refresh();                                                               // sends all MCU displayData to the display

    void printDirect(char* string, uint8_t row, uint8_t col);                           // copies the string into the displayData and also to the display, no need to call to refresh() to actually transfer it to the display
    void writeByteDirect(char data, uint8_t row, uint8_t col);                          // copies a single byte to the displayData and immediately to the display, so no refresh needed
    void writeArrayDirect(char* data, uint8_t length, uint8_t row, uint8_t col);        // copies an array (could contain 0x00) of length to the displayData

    void setCGRam(const char* CGData, uint8_t index);        // sets the LCD CGRam data at index (0..7) from raw CGData array

    uint8_t getNmbrOfRows() const;
    uint8_t getNmbrOfCols() const;
    uint8_t getNmbrOfChars() const;

    static constexpr uint8_t horizontalPixelsPerCharacter{5};
    static constexpr uint8_t verticalPixelsPerCharacter{8};
    static constexpr uint8_t pixelsBetweenCharacters{1};


  private:
    uint8_t ramAddressfromRowCol(uint8_t row, uint8_t col);        // calculate for each type of display, the LCD ram address, from row / col coordinates
    void writeNibbleLCD(uint8_t iData, bool commandData);          // private helper function to write 4 bits to the LCD
    void writeByteLCD(uint8_t iData, bool commandData);            // private helper function to write 8 bits to the LCD

    displayType theDisplayType;        // type of the display, in nmbrOfRows * chars
    uint8_t I2CAddress;                // I2C address of the display
    uint8_t* displayData;              // pointer to dynamic storage which holds a copy of the data to be shown on the display
    bool backLight;                    // is the backLight on/off
    uint8_t nmbrOfColumns;             // how many columns (=chars) on one line
    uint8_t nmbrOfRows;                // how many rows = lines no the display
    uint8_t nmbrOfChars;               // how many chars in total
};

#endif
