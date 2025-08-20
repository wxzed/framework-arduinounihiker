#include "AIRecognition.h"
#include "unihiker_k10.h"
#include "who_ai_utils.hpp"
#include "ai.hpp"


extern uint8_t _sensitivity; 
extern QueueHandle_t xQueueCamer;
extern QueueHandle_t xQueueAI;
static TaskHandle_t faceAITaskHandle = NULL;   // Face recognition handle
static TaskHandle_t eventTaskHandle = NULL;    // Event handle
static TaskHandle_t catAITaskHandle = NULL;    // Cat face recognition handle
static TaskHandle_t moveAITaskHandle = NULL;   // Movement recognition handle
static TaskHandle_t codeAITaskHandle = NULL;   // QR code recognition handle
static TaskHandle_t NoModeTaskHandle = NULL;   // No mode recognition handle
SemaphoreHandle_t readDataMutex;

bool isTaskRunning = true;

typedef struct{
  sCatData_t _catData;
  sFaceData_t _faceData;
  char _codeData[200];
  int centerOfInertia[2];
  int _faceIDNumber;
  bool faceMode;
  bool catMode;
  bool moveMode;
  bool codeMode;
}sAIData_t;

sAIData_t *aiGetData = NULL;
QueueHandle_t xQueueResult = NULL;
QueueHandle_t xQueueEvent= NULL;
uint8_t _moveMode = 0;
//extern sAIRecognition_t * _recognition;
extern SemaphoreHandle_t xLvglMutex;
extern lv_obj_t *_cam;
extern uint8_t _recognize;  
extern int _faceID;  

static void _drawRect(lv_obj_t *obj, int16_t x, int16_t y, int16_t w, int16_t h)
{ // Draw the rectangle for face recognition
  xSemaphoreTake(xLvglMutex, portMAX_DELAY);
  lv_obj_set_size(obj, w, h);  // Set the size of the rectangle
  lv_obj_set_style_border_opa(obj, LV_OPA_COVER, 0);
  lv_obj_set_style_border_color(obj, lv_color_hex(0xff0000), 0);  // Set the border color to red
  lv_obj_set_style_border_width(obj, 2, 0);  // Set the border width to 2 pixels
  lv_obj_set_pos(obj, x, y);  // Set the position of the rectangle
  lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);  // Clear the scrollable flag
  xSemaphoreGive(xLvglMutex);
}


static void _cleanDraRec(lv_obj_t *obj)
{
  lv_obj_set_style_bg_opa(obj,LV_OPA_TRANSP,0);
  lv_obj_set_style_border_opa(obj,LV_OPA_TRANSP,0);
}

static void task_read_ai_data(void *arg)
{
  sAIRead_t* aiData;
  aiGetData = (sAIData_t *)heap_caps_malloc(sizeof(sAIData_t), MALLOC_CAP_SPIRAM);
  assert(aiGetData);
  aiGetData->catMode = false;
  aiGetData->faceMode = false;
  aiGetData->moveMode = false;
  aiGetData->codeMode = false;
  while(1){
    if(xQueueReceive(xQueueResult,&aiData,portMAX_DELAY)){
      xSemaphoreTake(readDataMutex, portMAX_DELAY);
      int i = 1,x =0,y=0,w=0,h=0;
      aiGetData->moveMode = aiData->is_moved;
      aiGetData->faceMode = aiData->is_faceok;
      aiGetData->catMode = aiData->is_catok;
      aiGetData->codeMode = aiData->is_codeok;

      if(aiData->is_faceok){
        for (std::list<dl::detect::result_t>::iterator prediction = aiData->is_detectResults->begin(); prediction != aiData->is_detectResults->end(); prediction++, i++)
        {
          x = prediction->box[0];
          y = prediction->box[1];
          w = prediction->box[2] -  prediction->box[0];
          h = prediction->box[3] - prediction->box[1];
          aiGetData->_faceData.faceFrameLength = w;
          aiGetData->_faceData.faceFrameWidth = h;
          aiGetData->centerOfInertia[0] = (prediction->box[2] -  prediction->box[0])/2 + prediction->box[0];
          aiGetData->centerOfInertia[1] = (prediction->box[3] -  prediction->box[1])/2 + prediction->box[1];
          aiGetData->_faceData.leftEye[0] = prediction->keypoint[0];
          aiGetData->_faceData.leftEye[1] = prediction->keypoint[1];
          aiGetData->_faceData.rightEye[0] = prediction->keypoint[6];
          aiGetData->_faceData.rightEye[1] = prediction->keypoint[7];
          aiGetData->_faceData.nose[0] = prediction->keypoint[4];
          aiGetData->_faceData.nose[1] = prediction->keypoint[5];
          aiGetData->_faceData.leftMouth[0] = prediction->keypoint[2];
          aiGetData->_faceData.leftMouth[1] = prediction->keypoint[3];
          aiGetData->_faceData.rightMouth[0] = prediction->keypoint[8];
          aiGetData->_faceData.rightMouth[1] = prediction->keypoint[9];
        }
                
      }
            
      if(aiData->is_catok){
        for (std::list<dl::detect::result_t>::iterator prediction = aiData->is_detectResults->begin(); prediction != aiData->is_detectResults->end(); prediction++, i++)
        {
          x = prediction->box[0];
          y = prediction->box[1];
          w = prediction->box[2] -  prediction->box[0];
          h = prediction->box[3] - prediction->box[1];
          aiGetData->_catData.catFrameLength = w;
          aiGetData->_catData.catFrameWidth = h;
          aiGetData->centerOfInertia[0] = (prediction->box[2] -  prediction->box[0])/2 + prediction->box[0];
          aiGetData->centerOfInertia[1] = (prediction->box[3] -  prediction->box[1])/2 + prediction->box[1];
        }
      }

      if(aiData->is_codeok){
        if(aiData->codeData){
          strncpy(aiGetData->_codeData,aiData->codeData,strlen(aiData->codeData));
          aiGetData->_codeData[strlen(aiData->codeData)] = '\0';
        }
      }else{
        if(aiData->codeData){
          strncpy(aiGetData->_codeData,aiData->codeData,strlen(aiData->codeData));
          aiGetData->_codeData[strlen(aiData->codeData)] = '\0';
        }
      }

      if(!aiData->is_faceok && !aiData->is_catok){
          aiGetData->_faceData.faceFrameLength = -1;
          aiGetData->_faceData.faceFrameWidth = -1;
          for (int i = 0; i < 2; i++) {
            aiGetData->centerOfInertia[i] = -1;
            aiGetData->_faceData.leftEye[i] = -1;
            aiGetData->_faceData.rightEye[i] = -1;
            aiGetData->_faceData.nose[i] = -1;
            aiGetData->_faceData.leftMouth[i] = -1;
            aiGetData->_faceData.rightMouth[i] = -1;
          }
          aiGetData->_catData.catFrameLength = -1;
          aiGetData->_catData.catFrameWidth = -1;
          aiGetData->_faceIDNumber = -1;
      }
      xSemaphoreGive(readDataMutex);//释放获取数据锁
    }
    vTaskDelay(1);
  }
  vTaskDelete(NULL);

}


