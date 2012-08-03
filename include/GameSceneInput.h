/*
 * This is the header file for the GameSceneInput class.
 * This class will be used as the input module for the GameScene class
 * Author: Jordan Ell
 * Date: 05/01/12
 */
 
 #ifndef GAMESCENEINPUT_H
 #define GAMESCENEINPUT_H
 
 #include "framework.h"
 #include "GameScene.h"
 
 using namespace framework;
 
 namespace gravity
 {
	 class GameSceneInput: public InputModule
	 {
		 public:
			GameSceneInput(Game* game);
			
			void Initialize();
			void Update(SDL_Event* event);
			
			void SetScene(GameScene* gameScene);
			
		 private:
			GameScene* gameScene;
	 };
 }
 
 #endif
