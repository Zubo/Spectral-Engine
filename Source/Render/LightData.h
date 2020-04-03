#pragma once

#include "Core/Math/Vector3.h"
#include "Render/Enum/LightType.h"

namespace sp {
	class LightData {
	public:
		static int getNextId();
		LightData(LightType const type, Vector3 const & color, Vector3 const & position, Vector3 const & direction);

	private:

	public:
		int id;
		LightType type;
		Vector3 color;
		Vector3 position;
		Vector3 direction;
		bool changed;

	private:
		static int nextId;
	};
}
