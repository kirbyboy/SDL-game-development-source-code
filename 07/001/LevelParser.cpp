#include <vector>

#include "LevelParser.h"
#include "Level.h"
#include "TextureManager.h"
#include "Game.h"
#include "base64.h"
#include "TileLayer.h"

#include <iostream>

Level* LevelParser::parseLevel(const char *levelFile)
{
	// create TinyXML document and load the map XML
	TiXmlDocument levelDocument;
	levelDocument.LoadFile(levelFile);
	
	// create the level object
	Level* pLevel = new Level();
	
	// get the root node
	TiXmlElement* pRoot = levelDocument.RootElement();
	
	pRoot->Attribute("tilewidth", &m_tileSize);
	pRoot->Attribute("width", &m_width);
	pRoot->Attribute("height", &m_height);
	
	// parse the tilesets
	for(TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == std::string("tileset"))
		{
			parseTilesets(e, pLevel->getTilesets());
		}
	}
	
	// parse any object layers
	for(TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == std::string("layer"))
		{
			parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets());
		}
	}
	
	return pLevel;
}

void LevelParser::parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets)
{
	// first add the tileset to texture manager
	TheTextureManager::Instance()->load(pTilesetRoot->FirstChildElement()->Attribute("source"), pTilesetRoot->Attribute("name"), TheGame::Instance()->getRenderer());
	
	// create a tileset object
	Tileset tileset;
	pTilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
	pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
	pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->Attribute("margin", &tileset.margin);
	tileset.name = pTilesetRoot->Attribute("name");
	
	tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);
	
	pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*>* pLayers, const std::vector<Tileset>* pTilesets)
{
	TileLayer* pTileLayer = new TileLayer(m_tileSize, *pTilesets);
	
	// tile data
	std::vector<std::vector<int>> data;
	
	std::string decodeIDs;
	TiXmlElement* pDataNode;
	
	for(TiXmlElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == std::string("data"))
		{
			pDataNode = e;
		}
	}
	
	for(TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling())
	{
		TiXmlText* text = e->ToText();
		std::string t = text->Value();
		decodeIDs = base64_decode(t);
	}
	
	unsigned numGids = m_width * m_height;
	std::vector<unsigned> gids(numGids);
	
	// Fix until i know how base 64 works
	for(int i = 0; i < numGids; i++)
	{	
		gids[i] = (unsigned)(decodeIDs[i * 4]) * 1 +
				  (unsigned)(decodeIDs[(i * 4) + 1]) * 2 +
				  (unsigned)(decodeIDs[(i * 4) + 2]) * 4 +
				  (unsigned)(decodeIDs[(i * 4) + 3]) * 8;
	}
	
	std::vector<int> layerRow(m_width);
	
	for(int j = 0; j < m_height; j++)
	{
		data.push_back(layerRow);
	}
	
	for(int rows = 0; rows < m_height; rows++)
	{
		for(int cols = 0; cols < m_width; cols++)
		{
			data[rows][cols] = gids[rows * m_width + cols];
		}
	}


	pTileLayer->setTileIDs(data);
	
	pLayers->push_back(pTileLayer);
}
