#include "app.h"
#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

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
   
    ImageFree(image1);
    free(image1);
    image1 = NULL;
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
    ImageFree(image2);
    free(image2);
    image2 = NULL;
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
   
    ImageFree(image3);
    free(image3);
    image3 = NULL;
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
    ImageFree(image4);
    free(image4);
    image4 = NULL;
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
    ImageFree(image5);
    free(image5);
    image5 = NULL;
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
    ImageFree(image6);
    free(image6);
    image6 = NULL;
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
    ImageFree(image7);
    free(image7);
    image7 = NULL;
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
    ImageFree(image8);
    free(image8);
    image8 = NULL;
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
