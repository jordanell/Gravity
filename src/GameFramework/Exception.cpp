/*
 * This is the definition for the ContentManager class.
 * Author: Jordan Ell
 * Date: 26/09/11
 */

#include "Exception.h"

namespace Game_Framework
{
	Exception::Exception(const char* Msg, int n, const char* File, int nLine)
	{
		Message = Msg;
		ErrorValue = n;
		this->File = File;
		LineNum = nLine;
	}

	string Exception::Display()
	{
		ostringstream out;
		out << "Error <" << Message
		    << " - value is " << ErrorValue
		    << ">\n";
		out << " @" << File << "-" << LineNum << endl;
		return out.str();
	}
}
