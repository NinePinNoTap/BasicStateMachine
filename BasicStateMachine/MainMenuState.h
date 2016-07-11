#pragma once

#include <Windows.h>
#include <vector>

#include "InputManager.h"
#include "State.h"

using namespace std;

class MainMenuState : public State
{
public:
	void initialise()
	{
		m_menuItems.push_back("Play Game");
		m_menuItems.push_back("Show Splash Screen");
		m_menuItems.push_back("Exit Game");
	}
	
	virtual void terminate()
	{
		m_menuItems.clear();
	}
	virtual void loadState()
	{
		m_changeState = EGameState::State_None;
		m_selectedItem = 0;
	}
	virtual void unloadState()
	{

	}
	virtual void updateState(float dt = 0.0f)
	{
		if (InputManager::Instance()->getKeyDown(VK_UP))
		{
			m_selectedItem--;
			if (m_selectedItem < 0)
			{
				m_selectedItem = 0;
			}
		}
		else if (InputManager::Instance()->getKeyDown(VK_DOWN))
		{
			m_selectedItem++;
			if (m_selectedItem >= m_menuItems.size())
			{
				m_selectedItem = m_menuItems.size() - 1;
			}
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

	virtual void renderState()
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

private:
	std::vector<string> m_menuItems;
	int					m_selectedItem = 0;
};