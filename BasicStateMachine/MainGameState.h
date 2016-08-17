#pragma once

#include "InputManager.h"
#include "State.h"

class MainGameState : public State
{
public:
	MainGameState();
	~MainGameState();

	virtual void initialise();
	virtual void terminate();

	virtual void loadState();
	virtual void unloadState();

	virtual void updateState(float dt = 0.0f);
	virtual void renderState();

private:
};