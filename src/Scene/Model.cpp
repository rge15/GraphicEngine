#include "Model.hpp"

namespace Ocacho
{
	void Model::Draw( Shader* const p_shader )
	{
		SetModelMatrix(p_shader);
		material_->UseMaterial(p_shader);
		meshes_->Draw();
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Model::SetModelMatrix(Shader* const p_shader)
	{
		CalculateModelMatrix();
		p_shader->SetM4("u_model", model_);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Model::CalculateModelMatrix()
	{
		model_ = glm::mat4(1.0f);

		//Scale
		model_ = glm::scale(model_, scale_);

		//Rotation
		glm::quat quaternion(rotation_);
		model_ = model_ * glm::mat4_cast(quaternion);

		//Translation
		model_ = glm::translate(model_, position_);
	}
}