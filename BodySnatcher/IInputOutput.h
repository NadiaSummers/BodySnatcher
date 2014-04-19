#pragma once

#include "GameEngineCore.h"

class IInputOutput
{
	public:
		virtual void KeyOperations(void) = 0;
		virtual void SpecialKey(int key, int x, int y) = 0;
		virtual void SpecialKeyUp(int key, int x, int y) = 0;
		virtual void Keyboard(unsigned char key, int x, int y) = 0;
		virtual void KeyboardUp(unsigned char key, int x, int y) = 0;
		virtual void Mouse(int button, int state, int x, int y) = 0;
		virtual void MouseMove(int x, int y) = 0;
		virtual bool* GetKeyStates() = 0;
		virtual bool* GetSpecialKeyStates() = 0;
};

