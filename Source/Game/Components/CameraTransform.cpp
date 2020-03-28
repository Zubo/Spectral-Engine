#include "Game/Components/CameraTransform.h"

#include "Render/CameraData.h"

sp::CameraTransform::CameraTransform(GameObject * const gameObjectOwner) : Transform(gameObjectOwner) {
}

void sp::CameraTransform::setPosition(Vector3 const & position) {
 	Transform::setPosition(position);
	CameraData::setTranslation(position);
}

void sp::CameraTransform::setRotationEuler(Vector3 const & rotation) {
	Transform::setRotationEuler(rotation);
	CameraData::setRotation(rotation);
}
