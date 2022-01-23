#pragma once

#include "Scene.hpp"
#include "VideoDriver.hpp"
#include "FileManager.hpp"

#include <iostream>
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <string>



namespace Ocacho
{

	class Device
	{
		private:
			std::unique_ptr<FileManager> fileManager_ { std::make_unique<FileManager>() };
			std::unique_ptr<VideoDriver> videoDriver_ { std::make_unique<VideoDriver>() };
			std::unique_ptr<Scene> scene_ { std::make_unique<Scene>( getAspectRatio() ) };

			GLFWwindow* window_;
			
		public:
			int width_ { 640 }; 
			int height_ { 480 };
			std::string windowTitle_;
			

			Device( int p_width = 640, 
					int p_height = 480, 
					std::string p_windowTitle = "Title") :
					width_ { p_width }, height_ { p_height },
					windowTitle_ { p_windowTitle }
					{
						InitWindow();
						scene_->setFileManagerAcces( fileManager_.get() );
						videoDriver_->SetScene( scene_.get() );
					}
			
			~Device(){}

			float getAspectRatio() { return (float)width_/(float)height_; }
	
			void SetWindowCallbacks();

			const uint8_t IsWindowOpen() { return !glfwWindowShouldClose(window_); };

			void CloseWindow() { glfwSetWindowShouldClose(window_, GL_TRUE); };

			VideoDriver* const getVideoDriver()
			{
				return videoDriver_.get();
			}

			Scene* const getScene()
			{
				return scene_.get();
			}

			FileManager* const getFileManager()
			{
				return fileManager_.get();
			}

			void InitWindow()
			{
				window_ = videoDriver_->CreateWindow(width_, height_, windowTitle_);
				assert(window_);

				videoDriver_->MakeWindowCurrentContext(window_);

				//VideoDriver Init Glad
				videoDriver_->InitGlad();

				//Window Set Viewport
				videoDriver_->SetWindowViewport(width_, height_);

				//Driver Set Callbacks
				SetWindowCallbacks();
			}



	};
}