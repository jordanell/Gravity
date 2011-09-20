/*
 * This class represents a 2D vector.
 * Author: Jordan Ell
 * Date: 19/09/11
 */

#include <math.h>

class Vector2 {
	public:
		float X;
		float Y;
		
		// An initialized Vector2 without arguments creates a zero vector
		Vector2()
		{
			X = 0;
			Y = 0;
		}

		// Overloaded constructor to enable initial variable setting
		Vector2(float X, float Y)
		{
			this->X = X;
			this->Y = Y;
		}

		// Returns the length of the vector
		float Length()
		{
			return sqrt(X*X + Y*Y);
		}

		// This normalizes the vector to prevent movement issues
		void Normalize()
		{
			float length = this->Length();

			if(!length)
			{
				X = X/length;
				Y = Y/length;
			}
		}

		// This function returns the distance between itself and a second vector
		float Distance(Vector2 vector)
		{
			Vector2 distVect(vector.X - this->X, vector.Y - this->Y);
			return distVect.Length();
		}
};
