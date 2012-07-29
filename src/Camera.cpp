/*
 * This is the implementation file for the Manager class.
 * Author: Jordan Ell
 * Date: 11/10/11
 */

#include "Camera.h"

using namespace framework;

namespace ManhattanProject
{
	Camera::Camera()
	{
		Position.X = 0;
		Position.Y = 0;

		Size.X = DEFAULT_WIDTH;
		Size.Y = DEFAULT_HEIGHT;
	}

	Camera::Camera(Vector2 position, Vector2 size)
	{
		Position = position;
		Size = size;
	}

	framework::Rectangle Camera::GetRectangle()
	{
		framework::Rectangle rectangle(Position.X, Position.Y, Size.X, Size.Y);
		return rectangle;
	}
}
