#include "Scene.hpp"


namespace Ocacho
{
	SceneNode* Scene::AddCamera(
		const glm::vec3 p_pos, 
		const glm::vec3 p_lookAt,
		const u_int8_t p_activeCamera)
	{
		cameras_.emplace_back( std::make_unique<Camera>(p_pos, p_lookAt, p_activeCamera) );

		return cameras_.back().get();
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	SceneNode* Scene::AddModel(
		const std::size_t p_mesh, 
		const std::size_t p_material, 
		const glm::vec3 p_pos)
	{
		models_.emplace_back( 
			std::make_unique<Model>(
				deviceFileManager_->getMesh(p_mesh),
				deviceFileManager_->getMaterial(p_material),
				p_pos));

		return models_.back().get();
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Scene::DrawAll()
	{
		if(shader_ != nullptr)
		{
			shader_->UseShader();
			SetSceneShadersUniforms();
			SetSceneCameraShaderUniforms();
			DrawModels();
		}
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Scene::SetSceneShadersUniforms()
	{
		shader_->SetM4("u_projection", projection_ );
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Scene::SetSceneCameraShaderUniforms()
	{
		for(std::size_t i = 0 ; i < cameras_.size() ; i++ )
		{
			auto* camera = static_cast<Camera *>(cameras_.at(i).get()); 
			if( camera->IsCameraActive() )
			{
				shader_->SetM4("u_view", camera->GetViewMatrix());
			}
		}
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Scene::DrawModels()
	{
		for(std::size_t i = 0 ; i < models_.size() ; i++)
		{
			auto* model = static_cast<Model*>( models_.at(i).get());
			model->Draw( shader_ );
		}
	}
}