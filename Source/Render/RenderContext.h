#pragma once

#include <memory>

#include "PlatformIndependence/SpWindow.h"
#include "PlatformIndependence/SpType.h"
#include "Render/CameraData.h"
#include "Render/LightDataContainer.h"
#include "Render/RenderDataContainer.h"
#include "Render/Shader/ShaderProgram.h"

namespace sp {
	class RenderContext {
	public:
		RenderContext(SpInt const id);

	public:
		std::unique_ptr<SpWindow> const & getWindow() const;
		void assignWindow(std::unique_ptr<SpWindow> spWindowUnique);

	public:
		void createRenderData(SpInt const gameObjectId, bool const active, SpUnsigned const meshId, bool const isStatic);
		void updateObjectMesh(SpInt const gameObjectId, SpUnsigned const meshId, bool isStatic);
		void updateShaderProgram(SpInt const gameObjectId, ShaderProgram const shaderProgram);
		void updatePosition(SpInt const gameObjectId, Vector3 const & translation);
		void saveRotation(SpInt const gameObjectId, Vector3 const & rotationEuler);
		void updateScale(SpInt const gameObjectId, Vector3 const & scale);
		void updateTextureId(SpInt const gameObjectId, SpUnsigned const textureId, SpUnsigned const textureIdIndex);

	public:
		const SpInt Id;
		RenderDataContainer RenderDataContainer;
		LightDataContainer LightDataContainer;
		CameraData CameraData;

	private:
		std::unique_ptr<SpWindow> _spWindowUnique;
	};
}
