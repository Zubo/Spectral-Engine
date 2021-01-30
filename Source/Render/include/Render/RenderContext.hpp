#pragma once

#include <memory>

#include <Core/Event/EventBinding.hpp>
#include <PlatformIndependence/SpWindow.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <Render/CameraData.hpp>
#include <Render/LightDataContainer.hpp>
#include <Render/RenderDataContainer.hpp>
#include <Render/Shader/ShaderProgram.hpp>

namespace sp {
	class IEventContext;

	class RenderContext {
	public:
		RenderContext(SpInt const id);

	public:
		SpInt getId();
		RenderDataContainer const & getRenderDataContainer() const;
		RenderDataContainer & getRenderDataContainer();
		LightDataContainer const & getLightDataContainer() const;
		LightDataContainer & getLightDataContainer();
		CameraData const & getCameraData() const;
		CameraData & getCameraData();
		std::unique_ptr<SpWindow> const & getWindow() const;
		void bindWindow(std::unique_ptr<SpWindow> spWindowUnique, IEventContext & eventContext);
		void createRenderData(SpInt const gameObjectId, bool const active, SpUnsigned const meshId, bool const isStatic);
		void updateObjectMesh(SpInt const gameObjectId, SpUnsigned const meshId, bool isStatic);
		void updateShaderProgram(SpInt const gameObjectId, ShaderProgram const shaderProgram);
		void updatePosition(SpInt const gameObjectId, Vector3 const & translation);
		void saveRotation(SpInt const gameObjectId, Vector3 const & rotationEuler);
		void updateScale(SpInt const gameObjectId, Vector3 const & scale);
		void updateTextureId(SpInt const gameObjectId, SpUnsigned const textureId, SpUnsigned const textureIdIndex);

	private:
		const SpInt _id;
		RenderDataContainer _renderDataContainer;
		LightDataContainer _lightDataContainer;
		CameraData _cameraData;
		EventBinding _viewportChangedEventBinding;

	private:
		std::unique_ptr<SpWindow> _spWindowUnique;
	};
}
