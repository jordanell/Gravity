/*
 * This is the implementation file for the Tile class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "Tile.h"

using namespace framework;

namespace gravity
{

    Tile::Tile(Game* game) :
    DrawableGameComponent(game)
    {
        
    }

    Tile::Tile(Game* game, Texture2D* texture, Vector2 position, Vector2 scale, float rotation,
            Color color, bool physics) :
    DrawableGameComponent(game)
    {
        this->Texture = texture;
        this->Position = position;
        this->Scale = scale;
        this->Rotation = rotation;
        this->TintColor = color;
        this->Physics = physics;
        
        Initialize();
    }
    
    void Tile::Initialize()
    {
        
    }

    void Tile::Draw(Camera* camera)
    {
        game->Render->Draw(Texture, Position, TintColor);
    }

    void Tile::Update()
    {

    }
}

