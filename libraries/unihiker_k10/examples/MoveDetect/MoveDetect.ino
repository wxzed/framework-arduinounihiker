/*!
 * @file  MoveDetect.ino
 * @brief Switch on the camera and set the RGB light to display red when the camera detects a change in the picture; conversely, it displays blue.
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
#include "unihiker_k10.h"
#include "AIRecognition.h"

UNIHIKER_K10  k10;
uint8_t       screen_dir=2;
AIRecognition ai;


void setup() {
    k10.begin();
    k10.initScreen(screen_dir);
    ai.initAi();
    k10.initBgCamerImage();
    k10.setBgCamerImage(false);
    k10.creatCanvas();
    ai.switchAiMode(ai.NoMode);
    k10.setBgCamerImage(true);
    ai.switchAiMode(ai.Move);
    ai.setMotinoThreshold(100);
    k10.rgb->write(-1, 0x0000FF);
}
void loop() {
    if (ai.isDetectContent(AIRecognition::Move)) {
        k10.rgb->write(-1, 0xFF0000);
    }else {
        k10.rgb->write(-1, 0x0000FF);
    }
}