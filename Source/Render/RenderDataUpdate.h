namespace sp {
	class Mesh;
	class ShaderProgram;
	class Matrix4x4;

	void updateRenderData(int const gameObjectId, ShaderProgram const shaderProgram, bool const active, bool isStatic, Mesh const & mesh);
	void updateTranslationMatrix(int const gameObjectId, Matrix4x4 const & matrix);
	void updateRotationMatrix(int const gameObjectId, Matrix4x4 const & matrix);
	void updateScaleMatrix(int const gameObjectId, Matrix4x4 const & matrix);
}
