#include "CameraInputHandler.h"

#include "Core/Math/SpMath.h"
#include "Core/Math/Vector2.h"
#include "Game/Components/Camera.h"
#include "Game/Components/Transform.h"
#include "Game/GameObject/GameObject.h"
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
		 Vector2 const mouseOffset = Input::mouseAxis() * sensitivity;

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

		 auto const cameraShared = Camera::getMainCamera();
		 auto const transformWeak = cameraShared->getGameObject()->getComponent<Transform>();

		 if (auto const transformShared = transformWeak.lock()) {
			 transformShared->setRotationEuler(Vector3{ static_cast<float>(_pitch), static_cast<float>(_yaw), 0.0F });
		 }
	 }

	 void CameraInputHandler::processKeyInput(SpFloat deltaTime) {
	 	SpFloat const cameraSpeed = 1.0F;
	 	auto const transformWeak = getGameObject()->getComponent<Transform>();
		std::weak_ptr<Camera> cameraWeak = getGameObject()->getComponent<Camera>();

		Vector3 cameraFront = CameraData::getForward();

	 	if (auto transformShared = transformWeak.lock()) {
	 		Vector3 position = transformShared->getPosition();
			Vector3 oldPosition{ position };

	 		if (Input::keyDown(KeyCode::W)) {
	 			position += cameraSpeed * cameraFront * deltaTime;
				transformShared->setPosition(position);
	 		}
	 		if (Input::keyDown(KeyCode::S)) {
	 			position -= cameraSpeed * cameraFront * deltaTime;
				transformShared->setPosition(position);
	 		}
	 		if (Input::keyDown(KeyCode::A)) {
	 			position -= cameraSpeed * Vector3::cross(cameraFront, _worldUp).normalized() * deltaTime;
				transformShared->setPosition(position);
	 		}
	 		if (Input::keyDown(KeyCode::D)) {
	 			position += cameraSpeed * Vector3::cross(cameraFront, _worldUp).normalized() * deltaTime;
				transformShared->setPosition(position);
	 		}
	 	}
	 }
}
