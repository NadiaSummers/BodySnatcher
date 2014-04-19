#pragma once

#include <glut.h>
#include <stdlib.h>
#include <math.h>
#include "IInputOutput.h"
#include "GameEngineCore.h"

class IOSystem : public IInputOutput
{
	public:
		IOSystem(GameEngineCore* engineCore);
		~IOSystem(void);

		void KeyOperations(void);
		void SpecialKey(int key, int x, int y);
		void SpecialKeyUp(int key, int x, int y);
		void Keyboard(unsigned char key, int x, int y);
		void KeyboardUp(unsigned char key, int x, int y);
		void Mouse(int button, int state, int x, int y);
		void MouseMove(int x, int y);
		bool* GetKeyStates();
		bool* GetSpecialKeyStates();

	private:
		GameEngineCore* mEngineCore;
		bool mMouseClicked; /**< Flag for whether or not the mouse button is clicked (true = mouse clicked, false = mouse not clicked*/
		bool mKeyStates[256]; /**< Tracks the states of keyboard keys (true = key pressed, false = key not pressed)*/
		bool mSpecialKeyStates[4]; /**< Tracks the states of special arrow keys (true = key pressed, false = key not pressed*/
};

