/*
 * This is the header for the Scene class.
 * The Scene class will be used as a base class for all drawable scenes in the game. This can include
 * but not limited to: Menus, Levels etc.
 * Author: Jordan Ell
 * Date: 01/10/11
 */
 
 #ifndef SCENE_H
 #define SCENE_H
 
 #include "GameFramework.h"
 
 using namespace GameFramework;
 
 namespace ManhattanProject
 {
	 class Scene: public DrawableGameComponent
	 {
		 public:
			Scene(Game* game);
			
			GameComponentCollection* Components;
			Game* game;
			
			virtual void Initialize();
			virtual void Update();	
			virtual void Draw();
	 };
 }
 
 #endif

