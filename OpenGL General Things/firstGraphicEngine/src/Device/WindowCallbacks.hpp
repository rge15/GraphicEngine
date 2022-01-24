#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

void error_callback(int p_error, const char* p_desc)
{
    std::cout << "Error de GLFW : " << p_error << ". Descripcion : " << p_desc << "\n";
};

void framebuffer_size_callback(GLFWwindow* p_window, int p_width, int p_height)
{
    glViewport(0, 0, p_width, p_height);
}