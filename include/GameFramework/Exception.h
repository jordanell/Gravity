/*
 * This is the header for the Exception class.
 * Author: Jordan Ell
 * Date: 26/09/11
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

namespace GameFramework
{
	class Exception
	{
		public:
			Exception(const char* Msg, int n, const char* File, int nLine);

			virtual string Display();

		protected:
			string Message;
			int ErrorValue;
			string File;
			int LineNum;
	};
}

#endif
