/*!
 * @file  FaceDetect.ino
 * @brief Detects the height, width, and coordinates of the human face.
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
    ai.switchAiMode(ai.Face);
}
void loop() {
    if (ai.isDetectContent(AIRecognition::Face)) {
        k10.canvas->canvasText((String("Face Hight: ") + String(ai.getFaceData(AIRecognition::Length))), 0, 0, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->canvasText((String("Face Hight: ") + String(ai.getFaceData(AIRecognition::Width))), 0, 20, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->canvasText((String("Face coordinates X: ") + String(ai.getFaceData(AIRecognition::CenterX))), 0, 40, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->canvasText((String("Face coordinates Y: ") + String(ai.getFaceData(AIRecognition::CenterY))), 0, 60, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->updateCanvas();
    }
    delay(1000);
}