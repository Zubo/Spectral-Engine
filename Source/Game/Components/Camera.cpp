#include "Core/Math/LinearTransformations.h"
#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Vector3.h"
#include "Game/Components/Camera.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Components/GameObjectComponent.h"
#include "Game/Components/Transform.h"
#include "Render/CameraData.h"

namespace sp {
	std::shared_ptr<Camera> Camera::_mainCamera;

	Camera::Camera(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void Camera::initCamera(Degree fov, SpInt screenWidth, SpInt screenHeight) {
		CameraData::setFov(fov);
		CameraData::setScreenHeight(screenHeight);
		CameraData::setScreenWidth(screenWidth);
	}

	std::shared_ptr<Camera> Camera::getMainCamera() {
		return _mainCamera;
	}

	void Camera::setMainCamera(std::shared_ptr<Camera> const camera) {
		_mainCamera = camera;
	}
}

