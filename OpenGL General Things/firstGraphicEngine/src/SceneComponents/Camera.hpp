#pragma once

#include "../SceneNode.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace Ocacho{

	class Camera : SceneNode
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
			std::size_t cameraActive_ { 0 };
			// glm::vec3 position_ 	 { 0.0f, 0.0f, 0.0f };
			glm::vec3 target_	 	 { 0.0f, 0.0f, 0.0f };
			glm::vec3 upDirection_	 { 0.0f, 1.0f, 0.0f };
			glm::vec3 cameraDirection_;
			glm::vec3 rightDirection_;

			Camera( const std::size_t p_activeCamera , 
					const glm::vec3 p_pos, 
					const glm::vec3 p_lookAt = glm::vec3(0.0f, 0.0f, 0.0f)) :
					cameraActive_ { p_activeCamera },
					//TODO : Preguntar sobre inicializadores por herencia y construcción
					// position_ { p_pos }, 
					target_ { p_lookAt }
			{
				position_ = p_pos;
				CalculateCameraUpAxis();
			};

			Camera( const std::size_t p_activeCamera,
					const float p_posx, const float p_posy, const float p_posz,
					const float p_targetx = 0, 
					const float p_targety = 0, 
					const float p_targetz = 0) :
					cameraActive_ { p_activeCamera },
					//TODO : Preguntar sobre inicializadores por herencia y construcción
					//position_ { glm::vec3(p_posx, p_posy, p_posz) }, 
					target_ { glm::vec3(p_targetx, p_targety, p_targetz) }
			{
				position_ = glm::vec3(p_posx, p_posy, p_posz);
				CalculateCameraUpAxis();
			};

			~Camera();

			glm::vec3 GetCameraViewDirection()
			{
				return glm::normalize( target_ - position_ );
			}

			glm::mat4 GetViewMatrix()
			{
				return glm::lookAt(position_, target_, upDirection_);
			}

	};
}