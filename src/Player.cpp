/*
 * This is the implementation for the Player class.
 * This class will be used for the main character class.
 * Author: Jordan Ell
 * Date: 09/01/12
 */

#include "Player.h"

using namespace GameFramework;

namespace ManhattanProject
{
	Player::Player(Game* game):
		Entity(game)
	{
		this->game = game;
	}
	
	Player::Player(Game* game, Scene* scene, Camera* camera):
		Entity(game)
	{
		this->game = game;
		list<Uint8> listeners;
		listeners.push_back(SDL_KEYDOWN);
		listeners.push_back(SDL_KEYUP);
		scene->AddListener(this, listeners);
		this->camera = camera;
	}
	
	void Player::Initialize()
	{
	
	}
	
	void Player::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
	{
		cout << "Testing key down in player\n";
	}
	
	void Player::Update()
	{
	
	}
	
	void Player::Draw()
	{
	
	}
}

