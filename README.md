# Stadium

A 3D football stadium visualization written in C using FreeGLUT, GLU, and the fixed-function OpenGL pipeline. The application renders a football pitch, goals, stands, seating, stadium details, textures, lighting, and projected shadows.

The codebase is organized into focused modules for rendering, camera controls, lighting, geometry, and BMP image loading. The refactor is intended to improve maintainability while preserving the original scene and interaction model.

## Features

- 3D football stadium scene with textured geometry.
- Interactive camera positioning and rotation.
- Movable spotlight with adjustable position.
- Wireframe, filled-polygon, and point rendering modes.
- BMP texture loading through a standalone image utility.
- Unit tests for BMP image loading and pixel conversion.

## Requirements

You need a C compiler, GNU Make, FreeGLUT, GLU, OpenGL development libraries, and a working graphics driver/display.

On Debian or Ubuntu, install the build dependencies with:

```sh
sudo apt update
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev libgl1-mesa-dev
```

## Build

Run these commands from the repository root:

```sh
make
```

This builds the executable named `primer`.

To start the application:

```sh
./primer
```

The program loads its BMP textures from the `assets/` directory using paths relative to the repository root. Run it from the root directory so those paths resolve correctly.

To remove generated object files, the executable, and the test binary:

```sh
make clean
```

## Controls

| Key | Action |
| --- | --- |
| W / S | Move the camera farther from / closer to the scene |
| A / D | Increase / decrease camera rotation speed |
| R / F | Raise / lower the camera |
| J / L | Increase / decrease spotlight rotation speed |
| I / K | Move the spotlight farther from / closer to the scene |
| Y / H | Raise / lower the spotlight |
| 1 | Wireframe rendering |
| 2 | Filled-polygon rendering |
| 3 | Point rendering |
| Esc | Exit |

The movement and rotation controls accept uppercase and lowercase input, except R/F, which are handled as lowercase keys.

## Tests

Run the BMP image-loader unit test with:

```sh
make test
```

The image-loader test is a CPU-only test and does not require an OpenGL display. It covers BMP loading, padded scanlines, BGR-to-RGB conversion, image dimensions, and image-buffer cleanup.

## Project structure

```text
stadium/
├── src/
│   ├── main.c
│   ├── renderer.c
│   ├── renderer.h
│   ├── camera.c
│   ├── camera.h
│   ├── lighting.c
│   ├── lighting.h
│   ├── geometry/
│   │   ├── geometry.h
│   │   ├── pitch.c
│   │   ├── stands.c
│   │   ├── goals.c
│   │   ├── seats.c
│   │   └── stadium.c
│   └── utils/
│       ├── image.c
│       └── image.h
├── assets/
│   └── *.bmp
├── tests/
│   └── test_image.c
├── Makefile
├── README.md
└── .gitignore
```

### Module responsibilities

- `src/main.c` initializes the GLUT window and registers the application callbacks.
- `src/renderer.c` initializes OpenGL state, loads textures, and draws the scene.
- `src/camera.c` handles keyboard input and per-frame camera/spotlight updates.
- `src/lighting.c` configures lighting, updates the spotlight position, and provides shadow-matrix and normal-vector helpers.
- `src/geometry/` contains the geometry routines, split by stadium component.
- `src/utils/image.c` loads uncompressed 24-bit BMP images, handles padded scanlines and top-down or bottom-up image layouts, and converts pixel data from BGR to RGB.
- `assets/` stores the bitmap textures used by the renderer.
- `tests/` contains the image-loader regression test.

## Implementation notes

The renderer currently uses legacy fixed-function OpenGL. This repository's modular structure is a code-organization improvement; it is not a migration to a modern shader-based OpenGL renderer.


## WebGL browser edition

A browser-based WebGL 2 edition is available in [`webgl/`](webgl/). It uses Three.js to render a procedural stadium scene with interactive camera controls, movable spotlight, shadow mapping, and solid / wireframe / point display modes.

Run it locally:

```sh
cd webgl
python3 -m http.server 8000
```

Then open http://localhost:8000.

See [`webgl/README.md`](webgl/README.md) for browser controls and migration notes. The original C/OpenGL application remains intact.
