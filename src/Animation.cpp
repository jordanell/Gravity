/*
 * This is the implementation file for the Animation class.
 * Author: Jordan Ell
 * Date: 30/10/11
 */

#include "Animation.h"

using namespace GameFramework;

namespace ManhattanProject
{
	Animation::Animation(Game* game)
	{
		this->game = game;
	}

	Animation::Animation(Game* game, Vector2 Position, Texture2D* Texture, int Rows, int Columns, int FramesPerSecond)
	{
		this->game = game;

		this->Position = Position;
		this->Texture = Texture;
		this->Rows = Rows;
		this->Columns = Columns;
		this->FramesPerSecond = FramesPerSecond;

		this->Source = GameFramework::Rectangle(0, 0, Texture->Height, Texture->Width);
		CurrentRow = 0;
		CurrentColumn = 0;
	}

	void Animation::Update(int Ticks)
	{
		if(OldTicks+FramesPerSecond >= Ticks)
		{
			CurrentColumn++;
			if(CurrentColumn >= Columns)
			{
				CurrentColumn = 0;
				CurrentRow = 0;
			}

			this->Source = GameFramework::Rectangle((Texture->Width/Columns)*CurrentColumn,
							   (Texture->Height/Rows)*CurrentRow,
							   (Texture->Width/Columns)*(CurrentColumn+1),
							   (Texture->Height/Rows)*(CurrentRow+1));
		}
	}

	void Animation::Draw()
	{
		game->Render->Draw(Texture, Position, this->Source, Color(255,255,255,255), 0, 1);
	}
}
