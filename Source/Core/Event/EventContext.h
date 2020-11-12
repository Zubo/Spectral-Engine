#pragma once

#include <algorithm>
#include <functional>
#include <unordered_map>
#include <vector>

#include "Core/Event/Message/EventMessageType.h"
#include "Core/Event/EventSubscription.h"

namespace sp {
	class EventContext {
	private:
		using SubscriptionVector = std::vector<EventSubscription>;

	public:
		EventContext() = default;
		~EventContext() = default;

	public:
		void broadcastEvent(EventMessage & message) const;
		EventSubscription const & subscribe(EventMessageType const messageType, EventHandler const & eventHandler);
		void unsubscribe(SpInt const subscriptionId, EventMessageType const messageType);

	private:
		std::unordered_map<EventMessageType, SubscriptionVector> _eventHandlerMap;
	};
}
