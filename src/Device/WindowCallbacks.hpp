#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

void glErrorCallback(int p_error, const char* p_desc)
{
    std::cout << "Error de GLFW : " << p_error << ". Descripcion : " << p_desc << "\n";
};

void glFramebufferSizeCallback(GLFWwindow* p_window, int p_width, int p_height)
{
    glViewport(0, 0, p_width, p_height);
}