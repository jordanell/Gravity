/*
 * This is the header for the DrawableGameComponent class.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#ifndef DRAWABLEGAMECOMPONENT_H
#define DRAWABLEGAMECOMPONENT_H

#include "GameComponent.h"

namespace GameFramework
{
	class DrawableGameComponent: public GameComponent
	{
		public:
			bool Visible;

			DrawableGameComponent(Game* game);

			virtual void Initialize();
			virtual void Update();	
			virtual void Draw();	
	};
}

#endif
