//
// Created by Mick on 6-11-2026.
//

#include "hardware/Sensors.h"
#include "config/Board.h"
#include <Arduino.h>

static bool wasPetted = false;
static bool moodWasSwitched = false;

void sensorsBegin()
{
    pinMode(PIN_PET_BUTTON, INPUT_PULLUP);
    pinMode(PIN_MOOD_BUTTON, INPUT_PULLUP);
}

bool sensorWasPetted()
{
    bool pettedNow = digitalRead(PIN_PET_BUTTON) == LOW;
    bool petted = pettedNow && !wasPetted;
    wasPetted = pettedNow;

    return petted;
}

// todo weghalen for testing
bool sensorMoodButtonPressed()
{
    bool buttonPressedNow = digitalRead(PIN_MOOD_BUTTON) == LOW;
    bool moodSwitched = buttonPressedNow && !moodWasSwitched;
    moodWasSwitched = buttonPressedNow;

    return moodSwitched;
}
