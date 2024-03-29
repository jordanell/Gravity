/*
 * This class represents a Timer.
 * Author: Jordan Ell
 * Date: 24/09/11
 */

#include "Timer.h"

namespace framework
{
	Timer::Timer()
	{
		startTicks = 0;
		pausedTicks = 0;
		paused = false;
		started = false;
	}

	void Timer::Start()
	{
		started = true;
		paused = false;
		startTicks = SDL_GetTicks();
	}

	void Timer::Stop()
	{
		started = false;
		paused = false;
	}

	void Timer::Pause()
	{
		if(started && !paused)
		{
			paused = true;
			pausedTicks = SDL_GetTicks() - startTicks;
		}	
	}

	void Timer::Unpause()
	{
		if(paused)
		{
			paused = false;
			startTicks = SDL_GetTicks() - pausedTicks;
			pausedTicks = 0;
		}
	}

	int Timer::GetTicks()
	{
		if(started)
		{
			if(paused)
				return pausedTicks;
			else
				return SDL_GetTicks() - startTicks;
		}

		return 0;
	}

	bool Timer::IsStarted()
	{
		return started;
	}

	bool Timer::IsPaused()
	{
		return paused;
	}
}
