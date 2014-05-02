#include "GameAssetFactory.h"
#include "GameEngineCore.h"

GameAssetFactory::GameAssetFactory(){

}

void GameAssetFactory::Register(const string &assetName, CreateGameAsset create){
	m_FactoryMap[assetName] = create;
}

IAsset *GameAssetFactory::CreateAsset(const string &assetName){
	FactoryMap::iterator it = m_FactoryMap.find(assetName);
	if(it != m_FactoryMap.end())
		return it->second();
	return NULL;
}