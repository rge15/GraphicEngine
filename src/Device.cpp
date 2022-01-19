#include "Device.hpp"
#include "Device/WindowCallbacks.hpp"


namespace Ocacho
{
	void Device::SetWindowCallbacks()
	{
		glfwSetErrorCallback( error_callback );
		glfwSetFramebufferSizeCallback( window_, framebuffer_size_callback );
	}
}