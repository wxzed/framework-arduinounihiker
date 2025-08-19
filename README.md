# Framework Arduino UNIHIKER

基于 ESP32 Arduino 框架的 UNIHIKER K10 开发板支持包。

## 安装方法

### 方法 1：通过 Git 仓库安装（推荐）

在您的 `platformio.ini` 文件中添加：

```ini
[env:unihiker_k10]
platform = https://github.com/您的用户名/framework-arduinounihiker.git
board = unihiker_k10
framework = arduino
```

### 方法 2：通过发布版本安装

```ini
[env:unihiker_k10]
platform = https://github.com/您的用户名/framework-arduinounihiker.git#v1.0.0
board = unihiker_k10
framework = arduino
```

## 支持的开发板

- **unihiker_k10**: UNIHIKER K10 开发板 (ESP32-S3)

## 特性

- 基于 ESP32 Arduino 框架 2.0.17
- 支持 ESP32-S3 芯片
- 预编译的 TinyUF2 bootloader
- 优化的分区表配置
- 完整的库支持

## 使用示例

```cpp
#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Hello UNIHIKER K10!");
}

void loop() {
    Serial.println("Running...");
    delay(1000);
}
```

## 构建和上传

```bash
# 构建项目
pio run -e unihiker_k10

# 上传到开发板
pio run -e unihiker_k10 -t upload

# 监视串口输出
pio device monitor
```

## 依赖项

- PlatformIO Core
- Python intelhex 模块（用于 bootloader 生成）

## 许可证

LGPL-2.1-or-later

## 贡献

欢迎提交 Issue 和 Pull Request！


