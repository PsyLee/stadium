# Stadium

A 3D football stadium visualization written in C using FreeGLUT, GLU, and fixed-function OpenGL. This refactor separates rendering, camera input, lighting, geometry, and image loading while preserving the existing scene and controls.

## Requirements

On Debian or Ubuntu:

```sh
sudo apt update
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev
```

A working OpenGL-compatible graphics driver and display session are required to run the graphical application.

## Build and run

```sh
make clean all
./primer
```

Run the image-loader unit test (no OpenGL display required):

```sh
make test
```

## Controls

| Key | Action |
| --- | --- |
| W / S | Move camera farther from / closer to the scene |
| R / F | Raise / lower camera |
| A / D | Rotate camera |
| J / L | Rotate spotlight |
| I / K | Increase / decrease spotlight distance |
| Y / H | Raise / lower spotlight |
| 1 / 2 / 3 | Wireframe / filled / point rendering |
| Esc | Exit |

## Layout

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

- `renderer.c` owns render state, texture upload, and scene drawing.
- `camera.c` handles keyboard controls and idle updates.
- `lighting.c` configures the spotlight and contains shadow-matrix helpers.
- `geometry/` separates pitch, stands, goals, seating, and stadium details.
- `utils/image.c` loads uncompressed 24-bit BMPs, including padded scanlines and top-down or bottom-up images, and converts BGR to RGB.
- Textures are loaded from `assets/` relative to the repository root.

The rendering pipeline remains fixed-function OpenGL; this change focuses on maintainable module boundaries.
