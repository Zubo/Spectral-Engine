#pragma once

#include <memory>

#include "Game/Components/GameObjectComponent.h"
#include "Core/Math/Degree.h"

namespace sp {
	class GameObject;
	class Matrix4x4;
	class Vector3;

	class Camera : public GameObjectComponent {
	public:
		static std::shared_ptr<Camera> getMainCamera();
		static void setMainCamera(std::shared_ptr<Camera> const mainCamera);

	private:
		static std::shared_ptr<Camera> mainCamera;

	public:
		Camera(GameObject * gameObjectOwner);
		void initCamera(Degree fov, int screenWidth, int screenHeight);
	};
}
