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

	void CameraInputHandler::update(float deltaTime) {
		 this->processMouseInput();
		 this->processKeyInput(deltaTime);
	 }

	 void CameraInputHandler::processMouseInput() {

		 double const sensitivity = 0.05;
		 Vector2 const mouseOffset = Input::mouseAxis() * sensitivity;

		 if (mouseOffset.x * mouseOffset.x < 0.01F && mouseOffset.y * mouseOffset.y < 0.01F) {
			 return;
		 }

		 yaw -= mouseOffset.x;
		 pitch += mouseOffset.y;

		 if (pitch > 89.0F) {
			 pitch = 89.0F;
		 }
		 if (pitch < -89.0F) {
			 pitch = -89.0F;
		 }

		 auto const cameraShared = Camera::getMainCamera();
		 auto const transformWeak = cameraShared->getGameObject()->getComponent<Transform>();

		 if (auto const transformShared = transformWeak.lock()) {
			 transformShared->setRotationEuler(Vector3{ static_cast<float>(pitch), static_cast<float>(yaw), 0.0F });
		 }
	 }

	 void CameraInputHandler::processKeyInput(float deltaTime) {
	 	float const cameraSpeed = 1.0F;
	 	auto const transformWeak = this->getGameObject()->getComponent<Transform>();
		std::weak_ptr<Camera> cameraWeak = this->getGameObject()->getComponent<Camera>();

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
	 			position -= cameraSpeed * Vector3::cross(cameraFront, worldUp).normalized() * deltaTime;
				transformShared->setPosition(position);
	 		}
	 		if (Input::keyDown(KeyCode::D)) {
	 			position += cameraSpeed * Vector3::cross(cameraFront, worldUp).normalized() * deltaTime;
				transformShared->setPosition(position);
	 		}
	 	}
	 }
}
