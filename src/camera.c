#include "renderer.h"
#include "camera.h"
#include <stdio.h>
#include <stdlib.h>

void keyboard(unsigned char key, int x, int y)
{

   /*
Треба да може рефлекторот да ротира  околу целата сцена (буквите J и L)
 со независна брзина од евентуалното движење на погледот и постојано да
 свети кон истата позиција – значи постојано да свети кон средината на теренот без разлика 
каде се наоѓа и како е свртен погледот. Треба да може да се доближува и одалечува (буквите I и K) 
од теренот додека ротира и да се стеснува или раширува снопот (буквите Y и H).
*/
   printf("%d %f  \n", key, Yce);
   switch (key) {
      case 27:
         exit(0);
         break;
      case 'W':
         Yce+=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'S':
         Yce-=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'w':
         Yce+=0.5;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 's':
         Yce-=0.5;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'A':
         rotateAspeed+=0.01f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'a':
         rotateAspeed+=0.01f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'D':
         rotateAspeed-=0.01f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'd':
         rotateAspeed-=0.01f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case '1':
         polygonMode=GL_LINE;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case '2':
         polygonMode=GL_FILL;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case '3':
         polygonMode=GL_POINT;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'r':
         Y+=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'f':
         Y-=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'j':
         idl+=0.1f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'l':
         idl-=0.1f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'J':
         idl+=0.1f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'L':
         idl-=0.1f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'y':
         sv+=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'h':
         sv-=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'Y':
         sv+=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'H':
         sv-=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'i':
         Ra+=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'k':
         Ra-=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'I':
         Ra+=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;
      case 'K':
         Ra-=0.5f;
         glutPostRedisplay();  // obnovi go prikazot
         break;

   }
}

void idle(void)
{
  svR+=idl;
  rotateA+=rotateAspeed;
  glutPostRedisplay();
}
