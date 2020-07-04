#include "PlatformIndependence/SpType.h"
#include "Render/LightData.h"

namespace sp {
	SpInt LightData::_nextId = 0;

	LightData::LightData(LightType const type, Vector3 const & color, Vector3 const & position, Vector3 const & direction)
		: Type{ type },
		Color{ color },
		Position{ position },
		Direction{ direction },
		Changed{ true },
		Id{ LightData::getNextId() } {
	}

	SpInt LightData::getNextId()
	{
		return (++_nextId);
	}
}
