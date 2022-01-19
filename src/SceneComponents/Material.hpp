#pragma once

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>

#include "../utilities/RenderStructs.hpp"
#include "Shader.hpp"

namespace Ocacho
{
	class Material
	{
		private:

		public:
			std::vector<Texture> textures_;
			glm::vec3 			 baseColor_ { 1.0, 0.0, 0.0 };
			const Shader*		 shader_;

			Material( const Shader* const p_shader, 
					  const glm::vec3 p_baseColor) :
					  shader_ { p_shader },
					  baseColor_ { p_baseColor }
			{}
			
			Material(const std::vector<Texture> p_textures) :
					 textures_ { p_textures }
			{}

			Material(const std::vector<Texture> p_textures,
					 const Shader* const p_shader) :
					 textures_ { p_textures },
					 shader_ { p_shader }
			{}

			~Material();

			void PrepareMaterialForRendering();

			void TextureMaterial();
			void BaseColorMaterial();
	};
}