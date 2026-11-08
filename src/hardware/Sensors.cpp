//
// Created by Mick on 6-11-2026.
//

#include "hardware/Sensors.h"
#include "config/Board.h"
#include <Arduino.h>

#if defined(WOKWI)

// Simulator: knoppen "pet (P)" en "mood (M)"
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

#else

// TODO nog implementeren
void sensorsBegin()
{
}

bool sensorWasPetted()
{
    return false;
}

bool sensorMoodButtonPressed()
{
    return false;
}

#endif
