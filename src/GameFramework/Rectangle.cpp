/*
 * This class represents a 2D rectangle.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#include "Rectangle.h"

namespace Game_Framework
{
	Rectangle::Rectangle()
	{
		X = 0;
		Y = 0;
		Height = 0;
		Width = 0;
	}

	Rectangle::Rectangle(int X, int Y, int Height, int Width)
	{
		this->X = X;
		this->Y = Y;
		this->Height = Height;
		this->Width = Width;
	}

	//Returns the bottom location of a rectangle
	int Rectangle::Bottom()
	{
		return Y + Height;
	}

	//Returns the left location of a rectangle
	int Rectangle::Left()
	{
		return X;
	}

	//Returns the right location of a rectangle
	int Rectangle::Right()
	{
		return X + Width;
	}

	//Returns the top location of a rectangle
	int Rectangle::Top()
	{
		return Y;
	}

	//Returns a pointer to a Point which is the centre of the rectangle
	Point* Rectangle::Centre()
	{
		int x = this->Width/2 + this->X;
		int y = this->Height/2 + this->Y;

		Point* point = new Point(x, y);

		return point;
	}
		

	// This checks for a rectangle intersection with an axis aligned rectangle
	bool Rectangle::Intersects(Rectangle* rectangle)
	{
		if(this->Left() > rectangle->Right())
			return false;
		if(this->Right() < rectangle->Left())
			return false;
		if(this->Top() > rectangle->Bottom())
			return false;
		if(this->Bottom() < rectangle->Top())
			return false;

		return true;
	}
}
