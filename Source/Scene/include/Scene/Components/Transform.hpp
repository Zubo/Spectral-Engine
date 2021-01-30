#pragma once

#include <vector>

#include <Scene/Components/GameObjectComponent.hpp>
#include <Core/Math/Vector3.hpp>

namespace sp {
	class Matrix4x4;

	class Transform : public GameObjectComponent {
	public:
		Transform(GameObject * const gameObjectOwner);
		Vector3 const getPosition() const;
		virtual void setPosition(Vector3 const & positon);
		Vector3 const getRotationEuler() const;
		virtual void setRotationEuler(Vector3 const & rotation);
		void setScale(Vector3 const & scale);
		Vector3 const getScale() const;

	private:
		Vector3 _position;
		Vector3 _rotationEuler;
		Vector3 _scaleVec;
	};
}
