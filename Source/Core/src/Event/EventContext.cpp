#include <Core/Event/EventContext.hpp>

namespace sp {
	void EventContext::broadcastEvent(EventMessage & message) const {
		EventMessageType const messageType{ message.getMessageType() };
		
		auto subscritpionVectorIter = _eventHandlerMap.find(messageType);
		if (subscritpionVectorIter == _eventHandlerMap.end()) {
			return;
		}

		SubscriptionVector const & subscriptionVector{ subscritpionVectorIter->second };

		for (auto && subscription : subscriptionVector) {
			subscription.handle(message);
		}
	}

	IEventSubscription const & EventContext::subscribe(EventMessageType const messageType, EventHandler const & eventHandler) {
		SubscriptionVector & subscriptionVector{ _eventHandlerMap[messageType] };
		EventSubscription const & sub = subscriptionVector.emplace_back(EventSubscription{ messageType, eventHandler });
		return sub;
	}

	void EventContext::unsubscribe(SpInt const subscriptionId, EventMessageType const messageType) {
		SubscriptionVector & subscriptionVector{ _eventHandlerMap[messageType] };

		auto const existingSubscrIter{ 
			std::find_if(subscriptionVector.begin(), subscriptionVector.end(), 
			[subscriptionId](EventSubscription const & subscription) { return subscription.getSubscriptionId() == subscriptionId; })
		};

		subscriptionVector.erase(existingSubscrIter);
	}
}
