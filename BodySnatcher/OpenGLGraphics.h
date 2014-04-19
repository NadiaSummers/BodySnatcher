#pragma once

#include <glut.h>
#include "IGraphics.h"

class OpenGLGraphics : public IGraphics
{
	public:
		OpenGLGraphics();
		~OpenGLGraphics();

		void Initialise();
		void Update();
		void GenerateRenderLists(vector<ModelLoader> m);
		void RenderScene();
		void RenderTerrain(Terrain *t);

	private:
		vector<ModelLoader> models;
};

