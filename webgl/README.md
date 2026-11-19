# Stadium — WebGL Edition

A browser-based 3D stadium visualization migrated from the original C / FreeGLUT / fixed-function OpenGL application.

## Run

No native compiler or OpenGL libraries are required. Serve this directory with any static HTTP server:

```sh
cd webgl
python3 -m http.server 8000
```

Open [http://localhost:8000](http://localhost:8000).

The app uses WebGL 2 through Three.js ES modules loaded from jsDelivr. An internet connection is required for the Three.js module and Google Fonts.

## Controls

- Drag the scene to orbit the camera; scroll to zoom.
- Use the sliders to adjust camera height, distance, and spotlight orbit.
- `W/S`: zoom in/out; `A/D`: rotate camera; `R/F`: raise/lower camera.
- `J/L`: rotate the spotlight; `I/K`: adjust spotlight intensity; `Y/H`: adjust spotlight cone.
- `1`: wireframe; `2`: solid; `3`: point rendering.
- Reset camera restores the initial view.

## Migration notes

The original program uses legacy immediate-mode OpenGL calls, GLUT callbacks, the fixed-function matrix stack, and BMP textures. Those APIs are not available in WebGL. This edition replaces them with:

- Three.js scene graph and indexed geometry primitives.
- WebGL 2 vertex/fragment shaders managed by Three.js.
- Perspective camera and pointer-driven orbit/zoom controls.
- Ambient, directional, and movable spot lighting with shadow maps.
- Browser-native UI for the original camera, lighting, and polygon display controls.

This first browser edition recreates the stadium scene procedurally. It is an architectural migration, not a line-by-line translation of every legacy polygon and BMP material. The original C/OpenGL source remains unchanged.
