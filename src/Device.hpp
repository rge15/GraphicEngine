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
				std::make_unique<Scene>()};

			// Ptr to the window managed by Video Driver
			GLFWwindow* window_ { nullptr };
			
			// Width of the window
			int width_;

			// Width of the window
			int height_;

			// Title of the window
			std::string_view windowTitle_;

			/**
			 * @brief	Method that sets the callbacks for window
			 * 			events
			 */
			void SetWindowCallbacks();

			/**
			 * @brief	Method that init the window of the device
			 */
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
					scene_->SetProjection( getAspectRatio() );
					scene_->SetFileManagerAcces( fileManager_.get() );
					videoDriver_->SetScene( scene_.get() );
				}
			
			~Device(){}

			/**
			 * @brief	It return the aspect ratio of the window
			 * 
			 * @return	Aspect ratio value
			 */
			float getAspectRatio();

			/**
			 * @brief	Indicates if the window is opened
			 * 
			 * @return	Is window open 
			 */
			const uint8_t IsWindowOpen();

			/**
			 * @brief	Method that set the window to be closed
			 */
			void CloseWindow();

			/**
			 * @brief	It return a pointer to the device VideoDriver
			 * 
			 * @return	Pointer to the Device VideoDriver
			 */
			VideoDriver* const getVideoDriver();

			/**
			 * @brief	It return a pointer to the device Scene
			 * 
			 * @return	Pointer to the Device Scene
			 */
			Scene* const getScene();

			/**
			 * @brief	It return a pointer to the device FileManager
			 * 
			 * @return	Pointer to the Device FileManager
			 */
			FileManager* const getFileManager();
	};
}