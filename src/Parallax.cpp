/* 
 * File:   Parallax.cpp
 * Author: jordan
 * 
 * Created on August 1, 2012, 2:21 PM
 */

#include "Parallax.h"
#include "Camera.h"

using namespace framework;

namespace gravity
{

    Parallax::Parallax(Game* game):
    DrawableGameComponent(game)
    {
        
    }

    Parallax::Parallax(Game* game, framework::Rectangle Size):
    DrawableGameComponent(game)
    {
        this->Size = Size;
    }

    void Parallax::AddItem(Texture2D* texture)
    {
        this->Textures.push_back(texture);
    }

    void Parallax::Draw(Camera camera)
    {
        list<Texture2D*>::iterator it;
        for(it=Textures.begin(); it != Textures.end(); it++)
        {
            // Draw
            float ratioX = (float)(*it)->Width / (float)Size.Width;
            float ratioY = (float)(*it)->Height / (float)Size.Height;
            framework::Rectangle rec = framework::Rectangle(camera.Position.X*ratioX,
                    camera.Position.Y*ratioY, (*it)->Width, (*it)->Height);
            game->Render->Draw((*it), rec, Color(255, 255, 255, 255));
        }
    }
}

