#include <Core/Math/LinearTransformations.h>
#include <Core/Math/Matrix4x4.h>
#include <Core/Math/Vector3.h>
#include <Scene/Components/Camera.h>
#include <Scene/GameObject/GameObject.h>
#include <Scene/Components/GameObjectComponent.h>
#include <Scene/Components/Transform.h>
#include <Render/CameraData.h>

namespace sp {
	OptionalRef<Camera> Camera::_mainCamera;

	Camera::Camera(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void Camera::initCamera(Degree fov, SpInt screenWidth, SpInt screenHeight) {
		RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };
		CameraData & cameraData{ renderContext.getCameraData() };
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

