#pragma once

namespace sp {
	class IEventContext;
	class SpWindow;

	void bindWindowToEventContext(SpWindow & spWindow, IEventContext const & eventContext);
}
