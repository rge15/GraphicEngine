#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <iostream>


namespace Ocacho
{
	class Engine {
		private:

			int width_	{ 0 };
			int height_ { 0 };

			GLFWwindow* const window_ { glfwCreateWindow(width_, height_, "My title", NULL, NULL) };

			void SetEngineCallbacks();

		public:

			static void InitEngine3DDependences();

			void EngineSwapAndPoll() { glfwSwapBuffers(window_); glfwPollEvents(); }

			Engine(int p_screenWidth, int p_screenHeight) 
			: width_{ p_screenWidth }, height_{ p_screenHeight }
			{
				assert(window_);
				
				glfwMakeContextCurrent(window_);
				int gladInit = gladLoadGL();
				assert(gladInit);

				glViewport(0, 0, width_, height_);

				SetEngineCallbacks();

			};

			~Engine() { glfwDestroyWindow(window_); glfwTerminate(); };

			void UseProgram(const int p_IDProgram)
			{
				glUseProgram(p_IDProgram);
			}

			const uint8_t IsWindowOpen() { return !glfwWindowShouldClose(window_); };

			void CloseWindow() { glfwSetWindowShouldClose(window_, GL_TRUE); };

			void SetActiveCamera() { };

			float getAspectRatio() { return (float)width_/(float)height_; }

	};
}