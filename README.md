# Stadium

A 3D football stadium visualization written in C using legacy OpenGL, GLU,
and FreeGLUT. The project renders stadium geometry, seating, goals, lighting,
projected shadows, and bitmap textures.

## Requirements

On Debian or Ubuntu:

```sh
sudo apt update
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev
```

A working OpenGL-compatible graphics driver and display session are also required.

## Build and run

Run from the repository root (texture assets are loaded relative to the
working directory):

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

- `src/main.c` — GLUT entry point and callback registration.
- `src/app.h` — shared application declarations and module interfaces.
- `src/app_state.c` — shared camera, lighting, render-mode, and texture state.
- `src/camera.c` — keyboard controls and idle updates.
- `src/renderer.c` — scene display, OpenGL setup, texture upload, and GL diagnostics.
- `src/geometry.c` — stadium, pitch, stands, goals, seating, and scene geometry.
- `src/math3d.c` — vector normals and shadow projection math.
- `utils.c`, `utils.h` — BMP loading and image cleanup.
- `*.bmp` — texture assets.

The renderer intentionally remains on fixed-function OpenGL in this phase.
The module boundaries make a future shader/VBO migration easier without
requiring a visual rewrite now.

## Bitmap support

The image loader accepts uncompressed 24-bit BMP files with a Windows-style
DIB header of at least 40 bytes. It handles padded scanlines and both
bottom-up and top-down images, converting BGR pixels to RGB.
