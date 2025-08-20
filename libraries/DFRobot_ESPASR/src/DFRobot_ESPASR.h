#ifndef _DFROBOT_ESPASR_H
#define _DFROBOT_ESPASR_H
#include "Arduino.h"

#include "esp_process_sdkconfig.h"
#include "esp_wn_iface.h"
#include "esp_wn_models.h"
#include "esp_afe_sr_iface.h"
#include "esp_afe_sr_models.h"
#include "esp_mn_iface.h"
#include "esp_mn_models.h"
#include "model_path.h"
#include "esp_mn_speech_commands.h"

#define STACKSPACE_AWAKEN  0//唤醒任务堆栈剩余空间
//中英模式
#define CN_MODE        0
#define EN_MODE        1

#define  ONCE        0
#define  CONTINUOUS  1

class DFRobot_ESPASR {
public:
    DFRobot_ESPASR(void){};

    /**
    * @brief 初始化语音识别
    * 
    * @param enable 是否是能连续识别
    * @param xQueueID 返回识别词条ID的队列
    * @param wakeUpTime 唤醒时间
    * @param modeType CN:中文 EN:英文
    */
    void initASR(uint8_t mode= 0,QueueHandle_t xQueueID=NULL,uint8_t modeType = 0,uint16_t wakeUpTime = 6000);

    /**
     * @brief 添加命令词条
     * 
     * @param id 词条对应的ID
     * @param data 词条内容
     */
    void _addASRCommand(uint8_t id, char* data);

    uint8_t _asrState = 0;//标记语音是否初始化完成
    uint16_t _wakeUpTime = 0;
    uint8_t _modeType = 0;
    uint8_t _recognitionMode = 0;
    srmodel_list_t *models;
    esp_afe_sr_iface_t *afe_handle;
    bool _wakeUp = false;

};


#endif

