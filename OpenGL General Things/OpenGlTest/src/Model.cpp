#include "Model.hpp"
#include <iostream>

namespace Ocacho
{
	void Model::LoadModel(const std::string& p_path)
	{
		//Cargamos realmente el archivo
		Assimp::Importer modelImporter;

		const aiScene* scene = modelImporter.ReadFile(p_path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

		assert(scene);

		std::string finalPath { p_path.substr(0, p_path.find_last_of('/')) };
		directory_ = finalPath;

		aiNode* rootNode = scene->mRootNode;
		ProcessNode(rootNode, scene);
	}

	void Model::ProcessNode(const aiNode* const p_node,const aiScene* const p_scene)
	{
		meshes_.reserve(p_node->mNumMeshes);
		for(std::size_t i = 0 ; i < p_node->mNumMeshes; i++)
			meshes_.push_back( ProcessMesh(p_scene->mMeshes[p_node->mMeshes[i]], p_scene) );

		for(std::size_t i = 0 ; i < p_node->mNumChildren; i++)
			ProcessNode(p_node->mChildren[i], p_scene);
	}

	Mesh Model::ProcessMesh(const aiMesh* const p_mesh, const aiScene* const p_scene)
	{
		std::vector<Vertex>  meshVertex = MeshProcessVertex(p_mesh);
		std::vector<unsigned int> meshIndex = MeshProcessIndex(p_mesh);
		std::vector<Texture> meshTextures = MeshProcessMaterial(p_mesh, p_scene);

		return Mesh(meshVertex, meshIndex, meshTextures);
	}

	std::vector<Vertex> Model::MeshProcessVertex(const aiMesh* const p_mesh)
	{
		std::vector<Vertex> vertexVector;

		Vertex vertex;

		aiVector3D VertexData;
		aiVector3D Normal;
		aiVector3D UV;

		for(std::size_t i = 0 ; i < p_mesh->mNumVertices; i++)
		{
			VertexData 	= p_mesh->mVertices[i];
			Normal 	= p_mesh->mNormals[i];

			vertex.Position = glm::vec3(VertexData.x, VertexData.y, VertexData.z);
			vertex.Normal = glm::vec3(Normal.x, Normal.y, Normal.z);

			if(p_mesh->mTextureCoords[0])
			{
				UV = p_mesh->mTextureCoords[0][i];
				vertex.TextCoord = glm::vec2(UV.x, UV.y);
			}else
				vertex.TextCoord = glm::vec2(0.0f, 0.0f);
				
			vertexVector.push_back(vertex);
		}

		return vertexVector;
	}

	std::vector<unsigned int> Model::MeshProcessIndex(const aiMesh* const p_mesh)
	{
		std::vector<unsigned int> meshIndex;

		for(std::size_t i = 0 ; i < p_mesh->mNumFaces; i++)
		{
			aiFace face = p_mesh->mFaces[i];

			for(std::size_t j = 0 ; j < face.mNumIndices; j++)
				meshIndex.push_back(face.mIndices[j]);

		}

		return meshIndex;
	}

	//Aquí estarán las texturas que queramos recoger 
	std::vector<Texture> Model::MeshProcessMaterial(const aiMesh* const p_mesh, 
													const aiScene* const p_scene)
	{
		const aiMaterial* const material = p_scene->mMaterials[p_mesh->mMaterialIndex];

		///std::vector<Texture> meshTextures;
		//Cargamos las texturas de los tipos que queramos
		//Metemos las texturas cargadas en el meshTextures
	    // 1. diffuse maps
        //std::vector<Texture> diffuseMaps = LoadMaterialTextureType(material, aiTextureType_DIFFUSE, "texture_diffuse");
        // 2. specular maps
        // std::vector<Texture> specularMaps = LoadMaterialTextureType(material, aiTextureType_SPECULAR, "texture_specular");
        // 3. normal maps
        // std::vector<Texture> normalMaps = LoadMaterialTextureType(material, aiTextureType_HEIGHT, "texture_normal");
        // 4. height maps
        //std::vector<Texture> heightMaps = LoadMaterialTextureType(material, aiTextureType_AMBIENT, "texture_height");

		// uint8_t sizeVector = diffuseMaps.size() + specularMaps.size() + normalMaps.size() + heightMaps.size();
		// meshTextures.resize(sizeVector);

        // meshTextures.insert(meshTextures.end(), diffuseMaps.begin(), diffuseMaps.end());
        // meshTextures.insert(meshTextures.end(), specularMaps.begin(), specularMaps.end());
        // meshTextures.insert(meshTextures.end(), normalMaps.begin(), normalMaps.end());
		// meshTextures.insert(meshTextures.end(), heightMaps.begin(), heightMaps.end());

        std::vector<Texture> baseColor = LoadMaterialTextureType(material, aiTextureType_DIFFUSE, "texture_diffuse");

		//return meshTextures;
		return baseColor;
	}
	
	//Dado un material y un tipo de textura extrae las texturas e intenta generar las texturas.
	std::vector<Texture> Model::LoadMaterialTextureType(const aiMaterial* const p_mat, 
														const aiTextureType p_type, 
														const std::string_view p_typename)
	{
		std::vector<Texture> matTextures;

		for(unsigned int i = 0; i < p_mat->GetTextureCount(p_type); i++)
        {
            aiString textureName;
            p_mat->GetTexture(p_type, i, &textureName);

            // check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
            bool skip = false;
            for(unsigned int j = 0; j < loadedTextures_.size(); j++)
            {
                if(std::strcmp(loadedTextures_[j].path.data(), textureName.C_Str()) == 0)
                {
                    matTextures.push_back(loadedTextures_[j]);
                    skip = true; // a texture with the same filepath has already been loaded, continue to next one. (optimization)
                    break;
                }
            }
            if(!skip)
            {   // if texture hasn't been loaded already, load it
				unsigned int IDbool = GenerateTextureFromFile(textureName.C_Str(), directory_);
                if(IDbool)
				{	
					//Aquí se puede guardar en el vector de otra forma seguro
                	Texture texture;
					texture.ID = IDbool;
                	texture.type = p_typename;
                	texture.path = textureName.C_Str();
                	matTextures.push_back(texture);
                	loadedTextures_.push_back(texture);  // store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
				}
			}
        }
        return matTextures;
	}

	//Encargado de cargar la textura y generar el buffer para OpenGl
	unsigned int Model::GenerateTextureFromFile( const char * const p_textName, const std::string_view p_directory)
	{
		std::string filename = std::string(p_directory);
    	filename =  filename + "/" + std::string(p_textName);

		unsigned int textureID = 0;

		int width, height, nrComponents;

		//stbi_set_flip_vertically_on_load(true);

		unsigned char *data = stbi_load( filename.c_str(), &width, &height, &nrComponents, 0);

		if (data)
		{
			glGenTextures(1, &textureID);

			GLenum format;
			if (nrComponents == 1)
				format = GL_RED;
			else if (nrComponents == 3)
				format = GL_RGB;
			else if (nrComponents == 4)
				format = GL_RGBA;

			//Generate the buffer with the texture
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

			//Edit texture attributes
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			stbi_image_free(data);
		}
		else
		{
			std::cout << "Texture failed to load at path: " << p_textName << std::endl;
			stbi_image_free(data);
		}

		return textureID;
	}


	void Model::DrawModel(const Shader& p_shader)
	{
		for(std::size_t i = 0; i < meshes_.size(); i++)
			meshes_[i].Draw(p_shader);
	}

}