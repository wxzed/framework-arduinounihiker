#pragma once

#include <stdio.h>
#include "sdkconfig.h"
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#define ADD 0
#define CLEAR 1
#define CLEARALL 2
#define TYPT_CN 1
#define TYPE_EN 2
#ifdef __cplusplus
extern "C"
{
#endif
typedef struct{
  uint8_t cmd;///<命令
  uint8_t line;///<行号
  uint8_t list;///<列号
  uint16_t color;///<字体颜色
  uint8_t  fontSize;///<字体大小
  uint8_t type;///<类型
  uint8_t  buf[136];///<数据
}splayData_t;


struct playTextList{
  splayData_t play;
  struct playTextList* next;
};


/**
 * 创建链表
*/
struct playTextList* createList(void);
/**
 * 创建节点
*/
struct playTextList* createNode(splayData_t* data);
/**
 * @brief 尾插法
 * 
 * @param head 头节点
 * @param data 文字数据
 */
void insertListByTail(splayData_t* data);
/**
 * @brief 查询该位置已有文字
 * 
 * @param head 头节点
 * @param line 行号
 * @param list 列号
 * @return struct playTextList* 
 */
struct playTextList* search(splayData_t* data);
/**
 * @brief 添加文字
 * 
 * @param newData 文字数据的结构体
 */
void addText(splayData_t *newData);
void clearText(splayData_t *newData);
void clearTextAll(void);
// void appendNode(sReceiveData_t *newData);
// void deleteNode(sReceiveData_t *newData);

#ifdef __cplusplus
}
#endif


