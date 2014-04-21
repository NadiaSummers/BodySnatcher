

#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include <time.h>
#include <SOIL.h>
#include <lua.hpp>
#include "Terrain.h"

using namespace std;

Terrain newTerrain;
GLuint textures[10];
int texCount = 0;


void display(void)
{
glClearColor(0.0f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluPerspective(40, 1, 0, 10000);

	gluLookAt(512, 1024, -256, 768, 512, 256, 0, 1, 0);
	//gluLookAt(128, 300, -192, 256, 256, 256, 0, 1, 0);
	//gluLookAt(500, 200, 0, 500, 0, 500, 0, 1, 0);


	newTerrain.render();

	/*
	glBegin(GL_QUADS);
		glTexCoord2f (0.0, 0.0);		glVertex3f (0.0, 0.0, 0.0);
		glTexCoord2f (1.0, 0.0);		glVertex3f (1000.0, 0.0, 0.0);
		glTexCoord2f (1.0, 1.0);		glVertex3f (1000.0, 0, 1000.0);
		glTexCoord2f (0.0, 1.0);		glVertex3f (0.0, 0, 1000.0);
	glEnd();*/

	glFlush();
	glutSwapBuffers();
}


void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}


void input(unsigned char key, int x, int y)
{
}

//*NS temp
void loadTexture(char* filename)
{
	GLuint texture = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	glBindTexture(GL_TEXTURE_2D, texture);
	textures[texCount] = texture;
	texCount++;
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 640);
    glutCreateWindow("Body Snatcher");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(input);

	glEnable(GL_TEXTURE_2D);                     
    glShadeModel(GL_SMOOTH);               
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);            
    glClearDepth(1.0f);                   
    glEnable(GL_DEPTH_TEST);                   
    glDepthFunc(GL_LEQUAL);                   
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);


	//do stuffs!

	loadTexture("textures/ground.png");
	loadTexture("textures/cobble.png");
	loadTexture("textures/dirt.png");
	

	newTerrain.setScalingFactor(16, 2, 16);
	//base texture, heightmap file, heightmap file width
	newTerrain.generateTerrain(&textures[2], "textures/terrainheightmap.raw", 512);
	//texture, texturemap
	//first is bottom layer, stacks on top
	newTerrain.addMapLayer(&textures[0], "textures/tex-dirt512.raw");
	newTerrain.addMapLayer(&textures[1], "textures/tex-cobble512.raw");


    glutMainLoop();

	return 0;
}
