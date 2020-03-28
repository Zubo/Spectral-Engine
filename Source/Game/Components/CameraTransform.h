#pragma once

#include "Game/Components/Transform.h"

namespace sp {
	class CameraTransform : public Transform {
	public:
		CameraTransform(GameObject * const gameObjectOwner);
		virtual void setPosition(Vector3 const & positon) override;
		virtual void setRotationEuler(Vector3 const & rotation) override;
	};
}