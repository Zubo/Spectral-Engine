namespace sp {
	class Matrix4x4;
	class Vector3;

	Matrix4x4 const getLookAtMatrix(Vector3 const & forward, Vector3 const & up, Vector3 const & position);
}
