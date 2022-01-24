#include "FileManager.hpp"


namespace Ocacho
{
	std::unique_ptr<Mesh> FileManager::GetMeshFromFile(
		const std::string_view& p_path)
	{
		Assimp::Importer modelImporter;
		const aiScene* const scene  = modelImporter.ReadFile(p_path.data(), loadMeshFlags);

		const aiMesh* const mesh { SearchMeshInScene(scene) };

		std::unique_ptr<Mesh> loadedMesh;
		loadedMesh =  std::make_unique<Mesh>( LoadMeshFromAssimpMesh( mesh ) );

		return  loadedMesh;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	Mesh FileManager::LoadMeshFromAssimpMesh(
		const aiMesh* const p_meshNode)
	{
		std::vector<Vertex> vertexData { LoadVertexData(p_meshNode) };
		
		std::vector<unsigned int> indexData { LoadIndexData(p_meshNode) };

		return Mesh( vertexData, indexData );
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	std::vector<Vertex> FileManager::LoadVertexData(
		const aiMesh* const p_meshNode)
	{
		std::vector<Vertex> vertexList;

		std::size_t nuwVertex = p_meshNode->mNumVertices;

		vertexList.reserve( nuwVertex );

		for(std::size_t i = 0 ; i < nuwVertex; i++)
		{				
			vertexList.emplace_back( LoadVertex( p_meshNode, i ) );
		}

		return vertexList;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	Vertex FileManager::LoadVertex(
		const aiMesh* const p_meshNode, 
		const std::size_t p_id)
	{
		glm::vec3 vertexPos;
		glm::vec3 vertexNormal;
		glm::vec2 vertexUV;

		vertexPos = LoadVertexPostion(
			p_meshNode,
			p_id
		);

		vertexNormal = LoadVertexNormal(
			p_meshNode,
			p_id
		);

		vertexUV = LoadVertexUV(
			p_meshNode,
			p_id
		);

		return Vertex(
			vertexPos,
			vertexNormal,
			vertexUV
		);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	glm::vec3 FileManager::LoadVertexPostion(
		const aiMesh* const p_meshNode, 
		const std::size_t p_id)
	{
		aiVector3D VertexPos;

		VertexPos 	= p_meshNode->mVertices[p_id];

		return glm::vec3(
			VertexPos.x, 
			VertexPos.y, 
			VertexPos.z);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	glm::vec3 FileManager::LoadVertexNormal(
		const aiMesh* const p_meshNode, 
		const std::size_t p_id)
	{
		aiVector3D vertexNormal;

		vertexNormal = p_meshNode->mNormals[p_id];

		return glm::vec3(
			vertexNormal.x, 
			vertexNormal.y, 
			vertexNormal.z);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	glm::vec2 FileManager::LoadVertexUV(
		const aiMesh* const p_meshNode, 
		const std::size_t p_id)
	{
		aiVector2D vertexUV;

		if(p_meshNode->mTextureCoords[0])
		{
			vertexUV.x = p_meshNode->mTextureCoords[0][p_id].x;
			vertexUV.y = p_meshNode->mTextureCoords[0][p_id].y;
			
			return glm::vec2(vertexUV.x, vertexUV.y);
		}else
			return glm::vec2(0.0f, 0.0f);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	std::vector<unsigned int>  FileManager::LoadIndexData(
		const aiMesh* const p_meshNode) 
	{
		std::vector<unsigned int> indexData; 

		indexData.reserve(p_meshNode->mNumFaces * 3);

		for(std::size_t i = 0 ; i < p_meshNode->mNumFaces; i++)
		{
			aiFace face = p_meshNode->mFaces[i];

			//Esto se tiene que poder optimizar como enseño Fran
			for(std::size_t j = 0 ; j < face.mNumIndices; j++)
				indexData.push_back(face.mIndices[j]);
		}

		return indexData;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	const aiMesh* const FileManager::SearchMeshInScene(
		const aiScene* const p_scene)
	{
		assert(p_scene->mNumMeshes);
		return p_scene->mMeshes[0];
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	std::unique_ptr<Texture> FileManager::GetTextureFromFile(
		const std::string_view& p_path )
	{
		return std::make_unique<Texture>(p_path);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	std::vector<Texture*> FileManager::LoadMaterialTextures(
		const std::size_t p_textureIndex[])
	{
		std::vector<Texture*> textures;
		std::size_t sizeArray = sizeof(p_textureIndex)/sizeof(p_textureIndex[0]);

		assert(!(sizeArray <= 0));

		textures.reserve(sizeArray);

		for(std::size_t i { 0 } ; i < sizeArray ; i++)
			textures.emplace_back( getTexture( p_textureIndex[i]) );

		return textures;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	std::unique_ptr<Shader> FileManager::GetShaderFromFiles(
		const std::string_view& p_vertexPath,
		const std::string_view& p_fragmentPath)
	{
		std::unique_ptr<Shader> shader = std::make_unique<Shader>(
			p_vertexPath, 
			p_fragmentPath);
		return shader;
	}

}