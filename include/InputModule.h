/*
 * This is the header file for the InputModule class.
 * This class will be the base class for all input modules used in the game.
 * Author: Jordan Ell
 * Date: 05/01/12
 */
 
 #ifndef INPUTMODULE_H
 #define INPUTMODULE_H
 
 #include "GameFramework.h"
 
 using namespace GameFramework;
 
 namespace ManhattanProject
 {
	 class InputModule: public GameComponent
	 {
		 public:
			InputModule(Game* game);
			
			virtual void Initialize();
			virtual void Update(SDL_Event* event);
	 };
 }
 
 #endif

