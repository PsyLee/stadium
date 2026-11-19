#include "app.h"
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

void mreziste (void) {


glBindTexture(GL_TEXTURE_2D, texName2);
glMatrixMode(GL_TEXTURE);

   
      int i=0;
      int j=0;
	glBegin(GL_QUADS);
      for ( i=0; i<40; i++) 
      { 
        for ( j=0; j<20; j++)
        {
	
		
     		glNormal3f(0,1,0); 
			 glTexCoord2f(i/40.0,j/20.0); glVertex3f(i,0,j);
			 glTexCoord2f((i+1)/40.0,j/20.0); glVertex3f(i+1,0,j);
			 glTexCoord2f((i+1)/40.0,(j+1)/20.0); glVertex3f(i+1,0,j+1);
			 glTexCoord2f(i/40.0,(j+1)/20.0); glVertex3f(i,0,j+1);
		
	
        }
      }
glEnd();
glMatrixMode(GL_MODELVIEW);
   glBindTexture(GL_TEXTURE_2D, 0);
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

void pokriv(void)
{
	float mat_ambient []={0.1f, 	0.1f, 	0.1f,   0};
	   float mat_diffuse []={0.2f, 	0.2f, 	0.2f,  0};
	   float mat_specular[]={0.3f, 	0.3f, 	0.3f, 0};
	   float mat_shininess = 0.7;
	   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	   glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	   glFrontFace(GL_CW);
	
	glColor3f (0.1, 0.1, 0.1);
			glBegin(GL_POLYGON);
			glNormal3f(0,-1,0);
			glVertex3f (-40, 20, -40);
			glVertex3f (-40, 20, 40);
			glVertex3f (40, 20, 40);
			glVertex3f (40, 20, -40);
			glEnd();

			glBegin(GL_POLYGON);
			glNormal3f(0,1,0);
			glVertex3f (-40, -5, -40);
			glVertex3f (-40, -5, 40);
			glVertex3f (40, -5, 40);
			glVertex3f (40, -5, -40);
			glEnd();

			
			glBegin(GL_POLYGON);
			glNormal3f(-1,0,0);
			glVertex3f (-40, -5, -40);
			glVertex3f (40, -5, -40);
			glVertex3f (40, 20, -40);
			glVertex3f (-40, 20, -40);
			glEnd();
			
			glBegin(GL_POLYGON);
			glNormal3f(1,0,0);
			glVertex3f (-40, -5, 40);
			glVertex3f (40, -5, 40);
			glVertex3f (40, 20, 40);
			glVertex3f (-40, 20, 40);
			glEnd();

			glBegin(GL_POLYGON);
			glNormal3f(0,0,1);
			glVertex3f (-40, -5, -40);
			glVertex3f (-40, -5, 40);
			glVertex3f (-40, 20, 40);
			glVertex3f (-40, 20, -40);
			glEnd();
	
			glBegin(GL_POLYGON);
			glNormal3f(0,0,-1);
			glVertex3f (40, -5, -40);
			glVertex3f (40, -5, 40);
			glVertex3f (40, 20, 40);
			glVertex3f (40, 20, -40);
			glEnd();
}

void krug(void)
{
	float mat_ambient []={0.1f, 	0.1f, 	0.1f,   0};
	   float mat_diffuse []={0.2f, 	0.2f, 	0.2f,  0};
	   float mat_specular[]={0.3f, 	0.3f, 	0.3f, 0};
	   float mat_shininess = 0.7;
	   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	   glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	   glFrontFace(GL_CW);

	float pi=3.14;
	float ag=0.0;
			glColor3f (1, 1, 1);
			glBegin(GL_POLYGON);
			glNormal3f(0,1,0);
			for(ag=0.0;ag<2*pi;ag+=0.01)
			{
				glVertex3f (-30, 17, -30);
				glVertex3f (0, 17, 0);
				glVertex3f (0, 17, 0);
				glVertex3f (0, 17, 0);
			}
			glEnd();
	
}

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

void mrezha (void) {

glBindTexture(GL_TEXTURE_2D, parket);
glMatrixMode(GL_TEXTURE);


   glBegin(GL_QUADS);
      glNormal3f(0,1,0); 
      int i=0;
      int j=0;
      for ( i=0; i<40; i++) 
      { 
        for ( j=0; j<20; j++)
        {
          glTexCoord2f(i/40.0,j/20.0); glVertex3f(i,  0,j);
          glTexCoord2f((i+1)/40.0,j/20.0); glVertex3f(i+1,0,j);
          glTexCoord2f((i+1)/40.0,(j+1)/20.0); glVertex3f(i+1,0,j+1);
          glTexCoord2f(i/40.0,(j+1)/20.0); glVertex3f(i,  0,j+1);
        }
      }
   glEnd();
glMatrixMode(GL_MODELVIEW);
   glBindTexture(GL_TEXTURE_2D, 0);
}

void dolga_mreza(void)
{
	glBindTexture(GL_TEXTURE_2D, metal);
	glMatrixMode(GL_TEXTURE);

	glBegin(GL_QUADS);
      glNormal3f(0,1,0); 
      int i=0;
      int j=0;
      for ( i=0; i<44; i++) 
      { 
        for ( j=0; j<2; j++)
        {
          glTexCoord2f(i/44.0,j/2.0); glVertex3f(i,  0,j);
          glTexCoord2f((i+1)/44.0,j/2.0); glVertex3f(i+1,0,j);
          glTexCoord2f((i+1)/44.0,(j+1)/2.0); glVertex3f(i+1,0,j+1);
          glTexCoord2f(i/44.0,(j+1)/2.0); glVertex3f(i,  0,j+1);
        }
      }
   glEnd();
glMatrixMode(GL_MODELVIEW);
   glBindTexture(GL_TEXTURE_2D, 0);
}

void vertikalna_mreza(void)
{
	glBindTexture(GL_TEXTURE_2D, metal);
	glMatrixMode(GL_TEXTURE);
	glBegin(GL_QUADS);
      glNormal3f(0,0,1); 
      int i=0;
      int j=0;
      for ( i=0; i<44; i++) 
      { 
        for ( j=0; j<2; j++)
        {
          glTexCoord2f(i/44.0,j/2.0); glVertex3f(i, j,0);
          glTexCoord2f((i+1)/44.0,j/2.0); glVertex3f(i, j+1, 0);
          glTexCoord2f((i+1)/44.0,(j+1)/2.0); glVertex3f(i+1, j+1, 0);
          glTexCoord2f(i/44.0,(j+1)/2.0); glVertex3f(i+1, j, 0);
        }
      }
   glEnd();
glMatrixMode(GL_MODELVIEW);
   glBindTexture(GL_TEXTURE_2D, 0);
}

void krivina(void)
{
glBindTexture(GL_TEXTURE_2D, metal);
	
	   
	   glFrontFace(GL_CCW);
int daleku=0;
int blisku=2;
int vis=2;
	float ag=0.0;
glPushMatrix();
glTranslatef(22,0,12);
//glColor3f(0.1,0.1,0.1);

for(daleku=2,blisku=4;daleku<16;daleku+=2, blisku+=2, vis+=2)
{
	for(ag=0.0;ag<1.5707;ag+=0.1)
	{

glMatrixMode(GL_TEXTURE);
		glBegin(GL_POLYGON);
			glNormal3f(0,1,0); 
			glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis ,daleku*sin(ag));
			ag+=0.1;
			glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis, daleku*sin(ag));
			glTexCoord2f(blisku*cos(ag), blisku*sin(ag)); glVertex3f (blisku*cos(ag), vis, blisku*sin(ag));
			ag-=0.1;
			glTexCoord2f(blisku*cos(ag), blisku*sin(ag)); glVertex3f (blisku*cos(ag), vis, blisku*sin(ag));
		glEnd();
glMatrixMode(GL_MODELVIEW);
	}
}

 vis=0;

	for(daleku=2;daleku<16;daleku+=2, vis+=2)
	{
		for(ag=0.0;ag<1.5707;ag+=0.1)
		{
glMatrixMode(GL_TEXTURE);

			glBegin(GL_POLYGON);
				glNormal3f(-cos(ag+0.05),0,-sin(ag+0.05)); 
				glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis ,daleku*sin(ag));
				ag+=0.1;
				glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis, daleku*sin(ag));
				glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis+2, daleku*sin(ag));
				ag-=0.1;
				glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis+2, daleku*sin(ag));
			glEnd();
