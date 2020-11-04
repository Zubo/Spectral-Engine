#include "Game/Components/CameraTransform.h"
#include "Game/GameObject/GameObject.h"
#include "Render/CameraData.h"
#include "Render/RenderContext.h"

sp::CameraTransform::CameraTransform(GameObject * const gameObjectOwner) : Transform(gameObjectOwner) {
}

void sp::CameraTransform::setPosition(Vector3 const & position) {
 	Transform::setPosition(position);
	RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };
	CameraData & cameraData{ renderContext.CameraData };
	cameraData.setTranslation(position);
}

void sp::CameraTransform::setRotationEuler(Vector3 const & rotation) {
	Transform::setRotationEuler(rotation);
	RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };
	CameraData & cameraData{ renderContext.CameraData };
	cameraData.setRotation(rotation);
}
