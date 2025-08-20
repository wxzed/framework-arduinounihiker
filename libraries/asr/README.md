asr
===========================
* [English Version](./README_CN.md)

DFR0992 is a teaching development board related to AI.

![Product Effect Picture](../../resources/images/SEN0611.png)

## Product Link (https://www.dfrobot.com)

    SKU: SEN0611
  
## Table of Contents

  * [Overview](#overview)
  * [Library Installation](#library-installation)
  * [Methods](#methods)
  * [Compatibility](#compatibility)
  * [History](#history)
  * [Authors](#authors)

## Overview

DFR0992 is a teaching development board related to AI. It integrates on-board features such as voice recognition, face recognition, on-board buttons, LCD screen, gold fingers, temperature and humidity sensors, among others.

## Library Installation

Before using this library, please download the library files, paste them into the \Arduino\libraries directory, and then open the examples folder to run the demos.

## Methods

```C++
  /**
     * @fn begin
     * @brief Initialize Unihiker K 10
     */
    void begin(void);

    /**
     * @fn initScreen
     * @brief Initialize the screen
     * @param dir Screen initialization direction
     * @param faram Screen display frame rate
     */
    void initScreen(int dir=2, int frame = 0);

    /**
     * @fn setScreenBackground
     * @brief Set the background color
     * @param color Background color
     */
    void setScreenBackground(uint32_t color);

    /**
     * @fn creatCanvas
     * @brief Create canvas
     */
    void creatCanvas(void);

    /**
     * @fn initBgCamerImage
     * @brief Initialize the camera
     */
    void initBgCamerImage(void);
    /**
     * @fn setBgCamerImage
     * @brief Set whether the screen displays the camera image
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
     * @brief Save photos to SD card
     * @param imagePath Path to save photos
     */
    void photoSaveToTFCard(const char *imagePath);
    void photoSaveToTFCard(String imagePath);

    /**
     * @brief Get light intensity
     * 
     * @return uint16_t Returns the obtained light intensity
     */
    uint16_t readALS(void);

    /**
     * @brief Get UV intensity
     * 
     * @return uint16_t Returns the obtained UV intensity
     */
    uint16_t readUVS(void);

    /**
     * @brief Read microphone data
    */
    int16_t readMICData(void);

    /**
     * @fn getAccelerometerX
     * @brief Get acceleration X data
     */
    int getAccelerometerX();

    /**
     * @fn getAccelerometerY
     * @brief Get acceleration Y data
     */
    int getAccelerometerY();

    /**
     * @fn getAccelerometerZ
     * @brief Get acceleration Z data
     */
    int getAccelerometerZ();

    /**
     * @fn getStrength
     * @brief Get percentage
     */
    int getStrength();

    /**
     * @fn isGesture
     * @brief Set acceleration status
     * @param gesture Status configuration
     */
    bool isGesture(Gesture gesture);

    /**
     * @fn canvasDrawCode
     * @brief Display QR code object
     */
    void canvasDrawCode(String code);

    /**
     * @fn clearCode
     * @brief Clear QR code
     */
    void clearCode(void);
    /**
     * @fn playMusic
     * @brief Background play built-in music
     * @param melodies Music selection
     * @param options Playback form
     */
    void playMusic(Melodies melodies, MelodyOptions options = Once);

    /**
     * @brief Play specified note
     * @param frequency Note
     * @param samples Beat 1 beat 8000 1/2 beat 4000 others are the same
    */
    void playTone(int freq, int beat);
    /**
     * @fn stopPlayTone
     * @brief Stop playing
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
     * @brief Stop SD card music playback
     */
    void stopPlayAudio(void);
    /**
     * @fn recordSaveToTFCard
     * @brief Record to SD look
     * @param path Storage path
     * @param time Recording duration
     */
    void recordSaveToTFCard(const char* path,  uint8_t time);
    void recordSaveToTFCard(String path,  uint8_t time);
    /**
     * @fn write
     * @brief Set light 3 primary colors
     * @param index Lamp number
     * @param r Red
     * @param g Green
     * @param b Blue
     */
    void write(int8_t index, uint8_t r, uint8_t g, uint8_t b);
    /**
     * @fn write
     * @brief Set light color
     * @param index Set lamp number
     * @param color Color
     */
    void write(int8_t index, uint32_t color) { write(index, 0xff & (color >> 16), 0xff & (color >> 8), 0xff & color); }
    /**
     * @fn setRangeColor
     * @brief Set the brightness from the starting to the end
     * @param start Start lamp number
     * @param end End lamp number
     * @param c Lamp color
     */
    void setRangeColor(int16_t start, int16_t end, uint32_t c);
    /**
     * @fn brightness
     * @brief Set light brightness
     */
    void brightness(uint8_t b);
    /**
     * @fn isPressed
     * @brief Check if the button is pressed
     */
    bool isPressed(void);
    /**
     * @fn setPressedCallback
     * @brief Set button press callback
     * @param _cb Callback function
     */
    void setPressedCallback(CBFunc _cb);
    /**
     * @fn setUnPressedCallback
     * @brief Set button release callback
     * @param _cb Callback function
     */
    void setUnPressedCallback(CBFunc _cb);
    /**
     * @fn getData
     * @brief Get AHT20 data
     * @param type Data selection
     */
    float getData(eAHT20Data_t type);
    /**
     * @fn updateCanvas
     * @brief Update screen display Note: Automatically update when using the camera
     */
    void updateCanvas(void);

    /**
     * @fn canvasClear
     * @brief Clear canvas Note: Clear attributes on canvas
     */
    void canvasClear(void);

    /**
     * @fn canvasDrawBitmap
     * @brief Display local image on canvas
     * @param x Display coordinate X
     * @param y Display coordinate Y
     * @param w Image width
     * @param h Image height
     * @param bitmap Image data
     */
    void canvasDrawBitmap(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t* bitmap);

    /**
     * @fn canvasDrawImage
     * @brief Load images from SD card
     * @param x Display coordinate X
     * @param y Display coordinate Y
     * @param imagePath Image path
     */
    void canvasDrawImage(int16_t x, int16_t y, const void *dir);
    void canvasDrawImage(int16_t x, int16_t y, String imagePath);

    

    /**
     * @fn canvasText
     * @brief Display text on canvas
     * @param text Text content
     * @param row Row
     * @param color Display color
     */
    void canvasText(float text, uint8_t row, uint32_t color);
    void canvasText(String text, uint8_t row, uint32_t color);
    void canvasText(const char* text, uint8_t row, uint32_t color);
    /**
     * @fn canvasClear
     * @brief Clear text on canvas
     * @param row Row to clear
     */
    void canvasClear(uint8_t row);

     /**
     * @fn clearLocal
     * @brief Clear part of the canvas content
     * @param obj Canvas object
     * @param x Starting X coordinate
     * @param y Starting Y coordinate
     * @param w Length
     * @param h Width
    */
    void clearLocalCanvas(uint16_t x,uint16_t y,uint16_t w,uint16_t h);

    /**
     * @fn canvasText
     * @brief Display text on canvas
     * @param text Text content
     * @param x Display coordinate X
     * @param y Display coordinate Y 
     * @param color Display color
     * @param font Font size
     * @param count Line break count
     * //Need to communicate and discuss
     */

    void canvasText(float text, int16_t x, int16_t y, uint32_t color, eFontSize_t font, int count);
    void canvasText(String text, int16_t x, int16_t y, uint32_t color, eFontSize_t font, int count);
    void canvasText(const char* text, int16_t x, int16_t y, uint32_t color, eFontSize_t font, int count);
    
    /**
     * @fn canvasPoint
     * @brief Draw point
     * @param x Display coordinate X
     * @param y Display coordinate Y
     * @param color Display color
     */
    void canvasPoint(int16_t x, int16_t y, uint32_t color);

    /**
     * @fn canvasSetLineWidth
     * @brief Set line width
     * @param w Line width
     */
    void canvasSetLineWidth(uint8_t w = 10);

    /**
     * @fn canvasLine
     * @brief Draw line
     * @param x1, y2 Starting coordinates
     * @param x2, y2 End coordinates
     * @param color Color
     */
    void canvasLine(int x1, int y1, int x2, int y2, uint32_t color);

    /**
     * @fn canvasCircle
     * @brief Draw circle
     * @param x Display coordinate X
     * @param y Display coordinate Y
     * @param r Circle radius
     * @param color Border color
     * @param bg_color Background color
     * @param fill Whether to fill
     */
    void canvasCircle(int x, int y, int r, uint32_t color, uint32_t bg_color, bool fill);

    /**
     * @fn canvasRectangle
     * @brief Draw rectangle
     * @param x Display coordinate X
     * @param y Display coordinate Y
     * @param w Rectangle width
     * @param h Rectangle height
     * @param color Border color
     * @param bg_color Background color
     * @param fill Whether to fill
     */
    void canvasRectangle(int x, int y, int w, int h, uint32_t color, uint32_t bg_color, bool fill);


```


## Compatibility

MCU                |     face     |      cat     |      asr     |     AHT20    |      lux     |      move    | 
------------------ | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: |  
esp32 s3           |      √       |        √     |      √       |      √       |        √     |      √       | 


## History
- 2024-07-08 - Version 1.0.0

## Authors

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
