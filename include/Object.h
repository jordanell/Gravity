/*
 * This is the header for the Object class.
 * This class will be used as a base class for all objects inside the game including
 * tiles, containers, items and collision objects.
 * Author: Jordan Ell
 * Date: 06/11/11
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "GameFramework.h"
#include "Camera.h"

using namespace GameFramework;

namespace ManhattanProject
{
	class Object: public DrawableGameComponent
	{
		public:
			Object(Game* game);
		
			virtual void Initialize();
			virtual void Update();	
			virtual void Draw(Camera camera);
			
		private:
			int zindex;
	};
}

#endif
