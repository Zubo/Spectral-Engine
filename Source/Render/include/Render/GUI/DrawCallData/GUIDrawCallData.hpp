#pragma once

#include <variant>

#include <Render/GUI/DrawCallData/TextDrawCallData.hpp>
#include <Render/GUI/DrawCallData/TextureDrawCallData.hpp>

namespace sp {
	using GUIDrawCallData = std::variant<TextDrawCallData, TextureDrawCallData>;
}