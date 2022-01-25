#include "Camera.hpp"

namespace Ocacho
{

	void Camera::SetCameraDirection()
	{
		cameraDirection_ = glm::normalize(position_ - target_);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Camera::SetRightCameraDirection()
	{
		rightDirection_ = glm::normalize(glm::cross(upDirection_, cameraDirection_));
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Camera::SetUpCameraDirection()
	{
		upDirection_ = glm::normalize(glm::cross( cameraDirection_, rightDirection_ ));
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Camera::CalculateCameraUpAxis()
	{
		SetCameraDirection();
		SetRightCameraDirection();
		SetUpCameraDirection();
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	glm::vec3 Camera::GetCameraViewDirection()
	{
		return glm::normalize( position_ - target_ );
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	glm::mat4 Camera::GetViewMatrix()
	{
		CalculateCameraUpAxis();
		return glm::lookAt(position_, target_, upDirection_);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Camera::SetTarget( const glm::vec3 p_target )
	{
		target_ = p_target;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void Camera::SetTarget( const float p_targetX, 
					const float p_targetY, 
					const float p_targetZ)
	{
		target_ = glm::vec3( p_targetX, p_targetY, p_targetZ);
	}

}
