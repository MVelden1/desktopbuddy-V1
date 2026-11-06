//
// Created by Mick on 6-11-2026.
//

#include "Eyes.h"

static const uint16_t EYE_COLOR = RGB565_CYAN;

void eyesDraw(Arduino_GFX* canvas, int centerX, int centerY, EyeShape shape, int lid, bool isLeft)
{
    int x = centerX - shape.width / 2;
    int y = centerY - shape.height / 2;

    int blinkHeight = shape.height - (shape.height - 5) * lid / 100;
    int blinkTop = y + (shape.height - blinkHeight) * 73 / 100;

    canvas->fillRoundRect(x, blinkTop, shape.width, blinkHeight, shape.radius, EYE_COLOR);

    if (shape.lidBottom > 0)
    {
        canvas->fillRoundRect(x, y + shape.height - shape.lidBottom, shape.width,
                              shape.height, shape.radius, RGB565_BLACK);
    }

    if (shape.lidTilt != 0)
    {
        int top = y + shape.lidTop;
        int innerDrop = max(0, shape.lidTilt);
        int outerDrop = max(0, -shape.lidTilt);

        int leftDrop = isLeft ? outerDrop : innerDrop;
        int rightDrop = isLeft ? innerDrop : outerDrop;

        canvas->fillTriangle(x, top, x + shape.width, top, x + shape.width, top + rightDrop, RGB565_BLACK);
        canvas->fillTriangle(x, top, x + shape.width, top + rightDrop, x, top + leftDrop, RGB565_BLACK);
    }

    if (shape.lidTop > 0)
    {
        canvas->fillRect(x, y, shape.width, shape.lidTop, RGB565_BLACK);
    }
}
