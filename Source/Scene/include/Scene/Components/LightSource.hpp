#pragma once

#include <Scene/Components/GameObjectComponent.hpp>
#include <Scene/Components/Interface/ITransformChangeObserver.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <Render/Enum/LightType.hpp>

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
