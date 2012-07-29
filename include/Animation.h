/*
 * This is the header for the Animation class.
 * This class will handle sprite sheets and animate them
 * Author: Jordan Ell
 * Date: 30/10/11
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include "framework.h"

using namespace framework;

namespace ManhattanProject
{
	class Animation
	{
		public:
			Animation(Game* game);
			Animation(Game* game, Vector2 Position, Texture2D* Texture, int Rows, int Columns, int FramesPerSecond);

			Vector2 Position;

			void Update(int Ticks);
			void Draw();

		private:
			Game* game;
			Texture2D* Texture;
			int Rows;
			int Columns;

			// Keep track of the current frame
			int CurrentRow;
			int CurrentColumn;
			int FramesPerSecond;
			int OldTicks;
			framework::Rectangle Source;
	};
}

#endif
