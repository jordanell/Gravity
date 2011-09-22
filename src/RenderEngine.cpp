/*
 * This class represents a RenderEngine.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#include "RenderEngine.h"

namespace Game_Framework
{
	RenderEngine::RenderEngine(char* windowName, int width, int height, bool fullScreen)
	{
		Init(windowName, width, height, fullScreen);
		this->width = width;
		this->height = height;
	}

	void RenderEngine::Init(char* windowName, int width, int height, bool fullScreen)
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 8);

		SDL_WM_SetCaption(windowName, NULL);
		SDL_SetVideoMode(width,height,32, SDL_OPENGL);	//Set the last parameter to FULLSCREEN

		glClearColor(1,1,1,1); 				//RGB Alpha
	
		glViewport(0,0,width,height);			//Set the viewport for the screen size

		glShadeModel(GL_SMOOTH);

		glMatrixMode(GL_PROJECTION);			//Set openGl to 2D rendering
		glLoadIdentity();

		glDisable(GL_DEPTH_TEST);			//Disables objects that are drawn behind others.
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void RenderEngine::PreDraw()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();	//Start phase for rendering

		glOrtho(0,width,height,0,-1,1);	//Reseting the coordinates to be top left
	}

	void RenderEngine::Draw()
	{

	}

	void RenderEngine::PostDraw()
	{
		glPopMatrix();	//End phase for rendering

		SDL_GL_SwapBuffers();
	}
}