glMatrixMode(GL_MODELVIEW);
		}
	}

///////////////////////////////
//glColor3f(0.1,0.1,0.1);
glTranslatef(0,0,-24);
daleku=0;
blisku=2;
vis=2;
for(daleku=2,blisku=4;daleku<16;daleku+=2, blisku+=2, vis+=2)
{
	for(ag=3*1.5707;ag<4*1.5707;ag+=0.1)
	{
glMatrixMode(GL_TEXTURE);

		glBegin(GL_POLYGON);

			glNormal3f(0,1,0); 
			glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis ,daleku*sin(ag));
			ag+=0.1;
			glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis, daleku*sin(ag));
			glTexCoord2f(blisku*cos(ag), blisku*sin(ag)); glVertex3f (blisku*cos(ag), vis, blisku*sin(ag));
			ag-=0.1;
			glTexCoord2f(blisku*cos(ag), blisku*sin(ag)); glVertex3f (blisku*cos(ag), vis, blisku*sin(ag));

		glEnd();
glMatrixMode(GL_MODELVIEW);
	}
}
 vis=0;
	for(daleku=2;daleku<16;daleku+=2, vis+=2)
	{
		for(ag=3*1.5707;ag<4*1.5707;ag+=0.1)
		{
glMatrixMode(GL_TEXTURE);

			glBegin(GL_POLYGON);
				glNormal3f(-cos(ag+0.05),0,-sin(ag+0.05)); 
				glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis ,daleku*sin(ag));
				ag+=0.1;
				glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis, daleku*sin(ag));
				glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis+2, daleku*sin(ag));
				ag-=0.1;
				glTexCoord2f(daleku*cos(ag),daleku*sin(ag)); glVertex3f (daleku*cos(ag), vis+2, daleku*sin(ag));
			glEnd();
