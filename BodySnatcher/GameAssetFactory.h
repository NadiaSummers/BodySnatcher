#ifndef GAMEASSETFACTORY_H
#define GAMEASSETFACTORY_H

#include <map>
#include <string>
#include "IAsset.h"

using namespace std;

class GameAssetFactory{
private:
	GameAssetFactory();
	GameAssetFactory(const GameAssetFactory &) { };
	GameAssetFactory &operator=(const GameAssetFactory &) {return *this;}

	typedef map<string, CreateGameAsset> FactoryMap;
	FactoryMap m_FactoryMap;
public:
	~GameAssetFactory() { m_FactoryMap.clear(); };
	
	static GameAssetFactory *Get()
	{
		static GameAssetFactory instance;
		return &instance;
	}

	void Register(const string &assetName, CreateGameAsset create);
	IAsset *CreateAsset(const string &assetName);
};

#endif