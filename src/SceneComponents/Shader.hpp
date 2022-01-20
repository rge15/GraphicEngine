#pragma once

#include <glad/glad.h>

#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/gtc/type_ptr.hpp>

namespace Ocacho
{
	class Shader{
		private:
			void ReadAndCompileShader(const char* p_vertexPath, const char* p_fragmentPath)
			{
				const std::string vertexShaderCode   = ReadShader(p_vertexPath);
				const std::string fragmentShaderCode = ReadShader(p_fragmentPath);
				
				int vertexID 	= CompileShader(vertexShaderCode.c_str(), 	GL_VERTEX_SHADER   );
				int fragmentID  = CompileShader(fragmentShaderCode.c_str(), GL_FRAGMENT_SHADER );
			
				CreateShaderProgram(vertexID, fragmentID);
			
			};
			
			std::string ReadShader(const std::string& p_shaderPath);
			uint8_t 	CompileShader(const char* p_shaderCode, GLenum p_shaderType);
			void 		CreateShaderProgram(const int p_vShaderID, const int p_frShaderID);

		public:
			glID ID_ { 0 };

			Shader(const char* p_vertexPath, const char* p_fragmentPath)
			{
				ReadAndCompileShader(p_vertexPath, p_fragmentPath);
			};
			
			~Shader(){};

			void UseShader()
			{
				glUseProgram(ID_);
			}

			void SetBool(const std::string &p_name, bool p_value) const
			{         
			    glUniform1i(glGetUniformLocation(ID_, p_name.c_str()), (int)p_value); 
			}
			
			void SetInt(const std::string &p_name, int p_value) const
			{ 
			    glUniform1i(glGetUniformLocation(ID_, p_name.c_str()), p_value); 
			}
			
			void SetFloat(const std::string &p_name, float p_value) const
			{ 
			    glUniform1f(glGetUniformLocation(ID_, p_name.c_str()), p_value); 
			}

			void SetM4(const std::string &p_name, glm::mat4 p_value) const
			{ 
				glUniformMatrix4fv(glGetUniformLocation(ID_, p_name.c_str()), 1, GL_FALSE, glm::value_ptr(p_value));
			}

			void SetFloat3(const std::string &p_name, glm::vec3 p_value) const
			{ 
				glUniform3fv(glGetUniformLocation(ID_, p_name.c_str()), 3, glm::value_ptr(p_value));
			}

	};
}