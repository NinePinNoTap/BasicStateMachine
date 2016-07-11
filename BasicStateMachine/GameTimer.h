#pragma once

#include <Windows.h>

class GameTimer
{
public:
	GameTimer()
	{
		// Check to see if this system supports high performance timers.
		QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);

		// Find out how many times the frequency counter ticks every millisecond.
		m_ticksPerMs = (float)(m_frequency / 1000);

		QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);
	}

	~GameTimer() { }

	void update()
	{
		INT64 currentTime;
		float timeDifference;

		QueryPerformanceCounter((LARGE_INTEGER*)& currentTime);

		timeDifference = (float)(currentTime - m_startTime);

		m_frameTime = timeDifference / m_ticksPerMs;

		m_startTime = currentTime;
	}

	inline float getDeltaTime() { return m_frameTime; }

private:
	INT64	m_frequency;
	float	m_ticksPerMs;
	INT64	m_startTime;
	float	m_frameTime;
};