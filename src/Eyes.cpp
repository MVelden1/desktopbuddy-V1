//
// Created by Mick on 6-11-2026.
//

#include "Eyes.h"

static const uint16_t EYE_COLOR = RGB565_CYAN;

void eyesDraw(Arduino_GFX* canvas, int centerX, int centerY, EyeShape shape, int lid, bool isLeft, int offsetY)
{
    int x = centerX - shape.width / 2;
    int y = centerY + shape.offsetY - shape.height / 2;
    
    int visible = shape.height - shape.lidTop - shape.lidBottom - abs(shape.lidTilt) / 2;

    int closing = max(0, visible - 5) * lid / 100;

    int top = shape.lidTop + closing * 73 / 100;
    int bottom = shape.lidBottom + closing - closing * 73 / 100;

    // Eye
    canvas->fillRoundRect(x, y, shape.width, shape.height, shape.radius, EYE_COLOR);

    // lower eyelid
    if (bottom > 0)
    {
        if (shape.curvedBottom)
        {
            int r = shape.width * 6 / 10;
            canvas->fillEllipse(centerX, y + shape.height - bottom + r, r, r,RGB565_BLACK);
        }
        else
        {
            canvas->fillRoundRect(x - shape.radius, y + shape.height - bottom,
                                  shape.width + 2 * shape.radius, shape.height,
                                  shape.radius * 2, RGB565_BLACK);
        }
    }

    // upper eyelid
    if (top > 0)
    {
        canvas->fillRect(x, y, shape.width, top, RGB565_BLACK);
    }

    // upper corner eyelid
    if (shape.lidTilt != 0)
    {
        int lidY = y + top;
        int innerDrop = max(0, shape.lidTilt);
        int outerDrop = max(0, -shape.lidTilt);

        int leftDrop = isLeft ? outerDrop : innerDrop;
        int rightDrop = isLeft ? innerDrop : outerDrop;

        canvas->fillTriangle(x, lidY, x + shape.width, lidY, x + shape.width, lidY + rightDrop, RGB565_BLACK);
        canvas->fillTriangle(x, lidY, x + shape.width, lidY + rightDrop, x, lidY + leftDrop, RGB565_BLACK);
    }
}
