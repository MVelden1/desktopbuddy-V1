//
// Created by Mick on 6-11-2026.
//

#pragma once

enum class Mood
{
    Neutral,
    Happy,
    Sleepy,
    Surprised,
    Suspicious,
    Angry,
    Focused,
    Bored,
    Count
};

void moodUpdate(unsigned long now);