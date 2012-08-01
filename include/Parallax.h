/* 
 * File:   Parallax.h
 * Author: jordan
 *
 * Created on August 1, 2012, 2:21 PM
 */

#ifndef PARALLAX_H
#define	PARALLAX_H

#include "framework.h"
#include "Camera.h"

#include <list>

using namespace framework;

namespace ManhattanProject
{
    class Parallax: public DrawableGameComponent
    {
      public:
        Parallax(Game* game);
        Parallax(Game* game, framework::Rectangle Size);
        
        void AddItem(Texture2D* texture);
        
        void Draw(Camera camera);
        
      private:
        framework::Rectangle Size;
        list<Texture2D*> Textures;
        

    };
}

#endif	/* PARALLAX_H */

