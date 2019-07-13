#ifndef __LevelParser__
#define __LevelParser__

#include <vector>

#include "tinyxml.h"
#include "Level.h"

class Level;
class Layer;

class LevelParser
{
public:

	Level* parseLevel(const char* levelFile);
	
private:	

	void parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
	
	void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*>* pLayers, const std::vector<Tileset>* pTilesets);

	int m_tileSize;
	int m_width;
	int m_height;
};
	
	
#endif // __LevelParser__
