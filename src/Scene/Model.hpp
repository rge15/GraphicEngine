/**
 * @file Model.hpp
 * @author OcachoGames-Rodrigo (ocachogames@gmail.com)
 * @brief Model of Ocacho Graphic Engine Scene
 * 
 * A model object wil have the info for each object
 * in a scene.
 * 
 * At least right now, each model will have 
 * only 1 mesh and 1 material 
 * 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2021
 */
#pragma once

#include "SceneNode.hpp"
#include "../FileManager/Mesh.hpp"
#include "../FileManager/Shader.hpp"
#include "../FileManager/Material.hpp"

namespace Ocacho
{
	class Model : public SceneNode
	{
		private:
			// Model matrix of each model
			glm::mat4 model_ { glm::mat4(1.0f) };
			
			// Pointer to the model mesh
			Mesh*		meshes_;

			//Pointer to the model material
			Material*	material_;

			/**
			 * @brief	Calculates the model matrix of the model
			 * 			with his scene data
			 */
			void CalculateModelMatrix();

		public:
			Model(	Mesh* const p_mesh, 
					Material* const p_material, 
					const glm::vec3 p_pos = glm::vec3(0.0f, 0.0f, 0.0f)) :
					SceneNode( p_pos )
			{
				assert( p_mesh != nullptr );
				assert( p_material != nullptr );

				meshes_ = p_mesh;
				material_ = p_material;
			}

			~Model(){};

			/**
			 * @brief	Draw the model mesh with his material
			 * 
			 * @tparam	p_shader Pointer to shader which draws
			 */
			void Draw( Shader* const p_shader );

			/**
			 * @brief	Sets the model matrix of the given shader
			 * 			with the object model matrix
			 * 
			 * @tparam	p_shader Pointer to shader which draws
			 */
			void SetModelMatrix(Shader* const p_shader);

	};
}
