#include "PlatformIndependence/SpType.h"
#include "Render/LightData.h"

namespace sp {
	SpInt LightData::nextId = 0;

	LightData::LightData(LightType const type, Vector3 const & color, Vector3 const & position, Vector3 const & direction)
		: type{ type },
		color{ color },
		position{ position },
		direction{ direction },
		changed{ true },
		id{ LightData::getNextId() } {
	}

	SpInt LightData::getNextId()
	{
		return (++nextId);
	}
}
