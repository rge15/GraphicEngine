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

			// Ptr to the window managed by Video Driver
			GLFWwindow* window_ { nullptr };
			
			// Width of the window
			int width_;

			// Width of the window
			int height_;

			// Title of the window
			std::string_view windowTitle_;

			void SetWindowCallbacks();

			void InitWindow();


		public:
			Device( 
				int p_width = 640, 
				int p_height = 480, 
				std::string p_windowTitle = "Title") :
				width_ { p_width }, height_ { p_height },
				windowTitle_ { p_windowTitle.c_str() }
				{
					InitWindow();
					scene_->SetFileManagerAcces( fileManager_.get() );
					videoDriver_->SetScene( scene_.get() );
				}
			
			~Device(){}

			float getAspectRatio();

			const uint8_t IsWindowOpen();

			void CloseWindow();

			VideoDriver* const getVideoDriver();

			Scene* const getScene();

			FileManager* const getFileManager();
	};
}