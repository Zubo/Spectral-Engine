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
		void subscribe(EventSubscription const & eventSubscription);
		void unsubscribe(EventSubscription const & eventSubscription);

	private:
		std::unordered_map<EventMessageType, SubscriptionVector> _eventHandlerMap;
	};
}
