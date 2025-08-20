/*!
 * @file  DigitalOutput.ino
 * @brief P0 outputs a high level.
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      
 * @version     V1.0
 * @date        2024-12-30
 * @url         
 */
void setup() {
    pinMode(P0, OUTPUT);
}
void loop() {
    digitalWrite(P0, HIGH);
}