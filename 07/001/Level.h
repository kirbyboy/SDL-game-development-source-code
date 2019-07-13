#ifndef __Level__
#define __Level__

#include <vector>
#include <string>

#include "Layer.h"

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};

class Level
{
public:

	void update();
	void render();
	
	std::vector<Tileset>* getTilesets()
	{
		return &m_tilesets;
	}	
	
	std::vector<Layer*>* getLayers()
	{
		return &m_layers;
	}
	
private:

	friend class LevelParser;
	Level() {}

	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;	
};

#endif // __Level__
