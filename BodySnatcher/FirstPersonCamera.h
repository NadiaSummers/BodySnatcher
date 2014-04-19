#pragma once

#include <Windows.h>
#include <GL\gl.h>
#include <GL\glut.h>
#include <stdlib.h>
#include <math.h>
#include "ICamera.h"
#include "Timer.h"
#include "GameEngineCore.h"

class FirstPersonCamera : public ICamera
{
	private:
		GameEngineCore* mEngineCore;

		void ResetDiffValues(void);
		void SetPosDiff(const float pDeltaTime);
		
		Vector3D mPosition; /**< The camera position*/
		Vector3D mStartPosition; /**< The camera's initial position*/
		Vector3D mPositionDifference; /**< The coordinates of the desired camera position*/
		Timer mTimer; /**< Timer variable used to normalise camera speed*/
		float mSpeed; /**< The camera speed*/
		float mCameraRotation; /**< The direction to face the camera*/
		float mRotationX; /**< Amount to rotate on the x-axis*/
		float mRotationY; /**< Amount to rotate on the y-axis*/
		float mRadius; /**< The distance from the character to the camera*/
		float mMaxAngle; /**< Maximum camera vertical angle*/
		float mMinAngle; /**< Minimum camera vertical angle*/
		float mLastX; /**< Last mouse x-position*/
		float mLastY; /**< Last mouse y-position*/
		float mXrotrad; /**< The amount to rotate on the x-axis*/
		float mYrotrad; /**< The amount to rotate on the y-axis*/
		int mDiffX; /**< Value of the difference between the curren and last x position*/
		int mDiffY; /**< Value of the difference between the current and last y position*/
		bool mMouseClicked; /**< Flag for whether or not the mouse button is clicked (true = mouse clicked, false = mouse not clicked*/
		bool mKeyStates[256]; /**< Tracks the states of keyboard keys (true = key pressed, false = key not pressed)*/
		bool mSpecialKeyStates[4]; /**< Tracks the states of special arrow keys (true = key pressed, false = key not pressed*/

	public:
		FirstPersonCamera(GameEngineCore* engineCore);
		~FirstPersonCamera(void);

		const Vector3D& GetposDiff();
		const Vector3D& Getpos();
		void SetCameraPosition();
		void MoveCamera(/*const ModelManager& pModelManager, const TextureManager& pTextureManager*/);
		void PrepareMovement(float xpos, float ypos, float zpos, float rotation);
		void SetDiffValues(float x, float y, float z);
		void SpecialKey(int key, int x, int y);
		void SpecialKeyUp(int key, int x, int y);
		void Keyboard(unsigned char key, int x, int y);
		void KeyboardUp(unsigned char key, int x, int y);
		void Mouse(int button, int state, int x, int y);
		void MouseMotion(int x, int y);
		void KeyOperations();
		bool* GetKeyStates();
		bool* GetSpecialKeyStates();	
};

