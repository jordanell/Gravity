/* 
 * File:   MenuScene.h
 * Author: jordan
 *
 * Created on August 1, 2012, 3:24 PM
 */

#ifndef MENUSCENE_H
#define	MENUSCENE_H

#include "framework.h"
#include "Scene.h"
#include "Parallax.h"

using namespace framework;

namespace gravity
{
    class MenuScene: public Scene
    {
      public:
        MenuScene(Game* game);
        
        void Initialize();
        
        void Update();
	void Draw();
        
      private:
        Parallax* parallax;

    };
}

#endif	/* MENUSCENE_H */

