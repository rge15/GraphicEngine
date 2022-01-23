#include "Material.hpp"


namespace Ocacho
{
	// void Material::TextureMaterial()
	// {
	// 	unsigned int diffuseNr  = 1;
    //     unsigned int specularNr = 1;
    //     unsigned int normalNr   = 1;
    //     unsigned int heightNr   = 1;

    //     for(unsigned int i = 0; i < textures_.size(); i++)
    //     {
	// 		glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
	// 		// retrieve texture number (the N in diffuse_textureN)
	// 		std::string_view number;
	// 		std::string_view name = textures_[i].type;
	// 		if(name == "texture_diffuse")
	// 		    number = std::to_string(diffuseNr++);
	// 		else if(name == "texture_specular")
	// 		    number = std::to_string(specularNr++); // transfer unsigned int to string
	// 		else if(name == "texture_normal")
	// 		    number = std::to_string(normalNr++); // transfer unsigned int to string
	// 		else if(name == "texture_height")
	// 		    number = std::to_string(heightNr++); // transfer unsigned int to string

	// 		// now set the sampler to the correct texture unit
	// 		shader_->SetInt((std::string(name) + std::string(number)).c_str(), i);

	// 		// and finally bind the texture
	// 		glBindTexture(GL_TEXTURE_2D, textures_[i].ID);
	// 	}
	// }

	void Material::UseMaterial(Shader* const p_shader)
	{
		SetShaderColor(p_shader);
		SetShaderTextures(p_shader);
	}

	void Material::SetShaderColor(Shader* const p_shader)
	{
		p_shader->SetFloat3("u_baseColor", baseColor_);
	}

	void Material::SetShaderTextures(Shader* const p_shader)
	{

	}
}