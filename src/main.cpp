#include <iostream>
#include "Device.hpp"


int main()
{
	Ocacho::Device device_;

	Ocacho::VideoDriver* videoDriver_ = device_.getVideoDriver();
	Ocacho::FileManager* fileManager_ = device_.getFileManager();
	Ocacho::Scene*		 scene_ = device_.getScene();

	//Aquí se cargan los ficheros
	std::size_t MayaID = fileManager_->LoadMesh("/home/rodrigo/Escritorio/PersonalProj/firstGraphicEngine/models/Suzzane.obj");
	std::size_t MayaID2 = fileManager_->LoadMesh("/home/rodrigo/Escritorio/PersonalProj/firstGraphicEngine/models/prueba.obj");

	std::size_t TextureID = fileManager_->LoadTexture("/home/rodrigo/Escritorio/PersonalProj/Repositories/GraphicEngine/models/Untitled.png");

	std::size_t materialList[] = { TextureID };

	std::size_t MaterialID = fileManager_->AddMaterial(materialList);

	std::size_t ShaderID = fileManager_->LoadShader("/home/rodrigo/Escritorio/PersonalProj/Repositories/GraphicEngine/shaders/baseVertexShader.vs",
													"/home/rodrigo/Escritorio/PersonalProj/Repositories/GraphicEngine/shaders/baseFragmentShader.fs");

	scene_->SetShader(ShaderID);

	//Aquí se cargan los nodos de la escena

	Ocacho::SceneNode* camera = scene_->AddCamera();
	Ocacho::SceneNode* model1 = scene_->AddModel(MayaID, MaterialID);
	// Ocacho::SceneNode* model2 = scene_->AddModel(MayaID2, MaterialID);
	// Ocacho::SceneNode* model3 = scene_->AddModel(MayaID, MaterialID);
	
	
	model1->SetScale(0.1, 0.1, 0.1);
	
	// model2->SetScale(0.3, 0.1, 0.3);
	// model2->SetPosition(2,1,1);

	// model3->SetScale( 0.4, 0.1, 0.1 );
	// model3->SetPosition(-2, -1, -1);


	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while(device_.IsWindowOpen())
	{
		// *** Update Game Start

		// * Aquí se crean alomejor modelos dinámicos

		// *** Update Game End
		videoDriver_->BeginScene();

		scene_->DrawAll();
		//Aquí se renderiza la escena 

		videoDriver_->EndScene();
	}
}