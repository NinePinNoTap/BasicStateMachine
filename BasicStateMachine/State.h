#pragma once

#include <iostream>
#include <stdlib.h>

enum EGameState
{
	State_None,
	State_Menu_Splash,
	State_Menu_Main,
	State_Game_Main,
	State_Exit
};

class State
{
public:
	virtual void terminate() = 0;

	virtual void loadState() = 0;
	virtual void unloadState() = 0;

	virtual void updateState(float dt = 0.0f) = 0;
	virtual void renderState() = 0;

	inline EGameState getNextState() { return m_changeState; }

protected:
	EGameState m_changeState = EGameState::State_None;
};