/*
 * This is the header for the MapObject class.
 * This class will be used as a base class for all objects inside the game map including
 * tiles, containers, items and collision objects.
 * Author: Jordan Ell
 * Date: 06/11/11
 */

#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "GameFramework.h"
#include "Camera.h"

using namespace GameFramework;

namespace ManhattanProject
{
	class MapObject: public DrawableGameComponent
	{
		public:
			MapObject(Game* game);
		
			virtual void Initialize();
			virtual void Update();	
			virtual void Draw(Camera camera);
			
			inline bool operator<(const MapObject &) const;
			
		private:
			int zindex;
	};
}

#endif
