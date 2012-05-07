/*
 * This is the implementation file for the Scene class.
 * Author: Jordan Ell
 * Date: 20/10/11
 */

#include "CollisionRectangle.h"

using namespace GameFramework;

namespace ManhattanProject
{
	CollisionRectangle::CollisionRectangle(Game* game):
		MapObject(game)
	{
		this->game = game;

        this->Position = Vector2();
		this->Height = 0;
		this->Width = 0;
		this->Rotation = 0;
	}

	CollisionRectangle::CollisionRectangle(Game* game, Vector2 pos, int Height, int Width):
		MapObject(game)
	{
		this->game = game;

		this->Position = pos;
		this->Height = Height;
		this->Width = Width;
		this->Rotation = 0;
	}

	CollisionRectangle::CollisionRectangle(Game* game, Vector2 pos, int Height, int Width, float Rotation):
		MapObject(game)
	{
		this->game = game;

		this->Position = pos;
		this->Height = Height;
		this->Width = Width;
		this->Rotation = Rotation;
	}

	void CollisionRectangle::Draw(Camera camera)
	{
		// Draw this collision
		game->Render->Draw(NULL, GameFramework::Rectangle(Position.X-camera.Position.X, Position.Y-camera.Position.Y, Height, Width), Color(255,0,0,125));
	}
}
