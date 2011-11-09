/*
 * This is the header for the Item class.
 * This class is used to hold the constants for the game not the library.
 * Author: Jordan Ell
 * Date: 30/10/11
 */

#ifndef GAMEDEFINES_H
#define GAMEDEFINES_H

// Item Constants
const int ITEM_NAME = 30;
const int ITEM_DESCRIPTION = 100;

// Container Constants
const int CONTAINER_NAME = 30;
const int CONTAINER_DESCRIPTION = 75;

// Fix the Windows Rectangle issue
#ifdef _WIN32 || _WIN64
	#define Rectangle GameFramework::Rectangle
#endif

#endif
