#pragma once

#include "Core/Math/Vector3.h"
#include "Core/Math/Degree.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	class Matrix4x4;

	class CameraData {
	public:
		static Matrix4x4 const GetViewMatrix();
		static Matrix4x4 const GetProjectionMatrix();
		static void setFov(Degree const & fov);
		static void setScreenWidth(SpInt const screenWidth);
		static void setScreenHeight(SpInt const screenHeight);
		static Vector3 const getTranslation();
		static void setTranslation(Vector3 const & translation);
		static Vector3 const getRotation();
		static void setRotation(Vector3 const & rotation);
		static bool const getDataChanged();
		static void setDataChangedToFalse();
		static Vector3 const getForward();

	private:
		static bool dataChanged;
		static Vector3 translation;
		static Vector3 rotation;
		static Degree fov;
		static SpInt screenWidth;
		static SpInt screenHeight;
	};
}
