#ifndef __StateParser__
#define __StateParser__

#include <iostream>
#include <vector>
#include "tinyxml.h"

class GameObject;

class StateParser
{
	public:
	bool parseState(const char* stateFile, std::string stateID, std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs);
	
	private:
	void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*> *pObjects);
	void parseTextures(TiXmlElement* psStateRoot, std::vector<std::string> *pTextureIDs);
};

#endif /* defined(__StateParser__) */

