/**
 * @file Camera.hpp
 * @author OcachoGames-Rodrigo (ocachogames@gmail.com)
 * @brief Camera of Ocacho Graphic Engine Scene
 * 
 * A Camera object wil have the info for each camera
 * object in a scene.
 * 
 * Right now we can just have 1 camera
 * 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2021
 */
#pragma once

#include "SceneNode.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <iostream>
#include <iosfwd>

namespace Ocacho{

	class Camera : public SceneNode
	{
		private:
			// Up direction of the camera
			glm::vec3 	upDirection_	 	{ 0.0f, 1.0f, 0.0f };

			// Right direction of the camera
			glm::vec3 	rightDirection_;

			// Camera Direction in the scene
			glm::vec3 	cameraDirection_;

			// Flag for knowing if we have to use the object
			u_int8_t cameraActive_ 		{ 0 };

			// Target position to view
			glm::vec3 	target_	 	 		{ 0.0f, 0.0f, 0.0f };

			/**
			 * @brief	Sets the camera direction with the 
			 * 			camera position in the scene
			 */
			void SetCameraDirection();

			/**
			 * @brief	Sets the right camera direction with the 
			 * 			camera position and his upDiretion in the scene
			 */
			void SetRightCameraDirection();

			/**
			 * @brief	Sets the up camera direction with the
			 * 			camera position and his right final direcion 
			 */
			void SetUpCameraDirection();

			/**
			 * @brief	Update all the camera direction axis 
			 */
			void CalculateCameraUpAxis();

		public:
			Camera( const glm::vec3 p_pos = glm::vec3(1.0f, 1.0f, 1.0f), 
					const glm::vec3 p_lookAt = glm::vec3(0.0f, 0.0f, 0.0f),
					const u_int8_t p_activeCamera  = 1) :
					SceneNode( p_pos ),
					cameraActive_ { p_activeCamera },
					target_ { p_lookAt }
			{
				CalculateCameraUpAxis();
			};

			~Camera(){};

			/**
			 * @brief	Returns the Camera Direction in the scene
			 * 
			 * @return	Vector 3 with the camera direction in the scene
			 */
			glm::vec3 GetCameraViewDirection();

			/**
			 * @brief	Returns the View Matrix for the shader
			 * 
			 * @return	View Matrix of this camera
			 */
			glm::mat4 GetViewMatrix();

			/**
			 * @brief	Checks if the camera is active or not
			 * 
			 * @return	cameraActive_ value
			 */
			u_int8_t IsCameraActive();
			
			/**
			 * @brief	Sets the target_ data position to tha camera target 
			 * 
			 * @tparam	p_target Vector 3 target position
			 */
			void SetTarget( const glm::vec3 p_target );

			/**
			 * @brief	Sets the target_ data position to tha camera target 
			 * 
			 * @tparam	p_targetX Float with de x position of the target
			 * @tparam	p_targetY Float with de x position of the target
			 * @tparam	p_targetZ Float with de x position of the target
			 */
			void SetTarget( const float p_targetX, 
							const float p_targetY, 
							const float p_targetZ);

			/**
			 * @brief	Operato << override
			 * 			It shows the position, the target & the upDirection camera
			 * 
			 */
			friend std::ostream& operator<<(std::ostream& os, const Camera& p_cam)
			{
				os << "Camera pos   : " <<
				p_cam.position_.x << " , " << 
				p_cam.position_.y << " , " << 
				p_cam.position_.z << '\n';
				
				os << "Camera tar   : " << 
				p_cam.target_.x << " , " << 
				p_cam.target_.y << " , " << 
				p_cam.target_.z << '\n';
				
				os << "Camera upDir : " << 
				p_cam.upDirection_.x << " , " << 
				p_cam.upDirection_.y << " , " << 
				p_cam.upDirection_.z << '\n';

			    return os;
			}
	};
}