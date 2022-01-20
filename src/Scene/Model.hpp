#pragma once

#include "SceneNode.hpp"
#include "../FileManager/Mesh.hpp"
#include "../FileManager/Shader.hpp"
#include "../FileManager/Material.hpp"

namespace Ocacho
{
	class Model : SceneNode
	{
		Mesh*		meshes_;
		Material*	material_;
		Shader*		shader_;

		Model();
		~Model();

		void Draw()
		{
			shader_->UseShader();
			meshes_->Draw();
		}
	};
}
