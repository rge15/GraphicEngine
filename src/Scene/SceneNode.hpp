/**
 * @file SceneNode.hpp
 * @author OcachoGames-Rodrigo (ocachogames@gmail.com)
 * @brief SceneNode of Ocacho Graphic Engine Scene
 * 
 * A SceneNode object wil have the info about the position,
 * rotation and scale of a node in the scene
 * 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2021
 */
#pragma once

#include <glm/glm.hpp>

namespace Ocacho
{
	class SceneNode{		
		public:
			// Position of the node in the scene
			glm::vec3 position_;

			// Rotation of the node in the scene
			glm::vec3 rotation_;
			
			// Scale of the node in the scene
			glm::vec3 scale_;

			SceneNode(
				const glm::vec3 p_pos = glm::vec3(0, 0, 0), 
				const glm::vec3 p_rot = glm::vec3(0, 0, 0), 
				const glm::vec3 p_scale = glm::vec3(1, 1, 1) ):
				position_ { p_pos },
				rotation_ { p_rot },
				scale_ { p_scale }
			{}

			~SceneNode(){};

			/**
			 * @brief	Sets the scene node position
			 * 
			 * @tparam	p_pos Vector3 with the position
			 */
			void SetPosition( const glm::vec3 p_pos);

			/**
			 * @brief	Sets the scene node position
			 * 
			 * @tparam	p_posx FLoat with x position
			 * @tparam	p_posy FLoat with y position
			 * @tparam	p_posz FLoat with z position
			 */
			void SetPosition( const float p_posx, const float p_posy, const float p_posz);

			/**
			 * @brief	Sets the scene node rotation
			 * 
			 * @tparam	p_pos Vector3 with the rotation
			 */
			void SetRotation( const glm::vec3 p_rot );

			/**
			 * @brief	Sets the scene node rotations
			 * 
			 * @tparam	p_rotx FLoat with x rotation
			 * @tparam	p_roty FLoat with y rotation
			 * @tparam	p_rotz FLoat with z rotation
			 */
			void SetRotation( const float p_rotx, const float p_roty, const float p_rotz );

			/**
			 * @brief	Sets the scene node scale
			 * 
			 * @tparam	p_scale Vector3 with the scale
			 */
			void SetScale( const glm::vec3 p_scale);

			/**
			 * @brief	Sets the scene node scale
			 * 
			 * @tparam	p_scalex FLoat with x scale
			 * @tparam	p_scaley FLoat with y scale
			 * @tparam	p_scalez FLoat with z scale
			 */
			void SetScale( const float p_scalex, const float p_scaley, const float p_scalez);

	};
}