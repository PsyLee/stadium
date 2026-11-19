#ifndef STADIUM_LIGHTING_H
#define STADIUM_LIGHTING_H
#include <GL/freeglut.h>
void ReduceToUnit(float vector[3]);
void calcNormal(float vertices[3][3], float normal[3]);
void MakeShadowMatrix(GLfloat points[3][3], GLfloat lightPosition[4], GLfloat destination[4][4]);
void lightingInitialize(void);
void lightingUpdatePosition(float radius, float angle, float height, GLfloat lightPosition[4]);
#endif
