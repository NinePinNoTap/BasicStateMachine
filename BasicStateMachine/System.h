#pragma once

#include "StateMachine.h"
#include "GameTimer.h"

class System
{
public:
	System();
	~System();

	void initialise();

	void terminate();

	void run();

private:
	StateMachine		*m_stateMachine	= nullptr;
	GameTimer			*m_gameTimer	= nullptr;
	float				m_deltaTime		= 0;
};