glMatrixMode(GL_MODELVIEW);
		}
	}

glPopMatrix();


   glBindTexture(GL_TEXTURE_2D, 0);
}

void site_krivini(void)
{

	glPushMatrix();
	
	//glColor3f(0.1,0.1,0.1);
	
		krivina();
		glRotatef(180,0,1,0);
		krivina();

	glPopMatrix();

	
}

void tribina(void)
{
	
	   glFrontFace(GL_CW);

int i=0;
		glPushMatrix();
		glTranslatef(-22,0,12);
		//glColor3f(0.1,0.1,0.1);
for(i=2;i<16;i+=2)
	{
		glPushMatrix();
		glTranslatef(0,i,i);
		dolga_mreza();
		glPopMatrix();
	}
	
		glTranslatef(0,0,2);	
		//glColor3f(0.1,0.1,0.1);
for(i=0;i<14;i+=2)
	{
		glPushMatrix();
		glTranslatef(0,i,i);
		vertikalna_mreza();
		glPopMatrix();
	}
	glPopMatrix();
}

void teren(void)
{

	   glFrontFace(GL_CW);



	//glColor3f(0.2,0.3,1);
        glPushMatrix();
        glTranslatef(-20,0,-10);
glTranslatef(0,0,20);
	glRotatef(180,0,0,1);
glRotatef(180,0,1,0);
        mreziste();
glRotatef(180,0,1,-20);
	glRotatef(180,0,0,1);
glTranslatef(0,0,0);
      glPopMatrix();
}

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

