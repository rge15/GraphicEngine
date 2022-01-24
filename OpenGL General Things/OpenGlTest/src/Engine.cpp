#include "Engine.hpp"
#include "callbacks.hpp"

namespace Ocacho
{
	void Engine::InitEngine3DDependences()
	{
		if(!glfwInit())
		{
			std::cout << "Error al iniciar GLFW \n";
			assert(0);	
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	}

	void Engine::SetEngineCallbacks()
	{
		glfwSetErrorCallback( error_callback );
		glfwSetFramebufferSizeCallback( window_, framebuffer_size_callback );
	}
}