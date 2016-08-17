#pragma once

#include <Windows.h>
#include <vector>

#include "InputManager.h"
#include "State.h"

using namespace std;

class MainMenuState : public State
{
public:
	MainMenuState();
	~MainMenuState();

	void initialise();	
	virtual void terminate();

	virtual void loadState();
	virtual void unloadState();

	virtual void updateState(float dt = 0.0f);
	virtual void renderState();

private:
	void changeSelectedOption(int navigation);
	std::vector<string> m_menuItems;
	int					m_selectedItem = 0;
};