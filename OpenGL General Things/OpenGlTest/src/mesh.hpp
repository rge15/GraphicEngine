#pragma once

#include "Shader.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>

#include <vector>
#include <iostream>

namespace Ocacho
{

	struct Vertex
	{
		glm::vec3  Position;
		glm::vec3  Normal;
		glm::vec2  TextCoord;
		glm::ivec4 JointInfluence;
		glm::vec4  InfluenceWeight;
	};

	struct Texture
	{
		unsigned int		ID;
		std::string_view	type;
		std::string_view	path;
	};

	class Mesh
	{
		private:
			std::vector<Vertex>			vertex_;
			std::vector<unsigned int>	index_;
			std::vector<Texture>		textures_;

			unsigned int VBO;
			unsigned int VAO;
			unsigned int EBO;

		public:
			Mesh(const std::vector<Vertex>& p_vertex, const std::vector<unsigned int>& p_index,const std::vector<Texture>& p_textures)
			{
				vertex_ 	= p_vertex;
				index_ 		= p_index;
				textures_ 	= p_textures;

				// std::cout << "Aqui están los vertices : \n";

				// for(std::size_t i = 0 ; i < vertex_.size(); i++)
				// 	std::cout << i << " : " << vertex_[i].Position.x << " , " << vertex_[i].Position.y << " , " << vertex_[i].Position.z << '\n';

				// std::cout << "Aqui están los indices : \n";

				// for(std::size_t i = 0 ; i < index_.size(); i = i + 3)
				// 	std::cout << index_[i] << " , " << index_[i+1] << " , " << index_[i+2] << '\n';



				SetUpMesh();
			};

			~Mesh(){};

			void SetUpMesh();
			void Draw(const Shader& p_shader);
	};
}