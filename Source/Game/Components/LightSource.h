#pragma once

#include "Game/Components/GameObjectComponent.h"
#include "Game/Components/Interface/ITransformChangeObserver.h"
#include "PlatformIndependence/SpType.h"
#include "Render/Enum/LightType.h"

namespace sp {
	class Vector3;

	class LightSource : public GameObjectComponent, public ITransformChangeObserver {
	public:
		LightSource(GameObject * gameObjectOwner);

	public:
		void initLightSource(LightType const lightType);
		virtual void onPositionUpdated(Vector3 const & position) override;
		virtual void onRotationUpdated(Vector3 const & rotation) override;
		virtual void onScaleUpdated(Vector3 const & scale) override;

	private:
		SpInt _lightDataId;
	};
}
