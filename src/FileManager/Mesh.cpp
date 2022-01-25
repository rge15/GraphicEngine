#include "Mesh.hpp"

namespace Ocacho
{

	void Mesh::SetUpMesh()
	{
		glGenVertexArrays(1, &VAO_);
		glGenBuffers(1, &VBO_);
		glGenBuffers(1, &EBO_);

		glBindVertexArray(VAO_);

		glBindBuffer(GL_ARRAY_BUFFER, VBO_);
		glBufferData(GL_ARRAY_BUFFER, vertex_.size() * sizeof(Vertex), &vertex_[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_.size() * sizeof(FaceIndex), &index_[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, vertexNormals));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoords));

		glBindVertexArray(0);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Mesh::Draw()
	{
		glBindVertexArray(VAO_);
		glDrawElements(GL_TRIANGLES, index_.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

}