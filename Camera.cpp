#include "Camera.h"
#include "InputCommands.h"

using namespace DirectX;

void Camera::Update(const InputCommands & inputCommands)
{
	if (inputCommands.rotRight)
	{
		m_rotation.y -= m_rotSpeed;
	}
	if (inputCommands.rotLeft)
	{
		m_rotation.y += m_rotSpeed;
	}

	m_rotation.y += inputCommands.mouse_X;
	m_rotation.x += inputCommands.mouse_Y;

	// Avoid gimbal lock
	m_rotation.x = std::min(m_rotation.x, +89.f);
	m_rotation.x = std::max(m_rotation.x, -89.f);

	//create look direction from Euler angles in m_camOrientation	
	float cosY = cosf(XMConvertToRadians(m_rotation.y));
	float cosP = cosf(XMConvertToRadians(m_rotation.x));

	float sinY = sinf(XMConvertToRadians(m_rotation.y));
	float sinP = sinf(XMConvertToRadians(m_rotation.x));

	m_forward.x = sinY * cosP;
	m_forward.y = sinP;
	m_forward.z = cosP * cosY;
	m_forward.Normalize();

	//create right vector from look Direction
	Vector3 right;
	m_forward.Cross(Vector3::UnitY, right);
	right.Normalize();

	//process input and update stuff
	if (inputCommands.forward)
	{
		m_position += m_forward * m_speed;
	}
	if (inputCommands.back)
	{
		m_position -= m_forward * m_speed;
	}
	if (inputCommands.right)
	{
		m_position += right * m_speed;
	}
	if (inputCommands.left)
	{
		m_position -= right * m_speed;
	}

	//update lookat point
	m_lookAt = m_position + m_forward;
}

DirectX::SimpleMath::Vector3 Camera::GetPosition() const
{
	return m_position;
}

DirectX::SimpleMath::Matrix Camera::GetViewMatrix() const
{
	return Matrix::CreateLookAt(m_position, m_lookAt, Vector3::UnitY);
}

DirectX::SimpleMath::Matrix Camera::FocusCameraOnObject(Vector3 obj)
{
   objPos = Vector3(obj.x, obj.y, obj.z);

	return Matrix::CreateLookAt(objPos + OrbOffset, objPos, Vector3(0, 1, 0));
}
DirectX::SimpleMath::Matrix Camera::OrbCamera(Vector3 obj)
{

	objPos.x = obj.x;
	objPos.y = obj.y;
	objPos.z = obj.z;


	//Matrix Transform = Matrix::Translation(objPos, OrbOffset);
	Matrix rotY = Matrix::CreateRotationY(((m_rotation.y) * 3.1415 / 180)*0.01f);
	Matrix rotZ = Matrix::CreateRotationZ(((m_rotation.z) * 3.1415 / 180) * 0.01f);

	OrbOffset = Vector3::Transform(OrbOffset, rotY);
	OrbOffset = Vector3::Transform(OrbOffset, rotZ);


	return Matrix::CreateLookAt(objPos + OrbOffset , objPos, Vector3(0,1,0));
}
