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
#include "MapLoader.h"
#include "TileMap.h"
#include "SceneManager.h"

#include "Button.h"
#include "Label.h"

using namespace framework;

namespace gravity
{

    class MenuScene : public Scene
    {
      public:
        MenuScene(Game* game);
        MenuScene(Game* game, SceneManager* sm);

        ~MenuScene();

        void Initialize();

        void Update();
        void Draw();

        SceneManager* sm;

      private:
        TileMap* Map;
        Camera* camera;
        Vector2 camVelocity;

        Button* singleButton;
        Button* multiButton;
        Button* settingsButton;
        Button* exitButton;

    };
}

#endif	/* MENUSCENE_H */

