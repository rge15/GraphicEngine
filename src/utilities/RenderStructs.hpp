#pragma once

#include <glm/glm.hpp>
namespace Ocacho
{

	using FaceIndex = unsigned int;
	using glID 		= unsigned int;
	using ShaderID  = int;
	
	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 vertexNormals;
		glm::vec2 textureCoords;

		Vertex(
			glm::vec3 p_pos,
			glm::vec3 p_normal,
			glm::vec2 p_UV ):
			position { p_pos },
			vertexNormals { p_normal },
			textureCoords { p_UV }
		{}
	};

}