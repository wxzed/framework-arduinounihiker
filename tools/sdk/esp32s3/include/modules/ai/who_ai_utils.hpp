/*
 * @Author: tangjie133 1334875503@qq.com
 * @Date: 2023-01-14 10:12:45
 * @LastEditors: tangjie133 1334875503@qq.com
 * @LastEditTime: 2024-04-19 11:34:54
 * @FilePath: \esp-who\components\modules\ai\who_ai_utils.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include <list>
#include "dl_detect_define.hpp"
#include "esp_camera.h"
#include "face_recognition_tool.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "freertos/semphr.h"



typedef enum
{
    IDLE = 0,
    DETECT,
    ENROLL,
    RECOGNIZE,
    DELETE,
    DELETEALL,
} recognizer_state_t;

typedef struct{
  int  faceFrameLength;
  int  faceFrameWidth;
  int  leftEye[2];
  int  rightEye[2];
  int  nose[2];
  int  leftMouth[2];
  int  rightMouth[2];
}sFaceData_t;

typedef struct{
  int  catFrameLength;
  int  catFrameWidth;
}sCatData_t;

typedef struct{
  int enrolledID;//人脸当前学习的ID
  const char* codeData;//二维码数据
  bool is_moved;//移动检测数据
  bool is_faceok;//是否检测到
  bool is_catok;//是否检测到
  bool is_codeok;//是否检测到
  std::list<dl::detect::result_t> *is_detectResults; // 检测结果
}sAIRead_t;

typedef struct{
  recognizer_state_t cmd;//执行命令
  uint8_t id; //人脸ID
}sAISet_t;

typedef struct{
  std::list<dl::detect::result_t> *_detectResults; // 检测结果
  camera_fb_t *_frame;//人脸数据
}sAIRecognition_t;



/**
 * @brief Draw detection result on RGB565 image.
 * 
 * @param image_ptr     image
 * @param image_height  height of image
 * @param image_width   width of image
 * @param results       detection results
 */
void draw_detection_result(uint16_t *image_ptr, int image_height, int image_width, std::list<dl::detect::result_t> &results);

// /**
//  * @brief Draw detection result on RGB888 image.
//  * 
//  * @param image_ptr     image
//  * @param image_height  height of image
//  * @param image_width   width of image
//  * @param results       detection results
//  */

// void draw_detection_result(uint8_t *image_ptr, int image_height, int image_width, std::list<dl::detect::result_t> &results);

// /**
//  * @brief Print detection result in terminal
//  * 
//  * @param results detection results
//  */
// void print_detection_result(std::list<dl::detect::result_t> &results);

// /**
//  * @brief Decode fb , 
//  *        - if fb->format == PIXFORMAT_RGB565, then return fb->buf
//  *        - else, then return a new memory with RGB888, don't forget to free it
//  * 
//  * @param fb 
//  */
// void *app_camera_decode(camera_fb_t *fb);


// void getFaceData(std::list<dl::detect::result_t> &results, sAIRead_t *face);

// void getDataCat(std::list<dl::detect::result_t> &results, sAIRead_t *cat);
