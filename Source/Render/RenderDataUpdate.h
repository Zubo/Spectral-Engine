namespace sp {
	class Mesh;
	class ShaderProgram;
	class Matrix4x4;

	void createRenderData(int const gameObjectId, bool const active, unsigned int const meshId, bool const isStatic);
	void updateObjectMesh(int const gameObjectId, unsigned int const meshId, bool isStatic);
	void updateShaderProgram(int const gameObjectId, ShaderProgram const shaderProgram);
	void updateTranslationMatrix(int const gameObjectId, Matrix4x4 const & matrix);
	void updateRotationMatrix(int const gameObjectId, Matrix4x4 const & matrix);
	void updateScaleMatrix(int const gameObjectId, Matrix4x4 const & matrix);
}