void linii(void)
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


	glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(-20,0.03,-10);

          glBegin(GL_QUADS);
          glNormal3f(0,1,0); 
          glVertex3f(40, 0, 0);
          glVertex3f(40, 0, 0.1);
          glVertex3f(0, 0, 0.1);
          glVertex3f(0, 0, 0);
   	  glEnd();

	glBegin(GL_QUADS);
          glNormal3f(0,1,0); 
          glVertex3f(40, 0, 19.9);
          glVertex3f(40, 0, 20);
          glVertex3f(0, 0, 20);
          glVertex3f(0, 0, 19.9);
   	  glEnd();

	glBegin(GL_QUADS);
          glNormal3f(0,1,0); 
          glVertex3f(0.1, 0, 0);
          glVertex3f(0.1, 0, 19.9);
          glVertex3f(0, 0, 19.9);
          glVertex3f(0, 0, 0);
   	  glEnd();
	
	glBegin(GL_QUADS);
          glNormal3f(0,1,0); 
          glVertex3f(40, 0, 0);
          glVertex3f(40, 0, 19.9);
          glVertex3f(39.9, 0, 19.9);
          glVertex3f(39.9, 0, 0);
   	  glEnd();

	glBegin(GL_QUADS);
          glNormal3f(0,1,0); 
          glVertex3f(20.05, 0, 0);
          glVertex3f(20.05, 0, 19.9);
          glVertex3f(19.95, 0, 19.9);
          glVertex3f(19.95, 0, 0);
   	  glEnd();



	glTranslatef(40,-0.01,11.5);

	///<<<<<<<<<<<<<<<<<<<<<<<<
	float ag=0.0;
	float pi=3.14;
	
		for(ag=pi/2;ag<pi;ag+=0.01)
		{

			glBegin(GL_POLYGON);
				glVertex3f (6.1*cos(ag), 0.0, 6.1*sin(ag));
				ag+=0.01;
				glVertex3f (6.1*cos(ag), 0.0, 6.1*sin(ag));
				glVertex3f (6*cos(ag), 0.0, 6*sin(ag));
				ag-=0.01;
				glVertex3f (6*cos(ag), 0.0, 6*sin(ag));
			glEnd();
		}

			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-6.1, 0, 0); 
			glVertex3f(-6.1, 0, -3);
			glVertex3f(-6, 0, -3);  
			glVertex3f(-6, 0, 0);
		   	glEnd();
	
			glColor3f(1,1,1);
			
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-9.1, 0, -0.2); 
			glVertex3f(-9.1, 0, -0.7);
			glVertex3f(-9, 0, -0.7);  
			glVertex3f(-9, 0, -0.2);
		   	glEnd();
			
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-9.1, 0, -1.2); 
			glVertex3f(-9.1, 0, -1.7);
			glVertex3f(-9, 0, -1.7);  
			glVertex3f(-9, 0, -1.2);
		   	glEnd();
		
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-9.1, 0, -2.2); 
			glVertex3f(-9.1, 0, -2.7);
			glVertex3f(-9, 0, -2.7);  
			glVertex3f(-9, 0, -2.2);
		   	glEnd();

			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-7.1, 0, -1); 
			glVertex3f(-7.1, 0, -2);
			glVertex3f(-7, 0, -2);  
			glVertex3f(-7, 0, -1);
		   	glEnd();

			
			glColor3f(1,1,1);

		glTranslatef(0,0,-3);
		for(ag=pi;ag<pi+pi/2;ag+=0.01)
		{

			glBegin(GL_POLYGON);
				glVertex3f (6.1*cos(ag), 0.0, 6.1*sin(ag));
				ag+=0.01;
				glVertex3f (6.1*cos(ag), 0.0, 6.1*sin(ag));
				glVertex3f (6*cos(ag), 0.0, 6*sin(ag));
				ag-=0.01;
				glVertex3f (6*cos(ag), 0.0, 6*sin(ag));
			glEnd();
		}
		glTranslatef(0,0,3);
//////////////////////////////////////////////////////////////////////////////////////

		float g=pi/2+0.02;
		ag=0.0;
		for(ag=pi/2+10*0.02;ag<pi;ag+=2*0.02, g+=4*0.02)
		{
			for(;ag<g;ag+=0.01)
			{
				glBegin(GL_POLYGON);
					glVertex3f (9.1*cos(ag), 0.0, 9.1*sin(ag));
					ag+=0.01;
					glVertex3f (9.1*cos(ag), 0.0, 9.1*sin(ag));
					glVertex3f (9*cos(ag), 0.0, 9*sin(ag));
					ag-=0.01;
					glVertex3f (9*cos(ag), 0.0, 9*sin(ag));
				glEnd();
			}
		}
		
         ///////////////////
		glTranslatef(0,0,-3);
		glRotatef(180,1,0,0);
		g=pi/2+0.02;
		ag=0.0;
		for(ag=pi/2+10*0.02;ag<pi;ag+=2*0.02, g+=4*0.02)
		{
			for(;ag<g;ag+=0.01)
			{
				glBegin(GL_POLYGON);
					glVertex3f (9.1*cos(ag), 0.0, 9.1*sin(ag));
					ag+=0.01;
					glVertex3f (9.1*cos(ag), 0.0, 9.1*sin(ag));
					glVertex3f (9*cos(ag), 0.0, 9*sin(ag));
					ag-=0.01;
					glVertex3f (9*cos(ag), 0.0, 9*sin(ag));
				glEnd();
			}
		}
		glRotatef(180,1,0,0);
		glTranslatef(0,0,3);
////////////////////////////////////////////////////////////////////////////////////////
		
		glTranslatef(0,0,-3);
		
