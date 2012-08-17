/*
 * This is the implementation file for the SceneManager class.
 * Author: Jordan Ell
 * Date: 01/10/11
 */

#include "SceneManager.h"
#include <iostream>


using namespace framework;

namespace gravity
{

    SceneManager::SceneManager(Game* game) :
    DrawableGameComponent(game)
    {
        this->game = game;
        this->Initialize();
    }

    void SceneManager::Initialize()
    {
        //Always initialize to the launcher scene
        ActiveScene = new LauncherScene(game, this);

        DrawableGameComponent::Initialize();
    }

    void SceneManager::Draw()
    {
        if (ActiveScene != NULL)
            ActiveScene->Draw();
        DrawableGameComponent::Draw();
    }

    void SceneManager::Update()
    {
        switch(changeRequest)
        {
            case CR_None:
                break;
            case CR_MenuScene:
                toMenuScene();
                break;
            case CR_GameScene:
                toGameScene();
                break;
        }
        
        if (ActiveScene != NULL)
            ActiveScene->Update();
        
        DrawableGameComponent::Update();
    }
    
    void SceneManager::preSceneChange()
    {
        delete ActiveScene;
        changeRequest = CR_None;
    }
    
    void SceneManager::toGameScene()
    {
        preSceneChange();
        ActiveScene = new GameScene(game);
    }
    
    void SceneManager::toMenuScene()
    {
        preSceneChange();
        game->Content->ClearTextureMap();
        //game->Render->SetResolution(1080, 720);
        ActiveScene = new MenuScene(game, this);
    }
}
