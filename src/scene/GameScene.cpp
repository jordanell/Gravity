/*
 * This is the implementation file for the LauncherScene class.
 * Author: Jordan Ell
 * Date: 09/10/11
 */

#include "GameScene.h"

using namespace framework;

namespace gravity
{

    GameScene::GameScene(Game* game) :
    Scene(game)
    {
        this->game = game;
        this->Initialize();

        GetCurrentDir(RootDirectory, sizeof (RootDirectory));
        RootDirectory[sizeof (RootDirectory) - 1] = '\0';
    }

    GameScene::GameScene(Game* game, SceneManager* sm) :
    Scene(game)
    {
        this->game = game;
        this->sm = sm;
        this->Initialize();

        GetCurrentDir(RootDirectory, sizeof (RootDirectory));
        RootDirectory[sizeof (RootDirectory) - 1] = '\0';
    }

    GameScene::~GameScene()
    {
        delete Map;
    }

    void GameScene::Initialize()
    {
        // Load the camera at 0,0
        camera = new Camera(Vector2(-200, -100), Vector2(600, 400));

        // Create the map loader and load the map
        MapLoader* ml = new MapLoader(this->game);
        Map = ml->LoadMap("maps/testlevel.xml", this);

        // Initialize the entities here
        entityManager = new EntityManager(game, Map);

        // Set up to listen for camera movements
        list<Uint8> listeners;
        listeners.push_back(SDL_KEYDOWN);
        this->AddListener(this, listeners);
        SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


        Scene::Initialize();
    }

    void GameScene::Draw()
    {
        if (Map != NULL)
            Map->Draw(camera);

        Scene::Draw();
    }

    void GameScene::Update()
    {

        Scene::Update();
    }

    void GameScene::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
    {
        if (sym == SDLK_w)
            camera->Position.Y -= 4;
        else if (sym == SDLK_s)
            camera->Position.Y += 4;
        else if (sym == SDLK_a)
            camera->Position.X += 4;
        else if (sym == SDLK_d)
            camera->Position.X -= 4;
    }
}

