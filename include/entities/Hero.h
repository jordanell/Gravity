/* 
 * File:   Hero.h
 * Author: jordan
 *
 * Created on September 20, 2012, 3:22 PM
 */

#ifndef HERO_H
#define	HERO_H

#include "Box2D/Box2D.h"

#include "Entity.h"
#include "TileMap.h"

using namespace framework;

namespace gravity
{

    class Hero: public Entity
    {
      public:
        Hero(Game* game, TileMap* Map);
        
        void SetPosition(Vector2 Position);
        
        void Initialize();
        void Update();
        void Draw();

      private:
        void InitPhysics();
        
        TileMap* Map;
        
        Vector2 Position;
        Texture2D* PartBody;
        
        b2Body* Body;
    };
}

#endif	/* HERO_H */

