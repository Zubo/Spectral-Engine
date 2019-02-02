#pragma once

#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Vector3.h"
#include "Radian.h"
#include "Degree.h"
#include "SpMath.h"

namespace sp {
	inline const Matrix4x4 translate(Matrix4x4 const & mat, Vector3 const & translation) {
		Matrix4x4 translationMat;
		translationMat[0][3] = translation.x;
		translationMat[1][3] = translation.y;
		translationMat[2][3] = translation.z;

		return translationMat * mat;
	}

	inline const Matrix4x4 scale(Matrix4x4 const & mat, Vector3 const & scale) {
		Matrix4x4 scaleMat;

		scaleMat[0][0] = scale.x;
		scaleMat[1][1] = scale.y;
		scaleMat[2][2] = scale.z;

		return scaleMat * mat;
	}

	inline Matrix4x4 const rotateX(Matrix4x4 const & mat, Radian const angle) {
		Matrix4x4 rotationMat;
		rotationMat[1][1] = cos(angle);
		rotationMat[1][2] = -sin(angle);
		rotationMat[2][1] = sin(angle);
		rotationMat[2][2] = cos(angle);

		return rotationMat * mat;
	}

	inline Matrix4x4 const rotateY(Matrix4x4 const & mat, Radian const angle) {
		Matrix4x4 rotationMat{};
		rotationMat[0][0] = cos(angle);
		rotationMat[0][2] = sin(angle);
		rotationMat[2][0] = -sin(angle);
		rotationMat[2][2] = cos(angle);

		return rotationMat * mat;
	}

	inline Matrix4x4 const rotateZ(Matrix4x4 const & mat, Radian const angle) {
		Matrix4x4 rotationMat{};
		rotationMat[0][0] = cos(angle);
		rotationMat[0][1] = -sin(angle);
		rotationMat[1][0] = sin(angle);
		rotationMat[1][1] = cos(angle);

		return rotationMat * mat;
	}

	inline Matrix4x4 const getCoordinateSystemMatrix(Vector3 const & forward, Vector3 const & up) {
		Matrix4x4 result{};
		Vector3 const right = Vector3::cross(forward, up);

		result[0][0] = right.x;
		result[0][1] = right.y;
		result[0][2] = right.z;
		result[1][0] = up.x;
		result[1][1] = up.y;
		result[1][2] = up.z;
		result[2][0] = -forward.x;
		result[2][1] = -forward.y;
		result[2][2] = -forward.z;

		return result;
	}

	inline Matrix4x4 const getLookAtMatrix(Vector3 const & forward, Vector3 const & up, Vector3 const & position) {
		Matrix4x4 coordinateSystemMatrix = getCoordinateSystemMatrix(forward, up);
		Matrix4x4 translationMatrix = translate(Matrix4x4{}, -position);

		return coordinateSystemMatrix * translationMatrix;
	}

	Matrix4x4 const getPerspectiveMat(Degree const fov, float const aspect, float const near, float const far);
}
