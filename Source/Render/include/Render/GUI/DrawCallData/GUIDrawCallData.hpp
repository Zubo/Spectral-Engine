#pragma once

#include <variant>

#include <Render/GUI/DrawCallData/TextDrawCallData.hpp>

namespace sp {
	using GUIDrawCallData = std::variant<TextDrawCallData>;
}