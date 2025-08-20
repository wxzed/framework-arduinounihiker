#ifndef _AI_RECOGNITION_H_
#define _AI_RECOGNITION_H_
#include "who_ai_utils.hpp"
#include "Arduino.h"

class AIRecognition{
public:
    enum eAiType_t
    {
        Face, //人脸识别
        Cat, //猫脸识别
        Move, //移动检测
        Code, //二维码识别
        NoMode, //
    };

    enum eFaceOrCatData_t
    {
        Length,
        Width,
        CenterX,
        CenterY,
        LeftEyeX,
        LeftEyeY,
        RightEyeX,
        RightEyeY,
        NoseX,
        NoseY,
        LeftMouthX,
        LeftMouthY,
        RightMouthX,
        RightMouthY,
    };

    AIRecognition(void){};

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
};



#endif

