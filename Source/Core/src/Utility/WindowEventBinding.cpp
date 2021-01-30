#include <Core/Utility/WindowEventBinding.hpp>

#include <Core/Event/IEventContext.hpp>
#include <Core/Event/Message/Messages/ViewportChangedMessage.hpp>
#include <PlatformIndependence/SpWindow.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	void bindWindowToEventContext(SpWindow & spWindow, IEventContext const & eventContext) {
		spWindow.registerSetFramebufferSizeCallback(
			[&eventContext](SpInt width, SpInt height) {
				ViewportChangedMessage message{ width, height };
				eventContext.broadcastEvent(message);
		});
	}
}
