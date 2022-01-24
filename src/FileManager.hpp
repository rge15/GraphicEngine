#pragma once

#include <unordered_map>
#include <string_view>
#include <memory>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>	
#include <assimp/postprocess.h>

#include "Scene/Model.hpp"
#include "FileManager/FileManagerFlags.hpp"


namespace Ocacho
{
	class FileManager
	{
		private:
			std::unordered_map<std::size_t, std::unique_ptr<Mesh>* const>		meshFileMemory_;
			std::unordered_map<std::size_t, std::unique_ptr<Texture>* const>	textureFileMemory_;
			std::unordered_map<std::size_t, std::unique_ptr<Material>* const>	materialFileMemory_;
			std::unordered_map<std::size_t, std::unique_ptr<Shader>* const>		shaderFileMemory_;

			std::vector<std::unique_ptr<Mesh>>		loadedMeshes_;
			std::vector<std::unique_ptr<Texture>>	loadedTextures_;
			std::vector<std::unique_ptr<Material>>	loadedMaterials_;
			std::vector<std::unique_ptr<Shader>>	loadedShaders_;

			std::size_t meshIndex_ { 0 };
			std::size_t textureIndex_ { 0 };
			std::size_t materialIndex_ { 0 };
			std::size_t shaderIndex_ { 0 };

			// *** Métodos cargar malla
			std::unique_ptr<Mesh> GetMeshFromFile(const std::string_view& p_path );

			void LoadMeshFromFile(	
				const aiMesh* const p_meshNode, 
				std::vector<Vertex>& p_vertex,
				std::vector<unsigned int>& p_index);
			
			void LoadVertexData(
				const aiMesh* const p_meshNode, 
				std::vector<Vertex>& p_vertex);
			
			void LoadIndexData(
				const aiMesh* const p_meshNode, 
				std::vector<unsigned int>& p_index);
			
			const aiMesh* const SearchMeshInScene(
				const aiScene* const p_scene);
			// *** Métodos cargar malla
			
			// *** Métodos cargar texturas
			std::unique_ptr<Texture> GetTextureFromFile(
				const std::string_view& p_path );
			// *** Métodos cargar texturas

			// *** Método cargar material
			std::vector<Texture*>	LoadMaterialTextures(
				const std::size_t p_textures[]
			);
			// *** Método cargar material

			// *** Método crear/cargar shader 
			std::unique_ptr<Shader> GetShaderFromFiles(
				const std::string_view& p_vertexPath,
				const std::string_view& p_fragmentPath
			);
			// **** Método crear/cargar shader

		public:
			FileManager(){
				loadedMeshes_.reserve(10);
				loadedTextures_.reserve(10);
				loadedMaterials_.reserve(10);
				loadedShaders_.reserve(10);
			};
			~FileManager(){};
			
			// *** Métodos cargar malla
			std::size_t LoadMesh( const std::string_view& p_meshPath )
			{
				//Aquí guardar path para evitar replicados en el futuro

				loadedMeshes_.emplace_back( std::move(GetMeshFromFile(p_meshPath)) );
				meshFileMemory_.insert( { meshIndex_, &loadedMeshes_[meshIndex_] } );

				return meshIndex_++;
			}
			// *** Métodos cargar malla

			// *** Métodos cargar textura
			std::size_t LoadTexture( const std::string_view& p_texturePath )
			{
				//Aquí guardar path para evitar replicados en el futuro
				loadedTextures_.emplace_back( std::move(GetTextureFromFile(p_texturePath)) );
				textureFileMemory_.insert( { textureIndex_, &loadedTextures_[textureIndex_] } );

				return textureIndex_++;
			}
			// *** Métodos cargar texturas

			// *** Métodos cargar materiales
			std::size_t AddMaterial( const std::size_t p_textures[] )
			{
				loadedMaterials_.emplace_back( std::make_unique<Material>( LoadMaterialTextures(p_textures)) );
				materialFileMemory_.insert( { materialIndex_, &loadedMaterials_[materialIndex_] } );
			
				return materialIndex_++;
			}

			std::size_t AddMaterial( const glm::vec3 p_color )
			{
				loadedMaterials_.emplace_back( std::make_unique<Material>( p_color ));
				materialFileMemory_.insert( { materialIndex_, &loadedMaterials_[materialIndex_] } );
			
				return materialIndex_++;
			}
			// *** Métodos cargar materiales

			// *** Métodos cargar shaders
			std::size_t LoadShader(	const std::string_view& p_vertexPath,
									const std::string_view& p_fragmentPath )
			{
				loadedShaders_.emplace_back( 
					std::move( GetShaderFromFiles(p_vertexPath, p_fragmentPath) ));

				shaderFileMemory_.insert( { shaderIndex_, &loadedShaders_[shaderIndex_] } );

				return shaderIndex_++;
			}
			// *** Métodos cargar shaders

			// *** Getters
			Texture* getTexture(const std::size_t p_indexValue)
			{
				assert(!(p_indexValue >= textureIndex_ || p_indexValue < 0 ));
				return textureFileMemory_.at(p_indexValue)->get();
			}

			Mesh* getMesh(const std::size_t p_indexValue)
			{
				assert(!(p_indexValue >= meshIndex_ || p_indexValue < 0 ));
				return meshFileMemory_.at(p_indexValue)->get();
			}

			Material* getMaterial(const std::size_t p_indexValue)
			{
				assert(!(p_indexValue >= materialIndex_ || p_indexValue < 0 ));
				return materialFileMemory_.at(p_indexValue)->get();
			}

			Shader* getShader(const std::size_t p_indexValue)
			{
				assert(!(p_indexValue >= shaderIndex_ || p_indexValue < 0 ));
				return shaderFileMemory_.at(p_indexValue)->get();
			}

	};
}