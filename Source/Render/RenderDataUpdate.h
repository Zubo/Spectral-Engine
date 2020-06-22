#pragma once

#include "PlatformIndependence/SpType.h"

namespace sp {
	class Mesh;
	class ShaderProgram;
	class Matrix4x4;
	class Vector3;

	void createRenderData(SpInt const gameObjectId, bool const active, SpUnsigned const meshId, bool const isStatic);
	void updateObjectMesh(SpInt const gameObjectId, SpUnsigned const meshId, bool isStatic);
	void updateShaderProgram(SpInt const gameObjectId, ShaderProgram const shaderProgram);
	void updatePosition(SpInt const gameObjectId, Vector3 const & translation);
	void saveRotation(SpInt const gameObjectId, Vector3 const & rotationEuler);
	void updateScale(SpInt const gameObjectId, Vector3 const & scale);
	void updateTextureId(SpInt const gameObjectId, SpUnsigned const textureId, SpUnsigned const textureIdIndex);
}
