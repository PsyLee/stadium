#include "geometry.h"
#include "../renderer.h"
#include <math.h>

void eu(void)
{
	
float pi=3.14;
float agol=pi/2;
float petina=0.6283;
float cekor=1.2566;
   glColor3f (1.0, 1.0, 0.0 );
float i;
for(i=0.0;i<2*pi;i+=0.5235)
{

glBegin(GL_POLYGON);

glVertex3f (15*cos(i)+cos(agol), 15*sin(i)+sin(agol), 0.0);
agol+=cekor;
glVertex3f (15*cos(i)+cos(agol), 15*sin(i)+sin(agol), 0.0);
agol+=cekor;
glVertex3f (15*cos(i)+cos(agol), 15*sin(i)+sin(agol), 0.0);
agol+=cekor;
glVertex3f (15*cos(i)+cos(agol), 15*sin(i)+sin(agol), 0.0);
agol+=cekor;
glVertex3f (15*cos(i)+cos(agol), 15*sin(i)+sin(agol), 0.0);

glEnd();

float prv=agol, vtor=agol+petina, tret=agol+cekor;

glBegin(GL_TRIANGLES);

glVertex3f (15*cos(i)+cos(prv), 15*sin(i)+sin(prv), 0.0);
glVertex3f (15*cos(i)+3*cos(vtor), 15*sin(i)+3*sin(vtor), 0.0);
glVertex3f (15*cos(i)+cos(tret), 15*sin(i)+sin(tret), 0.0);

glEnd();
//////////////
prv+=cekor;
vtor+=cekor;
tret+=cekor;
glBegin(GL_TRIANGLES);

glVertex3f (15*cos(i)+cos(prv), 15*sin(i)+sin(prv), 0.0);
glVertex3f (15*cos(i)+3*cos(vtor), 15*sin(i)+3*sin(vtor), 0.0);
glVertex3f (15*cos(i)+cos(tret), 15*sin(i)+sin(tret), 0.0);

glEnd();
//////////////
prv+=cekor;
vtor+=cekor;
tret+=cekor;
glBegin(GL_TRIANGLES);

glVertex3f (15*cos(i)+cos(prv), 15*sin(i)+sin(prv), 0.0);
glVertex3f (15*cos(i)+3*cos(vtor), 15*sin(i)+3*sin(vtor), 0.0);
glVertex3f (15*cos(i)+cos(tret), 15*sin(i)+sin(tret), 0.0);

glEnd();
//////////////
prv+=cekor;
vtor+=cekor;
tret+=cekor;
glBegin(GL_TRIANGLES);

glVertex3f (15*cos(i)+cos(prv), 15*sin(i)+sin(prv), 0.0);
glVertex3f (15*cos(i)+3*cos(vtor), 15*sin(i)+3*sin(vtor), 0.0);
glVertex3f (15*cos(i)+cos(tret), 15*sin(i)+sin(tret), 0.0);

glEnd();
//////////////
prv+=cekor;
vtor+=cekor;
tret+=cekor;
glBegin(GL_TRIANGLES);

glVertex3f (15*cos(i)+cos(prv), 15*sin(i)+sin(prv), 0.0);
glVertex3f (15*cos(i)+3*cos(vtor), 15*sin(i)+3*sin(vtor), 0.0);
glVertex3f (15*cos(i)+cos(tret), 15*sin(i)+sin(tret), 0.0);

glEnd();
//////////////
}
}

void kutlesh(void)
{

   glColor3f (1.0, 1.0, 0.0);
 float pi=3.14;
float i;

float ag=0.0;
	glBegin(GL_POLYGON);
	glNormal3f(0,0,-1);
	while(ag<2*pi)
	{
		glVertex3f (2*cos(ag), 2*sin(ag), 0.0);
		ag+=0.01;
	}
	glEnd();


for(i=0.0;i<2*pi;i+=0.3926*2)
{
float ag=i+pi/2;
	glBegin(GL_POLYGON);
	glNormal3f(0,0,-1);
	while(ag<pi+pi/2+i)
	{
		glVertex3f (4*cos(i)+0.7*cos(ag), 4*sin(i)+0.7*sin(ag), 0.0);
		ag+=0.01;
	}
	glVertex3f (12*cos(i), 12*sin(i), 0.0);
	glEnd();
}

for(i=0.3926;i<2*pi;i+=0.3926*2)
{
float ag=i+pi/2;
	glBegin(GL_POLYGON);
	glNormal3f(0,0,-1);
	while(ag<pi+pi/2+i)
	{
		glVertex3f (5*cos(i)+0.5*cos(ag), 5*sin(i)+0.5*sin(ag), 0.0);
		ag+=0.01;
	}
	glVertex3f (12*cos(i), 12*sin(i), 0.0);
	glEnd();
}
}

