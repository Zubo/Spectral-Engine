#include "Core/Math/LinearTransformations.h"
#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Vector3.h"
#include "Game/Components/Camera.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Components/GameObjectComponent.h"
#include "Game/Components/Transform.h"
#include "Render/CameraData.h"

namespace sp {
	OptionalRef<Camera> Camera::_mainCamera;

	Camera::Camera(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void Camera::initCamera(Degree fov, SpInt screenWidth, SpInt screenHeight) {
		RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };
		CameraData & cameraData{ renderContext.CameraData };
		cameraData.setFov(fov);
		cameraData.setScreenHeight(screenHeight);
		cameraData.setScreenWidth(screenWidth);
	}

	Camera & Camera::getMainCamera() {
		return _mainCamera;
	}

	void Camera::setMainCamera(Camera & camera) {
		_mainCamera = camera;
	}
}

