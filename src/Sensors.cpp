//
// Created by Mick on 6-11-2026.
//

#include "Sensors.h"
#include <Arduino.h>

static const int PET_PIN = 18;
static bool wasPetted = false;

void sensorsBegin()
{
    pinMode(PET_PIN, INPUT_PULLUP);
}

bool sensorWasPetted()
{
    bool pettedNow = digitalRead(PET_PIN) == LOW;
    bool petted = pettedNow && !wasPetted;
    wasPetted = pettedNow;

    return petted;
}
