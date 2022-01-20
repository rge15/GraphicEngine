#pragma once

#include <vector>
#include <memory>
#include <glm/glm.hpp>

#include "Scene/Model.hpp"
#include "Scene/Camera.hpp"


namespace Ocacho
{

	class Scene
	{
		private:
			glm::mat4 projection_;

			std::vector<std::unique_ptr<Camera>> 	cameras_;
			std::vector<std::unique_ptr<Model>>		models_;
		public:
			//TODO : Implementación luces
			// std::vector<Lights> lights_;


			Scene(const float p_aspectRatio):
				projection_ { glm::perspective( glm::radians(45.0f), p_aspectRatio, 0.1f, 100.0f ) }
			{
				cameras_.reserve(10);
				models_.reserve(10);
			};

			~Scene(){};

			void SetProjection(const float p_aspectRatio)
			{
				glm::perspective( glm::radians(45.0f), p_aspectRatio, 0.1f, 100.0f );
			}

			void DrawAll();

			SceneNode* AddCamera();

			SceneNode* AddModel();
	};
}
