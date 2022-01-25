#include "SceneNode.hpp"

namespace Ocacho
{
	void SceneNode::SetPosition( const glm::vec3 p_pos)
	{
		position_ = p_pos;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void SceneNode::SetScale( const glm::vec3 p_scale)
	{
		scale_ = p_scale;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void SceneNode::SetPosition( const float p_posx, const float p_posy, const float p_posz)
	{
		position_ = glm::vec3( p_posx, p_posy, p_posz );
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void SceneNode::SetRotation( const glm::vec3 p_rot )
	{
		rotation_ = p_rot;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void SceneNode::SetRotation( const float p_rotx, const float p_roty, const float p_rotz )
	{
		rotation_ = glm::vec3(p_rotx, p_roty, p_rotz);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void SceneNode::SetScale( const float p_scalex, const float p_scaley, const float p_scalez)
	{
		scale_ = glm::vec3( p_scalex, p_scaley, p_scalez);
	}	
}
