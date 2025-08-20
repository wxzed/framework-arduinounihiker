/*!
 * @file  FaceRecognition.ino
 * @brief Press button A to learn the face and button B to detect the face.
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
//有问题
#include "unihiker_k10.h"
#include "AIRecognition.h"

String ID;

void onButtonAPressed();
void onButtonBPressed();

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
    k10.buttonA->setPressedCallback(onButtonAPressed);
    k10.buttonB->setPressedCallback(onButtonBPressed);
    k10.setBgCamerImage(true);
    ai.switchAiMode(ai.Face);
}
void loop() {
    if (ai.isRecognized()) {
        ID = ai.getRecognitionID();
        k10.canvas->canvasText((String("Face ID: ") + String(ID)), 0, 0, 0x0000FF, k10.canvas->eCNAndENFont24, 50, true);
        k10.canvas->canvasText(ID, 0, 30, 0x0000FF, k10.canvas->eCNAndENFont24, 50, true);
        k10.canvas->updateCanvas();
    }
}

void onButtonAPressed() {
    k10.rgb->write(-1, 0x00FF00);
    ai.sendFaceCmd(ENROLL);
}
void onButtonBPressed() {
    k10.rgb->write(-1, 0x0000FF);
    ai.sendFaceCmd(RECOGNIZE);
}