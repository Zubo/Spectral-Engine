#include <Core/Event/EventBinding.hpp>
#include <Core/Event/EventSubscription.hpp>
#include <Core/Event/IEventContext.hpp>

namespace sp {
	EventBinding::~EventBinding() {
	}

	void EventBinding::bind(IEventContext & eventContext, EventMessageType const messageType, EventHandler const & handler) {
		if (_bound) {
			unbind();
		}

		IEventSubscription const & eventSubscription = eventContext.subscribe(messageType, handler);

		_subscriptionId = eventSubscription.getSubscriptionId();
		_messageType = messageType;
		_eventContextRef = eventContext;
		_bound = true;
	}

	void EventBinding::unbind() {
		_eventContextRef->unsubscribe(_subscriptionId, _messageType);
		_bound = false;
	}
}
