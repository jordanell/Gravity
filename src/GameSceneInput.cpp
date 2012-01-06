/*
 * This is the implementation file for the GameSceneInput class.
 * This class will be used as the input module for the GameScene class
 * Author: Jordan Ell
 * Date: 05/01/12
 */
 
 #include "InputModule.h"
 #include "GameSceneInput.h"
 
 using namespace GameFramework;
 
 namespace ManhattanProject
 {
	 GameSceneInput::GameSceneInput(Game* game):
		InputModule(game)
	 {
		 this->game = game;
		 this->Initialize();
	 }
	 
	 void GameSceneInput::SetScene(GameScene* gameScene)
	 {
		 this->gameScene = gameScene;
	 }
	 
	 void GameSceneInput::Initialize()
	 {
	 
	 }
	 
	 void GameSceneInput::Update(SDL_Event* event)
	 {
	 
	 }
 }