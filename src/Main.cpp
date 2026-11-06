//
// Created by Mick on 6-11-2026.
//

#include <Arduino.h>
#include <Arduino_GFX_Library.h>
#include "Face.h"
#include "Sensors.h"
#include "Mood.h"

Arduino_DataBus* bus = new Arduino_HWSPI(41, 42, 40, 45, 46);
#ifdef WOKWI
Arduino_GFX* gfx = new Arduino_ILI9341(bus, 39, 3);
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
