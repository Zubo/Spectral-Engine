#include "CameraInputHandler.h"

#include "Core/Math/SpMath.h"
#include "Core/Math/Vector2.h"
#include "Scene/Components/Camera.h"
#include "Scene/Components/Transform.h"
#include "Scene/GameObject/GameObject.h"
#include "Render/CameraData.h"
#include "PlatformIndependence/Input/Input.h"

namespace sp {
	CameraInputHandler::CameraInputHandler(GameObject * gameObject) : GameObjectComponent{ gameObject } {
	}

	void CameraInputHandler::update(SpFloat deltaTime) {
		 processMouseInput();
		 processKeyInput(deltaTime);
	 }

	 void CameraInputHandler::processMouseInput() {

		 float const sensitivity = 0.05F;

		 Input & input{ _gameObjectOwner->GetSceneRef()->getInput() };
		 Vector2 const mouseOffset = input.mouseAxis() * sensitivity;

		 if (mouseOffset.X * mouseOffset.X < 0.01F && mouseOffset.Y * mouseOffset.Y < 0.01F) {
			 return;
		 }

		 _yaw -= mouseOffset.X;
		 _pitch += mouseOffset.Y;

		 if (_pitch > 89.0F) {
			 _pitch = 89.0F;
		 }
		 if (_pitch < -89.0F) {
			 _pitch = -89.0F;
		 }

		 Camera & camera = Camera::getMainCamera();
		 auto const transformOptionalRef = camera.getGameObject()->getComponent<Transform>();

		 if (transformOptionalRef.HasRef()) {
			 transformOptionalRef->setRotationEuler(Vector3{ static_cast<float>(_pitch), static_cast<float>(_yaw), 0.0F });
		 }
	 }

	 void CameraInputHandler::processKeyInput(SpFloat deltaTime) {
	 	SpFloat const cameraSpeed = 1.0F;
	 	OptionalRef<Transform> const transform = getGameObject()->getComponent<Transform>();
		OptionalRef<Camera> const camera = getGameObject()->getComponent<Camera>();

		RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };
		CameraData & cameraData{ renderContext.getCameraData() };
		Vector3 cameraFront = cameraData.getForward();

	 	if (transform.HasRef()) {
	 		Vector3 position = transform->getPosition();
			Vector3 oldPosition{ position };

			Input & input{ _gameObjectOwner->GetSceneRef()->getInput() };

	 		if (input.keyDown(KeyCode::W)) {
	 			position += cameraSpeed * cameraFront * deltaTime;
				transform->setPosition(position);
	 		}
	 		if (input.keyDown(KeyCode::S)) {
	 			position -= cameraSpeed * cameraFront * deltaTime;
				transform->setPosition(position);
	 		}
	 		if (input.keyDown(KeyCode::A)) {
	 			position -= cameraSpeed * Vector3::cross(cameraFront, _worldUp).normalized() * deltaTime;
				transform->setPosition(position);
	 		}
	 		if (input.keyDown(KeyCode::D)) {
	 			position += cameraSpeed * Vector3::cross(cameraFront, _worldUp).normalized() * deltaTime;
				transform->setPosition(position);
	 		}
	 	}
	 }
}