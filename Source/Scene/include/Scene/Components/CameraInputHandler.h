#pragma once

#include <Scene/Components/GameObjectComponent.h>
#include <Core/Math/Vector3.h>

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
	 	Vector3 _worldUp{ 0.0F, 1.0F, 0.0F };
	 	double _yaw = 0.0;
	 	double _pitch = 0.0;
	 };
}
