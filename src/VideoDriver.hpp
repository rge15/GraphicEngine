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
			std::unique_ptr<GLFWwindow, void(*)( GLFWwindow* )> window_ { nullptr, nullptr };

			Scene* scene_;
		
		public:
			VideoDriver(){ InitVideoDriver(); };
			~VideoDriver(){  };

			void InitVideoDriver();

			void InitGlad() { int glad = gladLoadGL(); assert(glad); }

			GLFWwindow* const CreateWindow(
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

			static void DropWindow( GLFWwindow* p_window )
			{
				glfwDestroyWindow(p_window);
				glfwTerminate();
			}

			void MakeWindowCurrentContext()
			{
				glfwMakeContextCurrent(window_.get());
			}

			void SetScene( Scene* const p_scene )
			{
				assert(p_scene != nullptr);

				scene_ = p_scene;
			}

			void BeginScene();

			void EndScene();
			
			void 	SetWindowViewport(	
				const std::size_t p_widthMax, 
				const std::size_t p_heigthMax,
				const std::size_t p_widthMin = 0,
				const std::size_t p_heigthMin = 0)
			{
				glViewport( p_widthMin, p_heigthMin, p_widthMax, p_heigthMax);
			}

	};
}