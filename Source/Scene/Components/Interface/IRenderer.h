#pragma once

namespace sp {
	class IRenderer {
	public:
		virtual void render() const = 0;
	};
}