#pragma once

#include <functional>

#include "Core/Event/Message/EventMessage.h"
#include "Core/Event/Message/EventMessageType.h"
#include "Core/Utility/OptionalRef.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	using EventHandler = std::function<void(EventMessage & message)>;
	class EventContext;

	class EventSubscription {
	public:
		EventSubscription(EventSubscription const & other) = default;
		EventSubscription(EventSubscription && other) = default;
		~EventSubscription();

	private:
		EventSubscription(EventContext & eventContext, EventHandler const & eventHandler, EventMessageType const eventMessageType);

	public:
		void handle(EventMessage & message) const;
		EventMessageType getMessageType() const;
		void operator=(EventSubscription const & other);
		bool operator==(EventSubscription const & other) const;

	private:
		SpInt _subscriptionId;
		EventHandler _eventHandler;
		EventMessageType _eventMessageType;
		OptionalRef<EventContext> _eventContextRef;
		
	public:
		static EventSubscription create(EventContext & eventContext, EventHandler const & eventHandler, EventMessageType const eventMessageType);

	private:
		static SpInt _nextSubscriptionId;
	};
}
