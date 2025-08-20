/*!
 * @file  Dot.ino
 * @brief Draw random dots on the screen and clear the screen after 50 dots.
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
#include "unihiker_k10.h"

UNIHIKER_K10 k10;
uint8_t      screen_dir=2;

void setup() {
    k10.begin();
    k10.initScreen(screen_dir);
    k10.creatCanvas();
    k10.setScreenBackground(0x000000);
}
void loop() {
    for (int index = 0; index < 50; index++) {
        k10.canvas->canvasPoint((random(0, 240+1)), (random(0, 320+1)), 0x0000FF);
        k10.canvas->updateCanvas();
    }
    k10.canvas->canvasClear();
}