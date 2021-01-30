#include <memory>

#include <Core/Event/EventSubscription.h>

namespace sp {
	SpInt EventSubscription::_nextSubscriptionId{ 0 };

	EventSubscription::EventSubscription(EventMessageType const eventMessageType, EventHandler const & eventHandler) :
		_subscriptionId{ _nextSubscriptionId++ },
		_eventMessageType{ eventMessageType },
		_eventHandler{ eventHandler } {
	}

	EventSubscription::EventSubscription(EventSubscription && other) :
		_subscriptionId{ other._subscriptionId },
		_eventMessageType{ other._eventMessageType },
		_eventHandler{ other._eventHandler } {
		other._subscriptionId = ErrorSubscriptionId;
		other._eventMessageType = EventMessageType::ErrorType;
		other._eventHandler = NULL;
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

	bool EventSubscription::operator==(IEventSubscription const & other) const {
		const EventSubscription * const otherEventSubscription{ dynamic_cast<const EventSubscription *>(&other) };

		if (otherEventSubscription == nullptr) {
			return false;
		}

		return otherEventSubscription->_subscriptionId == _subscriptionId;
	}

	void EventSubscription::operator=(EventSubscription const & other) {
		_subscriptionId = other._subscriptionId;
		_eventHandler = other._eventHandler;
		_eventMessageType = other._eventMessageType;
	}
}
