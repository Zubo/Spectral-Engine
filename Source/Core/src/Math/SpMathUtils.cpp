#include <Core/Math/SpMathUtils.hpp>

namespace sp {
	bool isPointInBox(Vector2 const point, Vector2 const boxOrigin, Vector2 const boxSize) {
		Vector2 const boxOppositeOrigin{ boxOrigin + boxSize };
		return boxOrigin.X <= point.X && boxOppositeOrigin.X >= point.X &&
			boxOrigin.Y <= point.Y && boxOppositeOrigin.Y >= point.Y;
	}
}
