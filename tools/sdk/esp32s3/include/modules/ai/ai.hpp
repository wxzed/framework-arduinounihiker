#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_code_scanner.h"


// /**
//  * @brief 注册AI
//  * 
//  * @param frame_i 图像输入队列
//  * @param event   控制输入队列
//  * @param result  数据返回队列
//  * @param text    屏幕显示文字队列
//  * @param frame_o 图像输出队列
//  * @param continuousRecognition 
//  */
// void register_ai(QueueHandle_t frame_i,
//                 QueueHandle_t event,
//                 QueueHandle_t result,
//                 QueueHandle_t text,
//                 QueueHandle_t frame_o = NULL,
//                 const bool continuousRecognition = false);

 void task_face_recognition(void *arg);
 void task_cat_recognition(void *arg);
 void task_motion_recognition(void *arg);
 void task_code_recognition(void *arg);
 void task_event_handler(void *arg);       
 void task_nomode_handler(void *arg);           

