/*
 * This is the implementation file for the TileLayer class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "TileLayer.h"
#include <list>

using namespace framework;

namespace gravity
{

    TileLayer::TileLayer(Game* game) :
    DrawableGameComponent(game)
    {
        this->ScrollSpeed = Vector2(1,1);
    }
    
    TileLayer::TileLayer(Game* game, Vector2 scrollspeed) :
    DrawableGameComponent(game)
    {
        this->ScrollSpeed = scrollspeed;
    }

    TileLayer::~TileLayer()
    {

    }

    /* Add a tile to the layer */
    void TileLayer::AddTile(Tile* tile)
    {
        this->Tiles.push_back(tile);
    }

    void TileLayer::Draw(Camera* camera)
    {
        //Iterate over list and draw tiles
        for (list<Tile*>::iterator it = Tiles.begin(); it != Tiles.end(); it++)
        {
            Tile* ptr = *it;
            Camera* camPos = new Camera(Vector2(camera->Position.X * ScrollSpeed.X, camera->Position.Y * ScrollSpeed.Y),
                    camera->Size);
            ptr->Draw(camPos);
            delete camPos;
        }
    }

    void TileLayer::Update()
    {

    }
}

