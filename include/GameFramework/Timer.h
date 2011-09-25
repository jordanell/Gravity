/*
 * This is the header for the Timer class.
 * Author: Jordan Ell
 * Date: 24/09/11
 */

#ifndef TIMER_H
#define TIMER_H

#include "SDL/SDL.h"

namespace Game_Framework
{
	class Timer
	{
		public:
			Timer();
			
			void Start();
			void Stop();
			void Pause();
			void Unpause();

			int GetTicks();
		
			bool IsStarted();
			bool IsPaused();

		private:
			int startTicks;
			
			int pausedTicks;

			bool paused;
			bool started;
	};
}

#endif
