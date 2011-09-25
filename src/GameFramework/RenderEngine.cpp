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
		Init(windowName, fullScreen);
		this->Width = width;
		this->Height = height;
	}

	void RenderEngine::Init(char* windowName, bool fullScreen)
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
		SDL_SetVideoMode(Width,Height,32, SDL_OPENGL);	//Set the last parameter to FULLSCREEN

		glClearColor(1,1,1,1); 				//RGB Alpha
	
		glViewport(0,0,Width,Height);			//Set the viewport for the screen size

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

		glOrtho(0,Width,Height,0,-1,1);	//Reseting the coordinates to be top left
	}

	//Destination rectangle
	void RenderEngine::Draw(Texture2D* tex, Rectangle* rec, Color* color)
	{
		glColor4ub(color->Red,color->Green,color->Blue,color->Alpha);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex->Texture);

		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex2f(rec->X, rec->Y);
		glTexCoord2d(1,0);glVertex2f(rec->X+rec->Width, rec->Y);
		glTexCoord2d(1,1);glVertex2f(rec->X+rec->Width, rec->Y+rec->Height);
		glTexCoord2d(0,1);glVertex2f(rec->X, rec->Y+rec->Height);			
		glEnd();
	}

	void RenderEngine::Draw(Texture2D* tex, Rectangle* rec, Rectangle* source, Color* color)
	{
		if(source == NULL)
			Draw(tex, rec, color);
		else
		{
			Point topLeft(source->X / tex->Width, source->Y / tex->Height);
			Point topRight((source->X + source->Width) / tex->Width, source->Y / tex->Height);
			Point botLeft(source->X / tex->Width, (source->Y + source->Height) / tex->Height);
			Point botRight((source->X + source->Width) / tex->Width, (source->Y + source->Height) / tex->Height);

			glColor4ub(color->Red,color->Green,color->Blue,color->Alpha);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, tex->Texture);

			glBegin(GL_QUADS);
			glTexCoord2d(topLeft.X,topLeft.Y);glVertex2f(rec->X, rec->Y);
			glTexCoord2d(topRight.X,topRight.Y);glVertex2f(rec->X+rec->Width, rec->Y);
			glTexCoord2d(botRight.X,botRight.Y);glVertex2f(rec->X+rec->Width, rec->Y+rec->Height);
			glTexCoord2d(botLeft.X,botRight.Y);glVertex2f(rec->X, rec->Y+rec->Height);			
			glEnd();
		}
	}

	void Draw(Texture2D* tex, Rectangle* rec, Rectangle* source, Color* color, float rotation)
	{
		Point topLeft;
		Point topRight;
		Point botLeft;
		Point botRight;

		if(source == NULL)
		{
			topLeft.X=0; topLeft.Y=0;
			topRight.X=1; topRight.Y=0;
			botLeft.X=0; botLeft.Y=1;
			botRight.X=1; botRight.Y=1;
		}
		else
		{
			topLeft.X=source->X / tex->Width; topLeft.Y=source->Y / tex->Height;
			topRight.X=(source->X + source->Width) / tex->Width; topRight.Y=source->Y / tex->Height;
			botLeft.X=source->X / tex->Width; botLeft.Y=(source->Y + source->Height) / tex->Height;
			botRight.X=(source->X + source->Width) / tex->Width; botRight.Y=(source->Y + source->Height) / tex->Height;
		}

		glColor4ub(color->Red,color->Green,color->Blue,color->Alpha);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex->Texture);

		glBegin(GL_QUADS);
		glTexCoord2d(topLeft.X,topLeft.Y);glVertex2f(rec->X, rec->Y);
		glTexCoord2d(topRight.X,topRight.Y);glVertex2f(rec->X+rec->Width, rec->Y);
		glTexCoord2d(botRight.X,botRight.Y);glVertex2f(rec->X+rec->Width, rec->Y+rec->Height);
		glTexCoord2d(botLeft.X,botRight.Y);glVertex2f(rec->X, rec->Y+rec->Height);			
		glEnd();
	}

	//Destination vector
	void RenderEngine::Draw(Texture2D* tex, Vector2* vec, Color* color)
	{
		glColor4ub(color->Red,color->Green,color->Blue,color->Alpha);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex->Texture);

		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex2f(vec->X, vec->Y);
		glTexCoord2d(1,0);glVertex2f(vec->X+tex->Width, vec->Y);
		glTexCoord2d(1,1);glVertex2f(vec->X+tex->Width, vec->Y+tex->Height);
		glTexCoord2d(0,1);glVertex2f(vec->X, vec->Y+tex->Height);			
		glEnd();
	}

	void RenderEngine::Draw(Texture2D* tex, Vector2* vec, Rectangle* source, Color* color)
	{
		if(source == NULL)
			Draw(tex, vec, color);
		else
		{
			Point topLeft(source->X / tex->Width, source->Y / tex->Height);
			Point topRight((source->X + source->Width) / tex->Width, source->Y / tex->Height);
			Point botLeft(source->X / tex->Width, (source->Y + source->Height) / tex->Height);
			Point botRight((source->X + source->Width) / tex->Width, (source->Y + source->Height) / tex->Height);

			glColor4ub(color->Red,color->Green,color->Blue,color->Alpha);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, tex->Texture);

			glBegin(GL_QUADS);
			glTexCoord2d(topLeft.X,topLeft.Y);glVertex2f(vec->X, vec->Y);
			glTexCoord2d(topRight.X,topRight.Y);glVertex2f(vec->X+tex->Width, vec->Y);
			glTexCoord2d(botRight.X,botRight.Y);glVertex2f(vec->X+tex->Width, vec->Y+tex->Height);
			glTexCoord2d(botLeft.X,botRight.Y);glVertex2f(vec->X, vec->Y+tex->Height);			
			glEnd();
		}
	}

	void RenderEngine::Draw(Texture2D* tex, Vector2* vec, Rectangle* source, Color* color, float rotation)
	{
		Point topLeft;
		Point topRight;
		Point botLeft;
		Point botRight;

		if(source == NULL)
		{
			topLeft.X=0; topLeft.Y=0;
			topRight.X=1; topRight.Y=0;
			botLeft.X=0; botLeft.Y=1;
			botRight.X=1; botRight.Y=1;
		}
		else
		{
			topLeft.X=source->X / tex->Width; topLeft.Y=source->Y / tex->Height;
			topRight.X=(source->X + source->Width) / tex->Width; topRight.Y=source->Y / tex->Height;
			botLeft.X=source->X / tex->Width; botLeft.Y=(source->Y + source->Height) / tex->Height;
			botRight.X=(source->X + source->Width) / tex->Width; botRight.Y=(source->Y + source->Height) / tex->Height;
		}

		glColor4ub(color->Red,color->Green,color->Blue,color->Alpha);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex->Texture);

		glBegin(GL_QUADS);
		glTexCoord2d(topLeft.X,topLeft.Y);glVertex2f(vec->X, vec->Y);
		glTexCoord2d(topRight.X,topRight.Y);glVertex2f(vec->X+tex->Width, vec->Y);
		glTexCoord2d(botRight.X,botRight.Y);glVertex2f(vec->X+tex->Width, vec->Y+tex->Height);
		glTexCoord2d(botLeft.X,botRight.Y);glVertex2f(vec->X, vec->Y+tex->Height);			
		glEnd();
	}

	void RenderEngine::PostDraw()
	{
		glPopMatrix();	//End phase for rendering

		SDL_GL_SwapBuffers();
	}
}
