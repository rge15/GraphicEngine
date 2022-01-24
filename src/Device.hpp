/**
 * @file Device.hpp
 * @author OcachoGames-Rodrigo (ocachogames@gmail.com)
 * @brief Device of Ocacho Graphic Engine
 * 
 * This class will manage the entire Ocacho 3D Engine with all
 * their parts. File manager, Video driver & Scene.
 * 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2021
 */
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

			//	Unique Ptr to the file manager 
			std::unique_ptr<FileManager> fileManager_ { 
				std::make_unique<FileManager>()};

			//	Unique Ptr to the video driver
			std::unique_ptr<VideoDriver> videoDriver_ { 
				std::make_unique<VideoDriver>() };
			
			//	Unique Ptr to the scene
			std::unique_ptr<Scene> scene_ { 
				std::make_unique<Scene>( getAspectRatio() )};

			//TODO : Mover window y todo lo suyo a videodriver
			//TODO : Ver tmbn como va a ir con el tema de ImGui
			//TODO : Tambien el Init Window
			GLFWwindow* window_;
			
			int width_; 
			int height_;

			std::string windowTitle_;

		public:
						

			Device( 
				int p_width = 640, 
				int p_height = 480, 
				std::string p_windowTitle = "Title") :
				width_ { p_width }, height_ { p_height },
				windowTitle_ { p_windowTitle }
				{
					InitWindow();
					scene_->SetFileManagerAcces( fileManager_.get() );
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
				window_ = videoDriver_->CreateWindow(
					width_, 
					height_, 
					windowTitle_);
				assert(window_);

				videoDriver_->MakeWindowCurrentContext(window_);

				//VideoDriver Init Glad
				videoDriver_->InitGlad();

				//Window Set Viewport
				videoDriver_->SetWindowViewport(
					width_, 
					height_);

				//Driver Set Callbacks
				SetWindowCallbacks();
			}

	};
}