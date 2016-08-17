#pragma once

#include <map>

#include "GameTimer.h"
#include "InputManager.h"
#include "State.h"

#include "SplashScreenState.h"
#include "MainMenuState.h"
#include "MainGameState.h"

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void initialise();
	void terminate();

	bool update(float dt);

private:
	bool updateState();

	std::map<EGameState, State*> m_states;

	SplashScreenState	*m_splashScreen	= nullptr;
	MainMenuState		*m_mainMenu		= nullptr;
	MainGameState		*m_mainGame		= nullptr;

	State*				m_state		= nullptr;
	EGameState			m_gameState = EGameState::State_Menu_Splash;
};