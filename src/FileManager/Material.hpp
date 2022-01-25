/**
 * @file Material.hpp
 * @author OcachoGames-Rodrigo (ocachogames@gmail.com)
 * @brief Material of Ocacho Graphic Engine
 * 
 * A Material will manage the shader textures
 * and the base color
 * 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2021
 */
#pragma once

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>

#include "../utilities/RenderStructs.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

namespace Ocacho
{
	class Material
	{
		private:
			// Vector of pointers to material textures 
			std::vector<Texture*>	textures_;

			// Base color of the material
			glm::vec3	baseColor_ { 0.1, 0.0, 0.0 };
	
			/**
			 * @brief	Sets the material textures to the given shader 
			 * 
			 * @tparam	p_shader Shader to set the textures in
			 */
			void LoadTexturesInShader(Shader* const p_shader);

			/**
			 * @brief	Sets the materials color to the given shader 
			 * 
			 * @tparam	p_shader Shader to set the color in
			 */
			void LoadBaseColorInShader(Shader* const p_shader);

			/**
			 * @brief	Sets the material data into the given shader 
			 * 
			 * @tparam	p_shader Shader to set the data in
			 */
			void SetShaderData(Shader* const p_shader);

		public:			
			Material(const std::vector<Texture*> p_textures):
					 textures_ { p_textures }
			{}

			Material(const glm::vec3 p_baseColor):
					 baseColor_ { p_baseColor }
			{}

			~Material(){};

			/**
			 * @brief	Sets the material color with the given color
			 * 
			 * @tparam	p_color Color to be setted
			 */
			void SetBaseColor( const glm::vec3 p_color );

			/**
			 * @brief	Sets the shader texture data with the material
			 * 			data
			 * 
			 * @tparam	p_shader Shader to set data
			 */
			void UseMaterial(Shader* const p_shader);
	};
}