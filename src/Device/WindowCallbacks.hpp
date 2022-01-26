/**
 * @file WindowCallbacks.hpp
 * @author OcachoGames-Rodrigo (ocachogames@gmail.com)
 * @brief Window Callbacks for Ocacho Graphic Engine
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

#include <iostream>
#include <GLFW/glfw3.h>


/**
 *  @brief Error function to execute if OpenGl fails someway
 * 
 *  @param p_error Error ID of OpenGl
 *  @param p_desc  Error decription of OpenGl 
 */
void glErrorCallback(int p_error, const char* p_desc)
{
    std::cout << "Error de GLFW : " << p_error << ". Descripcion : " << p_desc << "\n";
};

/**
 *  @brief  Resize function to execute if OpenGl window
 *          get resized
 * 
 *  @param p_window Window to be resized
 *  @param p_width  Width of new window size 
 *  @param p_height Heigth of new window size 
 */
void glFramebufferSizeCallback(GLFWwindow* p_window, int p_width, int p_height)
{
    glViewport(0, 0, p_width, p_height);
}