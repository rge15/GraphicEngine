/**
 * @file Mesh.hpp
 * @author OcachoGames-Rodrigo (ocachogames@gmail.com)
 * @brief Mesh of Ocacho Graphic Engine
 * 
 * A mesh will have the info of the vertex
 * and the faces of the mesh. It manages the
 * openGl buffer data. 
 * 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2021
 */
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
			//	Vector of vertex of the mesh
			std::vector<Vertex> 	vertex_;

			//	Vector of the face index of the mesh
			std::vector<FaceIndex>	index_;

			// Vertex Array OpenGl Object ID
			glID VAO_;

			// Vertex Buffer OpenGl Object ID for Vertex Data
			glID VBO_;

			// ELement Buffer OpenGl Object ID for Face Data
			glID EBO_;
		
		public:
			Mesh( const std::vector<Vertex> p_vertexList,
				  const std::vector<FaceIndex> p_indexList):
				  vertex_ { p_vertexList },
				  index_ { p_indexList }
				{
					SetUpMesh();
				}

			~Mesh(){};

			/**
			 * @brief	Generates the openGl buffers eith the mesh data
			 */
			void SetUpMesh();

			/**
			 * @brief	Draws the buffers openGl data
			 */			
			void Draw();
	};
}