/////>>>
glTranslatef(-40,0,0);
glRotatef(180,0,1,0);
	glColor3f(1,1,1);
		for(ag=pi/2;ag<pi;ag+=0.01)
		{

			glBegin(GL_POLYGON);
				glVertex3f (6.1*cos(ag), 0.0, 6.1*sin(ag));
				ag+=0.01;
				glVertex3f (6.1*cos(ag), 0.0, 6.1*sin(ag));
				glVertex3f (6*cos(ag), 0.0, 6*sin(ag));
				ag-=0.01;
				glVertex3f (6*cos(ag), 0.0, 6*sin(ag));
			glEnd();
		}
		
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-6.1, 0, 0); 
			glVertex3f(-6.1, 0, -3);
			glVertex3f(-6, 0, -3);  
			glVertex3f(-6, 0, 0);
		   	glEnd();
		
			glColor3f(1,1,1);
			
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-9.1, 0, -0.2); 
			glVertex3f(-9.1, 0, -0.7);
			glVertex3f(-9, 0, -0.7);  
			glVertex3f(-9, 0, -0.2);
		   	glEnd();
			
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-9.1, 0, -1.2); 
			glVertex3f(-9.1, 0, -1.7);
			glVertex3f(-9, 0, -1.7);  
			glVertex3f(-9, 0, -1.2);
		   	glEnd();
		
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-9.1, 0, -2.2); 
			glVertex3f(-9.1, 0, -2.7);
			glVertex3f(-9, 0, -2.7);  
			glVertex3f(-9, 0, -2.2);
		   	glEnd();

			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-7.1, 0, -1); 
			glVertex3f(-7.1, 0, -2);
			glVertex3f(-7, 0, -2);  
			glVertex3f(-7, 0, -1);
		   	glEnd();

			
			glColor3f(1,1,1);
		glTranslatef(0,0,-3);
		for(ag=pi;ag<pi+pi/2;ag+=0.01)
		{

			glBegin(GL_POLYGON);
				glVertex3f (6.1*cos(ag), 0.0, 6.1*sin(ag));
				ag+=0.01;
				glVertex3f (6.1*cos(ag), 0.0, 6.1*sin(ag));
				glVertex3f (6*cos(ag), 0.0, 6*sin(ag));
				ag-=0.01;
				glVertex3f (6*cos(ag), 0.0, 6*sin(ag));
			glEnd();
		}
		glTranslatef(0,0,3);



//////////////////////////////////////////////////////////////////////////////////////

		g=pi/2+0.02;
		ag=0.0;
		for(ag=pi/2+10*0.02;ag<pi;ag+=2*0.02, g+=4*0.02)
		{
			for(;ag<g;ag+=0.01)
			{
				glBegin(GL_POLYGON);
					glVertex3f (9.1*cos(ag), 0.0, 9.1*sin(ag));
					ag+=0.01;
					glVertex3f (9.1*cos(ag), 0.0, 9.1*sin(ag));
					glVertex3f (9*cos(ag), 0.0, 9*sin(ag));
					ag-=0.01;
					glVertex3f (9*cos(ag), 0.0, 9*sin(ag));
				glEnd();
			}
		}
		
         ///////////////////
		glTranslatef(0,0,-3);
		glRotatef(180,1,0,0);
		g=pi/2+0.02;
		ag=0.0;
		for(ag=pi/2+10*0.02;ag<pi;ag+=2*0.02, g+=4*0.02)
		{
			for(;ag<g;ag+=0.01)
			{
				glBegin(GL_POLYGON);
					glVertex3f (9.1*cos(ag), 0.0, 9.1*sin(ag));
					ag+=0.01;
					glVertex3f (9.1*cos(ag), 0.0, 9.1*sin(ag));
					glVertex3f (9*cos(ag), 0.0, 9*sin(ag));
					ag-=0.01;
					glVertex3f (9*cos(ag), 0.0, 9*sin(ag));
				glEnd();
			}
		}
		glRotatef(180,1,0,0);
		glTranslatef(0,0,3);
////////////////////////////////////////////////////////////////////////////////////////


		glTranslatef(0,0,-3);
		

      glPopMatrix();
}

void pod(void)
{
	   glFrontFace(GL_CW);
	//glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(-20,0,-10);
	glScalef(1.5,1,1.5);
        mrezha();
      glPopMatrix();
}
