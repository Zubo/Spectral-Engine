#pragma once

#include <functional>

#include "Core/Event/Message/EventMessage.h"
#include "Core/Event/Message/EventMessageType.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	using EventHandler = std::function<void(EventMessage & message)>;

	class EventSubscription {
	public:
		EventSubscription(EventMessageType const eventMessageType, EventHandler const & eventHandler);
		EventSubscription(EventSubscription const & other) = default;
		EventSubscription(EventSubscription && other) = default;
		~EventSubscription() = default;

	public:
		void handle(EventMessage & message) const;
		EventMessageType getMessageType() const;
		SpInt getSubscriptionId() const;
		void operator=(EventSubscription const & other);
		bool operator==(EventSubscription const & other) const;

	private:
		SpInt _subscriptionId;
		EventHandler _eventHandler;
		EventMessageType _eventMessageType;
		
	private:
		static SpInt _nextSubscriptionId;
	};
}
