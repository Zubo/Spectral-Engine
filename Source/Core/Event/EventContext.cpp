#include "Core/Event/EventContext.h"

namespace sp {
	void EventContext::subscribe(EventSubscription const & eventSubscription) {
		EventMessageType const messageType = eventSubscription.getMessageType();
		SubscriptionVector & subscriptionVector{ _eventHandlerMap[messageType] };

		auto const existingSubscrIter{ std::find(subscriptionVector.begin(), subscriptionVector.end(), eventSubscription) };

		if (existingSubscrIter != subscriptionVector.end()) {
			throw "Error: Trying to insert event subscription that already exists. Event subscription must be unique!";
		}

		subscriptionVector.emplace_back(eventSubscription);
	}

	void EventContext::unsubscribe(EventSubscription const & eventSubscription) {
		EventMessageType const messageType = eventSubscription.getMessageType();
		SubscriptionVector & subscriptionVector{ _eventHandlerMap[messageType] };

		auto const existingSubscrIter{ std::find(subscriptionVector.begin(), subscriptionVector.end(), eventSubscription) };
		subscriptionVector.erase(existingSubscrIter);
	}
}
