#include <Core/Math/LinearTransformations.hpp>
#include <Core/Math/Matrix4x4.hpp>
#include <Core/Math/Vector3.hpp>
#include <Scene/Components/Camera.hpp>
#include <Scene/GameObject/GameObject.hpp>
#include <Scene/Components/GameObjectComponent.hpp>
#include <Scene/Components/Transform.hpp>
#include <Render/CameraData.hpp>

namespace sp {
	OptionalRef<Camera> Camera::_mainCamera;

	Camera::Camera(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void Camera::initCamera(Degree fov, SpInt screenWidth, SpInt screenHeight) {
		RenderContext & renderContext{ _gameObjectOwner->getSceneRef()->getRenderContext() };
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

