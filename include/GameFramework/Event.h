#ifndef _EVENT_H_
    #define _EVENT_H_
#ifdef __linux__
	#include "SDL/SDL.h"
#else
	#include "SDL.h"
#endif

namespace GameFramework 
{ 
    class Event 
    {
        public: 
			Event();
			virtual ~Event();
			virtual void OnEvent(SDL_Event* Event); 
			virtual void OnInputFocus();
			virtual void OnInputBlur();
			virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
			virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
			virtual void OnMouseFocus();
			virtual void OnMouseBlur();
			virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
			virtual void OnMouseWheel(bool Up, bool Down);    //Not implemented
			virtual void OnLButtonDown(int mX, int mY);
			virtual void OnLButtonUp(int mX, int mY);
			virtual void OnRButtonDown(int mX, int mY);
			virtual void OnRButtonUp(int mX, int mY);
			virtual void OnMButtonDown(int mX, int mY);
			virtual void OnMButtonUp(int mX, int mY);
			virtual void OnMinimize();
			virtual void OnRestore();
			virtual void OnResize(int w,int h);
			virtual void OnExpose();
			virtual void OnExit();
			virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
        protected:
                       
    };
}
#endif
