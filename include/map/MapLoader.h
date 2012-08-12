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
        TileMap* LoadMap(const std::string &fileName, Scene* scene);
        string replaceAll(string str, string from, string to);
        
      private:
        TileMap* ParseMap(TiXmlNode* parent, Scene* scene);

        TileMap* ParseLayers(TileMap* map, TiXmlNode* parent);
        void ParseLayer(TileMap* map, TileLayer* layer, TiXmlNode* parent);

        void ParseTile(TileLayer* layer, TiXmlNode* parent);
        
        int StringToNumber(const string &Text);

        Game* game;
    };
}

#endif
