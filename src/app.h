#ifndef STADIUM_APP_H
#define STADIUM_APP_H

#include <GL/freeglut.h>

extern float Y, Yce, rotateA, rotateAspeed;
extern int polygonMode;
extern float sv, svR, Ra, idl;
extern GLuint texName2, parket, semaforce, reklam, stativi, precki, wood, metal;

void ReduceToUnit(float vector[3]);
void calcNormal(float v[3][3], float out[3]);
void MakeShadowMatrix(GLfloat points[3][3], GLfloat lightPos[4], GLfloat destMat[4][4]);
void eu(void);
void kutlesh(void);
void znaminja(void);
void mreziste (void);
void semafor(void);
void pokriv(void);
void krug(void);
void stol(int oboen);
void reklama(int oboen);
void klupa(int oboen);
void reflektor(void);
void mrezha (void);
void dolga_mreza(void);
void vertikalna_mreza(void);
void krivina(void);
void site_krivini(void);
void tribina(void);
void teren(void);
void stativa(int oboen);
void precka(int oboen);
void mrezicka(int oboen);
void gol(int oboen);
void linii(void);
void pod(void);
void logErrorMessages(void);
void display(void);
void init (void);
void keyboard(unsigned char key, int x, int y);
void idle(void);

#endif /* STADIUM_APP_H */
