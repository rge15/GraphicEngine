#include "VideoDriver.hpp"

namespace Ocacho
{
	void VideoDriver::BeginScene()
	{
		int width, height;

		glfwGetFramebufferSize(window_, &width, &height);
		int ratio = width / (float) height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void VideoDriver::EndScene()
	{
		glfwSwapBuffers(window_); 
		glfwPollEvents();
	}

	void VideoDriver::InitVideoDriver()
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

}