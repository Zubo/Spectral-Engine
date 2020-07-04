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
		this->_gameObjectOwner = gameObjectOwner;
	}

	void LightSource::initLightSource(LightType const lightType) {
		std::weak_ptr<Transform const> const transformWeak =
			this->_gameObjectOwner->getComponent<Transform>();

		std::shared_ptr<Transform const> const transformShared = transformWeak.lock();

		Vector3 const & position = transformShared->getPosition();
		Vector3 const & rotation = transformShared->getRotationEuler();
		Degree const xAngle{ rotation.X };
		Degree const yAngle{ rotation.Y };
		Vector3 const & direction = getDirection(xAngle, yAngle);

		LightData const lightData{ lightType, Vector3{ 1.0F }, position, direction };
		LightDataContainer & lightDataContainer = LightDataContainer::getInstance();
		lightDataContainer.saveLightData(lightData);

		this->_lightDataId = lightData.Id;
	}

	void LightSource::onPositionUpdated(Vector3 const & position) {
		LightDataContainer & lightDataContainer = LightDataContainer::getInstance();
		LightData lightData = lightDataContainer.getLightData(this->_lightDataId);
		lightData.Position = position;
		lightData.Changed = true;
		lightDataContainer.saveLightData(lightData);
	}

	void LightSource::onRotationUpdated(Vector3 const & rotation) {
		LightDataContainer & lightDataContainer = LightDataContainer::getInstance();
		LightData lightData = lightDataContainer.getLightData(this->_lightDataId);

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
