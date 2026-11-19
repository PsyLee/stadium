# Stadium

A 3D football stadium visualization written in C using legacy OpenGL, GLU,
and FreeGLUT.

## Requirements

On Debian or Ubuntu:

```sh
sudo apt update
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev
```

A working OpenGL-compatible graphics driver and display session are also required.

## Build and run

Run from the repository root so the BMP texture paths resolve:

```sh
make -f Makefilelinux clean all
./primer
```

Clean generated files with `make -f Makefilelinux clean`.

## Controls

| Key | Action |
| --- | --- |
| W / S | Move camera farther from / closer to the scene |
| R / F | Raise / lower camera |
| A / D | Rotate camera |
| J / L | Rotate spotlight |
| I / K | Increase / decrease spotlight distance |
| Y / H | Raise / lower spotlight |
| 1 | Wireframe rendering |
| 2 | Filled polygons |
| 3 | Point rendering |
| Esc | Exit |

## Source layout

- `primer.c` — scene geometry, rendering, lighting, camera, and input.
- `utils.c`, `utils.h` — BMP image loading and image-memory cleanup.
- `*.bmp` — textures used by the scene.

The renderer uses the fixed-function OpenGL pipeline and immediate-mode geometry.
