//
// Created by Mick on 8-11-2026.
//

#include "hardware/Display.h"
#include <Arduino.h>
#include "config/Board.h"

static Arduino_DataBus* bus = nullptr;
static Arduino_GFX* gfx = nullptr;

Arduino_GFX* displayBegin()
{
    bus = new Arduino_HWSPI(PIN_TFT_DC, PIN_TFT_CS, PIN_TFT_SCK, PIN_TFT_MOSI, PIN_TFT_MISO);

#if defined(WOKWI)
    gfx = new Arduino_ILI9341(bus, PIN_TFT_RST, 3);
#elif defined(BOARD_JINGCAI)
    gfx = new Arduino_ST7796(bus, PIN_TFT_RST, 1, false);
#endif

    pinMode(PIN_BACKLIGHT, OUTPUT);
    digitalWrite(PIN_BACKLIGHT, HIGH);

    gfx->begin();
    gfx->fillScreen(RGB565_BLACK);

    return gfx;
}
