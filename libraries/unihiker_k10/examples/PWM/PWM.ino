/*!
 * @file  PWM.ino
 * @brief P0 output PWM value
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
#include "unihiker_k10.h"


volatile float mind_n_level;

UNIHIKER_K10 k10;

void setup() {
    k10.begin();
    mind_n_level = 0;
    analogWrite(P0, map(0, 0, 1023, 0, 255));
}
void loop() {
    if ((k10.buttonA->isPressed())) {
        delay(100);
        mind_n_level += 1;
        if ((((int32_t(mind_n_level)) % (int32_t(3)))==0)) {
            analogWrite(P0, map(0, 0, 1023, 0, 255));
        }else if ((((int32_t(mind_n_level)) % (int32_t(3)))==1)) {
            analogWrite(P0, map(512, 0, 1023, 0, 255));
        }else if ((((int32_t(mind_n_level)) % (int32_t(3)))==2)) {
            analogWrite(P0, map(1023, 0, 1023, 0, 255));
        }
    }
}