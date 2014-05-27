#include "IOSystem.h"


IOSystem::IOSystem(GameEngineCore* engineCore):mEngineCore(engineCore)
{
}


IOSystem::~IOSystem(void)
{
}


void IOSystem::KeyOperations(void)
{
//	if(mKeyStates['q'])
//	{
//		mEngineCore->GetCamera()->setYrotrad(mRotationY / 180 * 3.141592654f);
//		mPositionDifference.x -= float(cos(mYrotrad)) * mSpeed;
//		mPositionDifference.z -= float(sin(mYrotrad)) * mSpeed;
//	}
//
//	if(mKeyStates['e'])
//	{
//		mYrotrad = (mRotationY / 180 * 3.141592654f);
//		mPositionDifference.x += float(cos(mYrotrad)) * mSpeed;
//		mPositionDifference.z += float(sin(mYrotrad)) * mSpeed;
//	}
//
//	if(mKeyStates['r'])
//	{
//		if(mRotationX < mMaxAngle) //restrict maximum vertical camera angle to mMaxAngle
//			mRotationX += 1;
//	}
//
//	if(mKeyStates['f'])
//	{
//		if(mRotationX > mMinAngle) //restrict minimum vertical camera angle to mMinAngle
//			mRotationX -= 1;
//	}
//
//	if(mKeyStates['w'])
//	{
//		mYrotrad = (mRotationY / 180 * 3.141592654f);
//		mXrotrad = (mRotationY / 180 * 3.141592654f); 
//		mPositionDifference.x += float(sin(mYrotrad)) * mSpeed;
//		mPositionDifference.z -= float(cos(mYrotrad)) * mSpeed;
//		mPositionDifference.y -= float(sin(mXrotrad)) * mSpeed;
//	}
//
//	if(mKeyStates['s'])
//	{
//		mYrotrad = (mRotationY / 180 * 3.141592654f);
//		mXrotrad = (mRotationX / 180 * 3.141592654f); 
//		mPositionDifference.x -= float(sin(mYrotrad)) * mSpeed;
//		mPositionDifference.z += float(cos(mYrotrad)) * mSpeed;
//		mPositionDifference.y += float(sin(mXrotrad)) * mSpeed;
//	}
//
//	if(mKeyStates['a'])
//	{
//		if(!mMouseClicked)
//		{
//			mRotationY += -1.0f; //rotate view left if mouse not clicked
//		}
//		else
//		{
//			//strafe left if mouse is clicked
//			mYrotrad = (mRotationY / 180 * 3.141592654f);
//			mPositionDifference.x -= float(cos(mYrotrad)) * mSpeed;
//			mPositionDifference.z -= float(sin(mYrotrad)) * mSpeed;
//		}
//
//	}
//
//	if(mKeyStates['d'])
//	{
//		if(!mMouseClicked)
//		{
//			mRotationY += 1.0f; //rotate view right if mouse not clicked
//		}
//		else
//		{
//			//strafe right if mouse is clicked
//			mYrotrad = (mRotationY / 180 * 3.141592654f);
//			mPositionDifference.x += float(cos(mYrotrad)) * mSpeed;
//			mPositionDifference.z += float(sin(mYrotrad)) * mSpeed;
//		}
//	}
//
//	if(mSpecialKeyStates[0])
//	{
//		mRotationY += -1.0f;
//	}
//
//	if(mSpecialKeyStates[1])
//	{
//		mRotationY += 1.0f;
//	}
//
//	if(mSpecialKeyStates[2])
//	{
//		mYrotrad = (mRotationY / 180 * 3.141592654f);
//		mXrotrad = (mRotationX / 180 * 3.141592654f); 
//		mPositionDifference.x += float(sin(mYrotrad)) * mSpeed;
//		mPositionDifference.z -= float(cos(mYrotrad)) * mSpeed;
//		mPositionDifference.y -= float(sin(mXrotrad)) * mSpeed;
//	}
//
//	if(mSpecialKeyStates[3])
//	{
//		mYrotrad = (mRotationY / 180 * 3.141592654f);
//		mXrotrad = (mRotationX / 180 * 3.141592654f); 
//		mPositionDifference.x -= float(sin(mYrotrad)) * mSpeed;
//		mPositionDifference.z += float(cos(mYrotrad)) * mSpeed;
//		mPositionDifference.y += float(sin(mXrotrad)) * mSpeed;
//	}
//
//	if(mKeyStates['o'])
//	{
//		mPositionDifference.y += 1.0f * mSpeed;
//	}
//	if(mKeyStates['l'])
//	{
//		mPositionDifference.y -= 1.0f * mSpeed;
//	}
//	//should not be used
//	mPositionDifference.y= 0.0;
}


