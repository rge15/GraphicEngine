#include "FileManager.hpp"


namespace Ocacho
{
	std::unique_ptr<Mesh> FileManager::GetMeshFromFile(const std::string_view& p_path)
	{
		//Cargamos realmente el archivo
		Assimp::Importer modelImporter;
		const aiScene* const scene = modelImporter.ReadFile(p_path.data(), loadMeshFlags);
		assert(scene);

		std::vector<Vertex>  meshVertex;
		std::vector<unsigned int> meshIndex;
		std::unique_ptr<Mesh> loadedMesh;

		LoadMeshFromFile( SearchMeshInScene( scene ), meshVertex, meshIndex);

		loadedMesh =  std::make_unique<Mesh>( meshVertex, meshIndex );

		// std::cout << "Mesh cargada :" << loadedMesh.get() << '\n';

		return  loadedMesh;
	}

	void FileManager::LoadMeshFromFile( const aiMesh* const p_meshNode,
										std::vector<Vertex>& p_vertex,
										std::vector<unsigned int>& p_index )
	{
		LoadVertexData(p_meshNode, p_vertex);
		LoadIndexData(p_meshNode, p_index);
	}

	void FileManager::LoadVertexData(const aiMesh* const p_meshNode, 
									 std::vector<Vertex>& p_vertex)
	{
		Vertex vertex;

		aiVector3D VertexData;
		aiVector3D Normal;
		aiVector2D UV;

		p_vertex.reserve(p_meshNode->mNumVertices);

		for(std::size_t i = 0 ; i < p_meshNode->mNumVertices; i++)
		{
			VertexData 	= p_meshNode->mVertices[i];
			Normal 	= p_meshNode->mNormals[i];

			vertex.position = glm::vec3(VertexData.x, VertexData.y, VertexData.z);
			vertex.vertexNormals = glm::vec3(Normal.x, Normal.y, Normal.z);

			if(p_meshNode->mTextureCoords[0])
			{
				UV.x = p_meshNode->mTextureCoords[0][i].x;
				UV.y = p_meshNode->mTextureCoords[0][i].y;
				vertex.textureCoords = glm::vec2(UV.x, UV.y);
			}else
				vertex.textureCoords = glm::vec2(0.0f, 0.0f);
				
			p_vertex.emplace_back(vertex);
		}
	}

	void FileManager::LoadIndexData(const aiMesh* const p_meshNode, 
									std::vector<unsigned int>& p_index)
	{

		p_index.reserve(p_meshNode->mNumFaces * 3);

		for(std::size_t i = 0 ; i < p_meshNode->mNumFaces; i++)
		{
			aiFace face = p_meshNode->mFaces[i];

			for(std::size_t j = 0 ; j < face.mNumIndices; j++)
				p_index.push_back(face.mIndices[j]);

		}
	}

	const aiMesh* const FileManager::SearchMeshInScene(const aiScene* const p_scene)
	{
		//Checkeamos que haya alguna malla para cargar
		assert(p_scene->mNumMeshes);
		return p_scene->mMeshes[0];
	}

	std::unique_ptr<Texture> FileManager::GetTextureFromFile(const std::string_view& p_path )
	{
		//Creo la textura y la devuelvo
		return std::make_unique<Texture>(p_path);
	}

	std::vector<Texture*> FileManager::LoadMaterialTextures(const std::size_t p_textureIndex[])
	{
		std::vector<Texture*> textures;
		std::size_t sizeArray = sizeof(p_textureIndex)/sizeof(p_textureIndex[0]);

		assert(!(sizeArray <= 0));

		textures.reserve(sizeArray);

		for(std::size_t i { 0 } ; i < sizeArray ; i++)
			textures.emplace_back( getTexture( p_textureIndex[i]) );

		return textures;
	}

	std::unique_ptr<Shader> FileManager::GetShaderFromFiles(
		const std::string_view& p_vertexPath,
		const std::string_view& p_fragmentPath)
	{
		std::unique_ptr<Shader> shader = std::make_unique<Shader>(p_vertexPath, p_fragmentPath);
		return shader;
	}

}