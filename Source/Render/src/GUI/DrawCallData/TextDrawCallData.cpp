#include <Core/Utility/OptionalRef.hpp>
#include <Render/GUI/DrawCallData/TextDrawCallData.hpp>

namespace sp {
	TextDrawCallData::TextDrawCallData(SpString const & text, Vector2 const position, Vector2 const scale, Font const & font) : 
		Text{ text },
		Position{ position },
		Scale{ scale },
		FontRef{ font } {
	}
}