void IOSystem::SpecialKey(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT :
			mSpecialKeyStates[0] = true;
			break;

		case GLUT_KEY_RIGHT :
			mSpecialKeyStates[1] = true;
			break;

		case GLUT_KEY_UP : 
			mSpecialKeyStates[2] = true;
			break;

		case GLUT_KEY_DOWN : 
			mSpecialKeyStates[3] = true;
			break;
	}
}


void IOSystem::SpecialKeyUp(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT :
			mSpecialKeyStates[0] = false;
			break;

		case GLUT_KEY_RIGHT :
			mSpecialKeyStates[1] = false;
			break;

		case GLUT_KEY_UP : 
			mSpecialKeyStates[2] = false;
			break;

		case GLUT_KEY_DOWN : 
			mSpecialKeyStates[3] = false;
			break;
	}
}


void IOSystem::Keyboard(unsigned char key, int x, int y)
{
	mKeyStates[key] = true; // Set the state of the current key to pressed
}


void IOSystem::KeyboardUp(unsigned char key, int x, int y)
{
	mKeyStates[key] = false; // Set the state of the current key to not pressed
}


void IOSystem::Mouse(int button, int state, int x, int y)
{
	//mEngineCore->GetCamera().Mouse(button, state, x, y);
	//mLastX = (float)x; //set lastx to the current x position
	//mLastY = (float)y; //set lasty to the current y position
	//
	//if((button == GLUT_LEFT_BUTTON) || (button == GLUT_RIGHT_BUTTON)) 
	//{
	//	mMouseClicked = (state == GLUT_DOWN);
	//	if(state == GLUT_DOWN)
	//	{
	//		glutSetCursor(GLUT_CURSOR_NONE);
	//	}
	//	else
	//	{
	//		glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_HEIGHT)/2); //rest the mouse point to center of window
	//		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	//	}
	//}
}


void IOSystem::MouseMove(int x, int y)
{
	mEngineCore->GetCamera().MouseMotion(x, y);
	//mDiffX = 0;// = x-lastx; //check the difference between the current x and the last x position
	//mDiffY = 0;// = y-lasty; //check the difference between the current y and the last y position

	//if(mMouseClicked)
	//{
	//	mDiffX = x-(int)mLastX; //check the difference between the current x and the last x position
	//	mDiffY = y-(int)mLastY; //check the difference between the current y and the last y position
	//}

	//mLastX = (float)x; //set lastx to the current x position
	//mLastY = (float)y; //set lasty to the current y position

	//mRotationX += (float) mDiffY; //set the xrot to xrot with the addition of the difference in the y position
	//mRotationY += (float) mDiffX; //set the yrot to yrot with the addition of the difference in the x position

	//if(mRotationX > mMaxAngle) //restrict maximum vertical camera angle to mMaxAngle
	//	mRotationX = mMaxAngle;
	//else if(mRotationX < mMinAngle) //restrict minimum vertical camera angle mMinAngle
	//	mRotationX = mMinAngle;
}


bool* IOSystem::GetKeyStates()
{
	return mKeyStates;
}


bool* IOSystem::GetSpecialKeyStates()
{
	return mSpecialKeyStates;
}