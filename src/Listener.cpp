/*
 * This is the implementation file for the Listener class
 * This class will be used to hold pointers to objects that are listening and 
 * what they are listening for.
 * Author: Jordan Ell
 * Date: 09/10/2012
 */

#include "Listener.h"

using namespace GameFramework;

namespace ManhattanProject
{
    Listener::Listener(Game* game, InputEvent* component, list<Uint8> events)
	{
		this->game = game;
		this->Component = component;
		this->EventTypes = events;
	}
}
