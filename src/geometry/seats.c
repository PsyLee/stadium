#include "geometry.h"
#include "../renderer.h"
#include <math.h>

void stol(int oboen)
{

if (oboen==1) {
 glBindTexture(GL_TEXTURE_2D, wood);
		glMatrixMode(GL_TEXTURE);
	   glFrontFace(GL_CCW);
		
		//glColor3f (1, 1, 1);
			glBegin(GL_POLYGON);
				glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f (0, 0, 0);
			glTexCoord2f(1,0); glVertex3f (0.05, 0, 0);
			glTexCoord2f(1,1); glVertex3f (0.05, 0.5, 0);
			glTexCoord2f(0,1); glVertex3f (0, 0.5, 0);
			glEnd();
	
			glBegin(GL_POLYGON);
				glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f (0.45, 0, 0);
			glTexCoord2f(1,0); glVertex3f (0.5, 0, 0);
			glTexCoord2f(1,1); glVertex3f (0.5, 0.5, 0);
			glTexCoord2f(0,1); glVertex3f (0.45, 0.5, 0);
			glEnd();

			glBegin(GL_POLYGON);
				glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f (0, 0, 0.5);
			glTexCoord2f(1,0); glVertex3f (0.05, 0, 0.5);
			glTexCoord2f(1,1); glVertex3f (0.05, 0.7, 0.5);
			glTexCoord2f(0,1); glVertex3f (0, 0.7, 0.5);
			glEnd();
	
			glBegin(GL_POLYGON);
				glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f (0.45, 0, 0.5);
			glTexCoord2f(1,0); glVertex3f (0.5, 0, 0.5);
			glTexCoord2f(1,1); glVertex3f (0.5, 0.7, 0.5);
			glTexCoord2f(0,1); glVertex3f (0.45, 0.7, 0.5);
			glEnd();

			glBegin(GL_POLYGON);
				glNormal3f(0,1,0);
			glTexCoord2f(0,0); glVertex3f (0, 0.5, 0);
			glTexCoord2f(1,0); glVertex3f (0, 0.5, 0.5);
			glTexCoord2f(1,1); glVertex3f (0.5, 0.5, 0.5);
			glTexCoord2f(0,1); glVertex3f (0.5, 0.5, 0);
			glEnd();

			glBegin(GL_POLYGON);
				glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f (0, 0.7, 0.5);
			glTexCoord2f(1,0); glVertex3f (0.5, 0.7, 0.5);
			glTexCoord2f(1,1); glVertex3f (0.5, 1, 0.5);
			glTexCoord2f(0,1); glVertex3f (0, 1, 0.5);
			glEnd();

glMatrixMode(GL_MODELVIEW);
   glBindTexture(GL_TEXTURE_2D, 0);

}else
{
		glColor4f(0,0,0,0.7);
		glFrontFace(GL_CCW);
		
		//glColor3f (1, 1, 1);
			glBegin(GL_POLYGON);
				glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f (0, 0, 0);
			glTexCoord2f(1,0); glVertex3f (0.05, 0, 0);
			glTexCoord2f(1,1); glVertex3f (0.05, 0.5, 0);
			glTexCoord2f(0,1); glVertex3f (0, 0.5, 0);
			glEnd();
	
			glBegin(GL_POLYGON);
				glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f (0.45, 0, 0);
			glTexCoord2f(1,0); glVertex3f (0.5, 0, 0);
			glTexCoord2f(1,1); glVertex3f (0.5, 0.5, 0);
			glTexCoord2f(0,1); glVertex3f (0.45, 0.5, 0);
			glEnd();

			glBegin(GL_POLYGON);
				glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f (0, 0, 0.5);
			glTexCoord2f(1,0); glVertex3f (0.05, 0, 0.5);
			glTexCoord2f(1,1); glVertex3f (0.05, 0.7, 0.5);
			glTexCoord2f(0,1); glVertex3f (0, 0.7, 0.5);
			glEnd();
	
			glBegin(GL_POLYGON);
				glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f (0.45, 0, 0.5);
			glTexCoord2f(1,0); glVertex3f (0.5, 0, 0.5);
			glTexCoord2f(1,1); glVertex3f (0.5, 0.7, 0.5);
			glTexCoord2f(0,1); glVertex3f (0.45, 0.7, 0.5);
			glEnd();

			glBegin(GL_POLYGON);
				glNormal3f(0,1,0);
			glTexCoord2f(0,0); glVertex3f (0, 0.5, 0);
			glTexCoord2f(1,0); glVertex3f (0, 0.5, 0.5);
			glTexCoord2f(1,1); glVertex3f (0.5, 0.5, 0.5);
			glTexCoord2f(0,1); glVertex3f (0.5, 0.5, 0);
			glEnd();

			glBegin(GL_POLYGON);
				glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f (0, 0.7, 0.5);
			glTexCoord2f(1,0); glVertex3f (0.5, 0.7, 0.5);
			glTexCoord2f(1,1); glVertex3f (0.5, 1, 0.5);
			glTexCoord2f(0,1); glVertex3f (0, 1, 0.5);
			glEnd();
}
	  
	
}

