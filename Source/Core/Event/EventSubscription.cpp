#include <memory>

#include "Core/Event/EventSubscription.h"

namespace sp {
	SpInt EventSubscription::_nextSubscriptionId{ 0 };

	EventSubscription::EventSubscription(EventMessageType const eventMessageType, EventHandler const & eventHandler) :
		_subscriptionId{ _nextSubscriptionId++ },
		_eventMessageType{ eventMessageType },
		_eventHandler{ eventHandler } {
	}

	void EventSubscription::handle(EventMessage & message) const {
		_eventHandler(message);
	}

	EventMessageType EventSubscription::getMessageType() const {
		return _eventMessageType;
	}

	SpInt EventSubscription::getSubscriptionId() const {
		return _subscriptionId;
	}

	void EventSubscription::operator=(EventSubscription const & other) {
		_subscriptionId = other._subscriptionId;
		_eventHandler = other._eventHandler;
		_eventMessageType = other._eventMessageType;
	}

	bool EventSubscription::operator==(EventSubscription const & other) const {
		return other._subscriptionId == _subscriptionId;
	}
}