void AIRecognition::initAi(void)
{
  xQueueAI = xQueueCreate(20, sizeof(camera_fb_t *)); // Create queue for AI data storage
  xQueueResult = xQueueCreate(20, sizeof(sAIRead_t *)); // Create queue for AI result data storage
  xQueueCamer = xQueueCreate(20, sizeof(camera_fb_t *)); // Create queue for camera data storage
  readDataMutex = xSemaphoreCreateMutex();
  xTaskCreatePinnedToCore(&task_read_ai_data, "task_read_ai_data", 4*1024, NULL, 5, NULL, 0); // Create task to receive data
}

void AIRecognition::switchAiMode(eAiType_t mode)
{
  if(faceAITaskHandle){
    xTaskNotifyGive(faceAITaskHandle);
    while(isTaskRunning){
      vTaskDelay(100);
    }
    vTaskDelete(eventTaskHandle);
    vQueueDelete(xQueueEvent);
    xQueueEvent = NULL;
    faceAITaskHandle = NULL;
    eventTaskHandle = NULL;
    isTaskRunning = true;
  }

  if(catAITaskHandle){
    xTaskNotifyGive(catAITaskHandle);
    while(isTaskRunning){
      vTaskDelay(100);
    }
    catAITaskHandle = NULL;
    isTaskRunning = true;
  }

  if(moveAITaskHandle){
    _moveMode = 0;
    xTaskNotifyGive(moveAITaskHandle);
    while(isTaskRunning){
        vTaskDelay(100);
    }
    moveAITaskHandle = NULL;
    isTaskRunning = true;
  }

  if(codeAITaskHandle){
    xTaskNotifyGive(codeAITaskHandle);
    while(isTaskRunning){
      vTaskDelay(100);
    }
    codeAITaskHandle = NULL;
    isTaskRunning = true;
  }

  if(NoModeTaskHandle){
    xTaskNotifyGive(NoModeTaskHandle);
    while(isTaskRunning){
      vTaskDelay(100);
    }
    NoModeTaskHandle = NULL;
    isTaskRunning = true;
  }

  switch(mode){
    case Face:
      xQueueEvent = xQueueCreate(4, sizeof(sAIRead_t *));
      assert(xQueueEvent);
      xTaskCreatePinnedToCore(task_face_recognition, "switchAiMode", 4 * 1024, (void*)xQueueCamer, 5, &faceAITaskHandle, 1);//0  4
      xTaskCreatePinnedToCore(task_event_handler, "event",  2 * 1024, NULL, 2, &eventTaskHandle, 1);//0  4
    break;

    case Cat:
      xTaskCreatePinnedToCore(task_cat_recognition, "switchAiMode", 4 * 1024, (void*)xQueueCamer, 4, &catAITaskHandle, 1);//0  4
    break;

    case Move:
      _moveMode = 1;
      xTaskCreatePinnedToCore(task_motion_recognition, "switchAiMode", 4 * 1024, (void*)xQueueCamer, 4, &moveAITaskHandle, 1);//0  4
    break;

    case Code:
      xTaskCreatePinnedToCore(task_code_recognition, "switchAiMode", 4 * 1024, (void*)xQueueCamer, 4, &codeAITaskHandle, 1);//0  4
    break;

    default:
      xTaskCreatePinnedToCore(task_nomode_handler, "switchAiMode", 4 * 1024, (void*)xQueueCamer, 4, &NoModeTaskHandle, 1);//0  4
    break;
  }
}
 
