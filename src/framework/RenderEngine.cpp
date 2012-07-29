/*
 * This class represents a RenderEngine.
 * Author: Jordan Ell
 * Date: 21/09/11
 */

#include "RenderEngine.h"
#include <iostream>

namespace framework
{
	RenderEngine::RenderEngine(const char* windowName, int width, int height, bool fullScreen)
	{
		this->Width = width;
		this->Height = height;
		this->FullScreen = fullScreen;
		Init(windowName, fullScreen);
	}

	void RenderEngine::Init(const char* windowName, bool fullScreen)
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
		if(!fullScreen)
			SDL_SetVideoMode(Width,Height,32, SDL_OPENGL);
		else
			SDL_SetVideoMode(Width,Height,32, SDL_OPENGL | SDL_FULLSCREEN);

        // Initialize TTF
        TTF_Init();


		glClearColor(0,0,0,1); 				//RGB Alpha

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
	void RenderEngine::Draw(Texture2D* tex, Rectangle rec, Color color)
	{
		glColor4ub(color.Red,color.Green,color.Blue,color.Alpha);
		if(tex != NULL)
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, tex->Texture);
			glBegin(GL_QUADS);
			glTexCoord2d(0,0);glVertex2f(rec.X, rec.Y);
			glTexCoord2d(1,0);glVertex2f(rec.X+rec.Width, rec.Y);
			glTexCoord2d(1,1);glVertex2f(rec.X+rec.Width, rec.Y+rec.Height);
			glTexCoord2d(0,1);glVertex2f(rec.X, rec.Y+rec.Height);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
		else
		{
			glBegin(GL_QUADS);
			glVertex2f(rec.X, rec.Y);
			glVertex2f(rec.X+rec.Width, rec.Y);
			glVertex2f(rec.X+rec.Width, rec.Y+rec.Height);
			glVertex2f(rec.X, rec.Y+rec.Height);
			glEnd();
		}
	}

	void Draw(Texture2D* tex, Rectangle rec, Color color, float rotation, float scale)
	{
		Point topLeft;
		Point topRight;
		Point botLeft;
		Point botRight;

		topLeft.X=rec.X; topLeft.Y = rec.Y;
		topRight.X=rec.X+rec.Width; topRight.Y=rec.Y;
		botLeft.X=rec.X; botLeft.Y=rec.Y+rec.Height;
		botRight.X=rec.X+rec.Width; botRight.Y=rec.Y+rec.Height;

		glColor4ub(color.Red,color.Green,color.Blue,color.Alpha);
		glEnable(GL_TEXTURE_2D);
		Point* point = rec.Centre();
		glTranslatef(point->X, point->Y, 0.0);
		glRotatef(45,0.0,0.0,-1.0);
		glTranslatef(-point->X, -point->Y, 0.0);
		glBindTexture(GL_TEXTURE_2D, tex->Texture);

		glBegin(GL_QUADS);
		glTexCoord2d(topLeft.X,topLeft.Y);glVertex2f(rec.X, rec.Y);
		glTexCoord2d(topRight.X,topRight.Y);glVertex2f((rec.X+rec.Width)*scale, rec.Y);
		glTexCoord2d(botRight.X,botRight.Y);glVertex2f((rec.X+rec.Width)*scale, (rec.Y+rec.Height)*scale);
		glTexCoord2d(botLeft.X,botRight.Y);glVertex2f(rec.X, (rec.Y+rec.Height)*scale);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	void Draw(Texture2D* tex, Rectangle rec, Rectangle source, Color color, float rotation, float scale)
	{
		Point topLeft;
		Point topRight;
		Point botLeft;
		Point botRight;

		topLeft.X=(float)source.X / (float)tex->Width; topLeft.Y=(float)source.Y / (float)tex->Height;
		topRight.X=((float)source.X + (float)source.Width) / (float)tex->Width; topRight.Y=(float)source.Y / (float)tex->Height;
		botLeft.X=(float)source.X / (float)tex->Width; botLeft.Y=((float)source.Y + (float)source.Height) / (float)tex->Height;
		botRight.X=((float)source.X + (float)source.Width) / (float)tex->Width; botRight.Y=((float)source.Y + (float)source.Height) / (float)tex->Height;

		glColor4ub(color.Red,color.Green,color.Blue,color.Alpha);
		glEnable(GL_TEXTURE_2D);
		Point* point = rec.Centre();
		glTranslatef(point->X, point->Y, 0.0);
		glRotatef(45,0.0,0.0,-1.0);
		glTranslatef(-point->X, -point->Y, 0.0);
		glBindTexture(GL_TEXTURE_2D, tex->Texture);

		glBegin(GL_QUADS);
		glTexCoord2d(topLeft.X,topLeft.Y);glVertex2f(rec.X, rec.Y);
		glTexCoord2d(topRight.X,topRight.Y);glVertex2f((rec.X+rec.Width)*scale, rec.Y);
		glTexCoord2d(botRight.X,botRight.Y);glVertex2f((rec.X+rec.Width)*scale, (rec.Y+rec.Height)*scale);
		glTexCoord2d(botLeft.X,botRight.Y);glVertex2f(rec.X, (rec.Y+rec.Height)*scale);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	//Destination vector
	void RenderEngine::Draw(Texture2D* tex, Vector2 vec, Color color)
	{
		glColor4ub(color.Red,color.Green,color.Blue,color.Alpha);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex->Texture);

		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex2f(vec.X, vec.Y);
		glTexCoord2d(1,0);glVertex2f(vec.X+tex->Width, vec.Y);
		glTexCoord2d(1,1);glVertex2f(vec.X+tex->Width, vec.Y+tex->Height);
		glTexCoord2d(0,1);glVertex2f(vec.X, vec.Y+tex->Height);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	void RenderEngine::Draw(Texture2D* tex, Vector2 vec, Color color, float rotation, float scale)
	{
		Point topLeft;
		Point topRight;
		Point botLeft;
		Point botRight;

		topLeft.X=vec.X; topLeft.Y = vec.Y;
		topRight.X=vec.X+tex->Width; topRight.Y=vec.Y;
		botLeft.X=vec.X; botLeft.Y=vec.Y+tex->Height;
		botRight.X=vec.X+tex->Width; botRight.Y=vec.Y+tex->Height;

		glColor4ub(color.Red,color.Green,color.Blue,color.Alpha);
		glEnable(GL_TEXTURE_2D);
		//This may cause problems in the future
		Point* point = Rectangle(topLeft.X, topLeft.Y, tex->Height, tex->Width).Centre();
		glTranslatef(point->X, point->Y, 0.0);
		glRotatef(45,0.0,0.0,-1.0);
		glTranslatef(-point->X, -point->Y, 0.0);
		glBindTexture(GL_TEXTURE_2D, tex->Texture);

		glBegin(GL_QUADS);
		glTexCoord2d(topLeft.X,topLeft.Y);glVertex2f(vec.X, vec.Y);
		glTexCoord2d(topRight.X,topRight.Y);glVertex2f((vec.X+tex->Width)*scale, vec.Y);
		glTexCoord2d(botRight.X,botRight.Y);glVertex2f((vec.X+tex->Width)*scale, (vec.Y+tex->Height)*scale);
		glTexCoord2d(botLeft.X,botRight.Y);glVertex2f(vec.X, (vec.Y+tex->Height)*scale);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	void RenderEngine::Draw(Texture2D* tex, Vector2 vec, Rectangle source, Color color, float rotation, float scale)
	{
		Point topLeft;
		Point topRight;
		Point botLeft;
		Point botRight;

		topLeft.X=(float)source.X / (float)tex->Width; topLeft.Y=(float)source.Y / (float)tex->Height;
		topRight.X=((float)source.X + (float)source.Width) / (float)tex->Width; topRight.Y=(float)source.Y / (float)tex->Height;
		botLeft.X=(float)source.X / (float)tex->Width; botLeft.Y=((float)source.Y + (float)source.Height) / (float)tex->Height;
		botRight.X=((float)source.X + (float)source.Width) / (float)tex->Width; botRight.Y=((float)source.Y + (float)source.Height) / (float)tex->Height;

		glColor4ub(color.Red,color.Green,color.Blue,color.Alpha);
		glEnable(GL_TEXTURE_2D);
		//This may cause problems in the future
		Point* point = source.Centre();
		glTranslatef(point->X, point->Y, 0.0);
		glRotatef(45,0.0,0.0,-1.0);
		glTranslatef(-point->X, -point->Y, 0.0);
		glBindTexture(GL_TEXTURE_2D, tex->Texture);

		glBegin(GL_QUADS);
		glTexCoord2d(topLeft.X,topLeft.Y);glVertex2f(vec.X, vec.Y);
		glTexCoord2d(topRight.X,topRight.Y);glVertex2f((vec.X+tex->Width)*scale, vec.Y);
		glTexCoord2d(botRight.X,botRight.Y);glVertex2f((vec.X+tex->Width)*scale, (vec.Y+tex->Height)*scale);
		glTexCoord2d(botLeft.X,botRight.Y);glVertex2f(vec.X, (vec.Y+tex->Height)*scale);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	void RenderEngine::PostDraw()
	{
		glPopMatrix();	//End phase for rendering

		SDL_GL_SwapBuffers();

		SDL_Delay(1);
	}

	bool RenderEngine::GetFullScreen()
	{
		return this->FullScreen;
	}

	int RenderEngine::GetWidth()
	{
		return this->Width;
	}

	int RenderEngine::GetHeight()
	{
		return this->Height;
	}

	void RenderEngine::SetCaption(const char* windowName)
	{
		SDL_WM_SetCaption(windowName, NULL);
	}

	void RenderEngine::SetResolution(int width, int height)
	{
		this->Width = width;
		this->Height = height;

		if(!FullScreen)
			SDL_SetVideoMode(Width,Height,32, SDL_OPENGL);
		else
			SDL_SetVideoMode(Width,Height,32, SDL_OPENGL | SDL_FULLSCREEN);

		glClearColor(0,0,0,1);

		glViewport(0,0,Width,Height);
	}

	void RenderEngine::SetFullScreen(bool fullScreen)
	{
		this->FullScreen = fullScreen;

		if(!FullScreen)
			SDL_SetVideoMode(Width,Height,32, SDL_OPENGL);
		else
			SDL_SetVideoMode(Width,Height,32, SDL_OPENGL | SDL_FULLSCREEN);
	}
	
	int RenderEngine::ConvertTextToTexture(SDL_Surface *surface)
	{
	    GLuint texture;
	 
	    if(surface)
	    {
	        glGenTextures(1, &texture);
	        glBindTexture(GL_TEXTURE_2D, texture);
	 
	        glTexImage2D(GL_TEXTURE_2D, 0, 3, surface->w, surface->h,
				0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
	 
	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	        
	        SDL_FreeSurface(surface);
	    }
	    else
	    {
	        SDL_Quit();
	        exit(-1);
	    }
	 
	    return texture;
	}

    void RenderEngine::Write(TTF_Font* font, Rectangle rec, char text[], Color color)
    {
		SDL_Color sColor = {color.Red, color.Green, color.Blue, color.Alpha};
		SDL_Surface* message = TTF_RenderText_Blended(font, text, sColor);
		message = SDL_DisplayFormatAlpha(message);
		
		unsigned object(0);
		glGenTextures(1, &object);
		glBindTexture(GL_TEXTURE_2D, object);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, message->w, message->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, message->pixels);
		
		glColor4ub(color.Red,color.Green,color.Blue,color.Alpha);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, object);

		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex2f(rec.X, rec.Y);
		glTexCoord2d(1,0);glVertex2f(rec.X+rec.Width, rec.Y);
		glTexCoord2d(1,1);glVertex2f(rec.X+rec.Width, rec.Y+rec.Height);
		glTexCoord2d(0,1);glVertex2f(rec.X, rec.Y+rec.Height);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		SDL_FreeSurface(message);
    }
}
