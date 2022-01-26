#pragma once

#include "Scene.hpp"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assert.h>

namespace Ocacho
{
	class VideoDriver
	{
		private:
			// Unique ptr to the opengl window
			std::unique_ptr<GLFWwindow, void(*)( GLFWwindow* )> window_ { nullptr, nullptr };

			// Pointer to the device scene
			Scene* scene_;
		
		public:
			VideoDriver(){ InitVideoDriver(); };
			~VideoDriver(){};

			/**
			 * @brief	Initialize all the video drivers dependencies
			 * 			as GLFW
			 * 
			 */
			void InitVideoDriver();

			/**
			 * @brief	Inits GLAD and load OpenGl Function
			 * 
			 */
			void InitGlad();

			/**
			 * @brief	Add a camera into the scene
			 * 
			 * @tparam	p_width Width of the window to create
			 * @tparam	p_heigth Heigth of the window to create
			 * @tparam	p_windowTitle Title for the window to create
			 * 
			 * @return	Pointer to the created glfw window
			 */
			GLFWwindow* const CreateWindow(
				const std::size_t p_width,
				const std::size_t p_heigth, 
				const std::string p_windowTitle);

			/**
			 * @brief	Static method for RAII pattern for manage
			 * 			window and free the window memory
			 * 
			 * @tparam	p_window Window to be destroyed
			 */
			static void DropWindow( GLFWwindow* p_window )
			{
				glfwDestroyWindow(p_window);
				glfwTerminate();
			}

			/**
			 * @brief	This method sets the videodriver window
			 * 			to be the Current One for OpenGL
			 */
			void MakeWindowCurrentContext();

			/**
			 * @brief	Sets the scene of the videoDriver to comunicate with
			 * 
			 * @tparam	p_scene Scene to be setted
			 */
			void SetScene( Scene* const p_scene );

			/**
			 * @brief	Method that prepare drivers to draw
			 */
			void BeginScene();

			/**
			 * @brief	Method that ends the drawing process
			 */
			void EndScene();
			
			/**
			 * @brief	Sets the window viewport to render for.
			 * 			It sets the min and max coordinates of the window to
			 * 			render, being the min coordinates at the upper-left
			 * 			corner of the viewport and the max coordinates
			 * 			at the down-right corner.
			 * 
			 * @tparam	p_widthMax Max Width coords of the window to view
			 * @tparam	p_heigthMax Max Heigth coords of the window to view
			 * @tparam	p_widthMin Width of the window to create
			 * @tparam	p_heigthMin Heigth of the window to create
			 */
			void SetWindowViewport(
				const std::size_t p_widthMax, 
				const std::size_t p_heigthMax,
				const std::size_t p_widthMin = 0,
				const std::size_t p_heigthMin = 0);

	};
}