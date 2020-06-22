#pragma once

#include "Core/Math/Vector3.h"
#include "PlatformIndependence/SpType.h"
#include "Render/Enum/LightType.h"

namespace sp {
	class LightData {
	public:
		static SpInt getNextId();
		LightData(LightType const type, Vector3 const & color, Vector3 const & position, Vector3 const & direction);

	private:

	public:
		SpInt id;
		LightType type;
		Vector3 color;
		Vector3 position;
		Vector3 direction;
		bool changed;

	private:
		static SpInt nextId;
	};
}