void klupa(int oboen)
{
if(oboen==1)
{
	glBindTexture(GL_TEXTURE_2D, wood);
glMatrixMode(GL_TEXTURE);
	   glFrontFace(GL_CW);
	
	//glColor3f(0.5,0.5,1);
	glBegin(GL_QUADS);
	  glNormal3f(0,1,0);
 	  glTexCoord2f(0,0); glVertex3f(-10, 2, -1);
	  glTexCoord2f(1,0); glVertex3f(10, 2, -1);
	  glTexCoord2f(1,1); glVertex3f(10, 2, 1);
	  glTexCoord2f(0,1); glVertex3f(-10, 2, 1);
   	  glEnd();
	
	
	glBegin(GL_QUADS);
	  glNormal3f(0,0,-1);
 	 glTexCoord2f(0,0); glVertex3f(-10, 0.04, 1);
	 glTexCoord2f(1,0); glVertex3f(10, 0.04, 1);
	 glTexCoord2f(1,1);  glVertex3f(10, 2, 1);
	 glTexCoord2f(0,1); glVertex3f(-10, 2, 1);
   	  glEnd();

	
	glBegin(GL_QUADS);
	  glNormal3f(0,0,-1);
 	 glTexCoord2f(0,0); glVertex3f(-10, 0.04, -1);
	 glTexCoord2f(1,0); glVertex3f(10, 0.04, -1);
	 glTexCoord2f(1,1); glVertex3f(10, 2, -1);
	 glTexCoord2f(0,1); glVertex3f(-10, 2, -1);
   	  glEnd();

	
	glBegin(GL_QUADS);
	  glNormal3f(0,0,1);
 	 glTexCoord2f(0,0); glVertex3f(-10, 0.04, -1);
	 glTexCoord2f(1,0); glVertex3f(-10, 0.04, 1);
	 glTexCoord2f(1,1); glVertex3f(-10, 2, 1);
	 glTexCoord2f(0,1); glVertex3f(-10, 2, -1);
   	  glEnd();

	glBegin(GL_QUADS);
	  glNormal3f(0,0,1);
 	 glTexCoord2f(0,0); glVertex3f(10, 0.04, 1);
	 glTexCoord2f(1,0); glVertex3f(10, 0.04, -1);
	 glTexCoord2f(1,1); glVertex3f(10, 2, -1);
	 glTexCoord2f(0,1); glVertex3f(10, 2, 1);
   	  glEnd();

	glMatrixMode(GL_MODELVIEW);
   glBindTexture(GL_TEXTURE_2D, 0);
}
else
{

	
	   glFrontFace(GL_CW);
	
	glColor4f(0,0,0,0.7);
	glBegin(GL_QUADS);
	  glNormal3f(0,1,0);
 	  glTexCoord2f(0,0); glVertex3f(-10, 2, -1);
	  glTexCoord2f(1,0); glVertex3f(10, 2, -1);
	  glTexCoord2f(1,1); glVertex3f(10, 2, 1);
	  glTexCoord2f(0,1); glVertex3f(-10, 2, 1);
   	  glEnd();
	
	
	glBegin(GL_QUADS);
	  glNormal3f(0,0,-1);
 	 glTexCoord2f(0,0); glVertex3f(-10, 0.04, 1);
	 glTexCoord2f(1,0); glVertex3f(10, 0.04, 1);
	 glTexCoord2f(1,1);  glVertex3f(10, 2, 1);
	 glTexCoord2f(0,1); glVertex3f(-10, 2, 1);
   	  glEnd();

	
	glBegin(GL_QUADS);
	  glNormal3f(0,0,-1);
 	 glTexCoord2f(0,0); glVertex3f(-10, 0.04, -1);
	 glTexCoord2f(1,0); glVertex3f(10, 0.04, -1);
	 glTexCoord2f(1,1); glVertex3f(10, 2, -1);
	 glTexCoord2f(0,1); glVertex3f(-10, 2, -1);
   	  glEnd();

	
	glBegin(GL_QUADS);
	  glNormal3f(0,0,1);
 	 glTexCoord2f(0,0); glVertex3f(-10, 0.04, -1);
	 glTexCoord2f(1,0); glVertex3f(-10, 0.04, 1);
	 glTexCoord2f(1,1); glVertex3f(-10, 2, 1);
	 glTexCoord2f(0,1); glVertex3f(-10, 2, -1);
   	  glEnd();

	glBegin(GL_QUADS);
	  glNormal3f(0,0,1);
 	 glTexCoord2f(0,0); glVertex3f(10, 0.04, 1);
	 glTexCoord2f(1,0); glVertex3f(10, 0.04, -1);
	 glTexCoord2f(1,1); glVertex3f(10, 2, -1);
	 glTexCoord2f(0,1); glVertex3f(10, 2, 1);
   	  glEnd();

}
}
