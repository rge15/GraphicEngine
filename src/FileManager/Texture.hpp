/**
 * @file Texture.hpp
 * @author OcachoGames-Rodrigo (ocachogames@gmail.com)
 * @brief Texture of Ocacho Graphic Engine
 * 
 * A Texture will manage image data and his
 * opengl buffer data
 * 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2021
 */
#pragma once

#include <string_view>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <assert.h>


#include "../utilities/RenderStructs.hpp"

namespace Ocacho
{

	class Texture
	{
		private:
			// OpenGl id buffer of the texture
			glID				ID_;

			// Type of the texture for shader diferentiation
			std::string_view	type_;

			/**
			 * @brief	Load the texture data and generates the openGl
			 * 			texture buffers
			 * 
			 * @tparam	p_path Path to the texture
			 */
			void SetUpTexture(const std::string_view& p_path);
			
			/**
			 * @brief	Sets the texture openGl attributes
			 * 			(wrapping, mipmaps)
			 */
			void SetOpenGlTextureAttributes();

		public:
			Texture(const std::string_view& p_texturePath)
			{
				SetUpTexture(p_texturePath);
			}

			~Texture()
			{
			}

			/**
			 * @brief	Sets the texture type of the texture object
			 * 
			 * @tparam	p_type Type of the texture
			 */
			void SetTextureType(const std::string_view& p_type);

			/**
			 * @brief	Returns the opengl generated Id for this texture
			 * 
			 * @return	The openGl ID texture buffer
			 */
			glID getID();
	};
}
