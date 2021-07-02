#include <Render/GUI/ImGUIId.hpp>

namespace sp {
	bool ImGUIID::operator==(ImGUIID const & other) const {
		return OwnerFunction == other.OwnerFunction &&
			Item == other.Item &&
			Index == other.Index;
	}
}
