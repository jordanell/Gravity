# Gravity

Gravity is a 2D puzzle platform game developed using SDL and OpenGL. This game is cross platform and currently supports Windows, OSX, and Linux.
This game makes use of a custom built 2D game framework which can be found inside of the framework directories.

# Dependencies

The project currently is setup to be developed and run on Ubuntu Linux be can be easily run on other platforms listed above with the following libraries installed.

`SDL 1.2
SDL-image1.2
SDL-ttf2.0
Box2d`

These dependencies also need to be install on Ubuntu to make the game run.

# Building

In order to build the executable, simple run `make` from the root directory. This will create the file bin/Game.

# Running

To run the game, from the root directory simply run the command `bin/Game`. Note: The game's content management system is set up to run from the root directory as of now.
Do not attempt to run the game from any other directory.
