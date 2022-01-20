#include "Texture.hpp"


namespace Ocacho
{

	void Texture::SetUpTexture(const std::string_view& p_texturePath)
	{
		int width, height, nrComponents;

		stbi_set_flip_vertically_on_load(true);
		unsigned char *data = stbi_load( p_texturePath.data(), &width, &height, &nrComponents, 0);

		assert(data);

		glGenTextures(1, &ID_);

		GLenum format;

		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else
			format = GL_RGBA;

		//Generate the buffer with the texture
		glBindTexture(GL_TEXTURE_2D, ID_);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

		//Edit texture attributes
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}

}
