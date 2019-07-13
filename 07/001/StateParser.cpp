#include <string>
#include <iostream>

#include "StateParser.h"
#include "GameObjectFactory.h"
#include "Game.h"

bool StateParser::parseState(const char* stateFile, std::string stateID, std::vector<GameObject *> *pObjects, std::vector<std::string> *pTextureIDs)
{
	// create the XML document
	TiXmlDocument xmlDoc;
	
	// load the state file
	if(!xmlDoc.LoadFile(stateFile))
	{
		std::cerr << xmlDoc.ErrorDesc() << std::endl;
		return false;
	}
	
	// get the root element
	TiXmlElement* pRoot = xmlDoc.RootElement(); // <STATES>
	
	// pre declare the states root node
	TiXmlElement* pStateRoot = 0;
	// get this states root node and assign it to pStateRoot
	for(TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == stateID)
		{
			pStateRoot = e;
		}
	}
	
	// pre declare the texture root
	TiXmlElement* pTextureRoot = 0;
	
	// get the root of the texture elements
	for(TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == std::string("TEXTURES"))
		{
			pTextureRoot = e;
		}
	}
	
	// now parse the textures
	parseTextures(pTextureRoot, pTextureIDs);
	
	// pre declare the object root node
	TiXmlElement* pObjectRoot = 0;
	
	// get the root node and assign it to pObjectRoot
	for(TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == std::string("OBJECTS"))
		{
			pObjectRoot = e;
		}
	}
	
	// now parse the objects
	parseObjects(pObjectRoot, pObjects);
	
	return true;
}

void StateParser::parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs)
{
	for(TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		std::string filenameAttribute = e->Attribute("filename");
		std::string idAttribute = e->Attribute("ID");
		pTextureIDs->push_back(idAttribute); // push into list
		
		TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheGame::Instance()->getRenderer());
	}
}

void StateParser::parseObjects(TiXmlElement *pStateRoot, std::vector<GameObject *> *pObjects)
{
	for(TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, numFrames, callbackID, animSpeed;
		std::string textureID;
		
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("numFrames", &numFrames);
		e->Attribute("callbackID", &callbackID);
		e->Attribute("animSpeed", &animSpeed);
		
		textureID = e->Attribute("textureID");
		
		GameObject* pGameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));
		pObjects->push_back(pGameObject);
	}
}
