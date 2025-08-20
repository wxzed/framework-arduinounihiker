/*!
 * @file  SpeechRecognitionEN.ino
 * @brief English SpeechRecognition, you need to set the UNIHIKER K10 built-in model to English version before uploading this code.
 * Model selection is in the Tool->Model->EN of Arduino IDE
 * Say ‘Hi Telly’ or ‘Jarvis’ to wake up the UNIHIKER, and then say ‘Switch on’ or ‘Switch off’ to switch on and off the on-board LEDs.
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
    asr.asrInit(CONTINUOUS, EN_MODE, 6000);
    while(asr._asrState == 0){delay(100);}
    k10.initScreen(screen_dir);
    k10.creatCanvas();
    asr.addASRCommand(0+1, "Switch on");
    asr.addASRCommand(1+1, "Switch off");
}
void loop() {
    if (asr.isWakeUp()) {
        k10.canvas->canvasText("Enter the Speech Recognition Mode, please say the command word...", 5, 30, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->updateCanvas();
    }else {
        k10.canvas->canvasText("Enter the sleep mode, please say the wake up word \"Hi Telly\" or \"Jarvis\"", 5, 30, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->updateCanvas();
    }
    if (asr.isDetectCmdID(0+1)) {
        k10.rgb->brightness(round(9));
        k10.rgb->write(-1, 0xFFFFFF);
    }else if (asr.isDetectCmdID(1+1)) {
        k10.rgb->brightness(round(0));
        k10.rgb->write(-1, 0xFFFFFF);
    }
}