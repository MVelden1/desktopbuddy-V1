//
// Created by Mick on 8-11-2026.
//

#include "face/Expressions.h"

struct MoodLook
{
    Expression rounded;
    Expression round;
};

static Expression both(EyeShape shape)
{
    return {shape, shape};
}

static const MoodLook LOOKS[] = {
    {
        // Neutral
        .rounded = both({64, 68, 16, 0, 0, 0, false, 0}),
        .round = both({62, 62, 31, 0, 0, 0, false, 0}),
    },
    {
        // Happy
        .rounded = both({64, 68, 16, 0, 0, 42, true, 0}),
        .round = both({62, 62, 31, 0, 0, 44, true, 0}),
    },
    {
        // Sleepy
        .rounded = {{64, 28, 10, 0, -6, 0, false, 14}, {64, 20, 9, 0, -6, 0, false, 18}},
        .round = {{62, 28, 14, 0, -6, 0, false, 14}, {62, 20, 10, 0, -6, 0, false, 18}},
    },
    {
        // Surprised
        .rounded = both({72, 80, 20, 0, 0, 0, false, 0}),
        .round = both({72, 72, 36, 0, 0, 0, false, 0}),
    },
    {
        // Suspicious
        .rounded = {{62, 30, 8, 0, 0, 0, false, 0}, {56, 30, 8, 0, 9, 0, false, 1}},
        .round = {{62, 30, 13, 0, 0, 0, false, 0}, {56, 30, 13, 0, 9, 0, false, 1}},
    },
    {
        // Angry
        .rounded = both({64, 68, 16, 24, 22, 0, false, 0}),
        .round = both({62, 62, 31, 16, 18, 14, false, 0}),
    },
    {
        // Focused
        .rounded = both({60, 20, 8, 0, 0, 0, false, 0}),
        .round = both({60, 20, 10, 0, 0, 0, false, 0}),
    },
    {
        // Bored
        .rounded = both({64, 68, 16, 34, 0, 0, false, 0}),
        .round = both({62, 62, 31, 31, 0, 0, false, 0}),
    },
};

static_assert(sizeof(LOOKS) / sizeof(LOOKS[0]) == (int)Mood::Count,
              "Elke Mood moet een rij hebben in LOOKS");

Expression expressionFor(EyeStyle style, Mood mood)
{
    const MoodLook& look = LOOKS[(int)mood];

    if (style == EyeStyle::Round)
    {
        return look.round;
    }
    return look.rounded;
}
