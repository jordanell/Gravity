/*
 * This is the head file for the Listener class
 * This class will be used to hold pointers to objects that are listening and 
 * what they are listening for.
 * Author: Jordan Ell
 * Date: 09/10/2012
 */

#ifndef LISTENER_H
#define LISTENER_H

#include "GameFramework.h"
#include <list>

using namespace GameFramework;

namespace ManhattanProject
{
    class Listener
    {
		public:
			Listener(Game* game, Event* component, list<Uint8>);
			void Initialize();
			
		private:
			Game* game;
			Event* Component;
			list<Uint8> EventTypes;
			
    };
}

#endif
