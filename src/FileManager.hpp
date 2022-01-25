/**
 * @file FileManager.hpp
 * @author OcachoGames-Rodrigo (ocachogames@gmail.com)
 * @brief FileManager of Ocacho Graphic Engine
 * 
 * The file manager will manage the intancies of each resource
 * in memory and will manage the acces to the resources content 
 * 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2021
 */
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
	using	MeshUniqPtr = std::unique_ptr<Mesh>;
	using	TextureUniqPtr = std::unique_ptr<Texture>;
	using	MaterialUniqPtr = std::unique_ptr<Material>;
	using	ShaderUniqPtr = std::unique_ptr<Shader>;
	
	class FileManager
	{
		private:
			//Map to know where is each mesh data in memory
			std::unordered_map<	std::size_t,
								MeshUniqPtr* const>		meshFileMemory_;
			//Map to know where is each texture data in memory
			std::unordered_map<	std::size_t,
								TextureUniqPtr* const>	textureFileMemory_;
			//Map to know where is each material data in memory
			std::unordered_map<	std::size_t,
								MaterialUniqPtr* const>	materialFileMemory_;
			//Map to know where is each shader data in memory
			std::unordered_map<	std::size_t,
								ShaderUniqPtr* const>	shaderFileMemory_;

			// Vector of each mesh in memory
			std::vector<MeshUniqPtr>		loadedMeshes_;
			// Vector of each texture in memory
			std::vector<TextureUniqPtr>		loadedTextures_;
			// Vector of each material in memory
			std::vector<MaterialUniqPtr>	loadedMaterials_;
			// Vector of each shader in memory
			std::vector<ShaderUniqPtr>		loadedShaders_;

			//Counter of meshes in memory
			std::size_t meshIndex_ { 0 };
			//Counter of textures in memory
			std::size_t textureIndex_ { 0 };
			//Counter of materials in memory
			std::size_t materialIndex_ { 0 };
			//Counter of shaders in memory
			std::size_t shaderIndex_ { 0 };

			/**
			 * @brief	Returns a Mesh object from a given path 
			 * 
			 * @tparam	Path where is the mesh to load
			 * 
			 * @return	UniquePtr of the loaded mesh
			 */
			std::unique_ptr<Mesh> GetMeshFromFile(
				const std::string_view& p_path);

			/**
			 * @brief	Returns a Mesh object from a given mesh assimp node
			 * 
			 * @tparam	Mesh assimp node with the mesh data
			 * 
			 * @return	Loaded Mesh object
			 */
			Mesh LoadMeshFromAssimpMesh(	
				const aiMesh* const p_meshNode);
			
			/**
			 * @brief	Returns a vector of Vertex data for a mesh
			 * 
			 * @tparam	p_meshNode = Mesh assimp node with the mesh data
			 * 
			 * @return	Vertex data of the mesh
			 */
			std::vector<Vertex> LoadVertexData(
				const aiMesh* const p_meshNode);
			
			/**
			 * @brief	Returns a single Vertex from a 
			 * 		  	mesh and his index in the mesh
			 * 
			 * @tparam 	p_meshNode Mesh assimp node with the mesh data
			 * @tparam	p_id given Vertex ID
			 * 
			 * @return 	Vertex data of the mesh
			 */
			Vertex LoadVertex(
				const aiMesh* const p_meshNode, 
				const std::size_t p_id);
			
			/**
			 * @brief	Returns the position of a vertex
			 * 
			 * @tparam 	p_meshNode Mesh assimp node with the mesh data
			 * @tparam	p_id given Vertex ID
			 * 
			 * @return 	Vertex position of the mesh
			 */
			glm::vec3 LoadVertexPostion(
				const aiMesh* const p_meshNode, 
				const std::size_t p_id);

			/**
			 * @brief	Returns the normal of a vertex
			 * 
			 * @tparam 	p_meshNode Mesh assimp node with the mesh data
			 * @tparam	p_id given Vertex ID
			 * 
			 * @return 	Vertex normal of the mesh
			 */
			glm::vec3 LoadVertexNormal(
				const aiMesh* const p_meshNode, 
				const std::size_t p_id);

			/**
			 * @brief	Returns the texture Coords of a vertex
			 * 
			 * @tparam 	p_meshNode Mesh assimp node with the mesh data
			 * @tparam	p_id given Vertex ID
			 * 
			 * @return 	Vertex texture Coords of the mesh
			 */
			glm::vec2 LoadVertexUV(
				const aiMesh* const p_meshNode, 
				const std::size_t p_id);

			/**
			 * @brief	Returns the index vertex of a face
			 * 
			 * @tparam 	p_meshNode Mesh assimp node with the mesh data
			 * 
			 * @return 	Vertex texture Coords of the mesh
			 */
			std::vector<unsigned int> LoadIndexData(
				const aiMesh* const p_meshNode);
			
			/**
			 * @brief	Returns a mesh Assimp Node
			 * 
			 * @tparam 	p_scene Scene assimp node with the mesh
			 * 
			 * @return 	The mesh Assimp Node
			 */
			const aiMesh* const SearchMeshInScene(
				const aiScene* const p_scene);
			
			/**
			 * @brief	Returns a texture Unique Ptr
			 * 
			 * @tparam	p_path Path where is the mesh to load
			 * 
			 * @return	UniquePtr of the loaded mesh
			 */
			TextureUniqPtr GetTextureFromFile(
				const std::string_view& p_path );

			/**
			 * @brief	Returns a vector of pointers to textures
			 * 			from the textures ID array 
			 * 
			 * @tparam	p_textures Array with the textures ID
			 * 
			 * @return	Vector of pointers to textures
			 */
			std::vector<Texture*>	LoadMaterialTextures(
				const std::size_t p_textures[]
			);

			/**
			 * @brief	Return a Shader Unique Ptr to a shader compiling his code 
			 * 
			 * @tparam	p_vertexPath Path to the vertex shader code
			 * @tparam	p_fragmentPath Path to the fragment shader code
			 * 
			 * @return	Unique ptr of a shader
			 */
			ShaderUniqPtr GetShaderFromFiles(
				const std::string_view& p_vertexPath,
				const std::string_view& p_fragmentPath
			);

		public:

			FileManager(){
				loadedMeshes_.reserve(10);
				loadedTextures_.reserve(10);
				loadedMaterials_.reserve(10);
				loadedShaders_.reserve(10);
			};
			~FileManager(){};
			
			/**
			 * @brief	Returns the index of the Mesh in memory 
			 * 			loaded from a given path 
			 * 
			 * @tparam	p_meshPath Path where is the mesh to load
			 * 
			 * @return	Index of Mesh in memory
			 */
			std::size_t LoadMesh( 
				const std::string_view& p_meshPath )
			{
				//Aquí guardar path para evitar replicados en el futuro

				loadedMeshes_.emplace_back( 
					std::move(GetMeshFromFile(p_meshPath)));
				
				meshFileMemory_.insert( 
					{ meshIndex_, &loadedMeshes_[meshIndex_] } );

				return meshIndex_++;
			}

			/**
			 * @brief	Returns the index of the Texture in memory 
			 * 			loaded from a given path 
			 * 
			 * @tparam	p_texturePath Path where is the texture to load
			 * 
			 * @return	Index of Texture in memory
			 */
			std::size_t LoadTexture( 
				const std::string_view& p_texturePath )
			{
				//Aquí guardar path para evitar replicados en el futuro
				loadedTextures_.emplace_back( 
					std::move(GetTextureFromFile(p_texturePath) ));

				textureFileMemory_.insert({
					textureIndex_, 
					&loadedTextures_[textureIndex_] });

				return textureIndex_++;
			}

			/**
			 * @brief	Returns the index of a Material in memory 
			 * 			created from Texture index
			 * 
			 * @tparam	p_textures Array of Index in memory of textures
			 * 
			 * @return	Index of Material in memory
			 */
			std::size_t AddMaterial( const std::size_t p_textures[] )
			{
				loadedMaterials_.emplace_back( 
					std::make_unique<Material>( LoadMaterialTextures(p_textures) ));
				
				materialFileMemory_.insert({
					materialIndex_, 
					&loadedMaterials_[materialIndex_] });
			
				return materialIndex_++;
			}

			/**
			 * @brief	Returns the index of a Material in memory 
			 * 			created from a base color
			 * 
			 * @tparam	p_color Color for the material
			 * 
			 * @return	Index of Material in memory
			 */
			std::size_t AddMaterial( const glm::vec3 p_color )
			{
				loadedMaterials_.emplace_back( 
					std::make_unique<Material>( p_color ));
				
				materialFileMemory_.insert({
					materialIndex_,
					&loadedMaterials_[materialIndex_] });
			
				return materialIndex_++;
			}

			/**
			 * @brief	Returns the index of a Shader in memory 
			 * 			created from the path's of the shader code
			 * 
			 * @tparam	p_vertexPath Path to the vertex shader code
			 * @tparam	p_fragmentPath Path to the fragment shader code
			 * 
			 * @return	Index of Shader in memory
			 */
			std::size_t LoadShader(	const std::string_view& p_vertexPath,
									const std::string_view& p_fragmentPath )
			{
				loadedShaders_.emplace_back( 
					std::move( GetShaderFromFiles(p_vertexPath, p_fragmentPath) ));

				shaderFileMemory_.insert({
					shaderIndex_, 
					&loadedShaders_[shaderIndex_] });

				return shaderIndex_++;
			}

			/**
			 * @brief	Returns the pointer to texture given
			 * 			the index of the texture in memory
			 * 
			 * @tparam	p_indexValue Index of texture in memory
			 * 
			 * @return	Pointer to texture in memory
			 */
			Texture* getTexture(const std::size_t p_indexValue)
			{
				assert(!(p_indexValue >= textureIndex_ || p_indexValue < 0 ));
				return textureFileMemory_.at(p_indexValue)->get();
			}

			/**
			 * @brief	Returns the pointer to Mesh given
			 * 			the index of the Mesh in memory
			 * 
			 * @tparam	p_indexValue Index of Mesh in memory
			 * 
			 * @return	Pointer to Mesh in memory
			 */
			Mesh* getMesh(const std::size_t p_indexValue)
			{
				assert(!(p_indexValue >= meshIndex_ || p_indexValue < 0 ));
				return meshFileMemory_.at(p_indexValue)->get();
			}

			/**
			 * @brief	Returns the pointer to Material given
			 * 			the index of the Material in memory
			 * 
			 * @tparam	p_indexValue Index of Material in memory
			 * 
			 * @return	Pointer to Material in memory
			 */
			Material* getMaterial(const std::size_t p_indexValue)
			{
				assert(!(p_indexValue >= materialIndex_ || p_indexValue < 0 ));
				return materialFileMemory_.at(p_indexValue)->get();
			}

			/**
			 * @brief	Returns the pointer to Shader given
			 * 			the index of the Shader in memory
			 * 
			 * @tparam	p_indexValue Index of Shader in memory
			 * 
			 * @return	Pointer to Shader in memory
			 */
			Shader* getShader(const std::size_t p_indexValue)
			{
				assert(!(p_indexValue >= shaderIndex_ || p_indexValue < 0 ));
				return shaderFileMemory_.at(p_indexValue)->get();
			}
	};
}