#include "Render/LightData.h"

namespace sp {
	int LightData::nextId = 0;

	LightData::LightData(LightType const type, Vector3 const & color, Vector3 const & position, Vector3 const & direction)
		: type{ type },
		color{ color },
		position{ position },
		direction{ direction },
		changed{ true },
		id{ LightData::getNextId() } {
	}

	int LightData::getNextId()
	{
		return (++nextId);
	}
}
