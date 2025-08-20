/*!
 * @file  UartSend.ino
 * @brief Serial output Hello(Default to USB-C)
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
void setup() {
    Serial.begin(9600);
}
void loop() {
    Serial.println("hello");
}