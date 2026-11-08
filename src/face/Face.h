//
// Created by Mick on 6-11-2026.
//

#pragma once

#include <Arduino_GFX_Library.h>
#include "../mood/Mood.h"

void faceBegin(Arduino_GFX* gfx);
void faceUpdate(unsigned long now);
void faceSetMood(Mood mood);
Mood faceGetMood();

