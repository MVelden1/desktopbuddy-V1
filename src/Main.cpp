//
// Created by Mick on 6-11-2026.
//

#include <Arduino.h>
#include <Arduino_GFX_Library.h>
#include "config/Board.h"
#include "face/Face.h"
#include "hardware/Sensors.h"
#include "mood/Mood.h"

Arduino_DataBus* bus = new Arduino_HWSPI(PIN_TFT_DC, PIN_TFT_CS, PIN_TFT_SCK, PIN_TFT_MOSI, PIN_TFT_MISO);
#ifdef WOKWI
Arduino_GFX* gfx = new Arduino_ILI9341(bus, PIN_TFT_RST, 3);
#else
Arduino_GFX* gfx = new Arduino_ST7789(bus, 39, 1, true);
#endif

void setup()
{
    Serial.begin(115200);
    Serial.println("Hallo, ik ben een desktopbuddy");

    pinMode(PIN_BACKLIGHT, OUTPUT);
    digitalWrite(PIN_BACKLIGHT, HIGH);

    gfx->begin();
    gfx->fillScreen(RGB565_BLACK);

    faceBegin(gfx);

    sensorsBegin();

    // faceSetMood(Mood::Surprised);
}

void loop()
{
    unsigned long now = millis();
    faceUpdate(now);
    moodUpdate(now);
}
