#pragma once

#include <optional>
#include <stack>
#include <Render/GUI/ImGUIId.hpp>

namespace sp {
	struct ImGUIContext {
	public:

	public:
		std::optional<ImGUIID> HotID;
		std::optional<ImGUIID> ActiveID;
		std::stack<ImGUIID> CurrentIDStack;
	};
}