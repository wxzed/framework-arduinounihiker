asr
===========================

* [English Version](./README.md)

DFR0992是一款与AI相关的教学开发板。

![产品效果图片](../../resources/images/SEN0611.png)

## 产品链接（https://www.dfrobot.com）

    SKU：DFR0992
  
## 目录

  * [概述](#概述)
  * [库安装](#库安装)
  * [方法](#方法)
  * [兼容性](#兼容性)
  * [历史](#历史)
  * [创作者](#创作者)

## 概述

该库用于语音合成和语音识别

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。


## 方法

```C++
  /** 
     * @brief 初始化语音识别
     * @param mode 模式 单次|连续
     * @param lang 语言 中文|英文
     * @param wakeUpTime 唤醒时间
    */
    void asrInit(uint8_t mode = 0, uint8_t lang = 0, uint16_t wakeUpTime = 6000);

    /**
     * @fn addASRCommand
     * @brief 添加语音识别命令词
     * @param id 命令词ID
     * @param cmd 命令词数据
     */
    void addASRCommand(uint8_t id, char* cmd);
    void addASRCommand(uint8_t id, String cmd);

    /**
     * @fn isWakeUp
     * @brief 获取唤醒状态
     */
    bool isWakeUp(void);

    /**
     * @fn isDetectCmdID 
     * @brief 获取命令词
     */
    bool isDetectCmdID(uint8_t id);

    /**
     * @fn setAsrSpeed
     * @brief 初始化TTS，并设置语速
     * @param speed 语速 ，范围0~5
     */
    void setAsrSpeed(uint8_t speed);
    /**
     * @fn speak
     * @brief 合成语音
     * @param prompt 合成语音内容
     */
    void speak(String prompt);

```


## 兼容性

MCU                |     asr    |  
------------------ | :----------: |   
esp32 s3           |      √       |  


## 历史
- 2024-07-08 - 1.0.0 版本

## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
