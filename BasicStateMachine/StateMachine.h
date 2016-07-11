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
	StateMachine()
	{

	}

	~StateMachine()
	{

	}

	void initialise()
	{
		// Initialise States
		m_splashScreen = new SplashScreenState;
		m_splashScreen->initialise(5);

		m_mainMenu = new MainMenuState;
		m_mainMenu->initialise();

		m_mainGame = new MainGameState;

		// Add to map
		m_states[EGameState::State_Menu_Splash] = m_splashScreen;
		m_states[EGameState::State_Menu_Main] = m_mainMenu;
		m_states[EGameState::State_Game_Main] = m_mainGame;

		// Initial state
		m_state = m_states[m_gameState];
		m_state->loadState();
	}

	void terminate()
	{
		for (std::map<EGameState, State*>::iterator it = m_states.begin(); it != m_states.end(); it++)
		{
			it->second->terminate();
			delete it->second;
		}

		m_states.clear();

		m_state = 0;
	}

	bool update(float dt)
	{
		bool result;

		//
		// States
		//

		result = updateState();
		if (!result)
		{
			return false;
		}

		m_state->updateState(dt);
		m_state->renderState();

		return true;
	}

private:
	bool updateState()
	{
		EGameState newGameState = m_state->getNextState();
		if (newGameState == EGameState::State_None)
		{
			return true;
		}

		if (newGameState == EGameState::State_Exit)
		{
			return false;
		}

		//
		// Unload Current State
		//
		if (m_state)
		{
			m_state->unloadState();
		}

		// 
		// Change to New State
		//

		m_state = m_states[newGameState];
		m_state->loadState();

		m_gameState = newGameState;

		return true;
	}

	std::map<EGameState, State*> m_states;

	SplashScreenState*	m_splashScreen	= nullptr;
	MainMenuState*		m_mainMenu		= nullptr;
	MainGameState*		m_mainGame		= nullptr;

	State*				m_state		= nullptr;
	EGameState			m_gameState = EGameState::State_Menu_Splash;
};