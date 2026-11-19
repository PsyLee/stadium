#include "geometry.h"
#include "../renderer.h"
#include <math.h>

void stativa(int oboen)
{
if(oboen==1)
{
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, stativi);
	  // glFrontFace(GL_CCW);
	int l=0;
	for(l=0;l<4;l++)
	{
		glPushMatrix();
			//glColor3f(1,1,1);
			glBegin(GL_QUADS);
			  glNormal3f(0,0,1); 
			glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
			glTexCoord2f(1,0);  glVertex3f(0.08, 0, 0);
			glTexCoord2f(1,1);  glVertex3f(0.08, 2.0, 0);
			glTexCoord2f(0,1);  glVertex3f(0, 2.0, 0);
		   	  glEnd();
		
		glPopMatrix();
		glRotatef(90,0,1,0);
		glTranslatef(0,0,0.08);
	}

glMatrixMode(GL_MODELVIEW);
   glBindTexture(GL_TEXTURE_2D, 0);
}
else
{
	int l=0;
	for(l=0;l<4;l++)
	{
		glPushMatrix();
			glColor4f(0,0,0,0.7);
			glBegin(GL_QUADS);
			  glNormal3f(0,0,1); 
			glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
			glTexCoord2f(1,0);  glVertex3f(0.08, 0, 0);
			glTexCoord2f(1,1);  glVertex3f(0.08, 2.0, 0);
			glTexCoord2f(0,1);  glVertex3f(0, 2.0, 0);
		   	  glEnd();
		
		glPopMatrix();
		glRotatef(90,0,1,0);
		glTranslatef(0,0,0.08);
	}

}
}

void precka(int oboen)
{
if(oboen==1)
{
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, precki);
	   glFrontFace(GL_CCW);
	int l=0;
	for(l=0;l<4;l++)
	{
		glPushMatrix();
			//glColor3f(1,1,1);
			glBegin(GL_QUADS);
			  glNormal3f(0,0,1);
 
			 glTexCoord2f(0,0); glVertex3f(0, 0, 0);
			 glTexCoord2f(1,0); glVertex3f(3.16, 0, 0);
			 glTexCoord2f(1,1); glVertex3f(3.16, 0.08, 0);
			 glTexCoord2f(0,1); glVertex3f(0, 0.08, 0);
		   	  glEnd();
		
		glPopMatrix();
		glRotatef(90,1,0,0);
		glTranslatef(0,0,-0.08);
	}
glMatrixMode(GL_MODELVIEW);
   glBindTexture(GL_TEXTURE_2D, 0);
}
else
{
	   glFrontFace(GL_CCW);
	int l=0;
	for(l=0;l<4;l++)
	{
		glPushMatrix();
			glColor4f(0,0,0,0.7);
			glBegin(GL_QUADS);
			  glNormal3f(0,0,1);
 
			 glTexCoord2f(0,0); glVertex3f(0, 0, 0);
			 glTexCoord2f(1,0); glVertex3f(3.16, 0, 0);
			 glTexCoord2f(1,1); glVertex3f(3.16, 0.08, 0);
			 glTexCoord2f(0,1); glVertex3f(0, 0.08, 0);
		   	  glEnd();
		
		glPopMatrix();
		glRotatef(90,1,0,0);
		glTranslatef(0,0,-0.08);
	}
}
}

void mrezicka(int oboen)
{
if(oboen==1)
{
	float mat_ambient []={0.5f, 	0.5f, 	0.5f,   0};
	   float mat_diffuse []={0.7f, 	0.7f, 	0.7f,  0};
	   float mat_specular[]={0.9f, 	0.9f, 	0.9f, 0};
	   float mat_shininess = 0.8;
	   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	   glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);

	glFrontFace(GL_CCW);

		int l=0;
	for(l=0;l<7;l++)
	{
		glPushMatrix();
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
			  glNormal3f(0,1,0);
 
			  glVertex3f(0, 0, 0.08);
			  glVertex3f(3.08, 0, 0.08);
			  glVertex3f(3.08, 0.01, 0.08);
			  glVertex3f(0, 0.01, 0.08);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,0,0.1);
	}
	
	for(l=0;l<32;l++)
	{
		glPushMatrix();
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
			  glNormal3f(0,1,0);
 
			  glVertex3f(0, 0.01, 0);
			  glVertex3f(0, 0.01, -0.6);
			  glVertex3f(0, 0.02, -0.6);
			  glVertex3f(0, 0.02, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0.1,0,0);
	}
	
	for(l=0;l<20;l++)
	{
		glPushMatrix();
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
			  glNormal3f(0,1,0);
 
			  glVertex3f(-0.08, 0, 0);
			  glVertex3f(-0.08, 0, -0.6);
			  glVertex3f(-0.08, 0.01, -0.6);
			  glVertex3f(-0.08, 0.01, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,-0.1,0);
	}
	
	for(l=0;l<6;l++)
	{
		glPushMatrix();
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
			  glNormal3f(0,0,1);
 
			  glVertex3f(-0.08, 0, 0);
			  glVertex3f(-0.08, 2, 0);
			  glVertex3f(-0.07, 2, 0);
			  glVertex3f(-0.07, 0, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,0,-0.1);
	}
