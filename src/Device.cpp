#include "Device.hpp"
#include "Device/WindowCallbacks.hpp"

namespace Ocacho
{
	void Device::SetWindowCallbacks()
	{
		glfwSetErrorCallback( glErrorCallback );
		glfwSetFramebufferSizeCallback( window_, glFramebufferSizeCallback );
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	float Device::getAspectRatio()
	{ 
	return (float)width_/(float)height_;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	const uint8_t Device::IsWindowOpen()
	{ 
		return !glfwWindowShouldClose(window_);
	};

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Device::CloseWindow()
	{ 
		glfwSetWindowShouldClose(window_, GL_TRUE);
	};

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	VideoDriver* const Device::getVideoDriver()
	{
		return videoDriver_.get();
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	Scene* const Device::getScene()
	{
		return scene_.get();
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	FileManager* const Device::getFileManager()
	{
		return fileManager_.get();
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Device::InitWindow()
	{
		window_ = videoDriver_->CreateWindow(
			width_, 
			height_, 
			windowTitle_.data());

		assert(window_);

		//Set the window to de Gl context
		videoDriver_->MakeWindowCurrentContext();

		//VideoDriver Init Glad
		videoDriver_->InitGlad();

		//Window Set Viewport
		videoDriver_->SetWindowViewport(
			width_, 
			height_);

		//Driver Set Callbacks
		SetWindowCallbacks();
	}
}