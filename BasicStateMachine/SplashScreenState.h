#pragma once

#include "State.h"

class SplashScreenState : public State
{
public:
	SplashScreenState();
	~SplashScreenState();

	virtual void initialise();
	virtual void terminate();

	virtual void loadState();
	virtual void unloadState();
	virtual void updateState(float dt = 0.0f);
	virtual void renderState();

private:
	float	m_loadTime		= 0.0f;
	float	m_currentTime	= 0.0f;
};