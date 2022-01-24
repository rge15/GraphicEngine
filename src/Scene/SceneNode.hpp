#pragma once

#include <glm/glm.hpp>

//Aquí No se pq me reconoce el include pero no me lo pilla el intelissense ni el compiler
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


struct quaterion
{
	glm::vec3 rotationAxis_;
	float rotationAngle_;
};

namespace Ocacho
{
	class SceneNode{		
		public:
			glm::vec3 position_;
			// TODO : Aquí es meter un vec3 con los angulos en grados
			// TODO : Y en model meter el cambio de degrees a quaterion
			quaterion rotation_;
			glm::vec3 scale_;

			SceneNode(	const glm::vec3 p_pos = glm::vec3(0, 0, 0), 
						const glm::vec4 p_rot = glm::vec4(0, 0, 0, 0), 
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

			void SetRotationAxis( const glm::vec3 p_rotAxis)
			{
				rotation_.rotationAxis_ = p_rotAxis;
			}

			void SetScale( const glm::vec3 p_scale)
			{
				scale_ = p_scale;
			}

			void SetPosition( const float p_posx, const float p_posy, const float p_posz)
			{
				position_ = glm::vec3( p_posx, p_posy, p_posz );
			}

			void SetRotationAxis( const float p_rotx, const float p_roty, const float p_rotz)
			{
				rotation_.rotationAxis_ = glm::vec3( p_rotx, p_roty, p_rotz);
			}

			void SetRotationAngle( const float p_angle)
			{
				rotation_.rotationAngle_ = p_angle;
			}

			void SetRotation( const glm::vec3 p_rotAxis, const float p_rotAngle )
			{
				rotation_.rotationAxis_ 	= p_rotAxis;
				rotation_.rotationAngle_ 	= p_rotAngle;
			}

			void SetScale( const float p_scalex, const float p_scaley, const float p_scalez)
			{
				scale_ = glm::vec3( p_scalex, p_scaley, p_scalez);
			}
	};
}