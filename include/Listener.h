/*
 * This is the head file for the Listener class
 * This class will be used to hold pointers to objects that are listening and 
 * what they are listening for.
 * Author: Jordan Ell
 * Date: 09/10/2012
 */

#ifndef LISTENER_H
#define LISTENER_H

#include "framework.h"
#include <list>

using namespace framework;

namespace gravity
{
    class Listener
    {
		public:
			InputEvent* Component;
			
			Listener(Game* game, InputEvent* component, list<Uint8>);
			void Initialize();
			
			bool IsListeningOnEvent(Uint8 EventType);
			
		private:
			Game* game;
			list<Uint8> EventTypes;
			
    };
}

#endif