void AIRecognition::sendFaceCmd(recognizer_state_t cmd)
{
  if(xQueueEvent){
    sAISet_t *aiSet = (sAISet_t*)heap_caps_malloc(sizeof(sAISet_t),MALLOC_CAP_SPIRAM);
    if(aiSet != NULL){
      switch(cmd){
        case ENROLL:
          aiSet->cmd = ENROLL;
        break;
        case RECOGNIZE:
          aiSet->cmd = RECOGNIZE;
        break;
        case DELETEALL:
          aiSet->cmd = DELETEALL;
        break;
        default:
        break;
      }
      if (xQueueSend(xQueueEvent, &aiSet, portMAX_DELAY) != pdTRUE) {
        heap_caps_free(aiSet);
      }
    }
  }
}

int AIRecognition::getCatData(eFaceOrCatData_t type)
{
  int ret = -1;
  xSemaphoreTake(readDataMutex, portMAX_DELAY);
  switch (type)
  {
  case Length:
    ret = aiGetData->_catData.catFrameLength;
  break;
  case Width:
    ret = aiGetData->_catData.catFrameWidth;
  break;
  case CenterX:
    ret = aiGetData->centerOfInertia[0];
  break;
  case CenterY:
    ret = aiGetData->centerOfInertia[1];
  break;
  default:
    break;
  }
  xSemaphoreGive(readDataMutex);
  return ret;
}

int AIRecognition::getFaceData(eFaceOrCatData_t type)
{
  int ret = -1;
  xSemaphoreTake(readDataMutex, portMAX_DELAY);
  switch (type){
    case Length:
      ret = aiGetData->_faceData.faceFrameLength;
    break;
    case Width:
      ret = aiGetData->_faceData.faceFrameWidth;
    break;
    case CenterX:
      ret = aiGetData->centerOfInertia[0];
    break;
    case CenterY:
      ret = aiGetData->centerOfInertia[1];
    break;
    case LeftEyeX:
      ret = aiGetData->_faceData.leftEye[0];
    break;
    case LeftEyeY:
      ret = aiGetData->_faceData.leftEye[1];
    break;
    case RightEyeX:
      ret = aiGetData->_faceData.rightEye[0];
    break;
    case RightEyeY:
      ret = aiGetData->_faceData.rightEye[1];
    break;
    case NoseX:
      ret = aiGetData->_faceData.nose[0];
    break;
    case NoseY:
      ret = aiGetData->_faceData.nose[1];
    break;
    case LeftMouthX:
      ret = aiGetData->_faceData.leftMouth[0];
    break;
    case LeftMouthY:
      ret = aiGetData->_faceData.leftMouth[1];
    break;
    case RightMouthX:
      ret = aiGetData->_faceData.rightMouth[0];
    break;
    case RightMouthY:
      ret = aiGetData->_faceData.rightMouth[1];
    break;
    
    default:
      break;
  }
  xSemaphoreGive(readDataMutex);
  return ret;
}

void AIRecognition::sendFaceCmd(uint8_t cmd, int id)
{
  if(xQueueEvent){
    sAISet_t *aiSet = (sAISet_t*)heap_caps_malloc(sizeof(sAISet_t),MALLOC_CAP_SPIRAM);
    if(aiSet != NULL){
      aiSet->cmd = RECOGNIZE;
      aiSet->id = id;
      if (xQueueSend(xQueueEvent, &aiSet, portMAX_DELAY) != pdTRUE) {
        heap_caps_free(aiSet);
      }
    }
  }
}

bool AIRecognition::isDetectContent(eAiType_t mode)
{
  bool ret = false;
  xSemaphoreTake(readDataMutex, portMAX_DELAY);
  switch(mode){
    case Face:
      ret = aiGetData->faceMode;
    break;

    case Cat:
      ret = aiGetData->catMode;
    break;

    case Move:
      ret = aiGetData->moveMode;
    break;

    case Code:
      ret = aiGetData->codeMode;
    break;

    default:
    break;
  }
  xSemaphoreGive(readDataMutex);
  return ret;
}

void AIRecognition::setMotinoThreshold(uint8_t threshold)
{
  _sensitivity = (200 - threshold);
}

String AIRecognition::getQrCodeContent(void)
{
  xSemaphoreTake(readDataMutex, portMAX_DELAY);
  String ret = String(aiGetData->_codeData);
  xSemaphoreGive(readDataMutex);
  return ret;
}

int AIRecognition::getRecognitionID(void)
{
  int ret = -1;
  if(_faceID != -1){
    ret = _faceID;
    _faceID = -1;
  }
  return ret;
}

bool AIRecognition::isRecognized(void)
{
  bool ret = false;
  if(_recognize == 1){
    _recognize = 0;
    ret = true;
  }
  return ret;
}
 