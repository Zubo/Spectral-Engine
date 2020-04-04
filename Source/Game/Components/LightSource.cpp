#include "Game/Components/LightSource.h"

#include <memory>

#include "Core/Math/Direction.h"
#include "Core/Math/Degree.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Components/GameObjectComponent.h"
#include "Game/Components/Transform.h"
#include "Render/Enum/LightType.h"
#include "Render/LightData.h"
#include "Render/LightDataContainer.h"

namespace sp {
	LightSource::LightSource(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
		this->gameObjectOwner = gameObjectOwner;
	}

	void LightSource::initLightSource(LightType const lightType) {
		std::weak_ptr<Transform const> const transformWeak =
			this->gameObjectOwner->getComponent<Transform>();

		std::shared_ptr<Transform const> const transformShared = transformWeak.lock();
		Vector3 const & position = transformShared->getPosition();
		Vector3 const & rotation = transformShared->getRotationEuler();
		Degree const xAngle{ rotation.x };
		Degree const yAngle{ rotation.y };
		Vector3 const & direction = getDirection(xAngle, yAngle);

		LightData const lightData{ lightType, Vector3{ 1.0F }, position, direction };
		LightDataContainer & lightDataContainer = LightDataContainer::getInstance();
		lightDataContainer.saveLightData(lightData);
	}

	void LightSource::onPositionUpdated(Vector3 const & position) {
		int const gameObjectId = this->gameObjectOwner->getId();
		LightDataContainer & lightDataContainer = LightDataContainer::getInstance();
		LightData lightData = lightDataContainer.getLightData(gameObjectId);
		lightData.position = position;
		lightData.changed = true;
		lightDataContainer.saveLightData(lightData);
	}

	void LightSource::onRotationUpdated(Vector3 const & rotation) {
		int const gameObjectId = this->gameObjectOwner->getId();
		LightDataContainer & lightDataContainer = LightDataContainer::getInstance();
		LightData lightData = lightDataContainer.getLightData(gameObjectId);

		Degree const xAngle{ rotation.x };
		Degree const yAngle{ rotation.y };
		Vector3 const & direction = getDirection(xAngle, yAngle);
		lightData.direction = direction;
		lightData.changed = true;
		lightDataContainer.saveLightData(lightData);
	}

	void LightSource::onScaleUpdated(Vector3 const & scale) {
		// Scale has no effect on light
	}
}
