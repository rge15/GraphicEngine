#include <iostream>
#include "Device.hpp"


int main()
{
	Ocacho::Device device_;

	Ocacho::VideoDriver* videoDriver_ = device_.getVideoDriver();

	Ocacho::FileManager* fileManager_ = device_.getFileManager();


	fileManager_->LoadMesh("/home/rodrigo/Escritorio/PersonalProj/firstGraphicEngine/models/cube.obj");

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