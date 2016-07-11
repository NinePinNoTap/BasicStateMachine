#pragma once

#include "State.h"

class SplashScreenState : public State
{
public:
	void initialise(float loadTime)
	{
		m_loadTime = loadTime;
	}

	virtual void terminate()
	{

	}
	virtual void loadState()
	{
		m_currentTime = 0.0f;
		m_changeState = EGameState::State_None;
	}
	virtual void unloadState()
	{

	}
	virtual void updateState(float dt = 0.0f)
	{
		m_currentTime += dt / 1000.0f;

		if (m_currentTime > m_loadTime)
		{
			m_changeState = EGameState::State_Menu_Main;
		}
	}
	virtual void renderState()
	{
		system("CLS");

		printf("Loading : %i / %i", (int)m_currentTime, (int)m_loadTime);
	}

private:
	float m_loadTime	= 0.0f;
	float m_currentTime	= 0.0f;
};