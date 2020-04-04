#pragma once

namespace sp {
	class Vector3;

	class ITransformChangeObserver {
	public:
		virtual void onPositionUpdated(Vector3 const & position) = 0;
		virtual void onRotationUpdated(Vector3 const & rotation) = 0;
		virtual void onScaleUpdated(Vector3 const & scale) = 0;
	};
}