void znaminja(void)
{
	float mat_ambient []={0.1f, 	0.1f, 	0.1f,   0};
	   float mat_diffuse []={0.2f, 	0.2f, 	0.2f,  0};
	   float mat_specular[]={0.3f, 	0.3f, 	0.3f, 0};
	   float mat_shininess = 0.2;
	   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	   glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	   glFrontFace(GL_CW);

	glPushMatrix();
	glTranslatef(3,17,20);
	glColor3f (0.1, 0.1, 1);
			glBegin(GL_POLYGON);
			glNormal3f(0,0,-1);
			glVertex3f (-1, -2,0.01);
			glVertex3f (1,-2,0.01);
			glVertex3f (1,2,0.01);
			glVertex3f (-1,2,0.01);
			glEnd();
	glScalef(0.025,0.025,0.025);
	eu();
	glScalef(40,40,40);
	glTranslatef(-3,-17,-20);
	glPopMatrix();
///////////////////////////////////////////////////////////////////

glPushMatrix();
	glTranslatef(-3,17,20);
	glColor3f (1, 0.1, 0.1);
			glBegin(GL_POLYGON);
			glNormal3f(0,0,-1);
			glVertex3f (-1, -2,0.01);
			glVertex3f (1,-2,0.01);
			glVertex3f (1,2,0.01);
			glVertex3f (-1,2,0.01);
			glEnd();
	glScalef(0.05,0.05,0.05);
	kutlesh();
	glScalef(20,20,20);
	glTranslatef(3,-17,-20);
	glPopMatrix();
}

void semafor(void)
{

	 glFrontFace(GL_CW);

	glPushMatrix();
	glTranslatef(-4,17,-25);
	
glBindTexture(GL_TEXTURE_2D, semaforce);
glMatrixMode(GL_TEXTURE);
int i;
int j;
			glBegin(GL_POLYGON);
			glNormal3f(0,0,-1);



 				glTexCoord2f(0,0); glVertex3f(0,0,0);
				 glTexCoord2f(1,0); glVertex3f(8,0,0);
				 glTexCoord2f(1,1); glVertex3f(8,8,0);
				 glTexCoord2f(0,1); glVertex3f(0,8,0);

			glEnd();
glMatrixMode(GL_MODELVIEW);
   glBindTexture(GL_TEXTURE_2D, 0);
	glTranslatef(4,-17,25);
	glPopMatrix();
}

void reklama(int oboen)
{
int i;
int j;
	
if(oboen==1)
{			
glBindTexture(GL_TEXTURE_2D, reklam);
glMatrixMode(GL_TEXTURE);
glFrontFace(GL_CW);
////////////
glBegin(GL_POLYGON);
			glNormal3f(0,0,-1);
				 glTexCoord2f(0,0); glVertex3f(0,0,0);
				 glTexCoord2f(1,0); glVertex3f(40,0,0);
				 glTexCoord2f(1,1); glVertex3f(40,2,0);
				 glTexCoord2f(0,1); glVertex3f(0,2,0);

			glEnd();
glMatrixMode(GL_MODELVIEW);
   glBindTexture(GL_TEXTURE_2D, 0);
}
else
{	glColor4f(0,0,0,0.7);
	glFrontFace(GL_CW);
		glBegin(GL_POLYGON);
			glNormal3f(0,0,-1);
				 glTexCoord2f(0,0); glVertex3f(0,0,0);
				 glTexCoord2f(1,0); glVertex3f(40,0,0);
				 glTexCoord2f(1,1); glVertex3f(40,2,0);
				 glTexCoord2f(0,1); glVertex3f(0,2,0);

			glEnd();
}

	
}

void reflektor(void)
{
	float mat_ambient []={0.1f, 	0.1f, 	0.1f,   0};
	   float mat_diffuse []={0.2f, 	0.2f, 	0.2f,  0};
	   float mat_specular[]={0.3f, 	0.3f, 	0.3f, 0};
	   float mat_shininess = 0.2;
	   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	   glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	   glFrontFace(GL_CCW);
	
	glColor3f(0.5,0.5,1);
	glBegin(GL_QUADS);
	  glNormal3f(0,1,0);
 	  glVertex3f(-0.5, 15, -0.5);
	  glVertex3f(0.5, 15, -0.5);
	  glVertex3f(0.5, 15, 0.5);
	  glVertex3f(-0.5, 15, 0.5);
   	  glEnd();

	
	glBegin(GL_QUADS);
	  glNormal3f(0,1,0);
 	  glVertex3f(-0.5, 16, -0.5);
	  glVertex3f(0.5, 16, -0.5);
	  glVertex3f(0.5, 16, 0.5);
	  glVertex3f(-0.5, 16, 0.5);
   	  glEnd();
	
	//glColor3f(1,0.5,0.5);
	glBegin(GL_QUADS);
	  glNormal3f(1,0,0);
 	  glVertex3f(-0.5, 15, 0.5);
	  glVertex3f(0.5, 15, 0.5);
	  glVertex3f(0.5, 16, 0.5);
	  glVertex3f(-0.5, 16, 0.5);
   	  glEnd();

	//glColor3f(1,0.5,0.5);
	glBegin(GL_QUADS);
	  glNormal3f(1,0,0);
 	  glVertex3f(-0.5, 15, -0.5);
	  glVertex3f(0.5, 15, -0.5);
	  glVertex3f(0.5, 16, -0.5);
	  glVertex3f(-0.5, 16, -0.5);
   	  glEnd();

	//glColor3f(1,0.5,0.5);
	glBegin(GL_QUADS);
	  glNormal3f(0,0,1);
 	  glVertex3f(-0.5, 15, -0.5);
	  glVertex3f(-0.5, 15, 0.5);
	  glVertex3f(-0.5, 16, 0.5);
	  glVertex3f(-0.5, 16, -0.5);
   	  glEnd();

	//glColor3f(1,0.5,0.5);
	glBegin(GL_QUADS);
	  glNormal3f(0,0,1);
 	  glVertex3f(0.5, 15, 0.5);
	  glVertex3f(0.5, 15, -0.5);
	  glVertex3f(0.5, 16, -0.5);
	  glVertex3f(0.5, 16, 0.5);
   	  glEnd();
}
