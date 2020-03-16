#include "Core/Math/Vector3.h"

#include "Core/Math/Degree.h"

namespace sp {
	class Matrix4x4;

	class CameraData {
	public:
		static Matrix4x4 const GetViewMatrix();
		static Matrix4x4 const GetProjectionMatrix();
		static void setFov(Degree const & fov);
		static void setScreenWidth(int const screenWidth);
		static void setScreenHeight(int const screenHeight);
		static void setTranslation(Vector3 const & translation);
		static void setRotation(Vector3 const & rotation);
		static void setDataChangedToFalse();

	private:
		static Vector3 const getForward();

	private:
		static bool dataChanged;
		static Vector3 translation;
		static Vector3 rotation;
		static Degree fov;
		static int screenWidth;
		static int screenHeight;
	};
}
