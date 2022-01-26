/**
 * @file Scene.hpp
 * @author OcachoGames-Rodrigo (ocachogames@gmail.com)
 * @brief Scene of Ocacho Graphic Engine
 * 
 * A Scene will manage all the Scene objects
 * as cameras, models or lights 
 * 
 * Right now we can just have 1 camera in the scene
 * and it doesn't manage lights
 * 
 * TODO : Implementación luces
 * 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2021
 */
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
			// Pointer to the file manager
			// for getting resources
			FileManager* deviceFileManager_;

			// Pointer to the scene shader
			Shader*	shader_ { nullptr };

			// Projection matrix of the scene
			glm::mat4 projection_;

			// Array of unique ptr to cameras of the scene
			std::vector<std::unique_ptr<SceneNode>>	cameras_;

			// Array of unique ptr to models of the scene
			std::vector<std::unique_ptr<SceneNode>>	models_;

			/**
			 * @brief	Set all the shader data from the scene
			 * 			as the projection matrix
			 */
			void	SetSceneShadersUniforms();

			/**
			 * @brief	Set all the shader data from the scenes
			 * 			cameras as the view matrix
			 */
			void	SetSceneCameraShaderUniforms();

			/**
			 * @brief	Draw all the models in the scene
			 */
			void	DrawModels();

		public:
			Scene()
			{
				cameras_.reserve(10);
				models_.reserve(10);
			};

			~Scene(){};

			/**
			 * @brief	Set the scene shader to given shader index in memory
			 */
			void SetShader( const std::size_t p_shaderID )
			{
				shader_ = deviceFileManager_->getShader(p_shaderID);
			}

			/**
			 * @brief	Set projection matrix given 
			 * 			the aspect ratio of the window
			 */
			void SetProjection(const float p_aspectRatio)
			{
				projection_ = glm::perspective( 
					glm::radians(45.0f),	//FOV
					p_aspectRatio,			//Aspect Ratio
					0.1f, 100.0f );			//Near and Far
			}

			/**
			 * @brief	Set the pointer to the file manager
			 * 			to get acces to sources loaded in memory
			 */
			void SetFileManagerAcces(FileManager* const p_fileManager)
			{
				deviceFileManager_ = p_fileManager;
			}

			/**
			 * @brief	Draw all the scenes nodes in the setted
			 * 			window
			 */
			void DrawAll();

			/**
			 * @brief	Add a camera into the scene
			 * 
			 * @tparam	p_pos Position of the camera
			 * @tparam	p_lookAt Target of the camera
			 * @tparam	p_activeCamera If the camera is active or not
			 * 
			 * @return	Pointer to the camera sceneNode
			 */
			SceneNode* AddCamera(
				const glm::vec3 p_pos = glm::vec3(1.0f, 1.0f, 1.0f), 
				const glm::vec3 p_lookAt = glm::vec3(0.0f, 0.0f, 0.0f),
				const u_int8_t p_activeCamera  = 1);

			/**
			 * @brief	Add a model into the scene

			 * @tparam	p_mesh Index in memory of the mesh
			 * @tparam	p_material  Index in memory of the material
			 * @tparam	p_pos Position of the model
			 * 
			 * @return	Pointer to the model sceneNode
			**/
			SceneNode* AddModel(
				const std::size_t p_mesh, 
				const std::size_t p_material, 
				const glm::vec3 p_pos = glm::vec3(0.0f, 0.0f, 0.0f));
	};
}
