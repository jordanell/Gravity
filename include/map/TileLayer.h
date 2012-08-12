/*
 * This is the header for the TileLayer class.
 * This class is used to hold a list of tiles and can draw those tiles
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#ifndef TILELAYER_H
#define TILELAYER_H

#include "framework.h"
#include "Tile.h"
#include "Camera.h"
#include <list>

using namespace framework;

namespace gravity
{

    class TileLayer : public DrawableGameComponent
    {
      public:
        TileLayer(Game* game);
        TileLayer(Game* game, Vector2 scrollspeed);

        ~TileLayer();

        void Update();
        void Draw(Camera* camera);

        void AddTile(Tile* tile);
        
        Vector2 ScrollSpeed;

      protected:
        list<Tile*> Tiles;
    };
}

#endif
