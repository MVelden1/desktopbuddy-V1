//
// Created by Mick on 6-11-2026.
//

#pragma once

#include <Arduino_GFX_Library.h>

struct EyeShape
{
    int width;
    int height;
    int radius;
    int lidTop;
    int lidTilt;
    int lidBottom;
    bool curvedBottom;
};

enum class EyeStyle
{
    Rounded,
    Round
};

void eyesDraw(Arduino_GFX* canvas, int centerX, int centerY, EyeShape shape, int lid, bool isLeft);
