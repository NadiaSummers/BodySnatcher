#include "ModelDatabase.h"


ModelDatabase::ModelDatabase(void)
{
}


ModelDatabase::~ModelDatabase(void)
{
	Clear();
}


map<string, Model3D> ModelDatabase::GetModels()
{
	return mModels;
}


bool ModelDatabase::AddModel(Model3D model, string id)
{
	bool added;
	unsigned int size = mModels.size();
	Model3D temp;

	temp.Copy(model);

	mModels.insert(pair<string, Model3D>(id, temp));

	if(size > mModels.size())
		added = true;
	else
		added = false;

	return added;
}


bool ModelDatabase::RemoveModel(string id)
{
	bool removed;
	unsigned int size = mModels.size();

	mModels.erase(id);

	if(mModels.size() < size)
		removed = true;
	else
		removed = false;

	return removed;
}


bool ModelDatabase::ContainsModel(string id)
{
	bool contains;
	map<string, Model3D>::iterator it = mModels.find(id);

	if(it != mModels.end())
		contains = true;
	else
		contains = false;

	return contains;
}


bool ModelDatabase::Clear()
{
	bool isClear;

	mModels.clear();

	if(mModels.empty())
		isClear = true;
	else
		isClear = false;

	return isClear;
}