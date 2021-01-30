#include "Direction.h"

#include "Core/Math/Degree.h"
#include "Core/Math/SpMath.h"
#include "Core/Math/Vector3.h"

namespace sp {
	Vector3 const getDirection(Degree const xAngle, Degree const yAngle)
	{
		Vector3 const dir = Vector3{
			cos(xAngle) * cos(yAngle),
			sin(xAngle),
			cos(xAngle) * sin(yAngle)
		};

		return dir;
	}
}
