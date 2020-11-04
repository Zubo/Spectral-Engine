#include "Render/CameraData.h"

#include "Core/Math/Degree.h"
#include "Core/Math/Direction.h"
#include "Core/Math/LinearTransformations.h"
#include "Core/Math/Vector3.h"

namespace sp {
	Matrix4x4 const CameraData::GetViewMatrix() {
		Vector3 const worldUp{ 0.0F, 1.0F, 0.0f };
		Vector3 const forward = CameraData::getForward();
		Vector3 const right = Vector3::cross(forward, worldUp).normalized();
		Vector3 const up = Vector3::cross(right, forward).normalized();
		Vector3 const & translation = CameraData::_translation;
		auto lookAt = getLookAtMatrix(forward, up, translation);
		return lookAt;
	}

	Matrix4x4 const CameraData::GetProjectionMatrix() {
		SpFloat aspect = static_cast<float>(CameraData::_screenWidth) / CameraData::_screenHeight;
		return getPerspectiveMat(CameraData::_fov, aspect, 0.1F, 100.0F);
	}

	void CameraData::setFov(Degree const & fov) {
		CameraData::_fov = fov;
		CameraData::_dataChanged = true;
	}

	void CameraData::setScreenWidth(SpInt const screenWidth) {
		CameraData::_screenWidth = screenWidth;
		CameraData::_dataChanged = true;
	}

	void CameraData::setScreenHeight(SpInt const screenHeight) {
		CameraData::_screenHeight = screenHeight;
		CameraData::_dataChanged = true;
	}

	Vector3 const CameraData::getTranslation()
	{
		return CameraData::_translation;
	}

	void CameraData::setTranslation(Vector3 const & translation) {
		CameraData::_translation = translation;
		CameraData::_dataChanged = true;
	}

	Vector3 const CameraData::getRotation()
	{
		return CameraData::_rotation;
	}

	void CameraData::setRotation(Vector3 const & rotation) {
		CameraData::_rotation = rotation;
		CameraData::_dataChanged = true;
	}

	bool CameraData::getDataChanged()
	{
		return CameraData::_dataChanged;
	}

	void CameraData::setDataChangedToFalse() {
		CameraData::_dataChanged = false;
	}

	Vector3 CameraData::getForward() {
		Vector3 const rotation = _rotation;
		Degree const rotX{ rotation.X };
		Degree const rotY{ rotation.Y };

		return getDirection(rotX, rotY);
	}
}
