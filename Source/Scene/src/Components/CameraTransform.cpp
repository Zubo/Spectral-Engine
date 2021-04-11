#include <Scene/Components/CameraTransform.hpp>
#include <Scene/GameObject/GameObject.hpp>
#include <Render/CameraData.hpp>
#include <Render/RenderContext.hpp>

sp::CameraTransform::CameraTransform(GameObject * const gameObjectOwner) : Transform(gameObjectOwner) {
}

void sp::CameraTransform::setPosition(Vector3 const & position) {
 	Transform::setPosition(position);
	RenderContext & renderContext{ _gameObjectOwner->getSceneRef()->getRenderContext() };
	CameraData & cameraData{ renderContext.getCameraData() };
	cameraData.setTranslation(position);
}

void sp::CameraTransform::setRotationEuler(Vector3 const & rotation) {
	Transform::setRotationEuler(rotation);
	RenderContext & renderContext{ _gameObjectOwner->getSceneRef()->getRenderContext() };
	CameraData & cameraData{ renderContext.getCameraData() };
	cameraData.setRotation(rotation);
}
