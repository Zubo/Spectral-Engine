#pragma once

#include <functional>

#include <Core/Event/IEventSubscription.h>

namespace sp {
	using EventHandler = std::function<void(EventMessage & message)>;
	class EventMessage;

	class IEventContext {
	public:
		virtual ~IEventContext() = default;

	public:
		virtual void broadcastEvent(EventMessage & message) const = 0;
		virtual IEventSubscription const & subscribe(EventMessageType const messageType, EventHandler const & eventHandler) = 0;
		virtual void unsubscribe(SpInt const subscriptionId, EventMessageType const messageType) = 0;
	};
}
