#pragma once

#include <Core/Math/Vector3.hpp>
#include <Core/Math/Degree.hpp>
#include <PlatformIndependence/SpType.hpp>

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
		SpInt _screenWidth = 0;
		SpInt _screenHeight = 0;
	};
}
