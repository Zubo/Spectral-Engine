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
		static bool getDataChanged();
		static void setDataChangedToFalse();
		static Vector3 const getForward();

	private:
		static bool _dataChanged;
		static Vector3 _translation;
		static Vector3 _rotation;
		static Degree _fov;
		static SpInt _screenWidth;
		static SpInt _screenHeight;
	};
}
