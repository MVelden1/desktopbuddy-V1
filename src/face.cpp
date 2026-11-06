//
// Created by Mick on 6-11-2026.
//

#include "face.h"

static Arduino_Canvas* face = nullptr;
static unsigned long lastBlink = 0;
static bool eyesOpen = true;

static void drawEyes(bool open)
{
    face->fillScreen(RGB565_BLACK);

    if (open)
    {
        face->fillRoundRect(0, 0, 48, 80, 16, RGB565_WHITE);
        face->fillRoundRect(104, 0, 48, 80, 16, RGB565_WHITE);
    }
    else
    {
        face->fillRoundRect(0, 0, 48, 5, 2, RGB565_WHITE);
        face->fillRoundRect(104, 0, 48, 5, 2, RGB565_WHITE);
    }
    face->flush();
}

void faceBegin(Arduino_GFX* gfx)
{
    face = new Arduino_Canvas(152, 80, gfx, 84, 70);
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
    } else if (!eyesOpen && now - lastBlink > 150)
    {
        eyesOpen = true;
        drawEyes(true);
        lastBlink = now;
    }
}
