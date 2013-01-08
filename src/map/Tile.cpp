/*
 * This is the implementation file for the Tile class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "Tile.h"
#include "TileLayer.h"
#include "TileMap.h"

using namespace framework;

namespace gravity
{

    Tile::Tile(Game* game) :
    DrawableGameComponent(game)
    {

    }

    Tile::Tile(Game* game, TileLayer* Layer, Texture2D* texture, Vector2 position, Vector2 scale, float rotation,
            Color color, bool physics) :
    DrawableGameComponent(game)
    {
        this->Texture = texture;
        this->Position = position;
        this->Scale = scale;
        this->Rotation = rotation;
        this->TintColor = color;
        this->Physics = physics;
        this->Layer = Layer;

        Initialize();
    }

    void Tile::Initialize()
    {
        // Create the body
        b2BodyDef myBodyDef;
        if (Physics)
            myBodyDef.
            myBodyDef.type = b2_dynamicBody;
        else
            myBodyDef.type = b2_staticBody;
        
        myBodyDef.position.Set((Position.X-HALF_BLOCK_PIXELS)*PIXELS_TO_METERS, 
                (Position.Y-HALF_BLOCK_PIXELS) * PIXELS_TO_METERS);
        myBodyDef.angle = 0;
        Body = this->Layer->Map->World->CreateBody(&myBodyDef);

        // Create the shape
        b2PolygonShape boxShape;
        boxShape.SetAsBox(HALF_BLOCK_METERS, HALF_BLOCK_METERS);
        boxShape.

        // Create the fixture
        b2FixtureDef boxFixtureDef;
        boxFixtureDef.shape = &boxShape;
        boxFixtureDef.density = 1;
        Body->CreateFixture(&boxFixtureDef);
    }

    void Tile::SetLayer(TileLayer* Layer)
    {
        this->Layer = Layer;
    }

    void Tile::Draw(Camera* camera)
    {
        Vector2 camPos = Vector2(Position.X - camera->Position.X,
                Position.Y - camera->Position.Y);
        game->Render->Draw(Texture, camPos, TintColor);
    }

    void Tile::Update()
    {
        if (Physics)
        {
            b2Vec2 bVec = Body->GetPosition();
            Position.X = (bVec.x+HALF_BLOCK_METERS)*METERS_TO_PIXELS;
            Position.Y = (bVec.y+HALF_BLOCK_METERS)*METERS_TO_PIXELS;
        }
    }
}

