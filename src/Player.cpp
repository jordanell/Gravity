/*
 * This is the implementation for the Player class.
 * This class will be used for the main character class.
 * Author: Jordan Ell
 * Date: 09/01/12
 */

#include "Player.h"

using namespace framework;

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
		listeners.push_back(SDL_MOUSEBUTTONDOWN);
		scene->AddListener(this, listeners);
		this->camera = camera;
	}
	
	void Player::Initialize()
	{
	
	}
	
	
	void Player::Update()
	{
	
	}
	
	void Player::OnLButtonDown(int mX, int mY)
	{
		cout << "Testing left button down in player\n";
	}
	
	void Player::Draw()
	{
		// This is a temporary player for testing!
		game->Render->Draw(NULL, framework::Rectangle(game->Render->GetWidth()/2 - 30, game->Render->GetHeight()/2 - 30, 60, 60), Color(0,0,255,255));
	}
}

