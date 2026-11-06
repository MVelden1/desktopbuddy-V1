//
// Created by Mick on 6-11-2026.
//

#include "Eyes.h"

static const uint16_t EYE_COLOR = RGB565_CYAN;

void eyesDraw(Arduino_GFX* canvas, int x, int y, EyeShape shape, int lid)
{
    int blinkHeight = shape.height - (shape.height - 5) * lid / 100;
    int blinkTop = y + (shape.height - blinkHeight) * 73 / 100;

    canvas->fillRoundRect(x, blinkTop, shape.width, blinkHeight, shape.radius, EYE_COLOR);

    if (shape.lidBottom > 0)
    {
        canvas->fillRoundRect(x, y + shape.height - shape.lidBottom, shape.width,
            shape.height, shape.radius, RGB565_BLACK);
    }

    if (shape.lidTop > 0)
    {
        canvas->fillRect(x, y, shape.width, shape.lidTop, RGB565_BLACK);
    }
}
