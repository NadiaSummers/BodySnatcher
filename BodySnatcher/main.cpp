

#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include <time.h>
#include <SOIL.h>
#include <vector>
#include <lua.hpp>
#include <luabind/luabind.hpp>
extern "C"
{
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}

#include "Terrain.h"
#include "TextureManager.h"

using namespace std;


Terrain newTerrain;
TextureManager texManager;

void display(void)
{
glClearColor(0.0f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluPerspective(40, 1, 0, 10000);

	gluLookAt(512, 1024, -256, 768, 512, 256, 0, 1, 0);
	//gluLookAt(128, 300, -192, 256, 256, 256, 0, 1, 0);
	//gluLookAt(500, 200, 0, 500, 0, 500, 0, 1, 0);

	//glBindTexture(GL_TEXTURE_2D, texManager.getTextureID(grass));
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


	lua_State *myLuaState = luaL_newstate();
	luabind::open(myLuaState);

	luabind::module(myLuaState)
	[
		luabind::class_<Terrain>("Terrain")
		.def(luabind::constructor<>())
		.def("setScalingFactor", &Terrain::setScalingFactor)
		.def("generateTerrain", (void(Terrain::*)(GLuint, const char *, int)) &Terrain::generateTerrain) //because char * lol.
		.def("addMapLayer", (void(Terrain::*)(GLuint, const char *))&Terrain::addMapLayer)				//requires explicit declaration
	];

	luabind::module(myLuaState)
	[
		luabind::class_<TextureManager>("TextureManager")
		.def(luabind::constructor<>())
		.def("loadTexture", (void(TextureManager::*)(int, const char *))&TextureManager::loadTexture)
		.def("getTexture", &TextureManager::getTexture)
	];

	luaL_dofile(myLuaState, "lua/levelone.lua");

	lua_close(myLuaState);
	/*
	texManager.loadTexture(0, "textures/ground.png");
	texManager.loadTexture(1, "textures/dirt.png");
	texManager.loadTexture(2, "textures/cobble.png");
	
	newTerrain.setScalingFactor(16, 2, 16);
	newTerrain.generateTerrain(texManager.getTexture(0), "textures/terrainheightmap.raw", 512);
	newTerrain.addMapLayer(texManager.getTexture(1), "textures/tex-dirt512.raw");
	newTerrain.addMapLayer(texManager.getTexture(2), "textures/tex-cobble512.raw");
	*/

    glutMainLoop();

	
	return 0;
}
