#include <Core/Math/Direction.hpp>

#include <Core/Math/Degree.hpp>
#include <Core/Math/SpMath.hpp>
#include <Core/Math/Vector3.hpp>

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
