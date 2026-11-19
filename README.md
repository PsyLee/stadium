# Stadium

A 3D stadium visualization written in C using legacy OpenGL, GLU, and FreeGLUT.
The application renders a football pitch, stands, goals, seating, lighting,
projected shadows, and bitmap textures.

## Requirements

On Debian or Ubuntu:

```sh
sudo apt update
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev
```

A working OpenGL-compatible graphics driver and display session are also required.

## Build

The project keeps its Linux makefile under the historical name `Makefilelinux`:

```sh
make -f Makefilelinux
```

Run the application from the repository root so the relative BMP texture paths
can be resolved:

```sh
./primer
```

Clean generated files:

```sh
make -f Makefilelinux clean
```

## Controls

| Key | Action |
| --- | --- |
| W / S | Move the camera farther from / closer to the scene |
| R / F | Raise / lower the camera |
| A / D | Rotate the camera around the scene |
| J / L | Rotate the spotlight |
| I / K | Increase / decrease spotlight distance |
| Y / H | Raise / lower the spotlight |
| 1 | Wireframe rendering |
| 2 | Filled polygons |
| 3 | Point rendering |
| Esc | Exit |

## Source layout

- `primer.c` — scene geometry, rendering, lighting, camera, and input.
- `utils.c`, `utils.h` — BMP image loading and image-memory cleanup.
- `*.bmp` — textures used by the scene.

The renderer currently uses the fixed-function OpenGL pipeline and immediate-mode
geometry. A migration to modern OpenGL is a separate, larger project; the current
maintenance changes intentionally preserve the existing rendering approach.

## Bitmap support

The image loader accepts uncompressed 24-bit BMP files with a Windows-style
DIB header of at least 40 bytes. It handles padded scanlines and both
bottom-up and top-down images, converting BGR pixels to RGB.
