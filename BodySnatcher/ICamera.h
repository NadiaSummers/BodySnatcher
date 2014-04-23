#ifndef ICAMERA_H
#define ICAMERA_H

#include "Vector3D.h"
//#include "GameEngineCore.h"

class ICamera
{
	public:
			/**
             * @brief Get the desired camera position
			 *
			 * @param none
			 * @return Vector3D& mPosDiff
             */
		virtual const Vector3D& GetposDiff() = 0;

			/**
             * @brief Get the current camera position
			 *
			 * @param none
			 * @return Vector3D& mPos
             */
		virtual const Vector3D& Getpos() = 0;

			/**
             * @brief Move the camera to its start position
			 *
			 * @param none
			 * @return void
             */
		virtual void SetCameraPosition() = 0;

			/**
             * @brief Move the camera to the desired position
			 *
			 * @param none
			 * @return void
             */
		virtual void MoveCamera(/*const ModelManager& pModelManager, const TextureManager& pTextureManager*/) = 0;


			/**
             * @brief Prepares the camera for movement
			 * 
			 * Prepares the camera for movement by waiting for input from mouse or keyboard 
			 * and setting coordinates and rotation for desired movement.
			 *
			 * @param float xpos - the camera's x position
			 * @param float ypos - the camera's y position
			 * @param float zpos - the camera's z position
			 * @param float rotation - the camera's rotation
			 * @return void
             */
		virtual void PrepareMovement(float xpos, float ypos, float zpos, float rotation) = 0;

			/**
             * @brief Set the camera positions
			 *
			 * @param float x - the x position
			 * @param float y - the y position
			 * @param float z - the z position
			 * @return void
             */
		virtual void SetDiffValues(float x, float y, float z) = 0;

			/**
             * @brief Function to be passed as glutSpecialFunc()
			 *
			 * @param int key - the key that was pressed
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		virtual void SpecialKey(int key, int x, int y) = 0;

			/**
             * @brief Function to be passed as glutSpecialUpFunc()
			 *
			 * @param int key - the key that was released
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		virtual void SpecialKeyUp(int key, int x, int y) = 0;

			/**
             * @brief Function to be passed as glutKeyboardFunc()
			 *
			 * @param unsigned char key - the key that was pressed
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		virtual void Keyboard(unsigned char key, int x, int y) = 0;

			/**
             * @brief Function to be passed as glutKeyboardUpFunc()
			 *
			 * @param unsigned char key - the key that was released
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		virtual void KeyboardUp(unsigned char key, int x, int y) = 0;

			/**
             * @brief Function to be passed as glutMouseFunc()
			 *
			 * @param int button - the mouse button clicked
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		virtual void Mouse(int button, int state, int x, int y) = 0;

			/**
             * @brief Function to be passed as glutMotionFunc()
			 *
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		virtual void MouseMotion(int x, int y) = 0;
	
	private:
			/**
             * @brief Handles all key presses.
             *
			 * Handles all key presses by tracking their current state and 
			 * taking the appropriate action if the key is currently in the 
			 * down position.
			 *
             * @param none
			 * @return void
             */
		virtual void KeyOperations(void) = 0;

			/**
             * @brief Resets the difference values for the camera position
             *
             * @param none
			 * @return void
             */
		virtual void ResetDiffValues(void) = 0;

			/**
             * @brief Sets the camera positions.
			 * 
			 * Sets the camera positions as a product of the time difference
			 * to normalise camera speed.
			 *
			 * @param const float pDeltaTime - time difference between frames
			 * @return void
             */
		virtual void SetPosDiff(const float pDeltaTime) = 0;

		virtual bool* GetKeyStates() = 0;
		virtual bool* GetSpecialKeyStates() = 0;
};
#endif
