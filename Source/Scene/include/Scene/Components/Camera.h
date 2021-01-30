#pragma once

#include <memory>

#include "Core/Math/Degree.h"
#include "Core/Utility/OptionalRef.h"
#include "Scene/Components/GameObjectComponent.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	class GameObject;
	class Matrix4x4;
	class Vector3;

	class Camera : public GameObjectComponent {
	public:
		static Camera & getMainCamera();
		static void setMainCamera(Camera & mainCamera);

	private:
		static OptionalRef<Camera> _mainCamera;

	public:
		Camera(GameObject * gameObjectOwner);
		void initCamera(Degree fov, SpInt screenWidth, SpInt screenHeight);
	};
}
