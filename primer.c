#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>  
#include "utils.c"

float Y=70;
float Yce=70;
float rotateA=0;
float rotateAspeed=0.0f;
int polygonMode=GL_FILL;
float sv=50.0;
float svR=3.14;
float Ra=20;
float idl=0.0;

static GLuint texName2;
static GLuint parket;
static GLuint semaforce;
static GLuint reklam;
static GLuint stativi;
static GLuint precki;
static GLuint wood;
static GLuint metal;



// Reduces a normal vector specified as a set of three coordinates,
// to a unit normal vector of length 1.
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

// Points p1, p2, & p3 specified in counterclockwise order
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

// Creates a shadow projection matrix out of the plane equation
// coefficients and the position of the light. The return value is stored
// in destMat[][]
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

void logErrorMessages(void) {
   GLenum glError;
   int i = 0;
   do {
     glError = glGetError();
	 if (glError!=GL_NO_ERROR) printf("%s \n", gluErrorString(glError));
     i++;
	 }
   while(i<6 && glError != GL_NO_ERROR);
}

void display(void)
{
   glPolygonMode(GL_FRONT_AND_BACK,polygonMode);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DOT3_RGBA);

	
   //Mestenje pogled
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(Yce*cos(rotateA),Y,Yce*sin(rotateA),0,0,0,0,1,0);
  


   // repozicioniranje na svetloto
	GLfloat svetlo0_position[]= {Ra*sin(svR),sv,Ra*cos(svR),1};
	glLightfv(GL_LIGHT0,GL_POSITION,svetlo0_position);
	GLfloat spotdir[]= {-Ra*sin(svR),-sv,-Ra*cos(svR)};
	glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spotdir);


	glPushMatrix();
		krug();
		znaminja();
		semafor();
	glTranslatef(1,0,12);
		stol(1);
	glTranslatef(-2.5,0,0);
		stol(1);
	glTranslatef(2.5,0,0);
	glTranslatef(-1,0,-12);
	glTranslatef(0,0,12);
	glScalef(0.5,0.5,0.5);
	glTranslatef(-25,0,2);
	glScalef(1,0.5,1);
		klupa(1);
	glScalef(1,2,1);
	glTranslatef(25,0,-4);
	glScalef(0.5,1,1);	
		klupa(1);
	glScalef(2,1,1);
	glTranslatef(25,0,4);
	glScalef(1,0.5,1);
		klupa(1);
	glScalef(1,2,1);
	glTranslatef(-25,0,-2);
	glScalef(2,2,2);
	glTranslatef(0,0,-12);
	//reflektor();
	glTranslatef(-20,0,-11);
	glRotatef(-35,1,0,0);
		reklama(1);
	glRotatef(35,1,0,0);
	glTranslatef(20,0,11);
		teren();
		linii();
	glRotatef(90,0,1,0);
	glTranslatef(1.5,0,20);
		gol(1);	
	glTranslatef(0,0,-39.9);
	glRotatef(180,0,1,0);
	glTranslatef(3,0,0);
		gol(1);
	glTranslatef(-3,0,0);	
	glRotatef(180,0,1,0);
	glTranslatef(0,0,39.9);
	glTranslatef(-1.5,0,-20);
	glRotatef(3*90,0,1,0);
	glTranslatef(-10,-0.01,-5);
		pod();
	glTranslatef(10,0.01,5);
		site_krivini();
		tribina();
	glRotatef(180,0,1,0);
		tribina();
	glRotatef(90,0,1,0);
	glTranslatef(0,0,10.02);
	glScalef(0.55,1,1);
		tribina();
	glTranslatef(0,0,-20.05);
	glRotatef(180,0,1,0);
		tribina();
	glPopMatrix();

glPushAttrib(GL_LIGHTING_BIT);
     glDisable(GL_LIGHTING);
     glDisable(GL_TEXTURE_2D);
     glPushMatrix();

       GLfloat shadowMat[4][4];

       // senkata ja vrzuvame za ramnina niz 3 tochki od ramninata na senkata
       GLfloat points[3][3] = { { 20,0.02,-20 },
                                { -20,0.02,-20 },
                                { -20,0.02,20 } };

       MakeShadowMatrix(points, svetlo0_position, shadowMat);
       glMultMatrixf((GLfloat *)shadowMat);

glTranslatef(1,0,12);
/*
	
 ЈАС И ФИЧО СМЕ НАЈБОЉИ! САМО ЗА У НАСА СМЕ!
		
		znaminja();
		semafor();
	
*/
		stol(0);

	glTranslatef(-2.5,0,0);
		stol(0);
	glTranslatef(2.5,0,0);
	glTranslatef(-1,0,-12);
	glTranslatef(0,0,12);
	glScalef(0.5,0.5,0.5);
	glTranslatef(-25,0,2);
	glScalef(1,0.5,1);
		klupa(0);
	glScalef(1,2,1);
	glTranslatef(25,0,-4);
	glScalef(0.5,1,1);	
		klupa(0);
	glScalef(2,1,1);
	glTranslatef(25,0,4);
	glScalef(1,0.5,1);
		klupa(0);
	glScalef(1,2,1);
	glTranslatef(-25,0,-2);
	glScalef(2,2,2);
	glTranslatef(0,0,-12);
	//reflektor();
	glTranslatef(-20,0,-11);
	glRotatef(-35,1,0,0);
		reklama(0);
	glRotatef(35,1,0,0);
	glTranslatef(20,0,11);
	glRotatef(90,0,1,0);
	glTranslatef(1.5,0,20);
		gol(0);	
	glTranslatef(0,0,-39.9);
	glRotatef(180,0,1,0);
	glTranslatef(3,0,0);
		gol(0);
	glTranslatef(-3,0,0);	
	glRotatef(180,0,1,0);
	glTranslatef(0,0,39.9);
	glTranslatef(-1.5,0,-20);
	glRotatef(3*90,0,1,0);
	glTranslatef(-10,-0.01,-5);
	glTranslatef(10,0.01,5);
