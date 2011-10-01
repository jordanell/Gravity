/*
 * This is the main function for the game. Here a Manager is created and the game loop begins.
 * The Initialize method also gets called within Run.
 */

#include "Manager.h"

using namespace ManhattanProject;

int main(int argc, char* args[])
{
	Manager* game = new Manager();
	game->Run();

	return 0;
}
