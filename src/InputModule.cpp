/*
 * This is the implementation file for the InputModule class.
 * This class will be the base class for all input modules used in the game.
 * Author: Jordan Ell
 * Date: 05/01/12
 */
 
 #include "InputModule.h"
 
 using namespace GameFramework;
 
 namespace ManhattanProject
 {
	 InputModule::InputModule(Game* game):
		GameComponent(game)
	{
		this->game = game;
		this->Initialize();
	}
	
	void InputModule::Initialize()
	{
	
	}
	
	void InputModule::Update(SDL_Event* event)
	{
	
	}
 }