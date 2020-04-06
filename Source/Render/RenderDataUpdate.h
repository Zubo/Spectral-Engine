#pragma once

namespace sp {
	class Mesh;
	class ShaderProgram;
	class Matrix4x4;
	class Vector3;

	void createRenderData(int const gameObjectId, bool const active, unsigned int const meshId, bool const isStatic);
	void updateObjectMesh(int const gameObjectId, unsigned int const meshId, bool isStatic);
	void updateShaderProgram(int const gameObjectId, ShaderProgram const shaderProgram);
	void updatePosition(int const gameObjectId, Vector3 const & translation);
	void saveRotation(int const gameObjectId, Vector3 const & rotationEuler);
	void updateScale(int const gameObjectId, Vector3 const & scale);
	void updateTextureId(int const gameObjectId, unsigned int const textureId, unsigned int const textureIdIndex);
}
