#include "OpenGLGraphics.h"

OpenGLGraphics::OpenGLGraphics(GameEngineCore* engineCore):mEngineCore(engineCore)
{
	m_DisplayLists = glGenLists (m_Models.size());
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


void OpenGLGraphics::GenerateRenderLists(vector<Model3D> m)
{
	cout << "method called: OpenGLGraphics::GenerateRenderLists(vector<Model3D>* m)" << endl;

	if(!m.empty())
	{
		for(unsigned int i=0; i<m.size(); i++) //for each model
		{
			glNewList (i, GL_COMPILE);
				glBegin (GL_TRIANGLES);
					for(unsigned int j=0; j<m[i].getFaces().size(); j++) //for each of the model's faces
					{
						glNormal3f(m[i].getNormals()[m[i].getFaces()[i].vn1 - 1].x, m[i].getNormals()[m[i].getFaces()[i].vn1 - 1].y, m[i].getNormals()[m[i].getFaces()[i].vn1 - 1].z); //set normals for vertex 1
						glTexCoord3f(m[i].getTexels()[m[i].getFaces()[i].vt1 - 1].x, m[i].getTexels()[m[i].getFaces()[i].vt1 - 1].y*-1, m[i].getTexels()[m[i].getFaces()[i].vt1 - 1].z); //set texture coordinates for vertex 1
						glVertex3f (m[i].getVertices()[m[i].getFaces()[j].v1 - 1].x, m[i].getVertices()[m[i].getFaces()[j].v1 - 1].y, m[i].getVertices()[m[i].getFaces()[j].v1 - 1].z); //first vertex of the face
						
						glNormal3f(m[i].getNormals()[m[i].getFaces()[i].vn2 - 1].x, m[i].getNormals()[m[i].getFaces()[i].vn2 - 1].y, m[i].getNormals()[m[i].getFaces()[i].vn2 - 1].z); //set normals for vertex 2
						glTexCoord3f(m[i].getTexels()[m[i].getFaces()[i].vt2 - 1].x, m[i].getTexels()[m[i].getFaces()[i].vt2 - 1].y*-1, m[i].getTexels()[m[i].getFaces()[i].vt2 - 1].z); //set texture coordinates for vertex 2
						glVertex3f (m[i].getVertices()[m[i].getFaces()[j].v2 - 1].x, m[i].getVertices()[m[i].getFaces()[j].v2 - 1].y, m[i].getVertices()[m[i].getFaces()[j].v2 - 1].z); //second vertex of the face
						
						glNormal3f(m[i].getNormals()[m[i].getFaces()[i].vn3 - 1].x, m[i].getNormals()[m[i].getFaces()[i].vn3 - 1].y, m[i].getNormals()[m[i].getFaces()[i].vn3 - 1].z); //set normals for vertex 3
						glTexCoord3f(m[i].getTexels()[m[i].getFaces()[i].vt3 - 1].x, m[i].getTexels()[m[i].getFaces()[i].vt3 - 1].y*-1, m[i].getTexels()[m[i].getFaces()[i].vt3 - 1].z); //set texture coordinates for vertex 3
						glVertex3f (m[i].getVertices()[m[i].getFaces()[j].v3 - 1].x, m[i].getVertices()[m[i].getFaces()[j].v3 - 1].y, m[i].getVertices()[m[i].getFaces()[j].v3 - 1].z); //third vertex of the face
					}
				glEnd ();
				//glTranslatef (1.5, 0.0, 0.0); /*  move position  */
			glEndList ();
		}
	}
}


void OpenGLGraphics::RenderScene()
{
}

//*NS check draw order of layers
void OpenGLGraphics::RenderTerrain(Terrain *t)
{

	//unsigned char heightColor;
	float texLeft, texBottom, texTop;

	glColor4f(1.0, 1.0, 1.0, 1);

	//need to render each terrain layer - 0 should be base and is treated differently
	for (int i = 0; i < t->getNumLayers(); i++)
	{
		glBindTexture(GL_TEXTURE_2D, mEngineCore->GetTextureManager().getTexture(t->getTextureName(i)));

		for (int z = 0; z < t->getSize() -1; z++)
		{
			
			glBegin(GL_TRIANGLE_STRIP);
				for (int x = 0; x < t->getSize(); x++)
				{
					
						//dont render mapLayers triangles with an alpha of 0 - invisible anyways!
						if (i > 0 && t->getTextureMapHeight(x, z , i) == 0)
						{
							break;
						}

						

						texLeft = (float)x / t->getSize() * t->getTextureScale();
						texBottom = (float)z / t->getSize() * t->getTextureScale();
						texTop = (float)(z + 1) / t->getSize() * t->getTextureScale();

						//only want to set this for subsequent layers (alpha)
						if (i > 0)
							glColor4f(1.0, 1.0, 1.0, t->getTextureMapHeight(x, z, i));
					
						
						//heightColor = t->getHeightColor(x, z);
						//glColor3ub(heightColor, heightColor, heightColor);
						glTexCoord2f(texLeft, texBottom);
						glVertex3f((float)x * t->GetScaleX(), t->getHeight(x, z), (float)z * t->GetScaleZ());


						//heightColor = t->getHeightColor(x, z + 1);
						//glColor3ub(heightColor, heightColor, heightColor);
						glTexCoord2f(texLeft, texTop);
						glVertex3f((float)x * t->GetScaleX(), t->getHeight(x, z + 1), (float)(z + 1) * t->GetScaleZ());
					
				}
		glEnd();
		}
	}
}


void OpenGLGraphics::Reshape(int w, int h)
{

}