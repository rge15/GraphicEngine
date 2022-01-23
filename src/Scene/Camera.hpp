#pragma once

#include "SceneNode.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace Ocacho{

	class Camera : public SceneNode
	{
		private:
			void SetCameraDirection()
			{
				cameraDirection_ = glm::normalize(position_ - target_);
			}

			void SetRightCameraDirection()
			{
				rightDirection_ = glm::normalize(glm::cross(upDirection_, cameraDirection_));
			}

			void SetUpCameraDirection()
			{
				upDirection_ = glm::normalize(glm::cross( cameraDirection_, rightDirection_ ));
			}

			void CalculateCameraUpAxis()
			{
				SetCameraDirection();
				SetRightCameraDirection();
				SetUpCameraDirection();
			}

		public:
			std::size_t cameraActive_ 		{ 0 };
			glm::vec3 	target_	 	 		{ 0.0f, 0.0f, 0.0f };
			glm::vec3 	upDirection_	 	{ 0.0f, 1.0f, 0.0f };
			glm::vec3 	cameraDirection_;
			glm::vec3 	rightDirection_;

			Camera( const glm::vec3 p_pos = glm::vec3(1.0f, 1.0f, 1.0f), 
					const glm::vec3 p_lookAt = glm::vec3(0.0f, 0.0f, 0.0f),
					const std::size_t p_activeCamera  = 1) :
					SceneNode( p_pos ),
					cameraActive_ { p_activeCamera },
					target_ { p_lookAt }
			{
				CalculateCameraUpAxis();
			};

			~Camera(){};

			glm::vec3 GetCameraViewDirection()
			{
				return glm::normalize( position_ - target_ );
			}

			glm::mat4 GetViewMatrix()
			{
				return glm::lookAt(position_, target_, upDirection_);
			}

			void SetTarget( const glm::vec3 p_target )
			{
				target_ = p_target;
			}

			void SetTarget( const float p_targetX, 
							const float p_targetY, 
							const float p_targetZ)
			{
				target_ = glm::vec3( p_targetX, p_targetY, p_targetZ);
			}

			void LogCameraData()
			{
				std::cout << "Camera pos : " << position_.x << " , " << position_.y << " , " << position_.z << '\n';
				std::cout << "Camera tar : " << target_.x << " , " << target_.y << " , " << target_.z << '\n';
				std::cout << "Camera upDir : " << upDirection_.x << " , " << upDirection_.y << " , " << upDirection_.z << '\n';
			}


	};
}