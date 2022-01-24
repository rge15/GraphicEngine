#include "Material.hpp"


namespace Ocacho
{
	void Material::UseMaterial(Shader* const p_shader)
	{
		SetShaderData(p_shader);
	}

	void Material::SetShaderData(Shader* const p_shader)
	{
		if(textures_.size() != 0)
		{
			p_shader->SetInt("textureFlag", 1);
			LoadTexturesInShader( p_shader );
		}
		else
		{
			p_shader->SetInt("textureFlag", 0);
			LoadBaseColorInShader( p_shader );
		}
	}

	//En estos momentos este método solo activa la primera textura pq solo vamos a hacer uso de una
	void Material::LoadTexturesInShader(Shader* const p_shader)
	{
		for(std::size_t i = 0; i < textures_.size(); i++)
    	{
			glActiveTexture(GL_TEXTURE0 + i); // activate proper texture unit before binding

			p_shader->SetFloat("texture1", i);

			glBindTexture(GL_TEXTURE_2D, textures_[i]->getID());
    	}
    	glActiveTexture(GL_TEXTURE0);
	}

	void Material::LoadBaseColorInShader(Shader* const p_shader)
	{
		p_shader->SetFloat3("u_baseColor", baseColor_);
	}

}