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
			glID				ID_;
			std::string_view	type_;

			void SetUpTexture(const std::string_view& p_path);

		public:

			Texture(const std::string_view& p_texturePath)
			{
				SetUpTexture(p_texturePath);
			}

			~Texture()
			{
			}

			void SetTextureType(const std::string_view& p_type)
			{
				type_ = p_type;
			}

	};
}
