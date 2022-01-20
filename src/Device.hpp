#pragma once

#include "Scene.hpp"
#include "VideoDriver.hpp"
#include "FileManger.hpp"

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
			std::unique_ptr<Scene> scene_ { std::make_unique<Scene>( getAspectRatio() ) };
			std::unique_ptr<FileManager> fileManager_ { std::make_unique<FileManager>() };
			std::unique_ptr<VideoDriver> videoDriver_ { std::make_unique<VideoDriver>() };

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

			// void error_callback(int p_error, const char* p_desc)
			// {
			//     std::cout << "Error de GLFW : " << p_error << ". Descripcion : " << p_desc << "\n";
			// };

			// void framebuffer_size_callback(GLFWwindow* p_window, int p_width, int p_height)
			// {
			//     glViewport(0, 0, p_width, p_height);
			// 	//Pregunta TAG la projection
			// 	width_ = p_width;
			// 	height_ = p_height;
			// 	scene_->SetProjection(getAspectRatio());
			// }

	};
}