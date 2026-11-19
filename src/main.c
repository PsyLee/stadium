#include "app.h"


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (700, 700); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Teren");
   init ();
   glutDisplayFunc(display); 
   glutIdleFunc(idle); 
   glutKeyboardFunc(keyboard); 
   glutMainLoop();
   return 0; 
}
