#pragma once

#include "InputManager.h"
#include "State.h"

class MainGameState : public State
{
public:
	virtual void terminate()
	{

	}
	virtual void loadState()
	{
		m_changeState = EGameState::State_None;
	}
	virtual void unloadState()
	{

	}
	virtual void updateState(float dt = 0.0f)
	{
		if (InputManager::Instance()->getKeyDown(VK_ESCAPE))
		{
			m_changeState = EGameState::State_Menu_Main;
		}
	}
	virtual void renderState()
	{
		system("CLS");

		printf("Game Loop!\n");
		printf("Escape to return to main menu");
	}

private:
};