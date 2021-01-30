#include <Core/Event/EventBinding.h>
#include <Core/Event/EventSubscription.h>
#include <Core/Event/IEventContext.h>

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
