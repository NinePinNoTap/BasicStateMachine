#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

bool InputManager::getKey(unsigned int key)
{
	// Check the status of the key and store it
	if (GetAsyncKeyState(key))
	{
		m_keys[key] = true;
	}
	else
	{
		m_keys[key] = false;
	}

	return m_keys[key];
}

bool InputManager::getKeyDown(unsigned int key)
{
	// If the key we want is down
	if (GetAsyncKeyState(key))
	{
		// If the key is already flagged as down
		if (m_keys[key])
		{
			return false;
		}
		else if (!m_keys[key])
		{
			// Key not down so flag that it is
			m_keys[key] = true;
			return true;
		}
	}
	else if (!GetAsyncKeyState(key))
	{
		m_keys[key] = false;
		return false;
	}

	return false;
}