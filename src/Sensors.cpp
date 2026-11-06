//
// Created by Mick on 6-11-2026.
//

#include "Sensors.h"
#include <Arduino.h>

static const int PET_PIN = 18;
static bool wasPetted = false;
// todo weghalen for testing
static const int MOOD_PIN = 17;
static bool moodWasSwitched = false;

void sensorsBegin()
{
    pinMode(PET_PIN, INPUT_PULLUP);
    // todo weghalen for testing
    pinMode(MOOD_PIN, INPUT_PULLUP);
}

bool sensorWasPetted()
{
    bool pettedNow = digitalRead(PET_PIN) == LOW;
    bool petted = pettedNow && !wasPetted;
    wasPetted = pettedNow;

    return petted;
}

// todo weghalen for testing
bool sensorMoodButtonPressed()
{
    bool buttonPressedNow = digitalRead(MOOD_PIN) == LOW;
    bool moodSwitched = buttonPressedNow && !moodWasSwitched;
    moodWasSwitched = buttonPressedNow;

    return moodSwitched;
}
