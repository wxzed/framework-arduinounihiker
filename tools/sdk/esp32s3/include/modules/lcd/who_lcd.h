#pragma once

#include <stdint.h>
#include "esp_log.h"
#include "screen_driver.h"

#if 1
#define BOARD_LCD_MOSI 21
#define BOARD_LCD_MISO -1
#define BOARD_LCD_SCK 12
#define BOARD_LCD_CS 14
#define BOARD_LCD_DC 13
#define BOARD_LCD_RST -1
#define BOARD_LCD_BL -1

#else
#define BOARD_LCD_MOSI 9
#define BOARD_LCD_MISO -1
#define BOARD_LCD_SCK 7
#define BOARD_LCD_CS 6
#define BOARD_LCD_DC 8
#define BOARD_LCD_RST 5
#define BOARD_LCD_BL 4
#endif

#define BOARD_LCD_PIXEL_CLOCK_HZ (40 * 1000 * 1000)
#define BOARD_LCD_BK_LIGHT_ON_LEVEL 0
#define BOARD_LCD_BK_LIGHT_OFF_LEVEL !BOARD_LCD_BK_LIGHT_ON_LEVEL
#define BOARD_LCD_H_RES 320
#define BOARD_LCD_V_RES 240
#define BOARD_LCD_CMD_BITS 8
#define BOARD_LCD_PARAM_BITS 8
#define LCD_HOST SPI2_HOST

#ifdef __cplusplus
extern "C"
{
#endif

    esp_err_t register_lcd(QueueHandle_t frame_i);

    // void app_lcd_draw_wallpaper();
    // void app_lcd_set_color(int color);

#ifdef __cplusplus
}
#endif
