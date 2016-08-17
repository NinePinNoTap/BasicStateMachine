#include "MainMenuState.h"
#include "Helper.h"

using namespace MathUtility;

MainMenuState::MainMenuState()
{

}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::initialise()
{
	m_menuItems.push_back("Play Game");
	m_menuItems.push_back("Show Splash Screen");
	m_menuItems.push_back("Exit Game");
}

void MainMenuState::terminate()
{
	m_menuItems.clear();
}

void MainMenuState::loadState()
{
	m_changeState = EGameState::State_None;
	m_selectedItem = 0;
}

void MainMenuState::unloadState()
{

}

void MainMenuState::updateState(float dt = 0.0f)
{
	if (InputManager::Instance()->getKeyDown(VK_UP))
	{
		changeSelectedOption(-1);
	}
	else if (InputManager::Instance()->getKeyDown(VK_DOWN))
	{
		changeSelectedOption(1);
	}

	if (InputManager::Instance()->getKeyDown(VK_RETURN))
	{
		if (m_selectedItem == 0)
			m_changeState = EGameState::State_Game_Main;
		else if (m_selectedItem == 1)
			m_changeState = EGameState::State_Menu_Splash;
		else if (m_selectedItem == 2)
			m_changeState = EGameState::State_Exit;
	}
}

void MainMenuState::renderState()
{
	system("CLS");

	if (m_menuItems.empty())
		return;

	for (unsigned int i = 0; i < m_menuItems.size(); i++)
	{
		if (i == m_selectedItem)
		{
			printf("> %s\n", m_menuItems[i].c_str());
		}
		else
		{
			printf("%s\n", m_menuItems[i].c_str());
		}
	}
}

void MainMenuState::changeSelectedOption(int navigation)
{
	m_selectedItem += navigation;

	Wrap<int>(m_selectedItem, 0, m_menuItems.size() - 1);
}