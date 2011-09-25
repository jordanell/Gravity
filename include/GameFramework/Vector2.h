/*
 * This is the header for Vector2 class.
 * Author: Jordan Ell
 * Date: 19/09/11
 */

#ifndef VECTOR2_H
#define VECTOR2_H

namespace Game_Framework
{
	class Vector2
	{
		public:
			float X;
			float Y;

			Vector2();
			Vector2(float X, float Y);
		
			float Length();
			void Normalize();
			float Distance(Vector2 vector);
	};
}

#endif

