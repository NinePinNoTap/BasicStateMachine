#pragma once

#include "StateMachine.h"
#include "GameTimer.h"

class System
{
public:
	System() { }

	~System() { }

	void initialise()
	{
		m_gameTimer = new GameTimer;

		new InputManager();

		m_stateMachine = new StateMachine;
		m_stateMachine->initialise();
	}

	void terminate()
	{
		if (m_stateMachine)
		{
			m_stateMachine->terminate();
			delete m_stateMachine;
			m_stateMachine = 0;
		}

		if (m_gameTimer)
		{
			delete m_gameTimer;
			m_gameTimer = 0;
		}
	}

	void run()
	{
		bool runApplication = true;
		while (runApplication)
		{
			m_gameTimer->update();
			m_deltaTime = m_gameTimer->getDeltaTime();

			runApplication = m_stateMachine->update(m_deltaTime);
		}

		terminate();
	}

private:
	StateMachine* m_stateMachine = nullptr;
	GameTimer*			m_gameTimer = nullptr;
	float				m_deltaTime = 0;
};