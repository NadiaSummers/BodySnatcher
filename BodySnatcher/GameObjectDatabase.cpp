#include "GameObjectDatabase.h"


GameObjectDatabase::GameObjectDatabase(void)
{
}


GameObjectDatabase::~GameObjectDatabase(void)
{
}


vector<gameObject> GameObjectDatabase::GetGameObjects()
{
	return mGameObjects;
}


bool GameObjectDatabase::AddGameObject(gameObject object)
{
	bool added = false;
	unsigned int size = mGameObjects.size();
	gameObject temp;

	temp.setID(object.getID());
	temp.setPositionX(object.getPositionX());
	temp.setPositionY(object.getPositionY());
	temp.setPositionZ(object.getPositionZ());
	temp.setScale(object.getScale());
	temp.setSphereSize(object.getSphereSize());
	temp.setModelID(object.getModelID());

	mGameObjects.push_back(temp);

	if(size > mGameObjects.size())
		added = true;
	else
		added = false;

	return added;
}


bool GameObjectDatabase::RemoveGameObject(unsigned int id)
{
	bool removed;
	unsigned int size = mGameObjects.size();

	for(unsigned int i=0; i<mGameObjects.size(); i++) //for each object
	{
		if(mGameObjects[i].getID() == id) //if the object's ID matches
		{
			mGameObjects.erase(mGameObjects.begin()+i);
			break;
		}
	}

	if(mGameObjects.size() < size)
		removed = true;
	else
		removed = false;

	return removed;
}


bool GameObjectDatabase::ContainsGameObject(unsigned int id)
{
	bool contains = false;
	
	for(unsigned int i=0; i<mGameObjects.size(); i++)
	{
		if(mGameObjects[i].getID() == id)
		{
			contains = true;
			break;
		}
	}

	return contains;
}


bool GameObjectDatabase::Clear()
{
	bool isClear;

	mGameObjects.clear();

	if(mGameObjects.empty())
		isClear = true;
	else
		isClear = false;

	return isClear;
}