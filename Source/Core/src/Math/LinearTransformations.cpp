#include "Core/Math/LinearTransformations.h"
#include "Core/Math/Matrix4x4.h"

namespace sp {
	Matrix4x4 getPerspectiveMat(Degree const fov, SpFloat const aspect, SpFloat const far, SpFloat const near) {
		Matrix4x4 result;
		result[1][1] = 1.0F / tan(fov / 2.0F);
		result[0][0] = result[1][1] / aspect;

		SpFloat const frustumDepth = near - far;
		result[2][2] = -(far + near) / frustumDepth;
		result[2][3] = (-2 * far * near) / frustumDepth;
		result[3][2] = -1.0F;
		result[3][3] = 0;

		return result;
	}

	Matrix4x4 getOrthographicMat(SpFloat const left, SpFloat const right, SpFloat const bottom, SpFloat const top, SpFloat const zNear, SpFloat const zFar) {
		Matrix4x4 result;
		result[0][0] = 2.0F / (right - left);
		result[1][1] = 2.0F / (top - bottom);
		result[2][2] = -2 / (zFar - zNear);
		result[0][3] = -(right + left) / (right - left);
		result[1][3] = -(top + bottom) / (top - bottom);
		result[2][3] = -(zFar + zNear) / (zFar - zNear);
		result[3][3] = 1;

		return result;
	}
}
