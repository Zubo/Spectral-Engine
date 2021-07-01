#pragma once

#include <Core/Math/Vector2.hpp>

namespace sp {	
	bool isPointInBox(Vector2 const point, Vector2 const boxOrigin, Vector2 const boxSize);
}
