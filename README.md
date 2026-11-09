# DesktopBuddy

> 🚧 **Work in progress.** Version 1 runs in the Wokwi simulator, and the port to real hardware is underway.

A small desk companion robot, inspired by Cozmo and the Tamagotchi. DesktopBuddy shows an animated face on a TFT screen, reacts when you interact with it and switches between moods.

## What it does

- **Living eyes:** blinks at random intervals and looks around smoothly
- **8 moods:** Neutral, Happy, Sleepy, Surprised, Suspicious, Angry, Focused and Bored, each with its own eye shape and eyelid position
- **Reacts to petting:** becomes happy when petted and calms back down after a few seconds
- **Two eye styles:** rounded rectangles or round eyes with a curved lower lid
- **Multi-board support:** pin definitions per board in `Board.h`, selected through a build flag

## Hardware

| | Simulator | Real board |
|---|---|---|
| Board | ESP32-S3 DevKitC | Jingcai ESP32-3248S035C (ESP32) |
| Display | ILI9341 | 3.5" ST7796 with GT911 touch |
| Input | Two push buttons (pet, mood) | Touch screen, light sensor |

## Tech stack

- C++ with the Arduino framework on ESP32
- [PlatformIO](https://platformio.org/) for builds and board environments
- [Arduino GFX Library](https://github.com/moononournation/Arduino_GFX) for drawing, using an off-screen canvas to prevent flicker
- [Wokwi](https://wokwi.com/) for simulating the hardware

## Building

```sh
pio run                          # build for the Wokwi simulator (default)
pio run -e v1-jingcai            # build for the real board
pio run -e v1-jingcai -t upload  # build and flash the real board
```

To run it in the simulator, build the default environment and start Wokwi (for example with the Wokwi extension in VS Code). It picks up `wokwi.toml` and `diagram.json`.

## Project structure

```
src/
├── Main.cpp              # Setup and main loop
├── config/Board.h        # Pin definitions per board
├── face/                 # Face rendering: eyes, expressions, blinking, looking around
├── hardware/             # Display and sensor setup
└── mood/                 # Mood logic and transitions
```

## Roadmap

- [x] Animated eyes with blinking and looking around
- [x] Moods and expressions
- [x] Simulation in Wokwi
- [ ] Touch input on the real board
- [ ] Light sensor (sleepy when it gets dark)
- [ ] Sound through the speaker
- [ ] Enclosure and physical build
