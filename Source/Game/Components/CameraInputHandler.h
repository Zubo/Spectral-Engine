#pragma once

#include "Game/Components/GameObjectComponent.h"
#include "Core/Math/Vector3.h"

namespace sp {
	 class CameraInputHandler : public GameObjectComponent {
	 public:
		 CameraInputHandler(GameObject * gameObject);

	 public:
		 void update(SpFloat deltaTime) override;

	 private:
	 	void processMouseInput();
	 	void processKeyInput(SpFloat deltaTime);
		
	 private:
	 	Vector3 worldUp{ 0.0F, 1.0F, 0.0F };
	 	double yaw = 0.0;
	 	double pitch = 0.0;
	 };
}
