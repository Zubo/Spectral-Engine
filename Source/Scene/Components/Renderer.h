#pragma once

#include "Scene/Components/GameObjectComponent.h"
#include "Scene/Components/Interface/IRenderer.h"
#include "Scene/Components/Interface/ITransformChangeObserver.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	class GameObject;

	class Renderer : public GameObjectComponent, public ITransformChangeObserver {
	public:
		Renderer(GameObject * const gameObjectOwner);
		void initRenderer(SpUnsigned const meshId);
		~Renderer();
		virtual void onPositionUpdated(Vector3 const & position) override;
		virtual void onRotationUpdated(Vector3 const & rotation) override;
		virtual void onScaleUpdated(Vector3 const & scale) override;

	private:
		bool hasMesh() const;
	};
}
