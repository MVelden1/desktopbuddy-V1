# DesktopBuddy

> 🚧 **Work in progress.** Version 1 runs in the Wokwi simulator and the port to real hardware is underway.

A small desk companion, inspired by Cozmo and the Tamagotchi. DesktopBuddy shows an animated face on a TFT screen, reacts when you pet it and switches between moods.

<!-- Demo: add a GIF of the simulator here, for example ![DesktopBuddy in Wokwi](docs/demo.gif) -->

## About this project

A personal project to learn embedded C++ and hardware.

## What it does

- **Living eyes:** blinks at random intervals and looks around
- **8 moods:** Neutral, Happy, Sleepy, Surprised, Suspicious, Angry, Focused and Bored, each with its own eye shape and eyelid position
- **Reacts to petting:** becomes happy when petted and calms back down after a few seconds
- **Two eye styles:** Rounded (rounded rectangles) and Round (circles), set in code

## Engineering highlights

- **Non-blocking main loop:** everything is timed with `millis()` instead of `delay()`, so blinking, looking around and input handling run side by side
- **State machine for blinking:** the eyelids move through Open, Closing and Opening states
- **Data-driven expressions:** every mood is one row in a table with an eye shape per style and a `static_assert` stops the build when a mood is missing a row
- **Hardware abstraction at compile time:** one codebase for the simulator and the real board, selected through a build flag; pins live in `config/Board.h` and display and input code per board in `hardware/`
- **Flicker-free drawing:** the face is drawn into an off-screen canvas and sent to the screen in one go

## Hardware

| | Simulator | Real board |
|---|---|---|
| Board | ESP32-S3 DevKitC | Jingcai ESP32-3248S035C (ESP32, 4 MB flash, no PSRAM) |
| Display | ILI9341, 320x240 | 3.5" ST7796, 480x320 |
| Input | Two push buttons (pet, mood) | GT911 touch screen (planned) |
| Extras | | Light sensor, speaker output, microSD (planned) |

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

To run it in the simulator, build the default environment and start Wokwi (for example with the Wokwi plugin in CLion or the Wokwi extension in VS Code). It picks up `wokwi.toml` and `diagram.json`. In the simulator, press **P** to pet and **M** to cycle through the moods.

## Project structure

```
src/
├── Main.cpp              # Setup and main loop
├── config/Board.h        # Pin definitions per board
├── face/                 # Face: behaviour (Face), drawing (Eyes) and eye shapes per mood (Expressions)
├── hardware/             # Display and input per board
└── mood/                 # Mood logic
```

## Roadmap

Version 1: a face on the desk

- [x] Animated eyes with blinking and looking around
- [x] Moods and expressions in two eye styles
- [x] Simulation in Wokwi
- [x] Project structure with support for multiple boards
- [ ] Smooth animation: one frame timer, easing and morphing between moods
- [ ] Running on the real board
- [ ] Touch input as petting
- [ ] Moods with a cause (sleepy after a long quiet period, annoyed when petted too much)
- [ ] Animations: falling asleep, waking up, being startled, curious mode
- [ ] Light sensor (sleepy when it gets dark) and sounds through the speaker

Later versions: motion and temperature sensors, a personality that develops over time, an enclosure and eventually a version that can move.
