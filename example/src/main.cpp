#include <Arduino.h>

// UNIHIKER K10 示例代码
void setup() {
    // 初始化串口通信
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("=================================");
    Serial.println("UNIHIKER K10 开发板初始化完成");
    Serial.println("=================================");
    
    // 显示系统信息
    Serial.printf("芯片型号: %s\n", ESP.getChipModel());
    Serial.printf("芯片版本: %d\n", ESP.getChipRevision());
    Serial.printf("CPU 频率: %d MHz\n", ESP.getCpuFreqMHz());
    Serial.printf("Flash 大小: %d MB\n", ESP.getFlashChipSize() / 1024 / 1024);
    Serial.printf("可用内存: %d KB\n", ESP.getFreeHeap() / 1024);
    
    if (psramFound()) {
        Serial.printf("PSRAM 大小: %d MB\n", ESP.getPsramSize() / 1024 / 1024);
        Serial.printf("可用 PSRAM: %d KB\n", ESP.getFreePsram() / 1024);
    } else {
        Serial.println("PSRAM 未检测到");
    }
    
    Serial.println("=================================");
}

void loop() {
    // 主循环
    static int counter = 0;
    
    Serial.printf("运行计数: %d, 可用内存: %d KB\n", 
                  counter++, ESP.getFreeHeap() / 1024);
    
    // 每10秒重启一次（演示用）
    if (counter % 10 == 0) {
        Serial.println("系统运行正常，10秒后重启...");
        delay(1000);
        ESP.restart();
    }
    
    delay(1000);
}


