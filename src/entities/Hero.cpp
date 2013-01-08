/* 
 * File:   Hero.cpp
 * Author: jordan
 * 
 * Created on September 20, 2012, 3:22 PM
 */

#include "Hero.h"

namespace gravity
{
        Hero::Hero(Game* game, TileMap* Map) :
        Entity(game)
        {
            this->Map = Map;
            
            Initialize();
        }
        
        void Hero::Initialize()
        {
            // Load the body
            this->PartBody = game->Content->LoadTexture("entities/hero/Hero.png");
            
            // Init the physics
            
        }
        
        void Hero::InitPhysics()
        {
            
        }
        
        void Hero::SetPosition(Vector2 Position)
        {
            this->Position = Position;
            if(this->Body != NULL)
            {
                // Update the physics
                Body->GetWorld()->DestroyBody(Body);
                
            }
        }
        
        void Hero::Update()
        {
            
        }
        
        void Hero::Draw()
        {
            
        }
}

