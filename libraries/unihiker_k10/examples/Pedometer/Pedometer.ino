/*!
 * @file  Pedometer.ino
 * @brief Counts the current number of steps and updates it on the screen.
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
#include "unihiker_k10.h"

volatile float mind_n_step;

UNIHIKER_K10 k10;
uint8_t      screen_dir=2;

void setup() {
    k10.begin();
    k10.initScreen(screen_dir);
    k10.creatCanvas();
    mind_n_step = 0;
    k10.canvas->canvasText("Step: ", 1, 0x0000FF);
    k10.canvas->updateCanvas();
}
void loop() {
    if (((k10.getStrength())>1000)) {
        mind_n_step += 1;
        k10.canvas->canvasText((String("Step: ") + String(mind_n_step)), 1, 0x0000FF);
        k10.canvas->updateCanvas();
        delay(1000);
    }
}