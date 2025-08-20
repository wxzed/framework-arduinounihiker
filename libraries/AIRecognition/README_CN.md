AIRecognition
===========================

* [English Version](./README.md)

DFR0992是一款与AI相关的教学开发板。

![产品效果图片](../../resources/images/SEN0611.png)

## 产品链接（https://www.dfrobot.com）

    SKU：SEN0611
  
## 目录

  * [概述](#概述)
  * [库安装](#库安装)
  * [方法](#方法)
  * [兼容性](#兼容性)
  * [历史](#历史)
  * [创作者](#创作者)

## 概述

该库用于ai的人脸识别，猫脸检测，二维码识别

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。


## 方法

```C++
  /**
     * @fn init
     * @brief 初始化AI
    */
    void initAi(void);

    /**
     * @fn switchAiMode
     * @brief 选择ai模式
    */
    void switchAiMode(eAiType_t mode);

    /**
     * @fn getFaceData
     * @brief 获取检测到人脸数据
    */
    int getFaceData(eFaceOrCatData_t type);

    /**
     * @fn getCatData
     * @brief 获取检测猫脸数据
    */
    int getCatData(eFaceOrCatData_t type);
    /**
     * @fn isDetectContent
     * @brief 检测到数据
     * @param mode 具体数据
    */
    bool isDetectContent(eAiType_t mode);
  

    /**
     * @fn sendFaceCmd
     * @brief 发送人脸指令
    */
    void sendFaceCmd(recognizer_state_t cmd);
    void sendFaceCmd(uint8_t cmd, int id);

    /**
     * @fn setMotinoThreshold
     * @brief 设置移动灵敏度，范围10~200
    */
    void setMotinoThreshold(uint8_t threshold);
    /**
     * @fn getQrCodeContent
     * @brief 获取二维码数据
     * @return 返回识别的二维码
     */
    String getQrCodeContent(void);
    /**
     * @fn getRecognitionID
     * @brief 获取人脸识别ID
     * @return 返回人脸识别ID
     */
    int getRecognitionID(void);
    /**
     * @fn isRecognized
     * @brief 人脸识别是否完成
     * @return 返回识别状态
     */
    bool isRecognized(void);

```


## 兼容性

MCU                |     face     |      cat     |      move    |     qrcode   |
------------------ | :----------: | :----------: | :----------: | :----------: | 
esp32 s3           |      √       |        √     |      √       |      √       |


## 历史
- 2024-07-08 - 1.0.0 版本

## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
