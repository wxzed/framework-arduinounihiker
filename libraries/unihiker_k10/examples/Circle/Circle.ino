/*!
 * @file  Circle.ino
 * @brief Draw circles on the screen
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
    k10.canvas->canvasCircle(120, 120, 40, 0xFFCC33, 0xFFCC33, true);
    k10.canvas->canvasCircle(160, 160, 40, 0xFFCC33, 0xFFCC33, true);
    k10.canvas->canvasCircle(120, 200, 40, 0xFFCC33, 0xFFCC33, true);
    k10.canvas->canvasCircle(80, 160, 40, 0xFFCC33, 0xFFCC33, true);
    k10.canvas->canvasCircle(120, 160, 20, 0xFFFF00, 0xFFFF00, true);
    k10.canvas->updateCanvas();
}
void loop() {

}