//
// Created by Mick on 8-11-2026.
//

#pragma once

#if defined(WOKWI)
// Simulator: ESP32-S3 met ILI9341
constexpr int PIN_TFT_SCK  = 40;
constexpr int PIN_TFT_MOSI = 45;
constexpr int PIN_TFT_MISO = 46;
constexpr int PIN_TFT_CS   = 42;
constexpr int PIN_TFT_DC   = 41;
constexpr int PIN_TFT_RST  = 39;
constexpr int PIN_BACKLIGHT = 5;

constexpr int PIN_PET_BUTTON  = 18;
constexpr int PIN_MOOD_BUTTON = 17;

#elif defined(BOARD_JINGCAI)
// Echt bord: Jingcai ESP32-3248S035C (ESP32, ST7796, GT911)
constexpr int PIN_TFT_SCK  = 14;
constexpr int PIN_TFT_MOSI = 13;
constexpr int PIN_TFT_MISO = 12;
constexpr int PIN_TFT_CS   = 15;
constexpr int PIN_TFT_DC   = 2;
constexpr int PIN_TFT_RST  = -1;   // reset zit vast aan de EN-knop, geen eigen pin
constexpr int PIN_BACKLIGHT = 27;

constexpr int PIN_TOUCH_SDA = 33;
constexpr int PIN_TOUCH_SCL = 32;
constexpr int PIN_TOUCH_INT = 21;
constexpr int PIN_TOUCH_RST = 25;

constexpr int PIN_LIGHT_SENSOR = 34;
constexpr int PIN_SPEAKER      = 26;

#else
#error "Geen bord gekozen: zet -DWOKWI of -DBOARD_JINGCAI in platformio.ini"
#endif
