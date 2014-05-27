#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include <time.h>

#include "GameEngineCore.h"

using namespace std;

void Init(int argc, char **argv);
void SpecialKey(int key, int x, int y);
void SpecialKeyUp(int key, int x, int y);
void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void MouseMotion(int x, int y);
void Display();
void Reshape(int w, int h);


int main(int argc, char **argv)
{
	Init(argc, argv);
	return 0;
}


void Init(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("BodySnatcher");

	//set glut events:
	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(SpecialKey);
	glutSpecialUpFunc(SpecialKeyUp);
	glutKeyboardUpFunc(KeyboardUp);
	glutKeyboardFunc(Keyboard);
	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMotion);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}


void SpecialKey(int key, int x, int y)
{
	GameEngineCore::GetInstance()->GetIOSystem().SpecialKey(key, x, y);
}


void SpecialKeyUp(int key, int x, int y)
{
	GameEngineCore::GetInstance()->GetIOSystem().SpecialKeyUp(key, x, y);
}


void Keyboard(unsigned char key, int x, int y)
{
	GameEngineCore::GetInstance()->GetIOSystem().Keyboard(key, x, y);
}


void KeyboardUp(unsigned char key, int x, int y)
{
	GameEngineCore::GetInstance()->GetIOSystem().KeyboardUp(key, x, y);
}


void Mouse(int button, int state, int x, int y)
{
	GameEngineCore::GetInstance()->GetIOSystem().Mouse(button, state, x, y);
}


void MouseMotion(int x, int y)
{
	GameEngineCore::GetInstance()->GetIOSystem().MouseMove(x, y);
}


void Display()
{
	GameEngineCore::GetInstance()->Update();
	GameEngineCore::GetInstance()->Draw();
}


void Reshape(int w, int h)
{
	GameEngineCore::GetInstance()->GetGraphicsEngine().Reshape(w, h);
}

//Terrain newTerrain;
//GLuint textures[10];
//int texCount = 0;
//
//
//void display(void)
//{
//glClearColor(0.0f, 0.1f, 0.1f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//
//	gluPerspective(40, 1, 0, 10000);
//
//	gluLookAt(512, 1024, -256, 768, 512, 256, 0, 1, 0);
//	//gluLookAt(128, 300, -192, 256, 256, 256, 0, 1, 0);
//	//gluLookAt(500, 200, 0, 500, 0, 500, 0, 1, 0);
//
//
//	newTerrain.render();
//
//	/*
//	glBegin(GL_QUADS);
//		glTexCoord2f (0.0, 0.0);		glVertex3f (0.0, 0.0, 0.0);
//		glTexCoord2f (1.0, 0.0);		glVertex3f (1000.0, 0.0, 0.0);
//		glTexCoord2f (1.0, 1.0);		glVertex3f (1000.0, 0, 1000.0);
//		glTexCoord2f (0.0, 1.0);		glVertex3f (0.0, 0, 1000.0);
//	glEnd();*/
//
//	glFlush();
//	glutSwapBuffers();
//}
//
//
//void myReshape(int w, int h)
//{
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    if (w <= h)
//        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
//            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
//    else
//        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
//            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//
//void input(unsigned char key, int x, int y)
//{
//}
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 640);
//    glutCreateWindow("Body Snatcher");
//    glutReshapeFunc(myReshape);
//    glutDisplayFunc(display);
//	glutIdleFunc(display);
//	glutKeyboardFunc(input);
//
//	glEnable(GL_TEXTURE_2D);                     
//    glShadeModel(GL_SMOOTH);               
//    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);            
//    glClearDepth(1.0f);                   
//    glEnable(GL_DEPTH_TEST);                   
//    glDepthFunc(GL_LEQUAL);                   
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glEnable(GL_BLEND);
//
//
//	//do stuffs!
//
//	loadTexture("textures/ground.png");
//	loadTexture("textures/cobble.png");
//	loadTexture("textures/dirt.png");
//	
//
//	newTerrain.setScalingFactor(16, 2, 16);
//	//base texture, heightmap file, heightmap file width
//	newTerrain.generateTerrain(&textures[2], "textures/terrainheightmap.raw", 512);
//	//texture, texturemap
//	//first is bottom layer, stacks on top
//	newTerrain.addMapLayer(&textures[0], "textures/tex-dirt512.raw");
//	newTerrain.addMapLayer(&textures[1], "textures/tex-cobble512.raw");
//
//
//    glutMainLoop();
//
//	return 0;
//}