#include "FirstPersonCamera.h"


FirstPersonCamera::FirstPersonCamera(GameEngineCore* engineCore):mEngineCore(engineCore)
{
	// intialise camera values
	mStartPosition.x = 0;
	mStartPosition.y = 0;
	mStartPosition.z = 0;
	mCameraRotation = 0;

	mSpeed = 100.0; 
	mPosition.x = 0.0; 
	mPosition.y = 0.0; 
	mPosition.z = 0.0; 
	mRotationX = 0.0; 
	mRotationY = 0.0;
	mPositionDifference.x = 0.0;
	mPositionDifference.y= 0.0;  
	mPositionDifference.z = 0.0;
	mRadius = 300.0f;
	mMaxAngle = 45.0;
	mMinAngle = 0.0;
	mYrotrad;
	mXrotrad;
	mMouseClicked = false;
	//mLastX = glutGet(GLUT_WINDOW_WIDTH)/2.0f; 
	//mLastY = glutGet(GLUT_WINDOW_HEIGHT)/2.0f;
	//mLastX = 0; 
	//mLastY = 0;

	//set camera key states to false (not pressed)
	for(int i=0; i<256; i++)
	{
		mKeyStates[i] = false;
	}

	//set camera special key states (arrow keys) to false (not pressed)
	for(int i=0; i<4; i++)
	{
		mSpecialKeyStates[i] = false;
	}
}


FirstPersonCamera::~FirstPersonCamera(void)
{
}


const Vector3D& FirstPersonCamera::GetposDiff()
{
	return mPositionDifference;
}


const Vector3D& FirstPersonCamera::Getpos()
{
	return mPosition;
}


void FirstPersonCamera::SetCameraPosition()
{
	glRotatef(mCameraRotation, 0.0, 1.0, 0.0); //rotate camera 180 degrees
	glTranslatef(mStartPosition.x, mStartPosition.y, mStartPosition.z); //translate camera starting position
}


void FirstPersonCamera::MoveCamera(/*const ModelManager& pModelManager, const TextureManager& pTextureManager*/)
{
	mPosition.x += mPositionDifference.x;
	mPosition.z += mPositionDifference.z;

	ResetDiffValues();
	glTranslatef(0.0f, 0.0f, -mRadius);
	
	glRotatef(mRotationX,1.0,0.0,0.0);
	
	//glPushAttrib(GL_CURRENT_BIT);
	//	glPushMatrix();
	//		glRotatef(0, 1, 0, 0);
	//		pModelManager.drawModel(mRobot, pTextureManager.getTextureID(taRobot));
	//		glPopMatrix();
	//glPopAttrib();
    
	glRotatef(mRotationY,0.0,1.0,0.0);  //rotate the camera on the y-axis (up and down)

	//mCameraBB.Translate(mPosition);
	//mCameraBB.Move(mPosDiff);
	glTranslated(-mPosition.x, 0.0f, -mPosition.z); //translate the screen to the position of the camera
}


void FirstPersonCamera::PrepareMovement(float xpos, float ypos, float zpos, float rotation)
{
	mStartPosition.x = xpos;
	mStartPosition.y = ypos;
	mStartPosition.z = zpos;
	mCameraRotation = rotation;

	// check for movement
	KeyOperations();
	double deltaTime = mTimer.Duration();
	mTimer.Reset();
	SetPosDiff(deltaTime);
}


void FirstPersonCamera::SetDiffValues(float x, float y, float z)
{
	mPositionDifference.x = x;
	mPositionDifference.y = y;
	mPositionDifference.z = z;
}


void FirstPersonCamera::SpecialKey(int key, int x, int y)
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


void FirstPersonCamera::SpecialKeyUp(int key, int x, int y)
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


void FirstPersonCamera::Keyboard(unsigned char key, int x, int y)
{
	mKeyStates[key] = true; // Set the state of the current key to pressed
}


void FirstPersonCamera::KeyboardUp(unsigned char key, int x, int y)
{
	mKeyStates[key] = false; // Set the state of the current key to not pressed
}


void FirstPersonCamera::Mouse(int button, int state, int x, int y)
{
	mLastX = (float)x; //set lastx to the current x position
	mLastY = (float)y; //set lasty to the current y position
	
	if((button == GLUT_LEFT_BUTTON) || (button == GLUT_RIGHT_BUTTON)) 
	{
		mMouseClicked = (state == GLUT_DOWN);
		if(state == GLUT_DOWN)
		{
			glutSetCursor(GLUT_CURSOR_NONE);
		}
		else
		{
			glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_HEIGHT)/2); //rest the mouse point to center of window
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		}
	}
}


void FirstPersonCamera::MouseMotion(int x, int y)
{
	mDiffX = 0;// = x-lastx; //check the difference between the current x and the last x position
	mDiffY = 0;// = y-lasty; //check the difference between the current y and the last y position

	if(mMouseClicked)
	{
		mDiffX = x-(int)mLastX; //check the difference between the current x and the last x position
		mDiffY = y-(int)mLastY; //check the difference between the current y and the last y position
	}

	mLastX = (float)x; //set lastx to the current x position
	mLastY = (float)y; //set lasty to the current y position

	mRotationX += (float) mDiffY; //set the xrot to xrot with the addition of the difference in the y position
	mRotationY += (float) mDiffX; //set the yrot to yrot with the addition of the difference in the x position

	if(mRotationX > mMaxAngle) //restrict maximum vertical camera angle to mMaxAngle
		mRotationX = mMaxAngle;
	else if(mRotationX < mMinAngle) //restrict minimum vertical camera angle mMinAngle
		mRotationX = mMinAngle;
}


