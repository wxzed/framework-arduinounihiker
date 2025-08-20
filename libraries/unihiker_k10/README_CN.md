unihiker_k10
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

DFR0992是一款与AI相关的教学开发板。板载集成语音识别，人脸识别，板载按键，LCD屏幕，金手指，温湿度等传感器。

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。


## 方法

```C++
  /**
     * @fn begin
     * @brief 初始化星空版K 10
     */
    void begin(void);

    /**
     * @fn initScreen
     * @brief 初始化屏幕
     * @param dir 初始化屏幕方向
     * @param faram 屏幕显示帧率
     */
    void initScreen(int dir=2, int frame = 0);

    /**
     * @fn setScreenBackground
     * @brief 设置背景颜色
     * @param color 背景颜色
     */
    void setScreenBackground(uint32_t color);

    /**
     * @fn creatCanvas
     * @brief 创建画布
     */
    void creatCanvas(void);

    /**
     * @fn initBgCamerImage
     * @brief 初始化摄像头
     */
    void initBgCamerImage(void);
    /**
     * @fn setBgCamerImage
     * @brief 设置屏幕是否显示摄像头画面
     * @param sta 配置状态
     */
    void setBgCamerImage(bool sta = true);

    /**
     * @fn initSDFile
     * @brief 初始化SD卡文件系统
    */
    void initSDFile(void);

    /**
     * @fn photoSaveToTFCard
     * @brief 拍照存储在SD卡中
     * @param 拍照存储路径
     */
    void photoSaveToTFCard(const char *imagePath);
    void photoSaveToTFCard(String imagePath);

    /**
     * @brief 获取光线强度
     * 
     * @return uint16_t 返回获取的光线强度
     */
    uint16_t readALS(void);

    /**
     * @brief 获取紫外线强度
     * 
     * @return uint16_t 返回获取的紫外线
     */
    uint16_t readUVS(void);

    /**
     * @brief 读取麦克风数据
    */
    int16_t readMICData(void);

    /**
     * @fn getAccelerometerX
     * @brief 获取加速度X数据
     */
    int getAccelerometerX();

    /**
     * @fn getAccelerometerY
     * @brief 获取加速度Y数据
     */
    int getAccelerometerY();

    /**
     * @fn getAccelerometerZ
     * @brief 获取加速度Z数据
     */
    int getAccelerometerZ();

    /**
     * @fn getStrength
     * @brief 获取占比
     */
    int getStrength();

    /**
     * @fn isGesture
     * @brief 设置加速度状态
     * @param gesture 状态配置
     */
    bool isGesture(Gesture gesture);

    /**
     * @fn canvasDrawCode
     * @brief 显示二维码 对象显示
     */
    void canvasDrawCode(String code);

    /**
     * @fn clearCode
     * @brief 清除二维码
     */
    void clearCode(void);
    /**
     * @fn playMusic
     * @brief 后台播放内置音乐
     * @param melodies 音乐选择
     * @param options 播放形式
     */
    void playMusic(Melodies melodies, MelodyOptions options = Once);

    /**
     * @brief 播放指定音符
     * @param frequency 音符
     * @param samples 节拍 一拍8000 1/2拍4000 其他同理
    */
    void playTone(int freq, int beat);
    /**
     * @fn stopPlayTone
     * @brief 停止播放
     */
    void stopPlayTone(void);
    /**
     * @fn playTFCardAudio
     * @brief 播放SD卡中的音乐
     */
    void playTFCardAudio(const char* path);
    void playTFCardAudio(String path);

    /**
     * @fn stopPlayAudio
     * @brief 停止SD卡播放的音乐
     */
    void stopPlayAudio(void);
    /**
     * @fn recordSaveToTFCard
     * @brief 录音到SD看中
     * @param path 存储路径
     * @param time 录制时长
     */
    void recordSaveToTFCard(const char* path,  uint8_t time);
    void recordSaveToTFCard(String path,  uint8_t time);
    /**
     * @fn write
     * @brief 设置灯3原色
     * @param index 灯号
     * @param r 红色
     * @param g 绿色
     * @param b 蓝色
     */
    void write(int8_t index, uint8_t r, uint8_t g, uint8_t b);
    /**
     * @fn write
     * @brief 设置灯颜色
     * @param index 设置灯号
     * @param color 颜色
     */
    void write(int8_t index, uint32_t color) { write(index, 0xff & (color >> 16), 0xff & (color >> 8), 0xff & color); }
    /**
     * @fn setRangeColor
     * @brief 设置灯从多少亮到多少
     * @param start 开始灯号
     * @param end 结束灯号
     * @param c 灯颜色
     */
    void setRangeColor(int16_t start, int16_t end, uint32_t c);
    /**
     * @fn brightness
     * @brief 设置灯亮度
     */
    void brightness(uint8_t b);
    /**
     * @fn isPressed
     * @brief 检测按键是否被按下
     */
    bool isPressed(void);
    /**
     * @fn setPressedCallback
     * @brief 设置按键按下回调
     * @param _cb 回到函数
     */
    void setPressedCallback(CBFunc _cb);
    /**
     * @fn setUnPressedCallback
     * @brief 设置按键松开回调
     * @param _cb 回到函数
     */
    void setUnPressedCallback(CBFunc _cb);
    /**
     * @fn getData
     * @brief 获取AHT20数据
     * @param type 数据选择
     */
    float getData(eAHT20Data_t type);
    /**
     * @fn updateCanvas
     * @brief 更新屏幕显示 注：使用摄像头时自动更新
     */
    void updateCanvas(void);

    /**
     * @fn canvasClear
     * @brief 清除画布 注:清除画布上属性
     */
    void canvasClear(void);

    /**
     * @fn canvasDrawBitmap
     * @brief 在画布上显示本地图片
     * @param x 显示坐标X
     * @param y 显示坐标Y
     * @param w 图片宽度
     * @param h 图片高度
     * @param bitmap 图像数据
     */
    void canvasDrawBitmap(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t* bitmap);

    /**
     * @fn canvasDrawImage
     * @brief 加载SD卡中图片
     * @param x 显示坐标X
     * @param y 显示坐标Y
     * @param imagePath 图片路径
     */
    void canvasDrawImage(int16_t x, int16_t y, const void *dir);
    void canvasDrawImage(int16_t x, int16_t y, String imagePath);

    

    /**
     * @fn canvasText
     * @brief 在画布上显示文字
     * @param text 文字内容
     * @param row 行
     * @param color 显示颜色
     */
    void canvasText(float text, uint8_t row, uint32_t color);
    void canvasText(String text, uint8_t row, uint32_t color);
    void canvasText(const char* text, uint8_t row, uint32_t color);
    /**
     * @fn canvasClear
     * @brief 清除画布上文字
     * @param row 需要清除行
     */
    void canvasClear(uint8_t row);

     /**
     * @fn clearLocal
     * @brief 清除画布局部内容
     * @param obj 画布对象
     * @param x 起始X坐标
     * @param y 起始Y坐标
     * @param w 长度
     * @param h 宽度
    */
    void clearLocalCanvas(uint16_t x,uint16_t y,uint16_t w,uint16_t h);

    /**
     * @fn canvasText
     * @brief 在画布上显示文字
     * @param text 文字内容
     * @param x 显示坐标X
     * @param y 显示坐标Y 
     * @param color 显示颜色
     * @param font 字体大小
     * @param count 换行字数
     * //需要沟通讨论
     */
    void canvasText(float text, int16_t x, int16_t y, uint32_t color, eFontSize_t font, int count);
    void canvasText(String text, int16_t x, int16_t y, uint32_t color, eFontSize_t font, int count);
    void canvasText(const char* text, int16_t x, int16_t y, uint32_t color, eFontSize_t font, int count);
    
    /**
     * @fn canvasPoint
     * @brief 画点
     * @param x 显示坐标X
     * @param y 显示坐标Y
     * @param color 显示颜色
     */
    void canvasPoint(int16_t x, int16_t y, uint32_t color);

    /**
     * @fn canvasSetLineWidth
     * @brief 设置线宽
     * @param w 线宽
     */
    void canvasSetLineWidth(uint8_t w = 10);

    /**
     * @fn canvasLine
     * @brief 画线
     * @param x1,y2 起点坐标
     * @param x2,y2 终点坐标
     * @param color 颜色
     */
    void canvasLine(int x1, int y1, int x2, int y2, uint32_t color);

    /**
     * @fn canvasCircle
     * @brief 画圆
     * @param x 显示坐标X
     * @param y 显示坐标Y
     * @param r 圆半径
     * @param color 边框颜色
     * @param bg_color 背景颜色
     * @param fill 是否填充
     */
    void canvasCircle(int x, int y, int r, uint32_t color, uint32_t bg_color, bool fill);

    /**
     * @fn canvasRectangle
     * @brief 画矩形
     * @param x 显示坐标X
     * @param y 显示坐标Y
     * @param w 矩形宽度
     * @param h 矩形高度
     * @param color 边框颜色
     * @param bg_color 背景颜色
     * @param fill 是否填充
     */
    void canvasRectangle(int x, int y, int w, int h, uint32_t color, uint32_t bg_color, bool fill);

```


## 兼容性

MCU                |     face     |      cat     |      asr     |     AHT20    |      lux     |      move    | 
------------------ | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: |  
esp32 s3           |      √       |        √     |      √       |      √       |        √     |      √       | 


## 历史
- 2024-07-08 - 1.0.0 版本

## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
