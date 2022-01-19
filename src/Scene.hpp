#pragma once

#include <vector>

// #include "utilities/RenderComponents.hpp"

namespace Ocacho
{

	class Scene
	{
		public:
			// std::vector<Camera> cameras_;
			//TODO : Implementación luces
			// std::vector<Lights> lights_;
			// std::vector<Model> models_;

			Scene(){};

			~Scene(){};

			void DrawAll();
	};
}
