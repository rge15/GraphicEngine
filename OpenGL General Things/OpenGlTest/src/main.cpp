#include <iostream>
#include <assert.h>
#include <memory>

#define STB_IMAGE_IMPLEMENTATION

#include "Engine.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Model.hpp"

int main()
{
	Ocacho::Engine::InitEngine3DDependences();	

	Ocacho::Engine engine(640,480);

	Ocacho::Model baseModel("/home/rodrigo/Escritorio/PersonalProj/OpenGlTest/models/prueba.obj");

	Ocacho::Shader baseShader("/home/rodrigo/Escritorio/PersonalProj/OpenGlTest/src/shaders/baseVertexShader.vs",
						  	  "/home/rodrigo/Escritorio/PersonalProj/OpenGlTest/src/shaders/baseFragmentShader.fs");

	Ocacho::Camera camera( glm::vec3(1.0f, 1.0f, 1.0f) , glm::vec3(0.0f, 0.0f, 0.0f));

	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, 3.0f));

	glm::mat4 proj = glm::perspective( glm::radians(45.0f), engine.getAspectRatio(), 0.1f, 100.0f );
	
	std::cout << "Aspect Ratio : " << engine.getAspectRatio() << '\n';

	std::cout << "Matriz : \n";
	std::cout << proj[0][0] << " , " << proj[0][1] << " , " << proj[0][2] << "\n";
	std::cout << proj[1][0] << " , " << proj[1][1] << " , " << proj[1][2] << "\n";
	std::cout << proj[2][0] << " , " << proj[2][1] << " , " << proj[2][2] << "\n";

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model , glm::vec3(0.5f, -0.5f, -0.5f));

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	while (engine.IsWindowOpen())
	{
		baseShader.UseShader();

		baseShader.SetM4("model", model );
		baseShader.SetM4("view", camera.LookAt());
		baseShader.SetM4("projection", proj );

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		baseModel.DrawModel(baseShader);

		engine.EngineSwapAndPoll();
	}	
}
