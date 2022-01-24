#pragma once

#include <unordered_map>
#include <string_view>
#include <memory>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>	
#include <assimp/postprocess.h>


#include "../stb_image.h"
#include "SceneComponents/Model.hpp"
#include "FileManager/FileManagerFlags.hpp"


namespace Ocacho
{
	class FileManager
	{
		private:
			std::unordered_map<std::size_t, std::unique_ptr<Mesh>* const>	meshFileMemory_;
			// std::unordered_map<std::size_t, Material*>	materialFileMemory_;
			// std::unordered_map<std::size_t, Shader*>		shaderFileMemory_;


			std::vector<std::unique_ptr<Mesh>>	loadedMeshes_ { 10 };

			std::size_t meshIndex_ { 0 };

			// *** Métodos cargar malla
			std::unique_ptr<Mesh> GetMeshFromFile(const std::string& p_path );

			void LoadMeshFromFile(	const aiMesh* const p_meshNode,
									std::vector<Vertex>& p_vertex,
									std::vector<unsigned int>& p_index);

			void LoadVertexData(const aiMesh* const p_meshNode, std::vector<Vertex>& p_vertex);
			void LoadIndexData(const aiMesh* const p_meshNode, std::vector<unsigned int>& p_index);
			
			const aiMesh* const SearchMeshInScene(const aiScene* const p_scene);

			// *** Métodos cargar malla

		public:
			FileManager(){};
			~FileManager(){};

			//TODO : Hacer todos estos métodos cuando haya un sistema más desacoplado
			//todo : y una estructura de las clases del motor correctas
 
			//void LoadMaterial
			//void CreateShader();
			//void CreateFile();
			
			// *** Métodos cargar malla
			std::size_t LoadMesh( const std::string& p_meshPath )
			{
				loadedMeshes_.emplace_back( std::move(GetMeshFromFile(p_meshPath)) );
				meshFileMemory_.insert( { meshIndex_, &loadedMeshes_[meshIndex_] } );

				return meshIndex_++;
			}
			// *** Métodos cargar malla
			
	};
}