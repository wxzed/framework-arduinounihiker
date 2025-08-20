/*!
 * @file  qrCodeScan.ino
 * @brief Display qrCode information on the UNIHIKER K10 screen
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
    ai.switchAiMode(ai.Code);
}
void loop() {
    if (ai.isDetectContent(AIRecognition::Code)) {
        k10.canvas->canvasText((String("QR code info: ") + String(ai.getQrCodeContent())), 0, 0, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->updateCanvas();
    }
}