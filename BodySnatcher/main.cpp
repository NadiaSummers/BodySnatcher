

#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include <time.h>
#include <SOIL.h>
#include <lua.hpp>
#include "Terrain.h"

using namespace std;

Terrain newTerrain;


void display(void)
{
	glClearColor(0.0f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluPerspective(40, 1, 0, 10000);

	gluLookAt(192, 300, -192, 192, 128, 0, 0, 1, 0);
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


//NS - would really rather have this in terrain class :(
int cpp_generateTerrain(lua_State* luaVM)
{
	int numParams = lua_gettop(luaVM);
	if (numParams !=3 || !lua_isstring(luaVM, 1) || !lua_isnumber(luaVM, 2) || !lua_isnumber(luaVM, 3))
	{
		cout << "Invalid Terrain Generation LUA." << endl;
		return 0;
	}
	char *filename = (char*) lua_tostring(luaVM, 1);
	const int newSize = (int) lua_tonumber(luaVM, 2);
	const double scale = (double) lua_tonumber(luaVM, 3);

	cout << scale << endl;
	newTerrain.setScalingFactor(1, scale, 1);
	newTerrain.generateTerrain(filename, newSize);
	return 1;
}

//NS - temp function for testing running lua files
void doLua()
{
	lua_State* luaState = lua_open();
	if (luaState == NULL)
	{
		cout << "Error initializing lua." << endl;
		system("pause");
	}

	lua_register(luaState, "cpp_generateTerrain", cpp_generateTerrain);

	luaL_openlibs(luaState);

	if (luaL_dofile(luaState, "lua\\terrain.lua"))
	{
		cout << "Can't open lua file!" << endl;
		system("pause");
	}
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


	//do stuffs!
	doLua();


    glutMainLoop();

	return 0;
}
