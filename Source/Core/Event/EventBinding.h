#pragma once

#include <functional>

#include "Core/Event/EventSubscription.h"
#include "Core/Event/Message/EventMessageType.h"
#include "Core/Utility/OptionalRef.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	class EventContext;

	class EventBinding {
	public:
		EventBinding() = default;
		~EventBinding();

	public:
		void bind(EventContext & eventContext, EventMessageType const messageType, EventHandler const & handler);
		void unbind();

	private:
		SpInt _subscriptionId;
		EventMessageType _messageType;
		OptionalRef<EventContext> _eventContextRef;
		bool _bound = false;
	};
}