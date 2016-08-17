#pragma once

#include <Windows.h>

class GameTimer
{
public:
	GameTimer();
	~GameTimer();

	void update();

	inline float getDeltaTime() { return m_frameTime; }

private:
	INT64	m_frequency;
	float	m_ticksPerMs;
	INT64	m_startTime;
	float	m_frameTime;
};