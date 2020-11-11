#include <memory>

#include "Core/Event/EventSubscription.h"
#include "Core/Event/EventContext.h"

namespace sp {
	SpInt EventSubscription::_nextSubscriptionId{ 0 };

	EventSubscription::~EventSubscription() {
		_eventContextRef->unsubscribe(*this);
	}

	EventSubscription::EventSubscription(EventContext & eventContext, EventHandler const & eventHandler, EventMessageType const eventMessageType) :
		_subscriptionId{ _nextSubscriptionId++ },
		_eventHandler{ eventHandler },
		_eventMessageType{ eventMessageType },
		_eventContextRef{ eventContext} {
	}

	void EventSubscription::handle(EventMessage & message) const {
		_eventHandler(message);
	}

	EventMessageType EventSubscription::getMessageType() const {
		return _eventMessageType;
	}

	void EventSubscription::operator=(EventSubscription const & other) {
		_subscriptionId = other._subscriptionId;
		_eventHandler = other._eventHandler;
		_eventMessageType = other._eventMessageType;
		_eventContextRef = other._eventContextRef;
	}

	bool EventSubscription::operator==(EventSubscription const & other) const {
		return other._subscriptionId == _subscriptionId;
	}

	EventSubscription EventSubscription::create(EventContext & eventContext, EventHandler const & eventHandler, EventMessageType const eventMessageType) {
		EventSubscription subscription{ eventContext, eventHandler, eventMessageType };
		eventContext.subscribe(subscription);

		return subscription;
	}
}
