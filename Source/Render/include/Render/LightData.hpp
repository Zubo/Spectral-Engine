#pragma once

#include <Core/Math/Vector3.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <Render/Enum/LightType.hpp>

namespace sp {
	class LightData {
	public:
		static SpInt getNextId();
		LightData(LightType const type, Vector3 const & color, Vector3 const & position, Vector3 const & direction);

	private:

	public:
		SpInt Id;
		LightType Type;
		Vector3 Color;
		Vector3 Position;
		Vector3 Direction;
		bool Changed;

	private:
		static SpInt _nextId;
	};
}
