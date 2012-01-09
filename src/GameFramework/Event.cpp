#include "Event.h"
 
namespace GameFramework 
{
    Event::Event() {
    }
     
    void Event::OnEvent(SDL_Event* Event) {
        switch(Event->type) {
            case SDL_ACTIVEEVENT: {
                switch(Event->active.state) {
                    case SDL_APPMOUSEFOCUS: {
                        if ( Event->active.gain )    OnMouseFocus();
                        else                OnMouseBlur();
     
                        break;
                    }
                    case SDL_APPINPUTFOCUS: {
                        if ( Event->active.gain )    OnInputFocus();
                        else                OnInputBlur();
     
                        break;
                    }
                    case SDL_APPACTIVE:    {
                        if ( Event->active.gain )    OnRestore();
                        else                OnMinimize();
     
                        break;
                    }
                }
                break;
            }
     
            case SDL_KEYDOWN: {
                OnKeyDown(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.unicode);
                break;
            }
     
            case SDL_KEYUP: {
                OnKeyUp(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.unicode);
                break;
            }
     
            case SDL_MOUSEMOTION: {
                OnMouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
                break;
            }
     
            case SDL_MOUSEBUTTONDOWN: {
                switch(Event->button.button) {
                    case SDL_BUTTON_LEFT: {
                        OnLButtonDown(Event->button.x,Event->button.y);
                        break;
                    }
                    case SDL_BUTTON_RIGHT: {
                        OnRButtonDown(Event->button.x,Event->button.y);
                        break;
                    }
                    case SDL_BUTTON_MIDDLE: {
                        OnMButtonDown(Event->button.x,Event->button.y);
                        break;
                    }
                }
                break;
            }
     
            case SDL_MOUSEBUTTONUP:    {
                switch(Event->button.button) {
                    case SDL_BUTTON_LEFT: {
                        OnLButtonUp(Event->button.x,Event->button.y);
                        break;
                    }
                    case SDL_BUTTON_RIGHT: {
                        OnRButtonUp(Event->button.x,Event->button.y);
                        break;
                    }
                    case SDL_BUTTON_MIDDLE: {
                        OnMButtonUp(Event->button.x,Event->button.y);
                        break;
                    }
                }
                break;
            }

            case SDL_QUIT: {
                OnExit();
                break;
            }
     
            case SDL_SYSWMEVENT: {
                //Ignore
                break;
            }
     
            case SDL_VIDEORESIZE: {
                OnResize(Event->resize.w,Event->resize.h);
                break;
            }
     
            case SDL_VIDEOEXPOSE: {
                OnExpose();
                break;
            }
     
            default: {
                OnUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
                break;
            }
        }
    }
     
    void Event::OnInputFocus() {
        //Pure virtual, do nothing
    }
     
    void Event::OnInputBlur() {
        //Pure virtual, do nothing
    }
     
    void Event::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
        //Pure virtual, do nothing
    }
     
    void Event::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
        //Pure virtual, do nothing
    }
     
    void Event::OnMouseFocus() {
        //Pure virtual, do nothing
    }
     
    void Event::OnMouseBlur() {
        //Pure virtual, do nothing
    }
     
    void Event::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
        //Pure virtual, do nothing
    }
     
    void Event::OnMouseWheel(bool Up, bool Down) {
        //Pure virtual, do nothing
    }
     
    void Event::OnLButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }
     
    void Event::OnLButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }
     
    void Event::OnRButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }
     
    void Event::OnRButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }
     
    void Event::OnMButtonDown(int mX, int mY) {
        //Pure virtual, do nothing
    }
     
    void Event::OnMButtonUp(int mX, int mY) {
        //Pure virtual, do nothing
    }
    
    void Event::OnMinimize() {
        //Pure virtual, do nothing
    }
     
    void Event::OnRestore() {
        //Pure virtual, do nothing
    }
     
    void Event::OnResize(int w,int h) {
        //Pure virtual, do nothing
    }
     
    void Event::OnExpose() {
        //Pure virtual, do nothing
    }
     
    void Event::OnExit() {
        //Pure virtual, do nothing
    }
     
    void Event::OnUser(Uint8 type, int code, void* data1, void* data2) {
        //Pure virtual, do nothing
    }
}
