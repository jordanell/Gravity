/*
 * This is the header for the Camera class.
 * This class is used to "move" tiles around the view port area
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "GameFramework.h"

using namespace GameFramework;

namespace ManhattanProject
{
	class Camera
	{
	public:
		Camera();
		Camera(Vector2 position, Vector2 size);
		
		Vector2 Position;
		Vector2 Size;
		
		Rectangle GetRectangle();
	};
}

#endif
