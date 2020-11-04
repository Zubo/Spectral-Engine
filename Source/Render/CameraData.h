#pragma once

#include "Core/Math/Vector3.h"
#include "Core/Math/Degree.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	class Matrix4x4;

	class CameraData {
	public:
		Matrix4x4 const GetViewMatrix();
		Matrix4x4 const GetProjectionMatrix();
		void setFov(Degree const & fov);
		void setScreenWidth(SpInt const screenWidth);
		void setScreenHeight(SpInt const screenHeight);
		Vector3 const getTranslation();
		void setTranslation(Vector3 const & translation);
		Vector3 const getRotation();
		void setRotation(Vector3 const & rotation);
		bool getDataChanged();
		void setDataChangedToFalse();
		Vector3 getForward();

	private:
		bool _dataChanged = false;
		Vector3 _translation;
		Vector3 _rotation;
		Degree _fov;
		SpInt _screenWidth;
		SpInt _screenHeight;
	};
}
