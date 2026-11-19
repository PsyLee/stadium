#include "lighting.h"
#include <math.h>

void ReduceToUnit(float vector[3])
{
    float length;
    length = (float)sqrt((vector[0]*vector[0]) +
                          (vector[1]*vector[1]) +
                          (vector[2]*vector[2]));
    if(length == 0.0f)
    length = 1.0f;
    vector[0] /= length;
    vector[1] /= length;
    vector[2] /= length;
}

void calcNormal(float v[3][3], float out[3])
{
    float v1[3],v2[3];
    static const int x = 0;
    static const int y = 1;
    static const int z = 2;
    v1[x] = v[0][x] - v[1][x];
    v1[y] = v[0][y] - v[1][y];
    v1[z] = v[0][z] - v[1][z];
    v2[x] = v[1][x] - v[2][x];
    v2[y] = v[1][y] - v[2][y];
    v2[z] = v[1][z] - v[2][z];
    out[x] = v1[y]*v2[z] - v1[z]*v2[y];
    out[y] = v1[z]*v2[x] - v1[x]*v2[z];
    out[z] = v1[x]*v2[y] - v1[y]*v2[x];
    ReduceToUnit(out);
}

void MakeShadowMatrix(GLfloat points[3][3], GLfloat lightPos[4],
                      GLfloat destMat[4][4])
{
    GLfloat planeCoeff[4];
    GLfloat dot;
    calcNormal(points,planeCoeff);
    planeCoeff[3] = - (
                        (planeCoeff[0]*points[2][0]) +
                        (planeCoeff[1]*points[2][1]) +
                        (planeCoeff[2]*points[2][2]));
    dot = planeCoeff[0] * lightPos[0] +
                        planeCoeff[1] * lightPos[1] +
                        planeCoeff[2] * lightPos[2] +
                        planeCoeff[3] * lightPos[3];
    destMat[0][0] = dot - lightPos[0] * planeCoeff[0];
    destMat[1][0] = 0.0f - lightPos[0] * planeCoeff[1];
    destMat[2][0] = 0.0f - lightPos[0] * planeCoeff[2];
    destMat[3][0] = 0.0f - lightPos[0] * planeCoeff[3];
    destMat[0][1] = 0.0f - lightPos[1] * planeCoeff[0];
    destMat[1][1] = dot - lightPos[1] * planeCoeff[1];
    destMat[2][1] = 0.0f - lightPos[1] * planeCoeff[2];
    destMat[3][1] = 0.0f - lightPos[1] * planeCoeff[3];
    destMat[0][2] = 0.0f - lightPos[2] * planeCoeff[0];
    destMat[1][2] = 0.0f - lightPos[2] * planeCoeff[1];
    destMat[2][2] = dot - lightPos[2] * planeCoeff[2];
    destMat[3][2] = 0.0f - lightPos[2] * planeCoeff[3];
    destMat[0][3] = 0.0f - lightPos[3] * planeCoeff[0];
    destMat[1][3] = 0.0f - lightPos[3] * planeCoeff[1];
    destMat[2][3] = 0.0f - lightPos[3] * planeCoeff[2];
    destMat[3][3] = dot - lightPos[3] * planeCoeff[3];
}

void lightingInitialize(void)
{
    // globalno svetlo
    GLfloat global_ambient[]= {0.6,0.6,0.6,0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    
    // Svetlo 0
    GLfloat svetlo0_ambient[]= {0.7,0.7,0.7,0};
    GLfloat svetlo0_diffuse[]= {0.8,0.8,0.8,1};
    GLfloat svetlo0_specular[]= {1,1,1,1};
    
    glLightfv(GL_LIGHT0,GL_AMBIENT,svetlo0_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,svetlo0_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,svetlo0_specular);
    
    glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,60.0f);
    glLighti(GL_LIGHT0,GL_SPOT_EXPONENT,30);
    glEnable(GL_LIGHT0);
}

void lightingUpdatePosition(float radius, float angle, float height, GLfloat lightPosition[4])
{
    GLfloat spotDirection[3];
    lightPosition[0] = radius * sinf(angle);
    lightPosition[1] = height;
    lightPosition[2] = radius * cosf(angle);
    lightPosition[3] = 1.0f;
    spotDirection[0] = -radius * sinf(angle);
    spotDirection[1] = -height;
    spotDirection[2] = -radius * cosf(angle);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection);
}
