//
// Created by Mick on 6-11-2026.
//

#include <Arduino.h>
#include <Arduino_GFX_Library.h>

Arduino_DataBus* bus = new Arduino_HWSPI(41, 42, 40, 45, 46);
#ifdef WOKWI
Arduino_GFX* gfx = new Arduino_ILI9341(bus, 39, 1);
#else
Arduino_GFX* gfx = new Arduino_ST7789(bus, 39, 1, true);
#endif

void setup()
{
    Serial.begin(115200);
    Serial.println("Hallo, ik ben een desktopbuddy");

    pinMode(5, OUTPUT);
    digitalWrite(5, HIGH);

    gfx->begin();
    gfx->fillScreen(RGB565_BLACK);

    gfx->fillRoundRect(84, 70, 48, 80, 16, RGB565_WHITE);
    gfx->fillRoundRect(188, 70, 48, 80, 16, RGB565_WHITE);
}

void loop()
{
}
