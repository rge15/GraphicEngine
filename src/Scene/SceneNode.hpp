#pragma once

#include <glm/glm.hpp>

namespace Ocacho
{
	class SceneNode{		
		public:
			glm::vec3 position_;
			glm::vec3 rotation_;
			glm::vec3 scale_;

			SceneNode(	const glm::vec3 p_pos = glm::vec3(0, 0, 0), 
						const glm::vec3 p_rot = glm::vec3(0, 0, 0), 
						const glm::vec3 p_scale = glm::vec3(1, 1, 1) ):
						position_ { p_pos },
						rotation_ { p_rot },
						scale_ { p_scale }
			{}

			~SceneNode(){};

			void SetPosition( const glm::vec3 p_pos)
			{
				position_ = p_pos;
			}

			void SetScale( const glm::vec3 p_scale)
			{
				scale_ = p_scale;
			}

			void SetPosition( const float p_posx, const float p_posy, const float p_posz)
			{
				position_ = glm::vec3( p_posx, p_posy, p_posz );
			}

			void SetRotation( const glm::vec3 p_rot )
			{
				rotation_ = p_rot;
			}

			void SetRotation( const float p_rotx, const float p_roty, const float p_rotz )
			{
				rotation_ = glm::vec3(p_rotx, p_roty, p_rotz);
			}

			void SetScale( const float p_scalex, const float p_scaley, const float p_scalez)
			{
				scale_ = glm::vec3( p_scalex, p_scaley, p_scalez);
			}
	};
}