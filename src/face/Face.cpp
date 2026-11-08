//
// Created by Mick on 6-11-2026.
//

#include "face/Face.h"
#include "face/Expressions.h"
#include "face/Eyes.h"
#include "mood/Mood.h"

enum class BlinkState
{
    Open,
    Closing,
    Opening
};

// --- drawing ---
static Arduino_Canvas* face = nullptr;
static Mood currentMood = Mood::Neutral;
static Expression currentExpression;
static const bool LEFT_EYE = true;
static const bool RIGHT_EYE = false;
static EyeStyle eyeStyle = EyeStyle::Round;


// --- blinking ---
static BlinkState blinkState = BlinkState::Open;
static unsigned long blinkInterval = 4000;
static unsigned long lastBlink = 0;
static unsigned long lastBlinkStep = 0;
static int lid = 0;

// --- look around ---
static const int MAX_LOOK_X = 40;
static const int MAX_LOOK_Y = 30;
static int lookX = 0;
static int lookY = 0;
static int targetX = 0;
static int targetY = 0;
static unsigned long lastLook = 0;
static unsigned long lookDuration = 2000;
static unsigned long lastLookStep = 0;

static void drawEyes()
{
    face->fillScreen(RGB565_BLACK);
    eyesDraw(face, 78 + lookX, 70 + lookY, currentExpression.left, lid, LEFT_EYE);
    eyesDraw(face, 154 + lookX, 70 + lookY, currentExpression.right, lid, RIGHT_EYE);
    face->flush();
}

static void updateShape()
{
    currentExpression = expressionFor(eyeStyle, currentMood);
}

void faceBegin(Arduino_GFX* gfx)
{
    face = new Arduino_Canvas(232, 140, gfx, 44, 40);
    face->begin(GFX_SKIP_OUTPUT_BEGIN);

    updateShape();
    drawEyes();
}

static void updateBlink(unsigned long now)
{
    switch (blinkState)
    {
    case BlinkState::Open:
        if (now - lastBlink > blinkInterval)
            blinkState = BlinkState::Closing;
        break;

    case BlinkState::Closing:
        if (now - lastBlinkStep > 30)
        {
            lid += 25;
            drawEyes();
            if (lid >= 100)
            {
                lid = 100;
                blinkState = BlinkState::Opening;
            }
            lastBlinkStep = now;
        }
        break;

    case BlinkState::Opening:
        if (now - lastBlinkStep > 30)
        {
            lid -= 20;
            drawEyes();
            if (lid <= 0)
            {
                lid = 0;
                lastBlink = now;
                blinkInterval = random(3000, 7000);
                blinkState = BlinkState::Open;
            }
            lastBlinkStep = now;
        }
        break;
    }
}

static void updateLook(unsigned long now)
{
    if (now - lastLook > lookDuration)
    {
        if (random(0, 2) == 0)
        {
            targetX = 0;
            targetY = 0;
        }
        else
        {
            targetX = random(-MAX_LOOK_X, MAX_LOOK_X + 1);
            targetY = random(-MAX_LOOK_Y, MAX_LOOK_Y + 1);
        }
        lookDuration = random(1000, 4000);
        lastLook = now;
    }

    if (now - lastLookStep > 30 && (lookX != targetX || lookY != targetY))
    {
        lookX += constrain(targetX-lookX, -4, 4);
        lookY += constrain(targetY-lookY, -4, 4);
        drawEyes();
        lastLookStep = now;
    }
}

void faceUpdate(unsigned long now)
{
    updateBlink(now);
    updateLook(now);
}

void faceSetMood(Mood mood)
{
    if (mood == currentMood)
    {
        return;
    }

    currentMood = mood;

    updateShape();
    drawEyes();
}

Mood faceGetMood()
{
    return currentMood;
}
