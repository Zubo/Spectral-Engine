#include <Scene/Components/LightSource.hpp>

#include <memory>

#include <Core/Math/Direction.hpp>
#include <Core/Math/Degree.hpp>
#include <Scene/GameObject/GameObject.hpp>
#include <Scene/Components/GameObjectComponent.hpp>
#include <Scene/Components/Transform.hpp>
#include <Render/Enum/LightType.hpp>
#include <Render/LightData.hpp>
#include <Render/LightDataContainer.hpp>
#include <Render/RenderContext.hpp>

namespace sp {
	LightSource::LightSource(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
		_gameObjectOwner = gameObjectOwner;
	}

	void LightSource::initLightSource(LightType const lightType) {
		OptionalRef<Transform const> const transformOptionalRef =
			_gameObjectOwner->getComponent<Transform const>();

		Vector3 const & position = transformOptionalRef->getPosition();
		Vector3 const & rotation = transformOptionalRef->getRotationEuler();
		Degree const xAngle{ rotation.X };
		Degree const yAngle{ rotation.Y };
		Vector3 const & direction = getDirection(xAngle, yAngle);

		LightData const lightData{ lightType, Vector3{ 1.0F }, position, direction };

		RenderContext & renderContext{ _gameObjectOwner->getSceneRef()->getRenderContext() };

		LightDataContainer & lightDataContainer{ renderContext.getLightDataContainer() };
		lightDataContainer.saveLightData(lightData);

		_lightDataId = lightData.Id;
	}

	void LightSource::onPositionUpdated(Vector3 const & position) {
		RenderContext & renderContext{ _gameObjectOwner->getSceneRef()->getRenderContext() };
		LightDataContainer & lightDataContainer{ renderContext.getLightDataContainer() };
		LightData lightData = lightDataContainer.getLightData(_lightDataId);
		lightData.Position = position;
		lightData.Changed = true;
		lightDataContainer.saveLightData(lightData);
	}

	void LightSource::onRotationUpdated(Vector3 const & rotation) {
		RenderContext & renderContext{ _gameObjectOwner->getSceneRef()->getRenderContext() };
		LightDataContainer & lightDataContainer{ renderContext.getLightDataContainer() };

		LightData lightData = lightDataContainer.getLightData(_lightDataId);

		Degree const xAngle{ rotation.X };
		Degree const yAngle{ rotation.Y };
		Vector3 const & direction = getDirection(xAngle, yAngle);
		lightData.Direction = direction;
		lightData.Changed = true;
		lightDataContainer.saveLightData(lightData);
	}

	void LightSource::onScaleUpdated(Vector3 const & scale) {
		(void)scale;
		// Scale has no effect on light
	}
}
