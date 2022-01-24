#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace Ocacho
{

	class Camera
	{
		private:

		public:
			glm::vec3 position_;
			glm::vec3 target_;
			glm::vec3 cameraUp_ { 0.0f, 1.0f, 0.0f };
			glm::vec3 cameraDirection_;
			glm::vec3 cameraRight_;

			Camera( const glm::vec3 p_pos = glm::vec3(1.0f, 1.0f, 1.0f), const glm::vec3 p_lookAt = glm::vec3(0.0f, 0.0f, 0.0f)) :
					position_ { p_pos }, target_ { p_lookAt }
			{
				CalculateCameraUpAxis();
			};

			~Camera(){};

			glm::mat4 LookAt()
			{
				//TODO : Ver si aquí es necesario recalcular el cameraUp_ ... 
				//TODO : ... o solo cuando cambie el ángulo de la cámara
				// LogCameraData();
				return glm::lookAt(position_, target_, cameraUp_);
			}

			glm::mat4 LookAtBackwards()
			{
				//TODO : Ver si aquí es necesario recalcular el cameraUp_ ... 
				//TODO : ... o solo cuando cambie el ángulo de la cámara
				glm::vec3 backwardsPosition = glm::vec3 ( -position_.x,
														   position_.y,
														  -position_.z );
				
				return glm::lookAt(backwardsPosition, target_, cameraUp_);
			}


			void CalculateCameraUpAxis()
			{
				cameraDirection_ = glm::normalize(position_ - target_);

				cameraRight_	 = glm::normalize(glm::cross(cameraUp_, cameraDirection_));

				cameraUp_		 = glm::normalize(glm::cross(cameraDirection_, cameraRight_));
			}

			void SetPosition(const glm::vec3 p_pos)
			{
				position_ = p_pos;
			}

			void SetTarget( const glm::vec3 p_target)
			{
				target_ = p_target;
			}

			void LogCameraData()
			{
				std::cout << "Camera pos : " << position_.x << " , " << position_.y << " , " << position_.z << '\n';
				std::cout << "Camera tar : " << target_.x << " , " << target_.y << " , " << target_.z << '\n';
				std::cout << "Camera upDir : " << cameraUp_.x << " , " << cameraUp_.y << " , " << cameraUp_.z << '\n';
			}

	};
}