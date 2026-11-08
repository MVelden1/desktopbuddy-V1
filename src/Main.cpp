//
// Created by Mick on 6-11-2026.
//

#include <Arduino.h>
#include "face/Face.h"
#include "hardware/Display.h"
#include "hardware/Sensors.h"
#include "mood/Mood.h"

void setup()
{
    Serial.begin(115200);
    Serial.println("Hallo, ik ben een desktopbuddy");

    Arduino_GFX* gfx = displayBegin();
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
