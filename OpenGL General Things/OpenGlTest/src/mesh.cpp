#include "mesh.hpp"



namespace Ocacho
{
	void Mesh::SetUpMesh()
	{
		// We generate the buffers for rendering
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		//We bind the Vertex Array Buffer ...
		glBindVertexArray(VAO);

		//... and load there all the info.
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertex_.size() * sizeof(Vertex), &vertex_[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_.size() * sizeof(unsigned int), &index_[0], GL_STATIC_DRAW);

		//We enable all the vertex attributes
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TextCoord));

		glBindVertexArray(0);
	}

	void Mesh::Draw(const Shader& p_shader)
	{
		// unsigned int diffuseNr  = 1;
        // unsigned int specularNr = 1;
        // unsigned int normalNr   = 1;
        // unsigned int heightNr   = 1;
        // for(unsigned int i = 0; i < textures_.size(); i++)
        // {
            // glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
            // // retrieve texture number (the N in diffuse_textureN)
            // std::string_view number;
            // std::string_view name = textures_[i].type;
            // if(name == "texture_diffuse")
                // number = std::to_string(diffuseNr++);
            // else if(name == "texture_specular")
                // number = std::to_string(specularNr++); // transfer unsigned int to string
            // else if(name == "texture_normal")
                // number = std::to_string(normalNr++); // transfer unsigned int to string
            //  else if(name == "texture_height")
                // number = std::to_string(heightNr++); // transfer unsigned int to string

            // // now set the sampler to the correct texture unit
            // glUniform1i(glGetUniformLocation(p_shader.ID_, (std::string(name) + std::string(number)).c_str()), i);
            // // and finally bind the texture
            // glBindTexture(GL_TEXTURE_2D, textures_[i].ID);
        // }

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, index_.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}