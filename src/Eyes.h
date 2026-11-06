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
};

const EyeShape NEUTRAL_EYES = {48, 80, 16, 0, 0, 0};
const EyeShape HAPPY_EYES = {48, 80, 16, 0, 0, 50};
const EyeShape SLEEPY_EYES = {48, 80, 16, 45, -6, 0};
const EyeShape SURPRISED_EYES = {56, 90, 22, 0, 0, 0};
const EyeShape SUSPICIOUS_EYES = {48, 80, 16, 28, 0, 22};
const EyeShape ANNOYED_EYES = {48, 80, 16, 14, 16, 0};

void eyesDraw(Arduino_GFX* canvas, int centerX, int centerY, EyeShape shape, int lid, bool isLeft);
