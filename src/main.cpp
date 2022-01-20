#include <iostream>
#include "Device.hpp"


int main()
{
	Ocacho::Device device_;

	Ocacho::VideoDriver* videoDriver_ = device_.getVideoDriver();

	Ocacho::FileManager* fileManager_ = device_.getFileManager();

	std::size_t MayaID = fileManager_->LoadMesh("/home/rodrigo/Escritorio/PersonalProj/firstGraphicEngine/models/cube.obj");

	std::size_t TextureID = fileManager_->LoadTexture("/home/rodrigo/Escritorio/PersonalProj/Repositories/GraphicEngine/models/Untitled.png");

	std::size_t material1Textures[] = { TextureID };
	std::size_t MaterialID = fileManager_->AddMaterial( material1Textures );


	//Aquí se cargan los ficheros

	//Aquí se cargan los modelos iniciales 

	while(device_.IsWindowOpen())
	{
		// *** Update Game Start

		// * Aquí se crean alomejor modelos dinámicos

		// *** Update Game End
		videoDriver_->BeginScene();
		
		//Aquí se renderiza la escena 

		videoDriver_->EndScene();
	}
}