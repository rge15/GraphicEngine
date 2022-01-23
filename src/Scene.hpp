#pragma once

#include <vector>
#include <memory>
#include <glm/glm.hpp>

#include "FileManager.hpp"
#include "Scene/Model.hpp"
#include "Scene/Camera.hpp"

namespace Ocacho
{

	class Scene
	{
		private:
			FileManager* deviceFileManager_;

			Shader*	shader_;

			glm::mat4	projection_;

			std::vector<std::unique_ptr<SceneNode>>	cameras_;
			std::vector<std::unique_ptr<SceneNode>>	models_;

			void	SetSceneShadersUniforms();
			void	SetSceneCameraShaderUniforms();
			void	DrawModels();

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

			void SetShader( const std::size_t p_shaderID )
			{
				shader_ = deviceFileManager_->getShader(p_shaderID);
			}

			void SetProjection(const float p_aspectRatio)
			{
				projection_ = glm::perspective( glm::radians(45.0f), p_aspectRatio, 0.1f, 100.0f );
			}

			void setFileManagerAcces(FileManager* const p_fileManager)
			{
				deviceFileManager_ = p_fileManager;
			}

			void DrawAll();

			SceneNode* AddCamera(
				const glm::vec3 p_pos = glm::vec3(1.0f, 1.0f, 1.0f), 
				const glm::vec3 p_lookAt = glm::vec3(0.0f, 0.0f, 0.0f),
				const std::size_t p_activeCamera  = 1);

			SceneNode* AddModel(
				const std::size_t p_mesh, 
				const std::size_t p_material, 
				const glm::vec3 p_pos = glm::vec3(0.0f, 0.0f, 0.0f));
	};
}
