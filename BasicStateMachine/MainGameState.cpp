#include "MainGameState.h"

MainGameState::MainGameState()
{

}

MainGameState::~MainGameState()
{

}

void MainGameState::initialise()
{

}

void MainGameState::terminate()
{

}

void MainGameState::loadState()
{
	m_changeState = EGameState::State_None;
}

void MainGameState::unloadState()
{

}

void MainGameState::updateState(float dt = 0.0f)
{
	if (InputManager::Instance()->getKeyDown(VK_ESCAPE))
	{
		m_changeState = EGameState::State_Menu_Main;
	}
}

void MainGameState::renderState()
{
	system("CLS");

	printf("Game Loop!\n");
	printf("Escape to return to main menu");
}