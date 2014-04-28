#pragma once

#include <string>
#include <vector>
#include "gameObject.h"

class GameObjectDatabase
{
	public:
		GameObjectDatabase(void);
		~GameObjectDatabase(void);

		vector<gameObject> GetGameObjects();
		bool AddGameObject(gameObject object);
		bool RemoveGameObject(unsigned int ID);
		bool ContainsGameObject(unsigned int ID);
		bool Clear();

	private:
		vector<gameObject> mGameObjects;
};

