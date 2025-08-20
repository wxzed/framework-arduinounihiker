/*!
 * @file  Line.ino
 * @brief Draw lines on the screen
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
#include "unihiker_k10.h"

int start, end;

UNIHIKER_K10 k10;
uint8_t      screen_dir=2;

void setup() {
    k10.begin();
    k10.initScreen(screen_dir);
    k10.creatCanvas();
    k10.canvas->canvasSetLineWidth(1);
    start = 0;
    end = 240;
}
void loop() {
    while (!(start==240)) {
        k10.canvas->canvasLine(start, 0, end, 320, 0xFF0000);
        k10.canvas->updateCanvas();
        start = 3;
        end = -3;
    }
}