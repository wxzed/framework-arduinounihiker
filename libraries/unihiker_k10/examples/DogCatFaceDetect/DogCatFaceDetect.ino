/*!
 * @file  DogCatFaceDetect.ino
 * @brief Detects cat and dog face length, height and coordinates.
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
    ai.switchAiMode(ai.Cat);
}
void loop() {
    if (ai.isDetectContent(AIRecognition::Cat)) {
        k10.canvas->canvasText((String("Pet Face Hight: ") + String(ai.getCatData(AIRecognition::Length))), 0, 0, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->canvasText((String("Pet Face Width: ") + String(ai.getCatData(AIRecognition::Width))), 0, 15, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->canvasText((String("Pet Face coordinates X: ") + String(ai.getCatData(AIRecognition::Length))), 0, 30, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->canvasText((String("Pet Face coordinates Y: ") + String(ai.getCatData(AIRecognition::Width))), 0, 45, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->updateCanvas();
    }
}