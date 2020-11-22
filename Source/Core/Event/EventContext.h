#pragma once

#include <algorithm>
#include <functional>
#include <unordered_map>
#include <vector>

#include "Core/Event/EventSubscription.h"
#include "Core/Event/IEventContext.h"
#include "Core/Event/Message/EventMessageType.h"

namespace sp {
	class EventContext : public IEventContext {
	private:
		using SubscriptionVector = std::vector<EventSubscription>;

	public:
		EventContext() = default;
		~EventContext() = default;

	public:
		virtual void broadcastEvent(EventMessage & message) const override;
		virtual IEventSubscription const & subscribe(EventMessageType const messageType, EventHandler const & eventHandler) override;
		virtual void unsubscribe(SpInt const subscriptionId, EventMessageType const messageType) override;

	private:
		std::unordered_map<EventMessageType, SubscriptionVector> _eventHandlerMap;
	};
}
