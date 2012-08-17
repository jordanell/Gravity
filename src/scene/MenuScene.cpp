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

    void exitButtonDown(Game* game, Scene* scene)
    {
        game->Exit();
    }
    
    void singlePlayerButtonDown(Game* game, Scene* scene)
    {
        MenuScene *mscene = dynamic_cast<MenuScene*> (scene);
        if (mscene->sm != NULL)
            mscene->sm->changeRequest = CR_GameScene;
    }
    
    MenuScene::MenuScene(Game* game):
    Scene(game)
    {
        Initialize();
    }
    
    MenuScene::MenuScene(Game* game, SceneManager* sm):
    Scene(game)
    {
        this->sm = sm;
        Initialize();
    }
    
    MenuScene::~MenuScene()
    {
        delete Map;
        delete camera;
    }

    void MenuScene::Initialize()
    {
        camera = new Camera(Vector2(0,0), Vector2(game->Render->GetWidth(),game->Render->GetHeight()));
        camVelocity = Vector2(0.4,0.7);
        
        MapLoader* ml = new MapLoader(this->game);
        Map = ml->LoadMap("maps/mainmenu.xml", this);
        delete ml;
        
        // Setup buttons
        singleButton = new Button(game, game->Content->LoadTexture("gui/buttons/Green250.png"),
                game->Content->LoadTexture("gui/buttons/Hover250.png"), 
                framework::Rectangle(game->Render->GetWidth()/2 - 100, game->Render->GetHeight()/2 - 100, 200, 40), this);
        singleButton->LButtonDownCallback = &singlePlayerButtonDown;
        
        multiButton = new Button(game, game->Content->LoadTexture("gui/buttons/Green250.png"),
                game->Content->LoadTexture("gui/buttons/Hover250.png"), 
                framework::Rectangle(game->Render->GetWidth()/2 - 100, game->Render->GetHeight()/2 - 50, 200, 40), this);
        
        settingsButton = new Button(game, game->Content->LoadTexture("gui/buttons/Blue250.png"),
                game->Content->LoadTexture("gui/buttons/Hover250.png"), 
                framework::Rectangle(game->Render->GetWidth()/2 - 100, game->Render->GetHeight()/2, 200, 40), this);
        
        exitButton = new Button(game, game->Content->LoadTexture("gui/buttons/Red250.png"),
                game->Content->LoadTexture("gui/buttons/Hover250.png"),
                framework::Rectangle(game->Render->GetWidth()/2 - 100, game->Render->GetHeight()/2 + 50, 200, 40), this);
        exitButton->LButtonDownCallback = &exitButtonDown;
        
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
        multiButton->Draw();
        settingsButton->Draw();
        exitButton->Draw();

        Scene::Draw();
    }

}