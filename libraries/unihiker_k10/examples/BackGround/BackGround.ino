/*!
 * @file  BackGround.ino
 * @brief UNIHIKER K10 screen display background colour
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
    k10.setScreenBackground(0xFFFF00);
}
void loop() {

}