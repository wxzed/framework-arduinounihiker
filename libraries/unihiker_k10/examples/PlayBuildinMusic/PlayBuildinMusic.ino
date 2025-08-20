/*!
 * @file  PlayBuildinMusic.ino
 * @brief Play UNIHKER K10 built-in music.
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
#include "unihiker_k10.h"

volatile int flag;

void onButtonBPressed();
void onButtonAPressed();

UNIHIKER_K10 k10;
Music        music;

void setup() {
    k10.begin();
    k10.buttonB->setPressedCallback(onButtonBPressed);
    k10.buttonA->setPressedCallback(onButtonAPressed);
    flag = 0;
}
void loop() {
    if ((flag==1)) {
        delay(500);
        music.playMusic(BIRTHDAY);
        flag = 0;
    }else if ((flag==2)) {
        delay(500);
        music.playTone(131,  8000);
        music.playTone(131,  8000);
        music.playTone(196,  8000);
        music.playTone(196,  8000);
        music.playTone(220,  8000);
        music.playTone(220,  8000);
        music.playTone(196,  8000);
        flag = 0;
    }
}


void onButtonBPressed() {
        flag = 2;
}
void onButtonAPressed() {
        flag = 1;
}