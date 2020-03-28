#pragma once

#include "GameObjectComponent.h"
#include "Core/Math/Vector3.h"

namespace sp {
	class Matrix4x4;

	class Transform : public GameObjectComponent {
	public:
		Transform(GameObject * const gameObjectOwner);
		Vector3 const getPosition() const;
		virtual void setPosition(Vector3 const & positon);
		Matrix4x4 const getTransformMatrix() const;
		Vector3 const getRotationEuler() const;
		virtual void setRotationEuler(Vector3 const & rotation);
		void setScale(Vector3 const & scale);
		Vector3 const getScale() const;

	private:
		Matrix4x4 const getTranslationMatrix() const;
		Vector3 position;
		Vector3 rotationEuler;
		Vector3 scaleVec;
	};
}
