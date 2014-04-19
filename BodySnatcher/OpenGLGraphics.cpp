#include <iostream>
#include "OpenGLGraphics.h"

using namespace std;

OpenGLGraphics::OpenGLGraphics()
{
}


OpenGLGraphics::~OpenGLGraphics()
{
}


void OpenGLGraphics::Initialise()
{
}


void OpenGLGraphics::Update()
{
}


void OpenGLGraphics::GenerateRenderLists(vector<ModelLoader> m)
{
	cout << "method called: OpenGLGraphics::GenerateRenderLists(vector<ModelLoader>* m)" << endl;

	if(!m.empty())
	{
	
		GLuint listName = glGenLists (1);
	
		glNewList (listName, GL_COMPILE);
			glColor3f (1.0, 0.0, 0.0);  /*  current color red  */
			glBegin (GL_TRIANGLES);
				for(int i=0; i<m.size(); i++) //for each model
				{
					for(int j=0; j<m[i].getFaces().size(); j++) //for each of the model's faces
					{
						glVertex3f (m[i].getVertices()[m[i].getFaces()[j].v1 - 1].x, m[i].getVertices()[m[i].getFaces()[j].v1 - 1].y, m[i].getVertices()[m[i].getFaces()[j].v1 - 1].z); //first vertex of the face
						glVertex3f (m[i].getVertices()[m[i].getFaces()[j].v2 - 1].x, m[i].getVertices()[m[i].getFaces()[j].v2 - 1].y, m[i].getVertices()[m[i].getFaces()[j].v2 - 1].z); //second vertex of the face
						glVertex3f (m[i].getVertices()[m[i].getFaces()[j].v3 - 1].x, m[i].getVertices()[m[i].getFaces()[j].v3 - 1].y, m[i].getVertices()[m[i].getFaces()[j].v3 - 1].z); //third vertex of the face
					}
				}
			glEnd ();
			//glTranslatef (1.5, 0.0, 0.0); /*  move position  */
		glEndList ();
	}
}


void OpenGLGraphics::RenderScene()
{
}


void OpenGLGraphics::RenderTerrain(Terrain *t)
{
	cout << "method called: OpenGLGraphics::RenderTerrain(Terrain *t)" << endl;
	
	unsigned char heightColor;
	float texLeft, texBottom, texTop;

	for (int z = 0; z < t->getSize() -1; z++)
	{
		glBegin(GL_TRIANGLE_STRIP);
			for (int x = 0; x < t->getSize(); x++)
			{
				texLeft = (float)x / t->getSize();
				texBottom = (float)z / t->getSize();
				texTop = (float)(z + 1) / t->getSize();


				heightColor = t->getHeightColor(x, z);
				glColor3ub(heightColor, heightColor, heightColor);
				glTexCoord2f(texLeft, texBottom);
				glVertex3f((float)x * t->GetScaleX(), t->getHeight(x, z), (float)z * t->GetScaleZ());
				
				heightColor = t->getHeightColor(x, z + 1);
				glColor3ub(heightColor, heightColor, heightColor);
				glTexCoord2f(texLeft, texTop);
				glVertex3f((float)x * t->GetScaleX(), t->getHeight(x, z + 1), (float)(z + 1) * t->GetScaleZ());
			}
		glEnd();
	}
}