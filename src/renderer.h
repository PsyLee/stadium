#ifndef STADIUM_RENDERER_H
#define STADIUM_RENDERER_H
#include <GL/freeglut.h>
extern float Y, Yce, rotateA, rotateAspeed;
extern int polygonMode;
extern float sv, svR, Ra, idl;
extern GLuint texName2, parket, semaforce, reklam, stativi, precki, wood, metal;
void logErrorMessages(void);
void display(void);
void init(void);
#endif