///////////////////////////////////


	for(l=0;l<20;l++)
	{
		glPushMatrix();
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
			  glNormal3f(0,1,0);
 
			  glVertex3f(-3.16, 0, 0);
			  glVertex3f(-3.16, 0, 0.6);
			  glVertex3f(-3.16, 0.01, 0.6);
			  glVertex3f(-3.16, 0.01, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,0.1,0);
	}
	
	for(l=0;l<6;l++)
	{
		glPushMatrix();
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
			  glNormal3f(0,0,1);
 
			  glVertex3f(-3.16, 0, 0);
			  glVertex3f(-3.16, -2, 0);
			  glVertex3f(-3.17, -2, 0);
			  glVertex3f(-3.17, 0, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,0,0.1);
	}
///////////////////////////////////////////////////////////
	for(l=0;l<20;l++)
	{
		glPushMatrix();
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
			  glNormal3f(0,1,0);
 
			  glVertex3f(-3.16, 0, 0.08);
			  glVertex3f(-0.08, 0, 0.08);
			  glVertex3f(-0.08, 0.01, 0.08);
			  glVertex3f(-3.16, 0.01, 0.08);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,-0.1,0);
	}
	
	for(l=0;l<31;l++)
	{
		glPushMatrix();
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
			  glNormal3f(0,0,1);
 
			  glVertex3f(-3.16, 2, 0);
			  glVertex3f(-3.16, 0, 0);
			  glVertex3f(-3.17, 0, 0);
			  glVertex3f(-3.17, 2, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0.1,0,0);
	}

}
else
{
glColor4f(0,0,0,0.7);
glFrontFace(GL_CCW);

		int l=0;
	for(l=0;l<7;l++)
	{
		glPushMatrix();
			glColor4f(0,0,0,0.7);
			glBegin(GL_QUADS);
			  glNormal3f(0,1,0);
 
			  glVertex3f(0, 0, 0.08);
			  glVertex3f(3.08, 0, 0.08);
			  glVertex3f(3.08, 0.01, 0.08);
			  glVertex3f(0, 0.01, 0.08);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,0,0.1);
	}
	
	for(l=0;l<32;l++)
	{
		glPushMatrix();
			glColor4f(0,0,0,0.7);
			glBegin(GL_QUADS);
			  glNormal3f(0,1,0);
 
			  glVertex3f(0, 0.01, 0);
			  glVertex3f(0, 0.01, -0.6);
			  glVertex3f(0, 0.02, -0.6);
			  glVertex3f(0, 0.02, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0.1,0,0);
	}
	
	for(l=0;l<20;l++)
	{
		glPushMatrix();
			glColor4f(0,0,0,0.7);
			glBegin(GL_QUADS);
			  glNormal3f(0,1,0);
 
			  glVertex3f(-0.08, 0, 0);
			  glVertex3f(-0.08, 0, -0.6);
			  glVertex3f(-0.08, 0.01, -0.6);
			  glVertex3f(-0.08, 0.01, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,-0.1,0);
	}
	
	for(l=0;l<6;l++)
	{
		glPushMatrix();
			glColor4f(0,0,0,0.7);
			glBegin(GL_QUADS);
			  glNormal3f(0,0,1);
 
			  glVertex3f(-0.08, 0, 0);
			  glVertex3f(-0.08, 2, 0);
			  glVertex3f(-0.07, 2, 0);
			  glVertex3f(-0.07, 0, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,0,-0.1);
	}
///////////////////////////////////


	for(l=0;l<20;l++)
	{
		glPushMatrix();
			glColor4f(0,0,0,0.7);
			glBegin(GL_QUADS);
			  glNormal3f(0,1,0);
 
			  glVertex3f(-3.16, 0, 0);
			  glVertex3f(-3.16, 0, 0.6);
			  glVertex3f(-3.16, 0.01, 0.6);
			  glVertex3f(-3.16, 0.01, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,0.1,0);
	}
	
	for(l=0;l<6;l++)
	{
		glPushMatrix();
			glColor4f(0,0,0,0.7);
			glBegin(GL_QUADS);
			  glNormal3f(0,0,1);
 
			  glVertex3f(-3.16, 0, 0);
			  glVertex3f(-3.16, -2, 0);
			  glVertex3f(-3.17, -2, 0);
			  glVertex3f(-3.17, 0, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,0,0.1);
	}
///////////////////////////////////////////////////////////
	for(l=0;l<20;l++)
	{
		glPushMatrix();
			glColor4f(0,0,0,0.7);
			glBegin(GL_QUADS);
			  glNormal3f(0,1,0);
 
			  glVertex3f(-3.16, 0, 0.08);
			  glVertex3f(-0.08, 0, 0.08);
			  glVertex3f(-0.08, 0.01, 0.08);
			  glVertex3f(-3.16, 0.01, 0.08);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0,-0.1,0);
	}
	
	for(l=0;l<31;l++)
	{
		glPushMatrix();
			glColor4f(0,0,0,0.7);
			glBegin(GL_QUADS);
			  glNormal3f(0,0,1);
 
			  glVertex3f(-3.16, 2, 0);
			  glVertex3f(-3.16, 0, 0);
			  glVertex3f(-3.17, 0, 0);
			  glVertex3f(-3.17, 2, 0);
		   	  glEnd();
		
		glPopMatrix();
		glTranslatef(0.1,0,0);
	}

}
}

void gol(int oboen)
{
	glPushMatrix();
		stativa(oboen);
	glTranslatef(0,0,0.08);
	glTranslatef(-3.08,0,-0.08);
		stativa(oboen);
	glTranslatef(0,2,-0.08);
		precka(oboen);
		mrezicka(oboen);
	glPopMatrix();	
}
