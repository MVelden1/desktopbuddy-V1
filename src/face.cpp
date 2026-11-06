//
// Created by Mick on 6-11-2026.
//

#include "face.h"

static Arduino_Canvas* face = nullptr;
static unsigned long lastBlink = 0;
static bool eyesOpen = true;
static Mood currentMood = Mood::Neutral;

static const int MAX_LOOK_X = 40;
static const int MAX_LOOK_Y = 30;

static int lookX = 0;
static int lookY = 0;
static int targetX = 0;
static int targetY = 0;

static unsigned long lastLook = 0;
static unsigned long lookDuration = 2000;
static unsigned long lastStep = 0;

static void drawEyes(bool open)
{
    face->fillScreen(RGB565_BLACK);
    if (currentMood == Mood::Neutral)
    {
        if (open)
        {
            face->fillRoundRect(40 + lookX, 30 + lookY, 48, 80, 16, RGB565_WHITE);
            face->fillRoundRect(144 + lookX, 30 + lookY, 48, 80, 16, RGB565_WHITE);
        }
        else
        {
            face->fillRoundRect(40 + lookX, 85 + lookY, 48, 5, 2, RGB565_WHITE);
            face->fillRoundRect(144 + lookX, 85 + lookY, 48, 5, 2, RGB565_WHITE);
        }
    }
    if (currentMood == Mood::Happy)
    {
        face->fillRoundRect(40 + lookX, 30 + lookY, 48, 80, 16, RGB565_WHITE);
        face->fillRoundRect(40 + lookX, 60 + lookY, 48, 80, 16, RGB565_BLACK);
        face->fillRoundRect(144 + lookX, 30 + lookY, 48, 80, 16, RGB565_WHITE);
        face->fillRoundRect(144 + lookX, 60 + lookY, 48, 80, 16, RGB565_BLACK);
    }
    face->flush();
}

void faceBegin(Arduino_GFX* gfx)
{
    face = new Arduino_Canvas(232, 140, gfx, 44, 40);
    face->begin(GFX_SKIP_OUTPUT_BEGIN);

    drawEyes(true);
}

void faceUpdate(unsigned long now)
{
    if (eyesOpen && now - lastBlink > 3000)
    {
        eyesOpen = false;
        drawEyes(false);
        lastBlink = now;
    }
    else if (!eyesOpen && now - lastBlink > 150)
    {
        eyesOpen = true;
        drawEyes(true);
        lastBlink = now;
    }

    if (now - lastLook > lookDuration)
    {
        if (random(0, 2) == 0)
        {
            targetX = 0;
            targetY = 0;
        }
        else
        {
            targetX = random(-MAX_LOOK_X, MAX_LOOK_X + 1);
            targetY = random(-MAX_LOOK_Y, MAX_LOOK_Y + 1);
        }
        lookDuration = random(1000, 4000);
        lastLook = now;
    }

    if (now - lastStep > 30 && (lookX != targetX || lookY != targetY))
    {
        lookX += constrain(targetX-lookX, -4, 4);
        lookY += constrain(targetY-lookY, -4, 4);
        drawEyes(eyesOpen);
        lastStep = now;
    }
}

void faceSetMood(Mood mood)
{
    currentMood = mood;
    drawEyes(true);
}
