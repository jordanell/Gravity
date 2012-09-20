/*
 * This is the implementation file for the TileMap class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "TileMap.h"

using namespace framework;

namespace gravity
{

    TileMap::TileMap(Game* game) :
    DrawableGameComponent(game)
    {
        this->game = game;

        Initialize();
    }

    TileMap::TileMap(Game* game, Scene* scene) :
    DrawableGameComponent(game)
    {
        this->game = game;
        this->scene = scene;

        Initialize();
    }

    TileMap::~TileMap()
    {
        for (list<TileLayer*>::iterator it = layers.begin(); it != layers.end(); it++)
        {
            TileLayer* ptr = *it;
            delete ptr;
        }
    }

    void TileMap::Initialize()
    {
        // Set up box2d
        b2Vec2 gravity(0, 2.0f);
        World = new b2World(gravity);
    }

    /* Tile Layer stuff */
    void TileMap::AddTileLayer()
    {
        TileLayer* newTileLayer = new TileLayer(game);
        layers.push_back(newTileLayer);
        newTileLayer->Map = this;
    }

    void TileMap::AddTileLayer(TileLayer* layer)
    {
        layers.push_back(layer);
    }

    TileLayer* TileMap::LastAddedLayer()
    {
        return layers.back();
    }

    void TileMap::Draw(Camera* camera)
    {
        //Iterator over list of tiles and draw them
        for (list<TileLayer*>::iterator it = layers.begin(); it != layers.end(); it++)
        {
            TileLayer* ptr = *it;
            ptr->Draw(camera);
        }
    }

    void TileMap::Update()
    {
        // Step the physics
        float32 timeStep = 1/(float)FRAMES_PER_SECOND; //the length of time passed to simulate (seconds)
        int32 velocityIterations = 8; //how strongly to correct velocity
        int32 positionIterations = 3; //how strongly to correct position

        World->Step(timeStep, velocityIterations, positionIterations);
        
        //Iterator over list of tiles and update them
        for (list<TileLayer*>::iterator it = layers.begin(); it != layers.end(); it++)
        {
            TileLayer* ptr = *it;
            ptr->Update();
        }
    }
}

