#ifndef OPENGLGRAPHICS_H
#define OPENGLGRAPHICS_H

#include <stdlib.h> 
#include <glut.h>
#include "IGraphics.h"
#include "GameEngineCore.h"

class GameEngineCore;
class OpenGLGraphics : public IGraphics
{
	public:
		OpenGLGraphics(GameEngineCore* engineCore);
		~OpenGLGraphics();

		void Initialise();
		void Update();
		void GenerateRenderLists(vector<Model3D> m);
		void RenderScene();
		void RenderTerrain(Terrain *t);
		void Reshape(int w, int h);

	private:
		GameEngineCore* mEngineCore;
		vector<Model3D> m_Models;
		GLuint m_DisplayLists;
};
#endif