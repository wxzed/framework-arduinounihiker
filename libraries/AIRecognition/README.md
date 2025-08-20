AIRecognition
===========================

* [English Version](./README.md)

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

This library is used for AI face recognition, cat face detection, and QR code recognition.

## Library Installation

Before using this library, download the library files, paste them into the \Arduino\libraries directory, and then open the examples folder to run the demos.

## Methods

```C++
  /**
     * @fn init
     * @brief Initialize AI
    */
    void initAi(void);

    /**
     * @fn switchAiMode
     * @brief Select AI mode
    */
    void switchAiMode(eAiType_t mode);

    /**
     * @fn getFaceData
     * @brief Get detected face data
    */
    int getFaceData(eFaceOrCatData_t type);

    /**
     * @fn getCatData
     * @brief Get detected cat face data
    */
    int getCatData(eFaceOrCatData_t type);

    /**
     * @fn isDetectContent
     * @brief Detect data
     * @param mode Specific data
    */
    bool isDetectContent(eAiType_t mode);

    /**
     * @fn sendFaceCmd
     * @brief Send face command
    */
    void sendFaceCmd(recognizer_state_t cmd);
    void sendFaceCmd(uint8_t cmd, int id);

    /**
     * @fn setMotinoThreshold
     * @brief Set motion sensitivity, range 10~200
    */
    void setMotinoThreshold(uint8_t threshold);

    /**
     * @fn getQrCodeContent
     * @brief Get QR code data
     * @return Recognized QR code
     */
    String getQrCodeContent(void);

    /**
     * @fn getRecognitionID
     * @brief Get face recognition ID
     * @return Face recognition ID
     */
    int getRecognitionID(void);

    /**
     * @fn isRecognized
     * @brief Check if face recognition is complete
     * @return Recognition status
     */
    bool isRecognized(void);


```


## Compatibility

MCU                |     face     |      cat     |      move    |     qrcode   |
------------------ | :----------: | :----------: | :----------: | :----------: | 
esp32 s3           |      √       |        √     |      √       |      √       |


## History
- 2024-07-08 - Version 1.0.0

## Authors

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
