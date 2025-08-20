/**
 * @file asr_en.ino
 * @author tangjie (jie.tang@dfrobot.com)
 * @brief 运行代码实现语音识别
 * @version 0.1
 * @date 2023-08-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "DFRobot_ESP32S3_BIT.h"
#include "DFRobot_ESPASR.h"
QueueHandle_t xQueueID = NULL;
ESP32S3_BIT bit;
DFRobot_ESPASR asr;
uint8_t id;
void setup() {
  Serial.begin(115200);
  //初始化主板
  while(bit.esp32BitBegin() != 0){
      printf("init error");
  }
  bit.initI2S();//初始化I2S
  xQueueID = xQueueCreate(20, sizeof(uint8_t));//创建存储ID的队列
  asr.initASR(CONTINUOUS,xQueueID,EN_MODE);//配置为中文连续识别
  asr.addASRCommand(1,"turn on the light");//配置ID0命令词条kai deng
  asr.addASRCommand(2,"turn off the light");//配置ID1命令词条guan deng
  
}

void loop() {
  if(xQueueReceive(xQueueID, &id, portMAX_DELAY)){
    if(id == 1){
      Serial.println("灯打开");
    }else if(id == 2){
      Serial.println("灯关闭");
    }
  }
}
