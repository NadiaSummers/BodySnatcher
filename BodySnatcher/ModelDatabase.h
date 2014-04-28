#pragma once

#include <map>
#include <string>
#include "Model3D.h"

using namespace std;

class ModelDatabase
{
	private:
		map <string, Model3D> mModels;

	public:
		ModelDatabase(void);
		~ModelDatabase(void);

		map<string, Model3D> GetModels();
		bool AddModel(Model3D model, string id);
		bool RemoveModel(string id);
		bool ContainsModel(string id);
		bool Clear();
};

