#pragma once

#include "../SceneNode.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Material.hpp"

namespace Ocacho
{
	class Model : SceneNode
	{
		std::vector<Mesh> meshes_;

		Model();
		~Model();

		void DrawAll(const Shader p_shader)
		{
			for(int i = 0; i < meshes_.size(); i++ )
				meshes_[i].Draw(p_shader);
		}
	};
}
