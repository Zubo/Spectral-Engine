#include "Render/CameraData.h"

#include "Core/Math/Degree.h"
#include "Core/Math/LinearTransformations.h"
#include "Core/Math/Vector3.h"

namespace sp {
	Matrix4x4 const CameraData::GetViewMatrix() {
		Vector3 const worldUp{ 0.0F, 1.0F, 0.0f };
		Vector3 const forward = CameraData::getForward();
		Vector3 const right = Vector3::cross(forward, worldUp).normalized();
		Vector3 const up = Vector3::cross(right, forward).normalized();
		Vector3 const & translation = CameraData::translation;
		auto lookAt = getLookAtMatrix(forward, up, translation);
		return lookAt;
	}

	Matrix4x4 const CameraData::GetProjectionMatrix() {
		float aspect = static_cast<float>(CameraData::screenWidth) / CameraData::screenHeight;
		return getPerspectiveMat(CameraData::fov, aspect, 0.1F, 100.0F);
	}

	void CameraData::setFov(Degree const & fov) {
		CameraData::fov = fov;
		CameraData::dataChanged = true;
	}

	void CameraData::setScreenWidth(int const screenWidth) {
		CameraData::screenWidth = screenWidth;
		CameraData::dataChanged = true;
	}

	void CameraData::setScreenHeight(int const screenHeight) {
		CameraData::screenHeight = screenHeight;
		CameraData::dataChanged = true;
	}

	void CameraData::setTranslation(Vector3 const & translation) {
		CameraData::translation = translation;
		CameraData::dataChanged = true;
	}

	void CameraData::setRotation(Vector3 const & rotation) {
		CameraData::rotation = rotation;
		CameraData::dataChanged = true;
	}

	void CameraData::setDataChangedToFalse() {
		CameraData::dataChanged = false;
	}

	Vector3 const CameraData::getForward() {
		Vector3 rotation = CameraData::rotation;
		Degree rotX{ rotation.x };
		Degree rotY{ rotation.y };
		float const x = static_cast<float>(cos(rotX) * cos(rotY));
		float const y = static_cast<float>(sin(rotX));
		float const z = static_cast<float>(cos(rotX) * sin(rotY));

		return Vector3{ x, y, z };
	}

	bool CameraData::dataChanged = false;
	Vector3 CameraData::translation{};
	Vector3 CameraData::rotation{};
	Degree CameraData::fov{};
	int CameraData::screenWidth;
	int CameraData::screenHeight;
}
