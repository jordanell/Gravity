/* 
 * File:   MenuScene.cpp
 * Author: jordan
 * 
 * Created on August 1, 2012, 3:24 PM
 */

#include "MenuScene.h"

using namespace framework;

namespace gravity
{

    MenuScene::MenuScene(Game* game):
    Scene(game)
    {
        Initialize();
    }
    
    MenuScene::~MenuScene()
    {
        delete Map;
        delete camera;
    }

    void MenuScene::Initialize()
    {
        camera = new Camera(Vector2(0,0), Vector2(600,400));
        camVelocity = Vector2(0.4,0.7);
        
        MapLoader* ml = new MapLoader(this->game);
        Map = ml->LoadMap("maps/mainmenu.xml", this);
        delete ml;
        
        // Setup buttons
        singleButton = new Button(game, game->Content->LoadTexture("scene/mainmenu/BlueButton.png"), framework::Rectangle(100, 200, 250, 45), this);
        //multiButton = new Button(game, game->Content->LoadTexture("scene/mainmenu/BlueButton.png"), framework::Rectangle(460, 325, 100, 50), this);
        
        Scene::Initialize();
    }

    void MenuScene::Update()
    {
        if(camera->Position.X >= 200 || camera->Position.X <= -200)
            camVelocity.X *= -1;
        if(camera->Position.Y >= 200 || camera->Position.Y <= -200)
            camVelocity.Y *= -1;
        
        camera->Position.X += camVelocity.X;
        camera->Position.Y += camVelocity.Y;
        
        Scene::Update();
    }
    
    void MenuScene::Draw()
    {
        if (Map != NULL)
            Map->Draw(camera);
        
        // Draw buttons
        singleButton->Draw();
        //multiButton->Draw();

        Scene::Draw();
    }

}