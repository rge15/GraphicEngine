#include "Shader.hpp"

namespace Ocacho{

	std::string Shader::ReadShader(const std::string_view& p_shaderPath)
	{
		std::string	shaderCode;
		std::ifstream	shaderFile;
	
		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			shaderFile.open(p_shaderPath.data());
			std::stringstream shaderStream;

			shaderStream << shaderFile.rdbuf();

			shaderFile.close();

			shaderCode = shaderStream.str();
		}
		catch(std::ifstream::failure e)
		{
			std::cerr << "ERROR READING SHADER FILE\n";
			std::cerr << p_shaderPath << "\n";
			std::cerr << e.what() << '\n';
		}
		
		return shaderCode;
	}

	uint8_t Shader::CompileShader(const char* p_shaderCode, GLenum p_shaderType)
	{
		uint8_t shaderID;
		int shaderInfo;

		shaderID = glCreateShader(p_shaderType);
		glShaderSource(shaderID, 1, &p_shaderCode, NULL);
		glCompileShader(shaderID);

		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &shaderInfo);
		
		//TODO Cambiar por sistema de assert
		//assert(shaderInfo);
		if(!shaderInfo)
		{
			char infoLog[512];
			glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
			std::cout << "ERROR SHADER COMPILATION_FAILED\n" << infoLog << '\n';
		}

		return shaderID;
	}

	void Shader::CreateShaderProgram(const int p_vShaderID, const int p_frShaderID)
	{
		int shaderCreationInfo;

		ID_ = glCreateProgram();
		glAttachShader(ID_, p_vShaderID);
		glAttachShader(ID_, p_frShaderID);
		glLinkProgram(ID_);

		glGetProgramiv(ID_, GL_LINK_STATUS, &shaderCreationInfo);


		//TODO Cambiar por sistema de assert
		//assert(shaderCreationInfo);

		if(!shaderCreationInfo)
		{
			char infoLog[512];
			glGetProgramInfoLog(ID_, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		glDeleteShader(p_vShaderID);
		glDeleteShader(p_frShaderID);
	}


}