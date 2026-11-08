//
// Created by Mick on 6-11-2026.
//

#include "Mood.h"
#include "../face/Face.h"
#include "../hardware/Sensors.h"

static unsigned long lastPetted = 0;

void moodUpdate(unsigned long now)
{
    if (sensorWasPetted())
    {
        faceSetMood(Mood::Happy);
        lastPetted = now;
    }

    if (faceGetMood() == Mood::Happy && now - lastPetted > 5000)
    {
        faceSetMood(Mood::Neutral);
    }

    // todo weghalen for testing
    if (sensorMoodButtonPressed())
    {
        int next = ((int)faceGetMood() + 1) % int(Mood::Count);
        faceSetMood((Mood)next);
    }
}
