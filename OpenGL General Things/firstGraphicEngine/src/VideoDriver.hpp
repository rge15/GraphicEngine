#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assert.h>

namespace Ocacho
{

	class VideoDriver
	{
		private:
			GLFWwindow* window_ { nullptr };
		
			void SetWindow(GLFWwindow* const p_window)
			{
				if(p_window != nullptr)
					window_ = p_window;
			}
		
		public:
			VideoDriver(){ InitVideoDriver(); };
			~VideoDriver(){ glfwDestroyWindow(window_); glfwTerminate(); };

			void InitVideoDriver();

			void InitGlad() { int glad = gladLoadGL(); assert(glad); }

			GLFWwindow* const CreateWindow( const std::size_t p_width,
											const std::size_t p_heigth, 
											const std::string p_windowTitle)
			{
				return glfwCreateWindow(p_width, p_heigth, p_windowTitle.c_str() , NULL, NULL);
			}

			void MakeWindowCurrentContext(GLFWwindow* const p_window)
			{
				glfwMakeContextCurrent(p_window);
				SetWindow(p_window);
			}

			void BeginScene();

			void EndScene();
			
			void 	SetWindowViewport(	const std::size_t p_widthMax, 
										const std::size_t p_heigthMax,
										const std::size_t p_widthMin = 0,
										const std::size_t p_heigthMin = 0)
			{
				glViewport( p_widthMin, p_heigthMin, p_widthMax, p_heigthMax);
			}

	};
}