#pragma once


#include "../stb_image.h"
#include "mesh.hpp"
#include "Shader.hpp"

#include <vector>
#include <string_view>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>	
#include <assimp/postprocess.h>


namespace Ocacho
{
	class Model
	{
		private:
			std::vector<Vertex> 		MeshProcessVertex(const aiMesh* const p_mesh);
			std::vector<unsigned int> 	MeshProcessIndex(const aiMesh* const p_mesh);
			std::vector<Texture>		MeshProcessMaterial(const aiMesh* const p_mesh, const aiScene* const p_scene);

			std::vector<Texture> 	LoadMaterialTextureType(const aiMaterial* const p_mat, 
															const aiTextureType p_type, 
															const std::string_view p_typename);

			unsigned int 			GenerateTextureFromFile(const char* const p_textName, 
															const std::string_view p_directory);


			std::vector<Texture> loadedTextures_;

			void LoadModel(const std::string& p_path);

			void ProcessNode(const aiNode* const p_node, const aiScene* const p_scene);

			Mesh ProcessMesh(const aiMesh* const p_mesh, const aiScene* const p_scene);

		public:
			std::vector<Mesh> 	meshes_;
			std::string_view	directory_;

			Model(const std::string& p_modelPath) { LoadModel( p_modelPath ); };
			~Model(){};



			void DrawModel(const Shader& p_shader);
	};
}