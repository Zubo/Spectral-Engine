#include "Core/Utility/WindowEventBinding.h"

#include "Core/Event/IEventContext.h"
#include "Core/Event/Message/Messages/ViewportChangedMessage.h"
#include "PlatformIndependence/SpWindow.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	void bindWindowToEventContext(SpWindow & spWindow, IEventContext const & eventContext) {
		spWindow.registerSetFramebufferSizeCallback(
			[&eventContext](SpInt width, SpInt height) {
				ViewportChangedMessage message{ width, height };
				eventContext.broadcastEvent(message);
		});
	}
}
