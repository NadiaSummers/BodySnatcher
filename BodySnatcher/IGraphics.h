#ifndef IGRAPHICS_H
#define IGRAPHICS_H

#include "ModelLoader.h"
#include "Terrain.h"

class IGraphics
{
	public:
		virtual void Initialise() = 0;
		virtual void Update() = 0;
		virtual void GenerateRenderLists(vector<ModelLoader> m) = 0;
		virtual void RenderScene() = 0;
		virtual void RenderTerrain(Terrain *t) = 0;			
};
#endif
