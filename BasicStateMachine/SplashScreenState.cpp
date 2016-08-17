#include "SplashScreenState.h"

SplashScreenState::SplashScreenState()
{

}

SplashScreenState::~SplashScreenState()
{

}

void SplashScreenState::initialise()
{
	m_loadTime = 5.0f;
}

void SplashScreenState::terminate()
{

}

void SplashScreenState::loadState()
{
	m_currentTime = 0.0f;
	m_changeState = EGameState::State_None;
}

void SplashScreenState::unloadState()
{

}

void SplashScreenState::updateState(float dt)
{
	m_currentTime += dt / 1000.0f;

	if (m_currentTime > m_loadTime)
	{
		m_changeState = EGameState::State_Menu_Main;
	}
}

void SplashScreenState::renderState()
{
	system("CLS");

	printf("Loading : %i / %i", (int)m_currentTime, (int)m_loadTime);
}