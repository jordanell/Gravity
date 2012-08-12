/*
 * This is the header for the Scene class.
 * The Scene class will be used as a base class for all drawable scenes in the game. This can include
 * but not limited to: Menus, Levels etc.
 * Author: Jordan Ell
 * Date: 01/10/11
 */

#ifndef SCENE_H
#define SCENE_H

#include "framework.h"
#include "Listener.h"  
#include <list>

using namespace framework;

namespace gravity
{

    class Scene : public DrawableGameComponent
    {
      public:
        Scene(Game* game);
        GameComponentCollection* Components;

        virtual void Initialize();
        virtual void Update();
        virtual void Draw();

        virtual void AddListener(InputEvent* Component, list<Uint8> EventTypes);
        virtual void PollListeners(SDL_Event* event);

      private:
        list<Listener*> Listeners;
    };
}

#endif

