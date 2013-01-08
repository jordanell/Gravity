/*
 * This is the header for the TileMap class.
 * This class is used to hold a list of TileLayers and can draw those layers to make up the map.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include "Box2D.h"

#include "framework.h"
#include "TileLayer.h"
#include "InputEvent.h"
#include "Camera.h"
#include "Scene.h"
#include <list>
#include <string>

using namespace framework;

namespace gravity
{

    class TileMap : public DrawableGameComponent, InputEvent
    {
      public:
        SDL_Event event;

        TileMap(Game* game);
        TileMap(Game* game, Scene* scene);

        ~TileMap();

        void Initialize();
        void Update();
        void Draw(Camera* camera);

        void AddTileLayer();
        void AddTileLayer(TileLayer* layer);

        TileLayer* LastAddedLayer();
        
        b2World* World;

      protected:
        Scene* scene;
        list<TileLayer*> layers;
    };
}

#endif
