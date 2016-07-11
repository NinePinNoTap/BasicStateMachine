#pragma once

#include <Windows.h>

#include "Singleton.h"

class InputManager : public Singleton<InputManager>
{
public:
	InputManager();
	~InputManager();

	// Getters
	bool getKeyDown(unsigned int key);
	bool getKey(unsigned int key);

private:
	bool m_keys[256];
};