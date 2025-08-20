/*!
 * @file  ButtonInterrupt.ino
 * @brief Press button A to draw a rectangle; press button B to draw a circle
 * press button AB at the same time to clear the screen display
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
#include "unihiker_k10.h"

void onButtonAPressed();
void onButtonBPressed();
void onButtonABPressed();

UNIHIKER_K10 k10;
uint8_t      screen_dir=2;


void setup() {
    k10.begin();
    k10.buttonA->setPressedCallback(onButtonAPressed);
    k10.initScreen(screen_dir);
    k10.creatCanvas();
    k10.buttonB->setPressedCallback(onButtonBPressed);
    k10.buttonAB->setPressedCallback(onButtonABPressed);
}
void loop() {

}

void onButtonAPressed() {
    k10.canvas->canvasRectangle(10, 100, 110, 100, 0xFF6666, 0x0000FF, true);
    k10.canvas->updateCanvas();
}
void onButtonBPressed() {
    k10.canvas->canvasCircle(180, 150, 50, 0xFF6666, 0x0000FF, true);
    k10.canvas->updateCanvas();
}
void onButtonABPressed() {
    k10.canvas->canvasClear();
    k10.canvas->updateCanvas();
}