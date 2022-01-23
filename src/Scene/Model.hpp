#pragma once

#include "SceneNode.hpp"
#include "../FileManager/Mesh.hpp"
#include "../FileManager/Shader.hpp"
#include "../FileManager/Material.hpp"

namespace Ocacho
{
	class Model : public SceneNode
	{
		public: 
			glm::mat4 model_ { glm::mat4(1.0f) };

			Mesh*		meshes_;
			Material*	material_;

			Model(	Mesh* const p_mesh, 
					Material* const p_material, 
					const glm::vec3 p_pos = glm::vec3(0.0f, 0.0f, 0.0f)) :
					SceneNode( p_pos )
			{
				assert( p_mesh != nullptr );
				assert( p_material != nullptr );

				meshes_ = p_mesh;
				material_ = p_material;
			}

			~Model(){};

			//TODO : MATERIAL THINGS
			//TODO : Hacer que el material setee sus texturas (Mirar LearnOpenGL)

			//TODO : GLSL THINGS
			//TODO : Investigar y ver el tema de texturas y colores en el shader

			void Draw( Shader* const p_shader )
			{
				SetModelMatrix(p_shader);
				material_->UseMaterial(p_shader);
				meshes_->Draw();
				// std::cout << "Mesh del modelo :" << meshes_ << '\n'; 
			}

			void SetModelMatrix(Shader* const p_shader)
			{
				CalculateModelMatrix();
				p_shader->SetM4("u_model", model_);
			}

			void CalculateModelMatrix()
			{
				model_ = glm::mat4(1.0f);
				// model = glm::translate(model , glm::vec3(0.5f, -0.5f, -0.5f));
				model_ = glm::scale(model_, scale_);
				//model_ = glm::rotate(model_, rotation_.rotationAngle_, rotation_.rotationAxis_ );
				model_ = glm::translate(model_, position_);
				// model = glm::rotate(model, );
			}
	};
}
