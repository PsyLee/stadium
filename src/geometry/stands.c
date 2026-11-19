#include "geometry.h"
#include "../renderer.h"
#include <math.h>

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
