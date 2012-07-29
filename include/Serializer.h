/*
 * This is the header for the Serializer class.
 * This class is used to load in XML objects.
 * Author: Jordan Ell
 * Date: 17/4/2012
 */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "framework.h"
#include "TileMap.h"
#include "TileLayer.h"
#include "Camera.h"
#include "Scene.h"

using namespace framework;

namespace ManhattanProject
{
	class Serializer
	{
        public:
            Serializer(Game* game);

            // Helper function
			int StringToNumber(const string &Text);

            // serializer
            TileMap* LoadMap(Game* game, const std::string &fileName, Scene* scene);
            TileMap* ParseMap(Game* game, TiXmlNode* parent, Scene* scene);

            TileMap* ParseLayers(TileMap* map, TiXmlNode* parent);
            void ParseLayer(TileMap* map, TileLayer* layer, TiXmlNode* parent);

            void ParseMapObjects(TileMap* map, TileLayer* layer, TiXmlNode* parent);

            void ParseTile(TileLayer* layer, TiXmlNode* parent);
            void ParseCollisionRectangle(TileMap* map, TiXmlNode* parent);

            Game* game;
	};
}

#endif
