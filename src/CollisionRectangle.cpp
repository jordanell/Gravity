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
		Object(game)
	{
		this->X = 0;
		this->Y = 0;
		this->Height = 0;
		this->Width = 0;
		this->Rotation = 0;
	}
	
	CollisionRectangle::CollisionRectangle(int X, int Y, int Height, int Width):
		Object(game)
	{
		this->X = X;
		this->Y = Y;
		this->Height = Height;
		this->Width = Width;
		this->Rotation = 0;
	}
	
	CollisionRectangle::CollisionRectangle(int X, int Y, int Height, int Width, float Rotation):
		Object(game)
	{
		this->X = X;
		this->Y = Y;
		this->Height = Height;
		this->Width = Width;
		this->Rotation = Rotation;
	}
}