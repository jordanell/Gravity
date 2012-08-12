/*
 * This is the header for the Map Loader class.
 * This class is used to load in XML objects.
 * Author: Jordan Ell
 * Date: 17/4/2012
 */

#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "framework.h"
#include "TileMap.h"
#include "TileLayer.h"
#include "Camera.h"
#include "Scene.h"

using namespace framework;

namespace gravity
{
    class MapLoader
    {
      public:
        MapLoader(Game* game);

        // Helper function
        TileMap* LoadMap(Game* game, const std::string &fileName, Scene* scene);
        
      private:
        TileMap* ParseMap(Game* game, TiXmlNode* parent, Scene* scene);

        TileMap* ParseLayers(TileMap* map, TiXmlNode* parent);
        void ParseLayer(TileMap* map, TileLayer* layer, TiXmlNode* parent);

        void ParseTile(TileLayer* layer, TiXmlNode* parent);
        
        int StringToNumber(const string &Text);

        Game* game;
    };
}

#endif
