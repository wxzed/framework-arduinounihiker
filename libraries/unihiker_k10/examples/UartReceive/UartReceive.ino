/*!
 * @file  UartReceive.ino
 * @brief K10 reads data from the serial port, when the acquired data is ‘R’, the RGB lamp shows red; when the acquired data is ‘G’, the RGB lamp shows green; when the acquired data is ‘B’, the RGB lamp shows blue. 
 * When the acquired data is ‘R’, the RGB lamp shows red; 
 * when the acquired data is ‘G’, the RGB lamp shows green; 
 * when the acquired data is ‘B’, the RGB lamp shows blue.
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
#include "unihiker_k10.h"

volatile float SerialCount;

UNIHIKER_K10 k10;


void setup() {
    k10.begin();
    Serial.begin(9600);
}
void loop() {
    if ((Serial.available())) {
        SerialCount= Serial.read();
        if ((SerialCount==(toascii('R')))) {
            k10.rgb->write(-1, 0xFF0000);
        }else if ((SerialCount==(toascii('G')))) {
            k10.rgb->write(-1, 0x00FF00);
        }else if ((SerialCount==(toascii('B')))) {
            k10.rgb->write(-1, 0x0000FF);
        }
    }
}