#pragma once

#include "GameObjectComponent.h"
#include "Utility/Math/Vector3.h"

namespace sp {
	class Matrix4x4;

	class Transform : public GameObjectComponent {
	public:
		Transform(GameObject * const gameObjectOwner);
		Vector3 const getPosition() const;
		void setPosition(Vector3 const & positon);
		Matrix4x4 const getTransformMatrix() const;
		Vector3 const getRotationEuler() const;
		Vector3 const getDirection() const;
		void setRotationEuler(Vector3 const & rotation);
		void setScale(Vector3 const & scale);

	private:
		Matrix4x4 const getTranslationMatrix() const;
		Vector3 position;
		Vector3 rotationEuler;
		Vector3 scaleVec;
	};
}