//		site_krivini();
//		tribina();
	glRotatef(180,0,1,0);
//		tribina();
	glRotatef(90,0,1,0);
	glTranslatef(0,0,10.02);
	glScalef(0.55,1,1);
//		tribina();
	glTranslatef(0,0,-20.05);
	glRotatef(180,0,1,0);
//		tribina();

	glPopMatrix();


glPopAttrib();
   glFlush();
   logErrorMessages();
   glutSwapBuffers();
 glDisable(GL_TEXTURE_2D);
}

void init (void) 
{ 
   glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-1, 1, -1, 1, 1, 1000);


  // glShadeModel(GL_SMOOTH);
   glEnable ( GL_DEPTH_TEST );
   glDepthFunc( GL_LEQUAL );
   glDepthMask( GL_TRUE );
   glDisable ( GL_CULL_FACE );
   glEnable(GL_LIGHTING);
   glEnable(GL_COLOR_MATERIAL);

   //prva tekstura - proceduralna
  // makeCheckImage();
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

/////////////////////////////////////////////////

Image *image1;

    image1 = (Image *) malloc(sizeof(Image));
    if (image1 == NULL) {
      	printf("Error allocating space for image");
	      exit(0);
     }

    if (!ImageLoad("teren.bmp", image1)) {
      	exit(1);
    }        

    glGenTextures(1, &texName2);
    glBindTexture(GL_TEXTURE_2D, texName2);   

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 
                0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
   
////////////////////////////////////////////////
Image *image2;

    image2 = (Image *) malloc(sizeof(Image));
    if (image2 == NULL) {
      	printf("Error allocating space for image");
	      exit(0);
     }

    if (!ImageLoad("parket.bmp", image2)) {
      	exit(1);
    }  
glGenTextures(1, &parket);
    glBindTexture(GL_TEXTURE_2D, parket);   

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 
                0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);
////////////////////////////////////////////////
Image *image3;

    image3 = (Image *) malloc(sizeof(Image));
    if (image3 == NULL) {
      	printf("Error allocating space for image");
	      exit(0);
     }

    if (!ImageLoad("semafor.bmp", image3)) {
      	exit(1);
    }        

    glGenTextures(1, &semaforce);
    glBindTexture(GL_TEXTURE_2D, semaforce);   

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image3->sizeX, image3->sizeY, 
                0, GL_RGB, GL_UNSIGNED_BYTE, image3->data);
   
/////////////////////////////////////////////////

Image *image4;

    image4 = (Image *) malloc(sizeof(Image));
    if (image4 == NULL) {
      	printf("Error allocating space for image");
	      exit(0);
     }

    if (!ImageLoad("reklama.bmp", image4)) {
      	exit(1);
    }        

    glGenTextures(1, &reklam);
    glBindTexture(GL_TEXTURE_2D, reklam);   

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image4->sizeX, image4->sizeY, 
                0, GL_RGB, GL_UNSIGNED_BYTE, image4->data);
////////////////////////////////////////////////

Image *image5;

    image5 = (Image *) malloc(sizeof(Image));
    if (image5 == NULL) {
      	printf("Error allocating space for image");
	      exit(0);
     }

    if (!ImageLoad("stativa.bmp", image5)) {
      	exit(1);
    }  
glGenTextures(1, &stativi);
    glBindTexture(GL_TEXTURE_2D, stativi);   

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image5->sizeX, image5->sizeY, 
                0, GL_RGB, GL_UNSIGNED_BYTE, image5->data);
////////////////////////////////////////////////

Image *image6;

    image6 = (Image *) malloc(sizeof(Image));
    if (image6 == NULL) {
      	printf("Error allocating space for image");
	      exit(0);
     }

    if (!ImageLoad("precka.bmp", image6)) {
      	exit(1);
    }  
glGenTextures(1, &precki);
    glBindTexture(GL_TEXTURE_2D, precki);   

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image6->sizeX, image6->sizeY, 
                0, GL_RGB, GL_UNSIGNED_BYTE, image6->data);
////////////////////////////////////////////////
Image *image7;

    image7 = (Image *) malloc(sizeof(Image));
    if (image7 == NULL) {
      	printf("Error allocating space for image");
	      exit(0);
     }

    if (!ImageLoad("wood.bmp", image7)) {
      	exit(1);
    }  
glGenTextures(1, &wood);
    glBindTexture(GL_TEXTURE_2D, wood);   

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image7->sizeX, image7->sizeY, 
                0, GL_RGB, GL_UNSIGNED_BYTE, image7->data);
////////////////////////////////////////////////
Image *image8;

    image8 = (Image *) malloc(sizeof(Image));
    if (image8 == NULL) {
      	printf("Error allocating space for image");
	      exit(0);
     }

    if (!ImageLoad("metal.bmp", image8)) {
      	exit(1);
    }  
glGenTextures(1, &metal);
    glBindTexture(GL_TEXTURE_2D, metal);   

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image8->sizeX, image8->sizeY, 
                0, GL_RGB, GL_UNSIGNED_BYTE, image8->data);
////////////////////////////////////////////////

   
   

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

glEnable(GL_BLEND);
   glBlendFunc( GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA  );

}


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

