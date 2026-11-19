#include "geometry.h"
#include "../renderer.h"
#include <math.h>

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
