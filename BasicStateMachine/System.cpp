#include "System.h"

System::System()
{
}

System::~System()
{ 
}

void System::initialise()
{
	m_gameTimer = new GameTimer;

	new InputManager();

	m_stateMachine = new StateMachine;
	m_stateMachine->initialise();
}

void System::terminate()
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

void System::run()
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