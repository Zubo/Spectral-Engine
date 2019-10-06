#include "Render/RenderData.h"

namespace sp {
	RenderData const & RenderData::operator=(RenderData const & renderData) {
		return RenderData{ renderData };
	}
}
