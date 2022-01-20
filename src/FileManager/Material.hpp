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

		public:
			std::vector<Texture*>	textures_;
			glm::vec3 			 	baseColor_ { 1.0, 0.0, 0.0 };
			
			Material(const std::vector<Texture*> p_textures):
					 textures_ { p_textures }
			{}

			~Material(){};

			void SetBaseColor( const glm::vec4 p_color )
			{
				baseColor_ = p_color;
			}

			// void PrepareMaterialForRendering();

			// void TextureMaterial();
			// void BaseColorMaterial();
	};
}