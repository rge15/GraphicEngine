#include "Device.hpp"
#include "Device/WindowCallbacks.hpp"

namespace Ocacho
{
	void Device::SetWindowCallbacks()
	{
		glfwSetErrorCallback( glErrorCallback );
		glfwSetFramebufferSizeCallback( window_, glFramebufferSizeCallback );
	}
}