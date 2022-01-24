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
			void LoadTexturesInShader(Shader* const p_shader);

			void LoadBaseColorInShader(Shader* const p_shader);

			void SetShaderData(Shader* const p_shader);

		public:
			std::vector<Texture*>	textures_;
			glm::vec3 			 	baseColor_ { 0.3, 0.3, 0.3 };
			
			Material(const std::vector<Texture*> p_textures):
					 textures_ { p_textures }
			{}

			Material(const glm::vec3 p_baseColor):
					 baseColor_ { p_baseColor }
			{}

			~Material(){};

			void SetBaseColor( const glm::vec4 p_color )
			{
				baseColor_ = p_color;
			}

			void UseMaterial(Shader* const p_shader);

	};
}