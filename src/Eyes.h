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
    int lidBottom;
};

const EyeShape NEUTRAL_EYES = {48, 80, 16, 0, 0};
const EyeShape HAPPY_EYES = {48, 80, 16, 0, 50};

void eyesDraw(Arduino_GFX* canvas, int x, int y, EyeShape shape, int lid);
