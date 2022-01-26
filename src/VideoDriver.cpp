#include "VideoDriver.hpp"

namespace Ocacho
{
	void VideoDriver::BeginScene()
	{
		int width, height;

		glfwGetFramebufferSize(window_.get(), &width, &height);
		float ratio = (float)width / (float)height;

		scene_->SetProjection(ratio);

		glViewport(0, 0, width, height);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void VideoDriver::EndScene()
	{
		glfwSwapBuffers(window_.get()); 
		glfwPollEvents();
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

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

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void VideoDriver::InitGlad()
	{
		int glad = gladLoadGL();
		assert(glad);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	GLFWwindow* const VideoDriver::CreateWindow(
		const std::size_t p_width,
		const std::size_t p_heigth, 
		const std::string p_windowTitle)
	{
		std::unique_ptr<GLFWwindow, void(*)( GLFWwindow* )> window{
			glfwCreateWindow(p_width, p_heigth, p_windowTitle.c_str() , NULL, NULL),
			DropWindow
		};

		window_ = std::move(window);
		
		assert(window_.get());

		return window_.get();
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void VideoDriver::MakeWindowCurrentContext()
	{
		glfwMakeContextCurrent(window_.get());
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void VideoDriver::SetScene( Scene* const p_scene )
	{
		assert(p_scene != nullptr);

		scene_ = p_scene;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void	VideoDriver::SetWindowViewport(	
		const std::size_t p_widthMax, 
		const std::size_t p_heigthMax,
		const std::size_t p_widthMin = 0,
		const std::size_t p_heigthMin = 0)
	{
		glViewport( p_widthMin, p_heigthMin, p_widthMax, p_heigthMax);
	}

}