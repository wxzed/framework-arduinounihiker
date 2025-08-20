/*!
 * @file  LED.ino
 * @brief Counts the current number of steps and updates it on the screen.
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
#include "unihiker_k10.h"

volatile int brightness;

UNIHIKER_K10 k10;

void setup() {
    k10.begin();
    brightness = 0;
    k10.rgb->brightness(round(brightness));
    k10.rgb->write(-1, 0x0000FF);
}

void loop() {
    while (!(brightness==9)) {
        k10.rgb->brightness(round(brightness));
        k10.rgb->write(-1, 0x0000FF);
        delay(200);
        brightness += 1;
    }while (!(brightness==0)) {
        k10.rgb->brightness(round(brightness));
        k10.rgb->write(-1, 0x0000FF);
        delay(200);
        brightness -= 1;
    }
}