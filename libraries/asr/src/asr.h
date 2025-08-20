#ifndef _ASR_H_
#define _ASR_H_

#include "Arduino.h"
#include "DFRobot_ESPASR.h"
#include "esp_tts.h"

class ASR:public DFRobot_ESPASR {

public:
    
    enum eAsrSpeed_t
    {
        Fast,    // 快
        Medium,  // 中
        Slow,    // 慢
    };

    ASR(void){};

    /** 
     * @brief 初始化语音识别
     * @param mode 模式：单次|连续
     * @param lang 语言：中文|英文
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
     * @param speed 语速，范围0~5
     */
    void setAsrSpeed(uint8_t speed);

    /**
     * @fn speak
     * @brief 合成语音
     * @param prompt 合成语音内容
     */
    void speak(String prompt);
    void speak(const char *prompt);
    void speak(float prompt);


    uint8_t _isDetectCmdID = 0;

    esp_tts_handle_t *tts_handle = NULL;

    QueueHandle_t xQueueTTS = NULL;



};

#endif
