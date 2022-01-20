#pragma once

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>

#include "../utilities/RenderStructs.hpp"
#include "Shader.hpp"


namespace Ocacho
{
	class Mesh
	{
		private:
			std::vector<Vertex> 	vertex_;
			std::vector<FaceIndex>	index_;
			//Esto por ahora será un solo material, 
			//en futuros upgrades hará falta un vector
			//de materials

			glID VBO;
			glID VAO;
			glID EBO;
		
		public:
			Mesh( const std::vector<Vertex> p_vertexList,
				  const std::vector<FaceIndex> p_indexList):
				  vertex_ { p_vertexList },
				  index_ { p_indexList }
				{
					SetUpMesh();
				}

			~Mesh(){};

			void SetUpMesh();
			
			void Draw();
	};
}
