#pragma once

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
		// glm::ivec4 JointInfluence;
		// glm::vec4  InfluenceWeight;
	};
	
	struct Texture
	{
		unsigned int		ID;
		std::string_view	type;
		std::string_view	path;
	};

}