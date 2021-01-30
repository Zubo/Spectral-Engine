#pragma once

#include <Core/Math/Vector3.h>
#include <Core/Math/Degree.h>
#include <PlatformIndependence/SpType.h>

namespace sp {
	class Matrix4x4;

	class CameraData {
	public:
		Matrix4x4 GetViewMatrix() const;
		Matrix4x4 GetProjectionMatrix() const;
		void setFov(Degree const & fov);
		void setScreenWidth(SpInt const screenWidth);
		void setScreenHeight(SpInt const screenHeight);
		Vector3 getTranslation() const;
		void setTranslation(Vector3 const & translation);
		Vector3 getRotation() const;
		void setRotation(Vector3 const & rotation);
		bool getDataChanged() const;
		void setDataChangedToFalse();
		Vector3 getForward() const;

	private:
		bool _dataChanged = false;
		Vector3 _translation;
		Vector3 _rotation;
		Degree _fov;
		SpInt _screenWidth;
		SpInt _screenHeight;
	};
}
