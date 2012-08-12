/*
 * This is the header for the Tile class.
 * This class will be used a the base class for all maps in the game. The tile is not a tile
 * In the conventional sense. It is not restricted in size or position.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#ifndef TILE_H
#define TILE_H

#include "framework.h"
#include "Camera.h"
#include <string>
#include <list>

using namespace framework;

namespace gravity
{

    class Tile : public DrawableGameComponent
    {
      public:
        Tile(Game* game);
        Tile(Game* game, Texture2D* texture, Vector2 position, Vector2 scale, float rotation,
                Color color, bool physics);
        
        ~Tile();

        void Initialize();

        void Update();
        void Draw(Camera* camera);

        Vector2 Position;
        Vector2 Scale;
        float Rotation;
        Color TintColor;
        bool Physics;

        Texture2D* Texture;

      protected:
    };
}

#endif
