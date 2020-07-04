#pragma once

#include <memory>

#include "Core/Math/Degree.h"
#include "Game/Components/GameObjectComponent.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	class GameObject;
	class Matrix4x4;
	class Vector3;

	class Camera : public GameObjectComponent {
	public:
		static std::shared_ptr<Camera> getMainCamera();
		static void setMainCamera(std::shared_ptr<Camera> const mainCamera);

	private:
		static std::shared_ptr<Camera> _mainCamera;

	public:
		Camera(GameObject * gameObjectOwner);
		void initCamera(Degree fov, SpInt screenWidth, SpInt screenHeight);
	};
}
