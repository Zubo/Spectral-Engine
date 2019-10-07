namespace sp {
	class Mesh;
	class ShaderProgram;

	void initializeRenderData(int const gameObjectId, ShaderProgram const shaderProgram, bool const active, bool isStatic, Mesh const & mesh);
}
