# UNIHIKER K10

* [Chinese Version](./README_CN.md)

DFR0992 is an AI-related educational development board.

![Product Image](../../resources/images/SEN0611.png)

## Product Link

- [Product Link](https://www.dfrobot.com)
- SKU: DFR0992

## Table of Contents

- [Overview](#overview)
- [Library Installation](#library-installation)
- [Methods](#methods)
- [Compatibility](#compatibility)
- [History](#history)
- [Authors](#authors)

## Overview

DFR0992 is an AI-related educational development board. It integrates voice recognition, face recognition, onboard buttons, LCD screen, GPIO headers, temperature and humidity sensors, and more.

## Library Installation

Before using this library, download the library files, paste them into the \Arduino\libraries directory, and then open the examples folder to run the demos.

## Methods

```cpp
/**
 * @fn begin
 * @brief Initialize UNIHIKER K10 board
 */
void begin(void);

/**
 * @fn initScreen
 * @brief Initialize the screen
 * @param dir Screen orientation
 * @param frame Screen display frame rate
 */
void initScreen(int dir = 2, int frame = 0);

/**
 * @fn setScreenBackground
 * @brief Set the screen background color
 * @param color Background color
 */
void setScreenBackground(uint32_t color);

/**
 * @fn creatCanvas
 * @brief Create a canvas
 */
void creatCanvas(void);

/**
 * @fn initBgCamerImage
 * @brief Initialize the camera image
 */
void initBgCamerImage(void);

/**
 * @fn setBgCamerImage
 * @brief Set whether to display the camera image on the screen
 * @param sta Configuration status
 */
void setBgCamerImage(bool sta = true);

/**
 * @fn initSDFile
 * @brief Initialize the SD card file system
 */
void initSDFile(void);

/**
 * @fn photoSaveToTFCard
 * @brief Save a photo to the SD card
 * @param imagePath Path to save the photo
 */
void photoSaveToTFCard(const char *imagePath);
void photoSaveToTFCard(String imagePath);

/**
 * @brief Get the ambient light intensity
 * @return uint16_t Ambient light intensity
 */
uint16_t readALS(void);

/**
 * @brief Get the UV light intensity
 * @return uint16_t UV light intensity
 */
uint16_t readUVS(void);

/**
 * @brief Read microphone data
 * @return int16_t Microphone data
 */
int16_t readMICData(void);

/**
 * @fn getAccelerometerX
 * @brief Get accelerometer X-axis data
 */
int getAccelerometerX();

/**
 * @fn getAccelerometerY
 * @brief Get accelerometer Y-axis data
 */
int getAccelerometerY();

/**
 * @fn getAccelerometerZ
 * @brief Get accelerometer Z-axis data
 */
int getAccelerometerZ();

/**
 * @fn getStrength
 * @brief Get strength
 */
int getStrength();

/**
 * @fn isGesture
 * @brief Detect gesture
 * @param gesture Gesture state
 */
bool isGesture(Gesture gesture);

/**
 * @fn canvasDrawCode
 * @brief Display QR code
 * @param code QR code to display
 */
void canvasDrawCode(String code);

/**
 * @fn clearCode
 * @brief Clear QR code from display
 */
void clearCode(void);

/**
 * @fn playMusic
 * @brief Background play of built-in music
 * @param melodies Music selection
 * @param options Playback options
 */
void playMusic(Melodies melodies, MelodyOptions options = Once);

/**
 * @brief Play a specified note
 * @param frequency Note frequency
 * @param samples Beat: 8000 for full beat, 4000 for half beat, others similarly
 */
void playTone(int freq, int beat);

/**
 * @fn stopPlayTone
 * @brief Stop playing tone
 */
void stopPlayTone(void);

/**
 * @fn playTFCardAudio
 * @brief Play music from SD card
 */
void playTFCardAudio(const char* path);
void playTFCardAudio(String path);

/**
 * @fn stopPlayAudio
 * @brief Stop playing music from SD card
 */
void stopPlayAudio(void);

/**
 * @fn recordSaveToTFCard
 * @brief Record and save to SD card
 * @param path Storage path
 * @param time Recording duration
 */
void recordSaveToTFCard(const char* path, uint8_t time);
void recordSaveToTFCard(String path, uint8_t time);

/**
 * @fn write
 * @brief Set RGB LED color
 * @param index LED index
 * @param r Red value
 * @param g Green value
 * @param b Blue value
 */
void write(int8_t index, uint8_t r, uint8_t g, uint8_t b);

/**
 * @fn setRangeColor
 * @brief Set range of RGB LED colors
 * @param start Start LED index
 * @param end End LED index
 * @param c Color
 */
void setRangeColor(int16_t start, int16_t end, uint32_t c);

/**
 * @fn brightness
 * @brief Set RGB LED brightness
 */
void brightness(uint8_t b);

/**
 * @fn isPressed
 * @brief Check if a button is pressed
 */
bool isPressed(void);

/**
 * @fn setPressedCallback
 * @brief Set callback function for button press
 * @param _cb Callback function
 */
void setPressedCallback(CBFunc _cb);

/**
 * @fn setUnPressedCallback
 * @brief Set callback function for button release
 * @param _cb Callback function
 */
void setUnPressedCallback(CBFunc _cb);

/**
 * @fn getData
 * @brief Get data from AHT20 sensor
 * @param type Data type to retrieve
 */
float getData(eAHT20Data_t type);

/**
 * @fn updateCanvas
 * @brief Update screen display (automatically updates when using camera)
 */
void updateCanvas(void);

/**
 * @fn canvasClear
 * @brief Clear canvas properties
 */
void canvasClear(void);

/**
 * @fn canvasDrawBitmap
 * @brief Display a local image on the canvas
 * @param x Display coordinate X
 * @param y Display coordinate Y
 * @param w Image width
 * @param h Image height
 * @param bitmap Image data
 */
void canvasDrawBitmap(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t* bitmap);

/**
 * @fn canvasDrawImage
 * @brief Load an image from SD card
 * @param x Display coordinate X
 * @param y Display coordinate Y
 * @param imagePath Image path
 */
void canvasDrawImage(int16_t x, int16_t y, const void *dir);
void canvasDrawImage(int16_t x, int16_t y, String imagePath);

/**
 * @fn canvasText
 * @brief Display text on the canvas
 * @param text Text content
 * @param row Row to display
 * @param color Text color
 */
void canvasText(float text, uint8_t row, uint32_t color);
void canvasText(String text, uint8_t row, uint32_t color);
void canvasText(const char* text, uint8_t row, uint32_t color);

/**
 * @fn canvasClear
 * @brief Clear text from the canvas
 * @param row Row to clear
 */
void canvasClear(uint8_t row);

/**
 * @fn clearLocalCanvas
 * @brief Clear a portion of the canvas
 * @param x Starting X coordinate
 * @param y Starting Y coordinate
 * @param w Length
 * @param h Width
 */
void clearLocalCanvas(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

/**
 * @fn canvasText
 * @brief Display text on the canvas
 * @param text Text content
 * @param x Display coordinate X
 * @param y Display coordinate Y 
 * @param color Text color
 * @param font Font size
 * @param count Line break count
 */
void canvasText(float text, int16_t x, int16_t y, uint32_t color, eFontSize_t font, int count);
void canvasText(String text, int16_t x, int16_t y, uint32_t color, eFontSize_t font, int count);
void canvasText(const char* text, int16_t x, int16_t y, uint32_t color, eFontSize_t font, int count);

/**
 * @fn canvasPoint
 * @brief Draw a point on the canvas
 * @param x Display coordinate X
 * @param y Display coordinate Y
 * @param color Point color
 */
void canvasPoint(int16_t x, int16_t y, uint32_t color);

/**
 * @fn canvasSetLineWidth
 * @brief Set line width for drawing
 * @param w Line width
 */
void canvasSetLineWidth(uint8_t w = 10);

/**
 * @fn canvasLine
 * @brief Draw a line on the canvas
 * @param x1, y1 Starting coordinates
 * @param x2, y2 Ending coordinates
 * @param color Line color
 */
void canvasLine(int x1, int y1, int x2, int y2, uint32_t color);

/**
 * @fn canvasCircle
 * @brief Draw a circle on the canvas
 * @param x Display coordinate X
 * @param y Display coordinate Y
 * @param r Circle radius
 * @param color Border color
 * @param bg_color Background color
 * @param fill Whether to fill the circle
 */
void canvasCircle(int x, int y, int r, uint32_t color, uint32_t bg_color, bool fill);

/**
 * @fn canvasRectangle
 * @brief Draw a rectangle on the canvas
 * @param x Display coordinate X
 * @param y Display coordinate Y
 * @param w Rectangle width
 * @param h Rectangle height
 * @param color Border color
 * @param bg_color Background color
 * @param fill Whether to fill the rectangle
 */
void canvasRectangle(int x, int y, int w, int h, uint32_t color, uint32_t bg_color, bool fill);

```


## Compatibility

MCU                |     face     |      cat     |      asr     |     AHT20    |      lux     |      move    | 
------------------ | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: |  
esp32 s3           |      √       |        √     |      √       |      √       |        √     |      √       | 


## History
- 2024-07-08 - Version 1.0.0

## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
