//Only support Chinese
/*!
 * @file  SpeechSynthesisCN.ino
 * @brief Chinese SpeechSynthesis, you need to set the UNIHIKER K10 built-in model to Chinese version before uploading this code.
 * Model selection is in the Tool->Model->CN of Arduino IDE
 * Say '你好小行’ or ‘你好小新’ to wake up the UNIHIKER, and then say ‘Switch on’ or ‘Switch off’ to switch on and off the on-board LEDs.
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
#include "asr.h"
#include "unihiker_k10.h"

UNIHIKER_K10 k10;
ASR          asr;
uint8_t      screen_dir=2;

void setup() {
    k10.begin();
    asr.asrInit(CONTINUOUS, CN_MODE, 6000);
    while(asr._asrState == 0){delay(100);}
    k10.initScreen(screen_dir);
    k10.creatCanvas();
    asr.setAsrSpeed(2);
    asr.addASRCommand(0+1, "kai deng");
    asr.addASRCommand(1+1, "guan deng");
}
void loop() {
    if (asr.isWakeUp()) {
        k10.canvas->canvasText("进入语音识别状态，请说控制命令词......", 5, 30, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->updateCanvas();
    }else {
        k10.canvas->canvasText("进入休眠状态，请说唤醒词\"你好，小形\"", 5, 30, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->updateCanvas();
    }
    if (asr.isDetectCmdID(0+1)) {
        asr.speak("灯光已打开");
        k10.rgb->brightness(round(9));
        k10.rgb->write(-1, 0xFFFFFF);
    }else if (asr.isDetectCmdID(1+1)) {
        asr.speak("灯光已关闭");
        k10.rgb->brightness(round(0));
        k10.rgb->write(-1, 0xFFFFFF);
    }
}