void FirstPersonCamera::KeyOperations(void)
{
	if(mEngineCore->GetIOSystem()->GetKeyStates()['q'])
	{
		mYrotrad = (mRotationY / 180 * 3.141592654f);
		mPositionDifference.x -= float(cos(mYrotrad)) * mSpeed;
		mPositionDifference.z -= float(sin(mYrotrad)) * mSpeed;
	}

	if(mEngineCore->GetIOSystem()->GetKeyStates()['e'])
	{
		mYrotrad = (mRotationY / 180 * 3.141592654f);
		mPositionDifference.x += float(cos(mYrotrad)) * mSpeed;
		mPositionDifference.z += float(sin(mYrotrad)) * mSpeed;
	}

	if(mEngineCore->GetIOSystem()->GetKeyStates()['r'])
	{
		if(mRotationX < mMaxAngle) //restrict maximum vertical camera angle to mMaxAngle
			mRotationX += 1;
	}

	if(mEngineCore->GetIOSystem()->GetKeyStates()['f'])
	{
		if(mRotationX > mMinAngle) //restrict minimum vertical camera angle to mMinAngle
			mRotationX -= 1;
	}

	if(mEngineCore->GetIOSystem()->GetKeyStates()['w'])
	{
		mYrotrad = (mRotationY / 180 * 3.141592654f);
		mXrotrad = (mRotationY / 180 * 3.141592654f); 
		mPositionDifference.x += float(sin(mYrotrad)) * mSpeed;
		mPositionDifference.z -= float(cos(mYrotrad)) * mSpeed;
		mPositionDifference.y -= float(sin(mXrotrad)) * mSpeed;
	}

	if(mEngineCore->GetIOSystem()->GetKeyStates()['s'])
	{
		mYrotrad = (mRotationY / 180 * 3.141592654f);
		mXrotrad = (mRotationX / 180 * 3.141592654f); 
		mPositionDifference.x -= float(sin(mYrotrad)) * mSpeed;
		mPositionDifference.z += float(cos(mYrotrad)) * mSpeed;
		mPositionDifference.y += float(sin(mXrotrad)) * mSpeed;
	}

	if(mEngineCore->GetIOSystem()->GetKeyStates()['a'])
	{
		if(!mMouseClicked)
		{
			mRotationY += -1.0f; //rotate view left if mouse not clicked
		}
		else
		{
			//strafe left if mouse is clicked
			mYrotrad = (mRotationY / 180 * 3.141592654f);
			mPositionDifference.x -= float(cos(mYrotrad)) * mSpeed;
			mPositionDifference.z -= float(sin(mYrotrad)) * mSpeed;
		}

	}

	if(mEngineCore->GetIOSystem()->GetKeyStates()['d'])
	{
		if(!mMouseClicked)
		{
			mRotationY += 1.0f; //rotate view right if mouse not clicked
		}
		else
		{
			//strafe right if mouse is clicked
			mYrotrad = (mRotationY / 180 * 3.141592654f);
			mPositionDifference.x += float(cos(mYrotrad)) * mSpeed;
			mPositionDifference.z += float(sin(mYrotrad)) * mSpeed;
		}
	}

	if(mEngineCore->GetIOSystem()->GetSpecialKeyStates()[0])
	{
		mRotationY += -1.0f;
	}

	if(mEngineCore->GetIOSystem()->GetSpecialKeyStates()[1])
	{
		mRotationY += 1.0f;
	}

	if(mEngineCore->GetIOSystem()->GetSpecialKeyStates()[2])
	{
		mYrotrad = (mRotationY / 180 * 3.141592654f);
		mXrotrad = (mRotationX / 180 * 3.141592654f); 
		mPositionDifference.x += float(sin(mYrotrad)) * mSpeed;
		mPositionDifference.z -= float(cos(mYrotrad)) * mSpeed;
		mPositionDifference.y -= float(sin(mXrotrad)) * mSpeed;
	}

	if(mEngineCore->GetIOSystem()->GetSpecialKeyStates()[3])
	{
		mYrotrad = (mRotationY / 180 * 3.141592654f);
		mXrotrad = (mRotationX / 180 * 3.141592654f); 
		mPositionDifference.x -= float(sin(mYrotrad)) * mSpeed;
		mPositionDifference.z += float(cos(mYrotrad)) * mSpeed;
		mPositionDifference.y += float(sin(mXrotrad)) * mSpeed;
	}

	if(mEngineCore->GetIOSystem()->GetKeyStates()['o'])
	{
		mPositionDifference.y += 1.0f * mSpeed;
	}
	if(mEngineCore->GetIOSystem()->GetKeyStates()['l'])
	{
		mPositionDifference.y -= 1.0f * mSpeed;
	}
	//should not be used
	mPositionDifference.y= 0.0;
}


void FirstPersonCamera::ResetDiffValues(void)
{
	mPositionDifference.x = 0;
	mPositionDifference.y = 0;
	mPositionDifference.z = 0;
}


void FirstPersonCamera::SetPosDiff(const float pDeltaTime)
{
	mPositionDifference.x *= pDeltaTime;
	mPositionDifference.y *= pDeltaTime;
	mPositionDifference.z *= pDeltaTime;
}


bool* FirstPersonCamera::GetKeyStates()
{
	return mKeyStates;
}


bool* FirstPersonCamera::GetSpecialKeyStates()
{
	return mSpecialKeyStates;
}
