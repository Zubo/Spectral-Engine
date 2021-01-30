#pragma once

#include "Core/Event/Message/EventMessageType.h"
#include "Core/Event/EventSubscription.h"

namespace sp {
	class IEventContext;
	class IEventHandler;

	class IEventBinding{
	public:
		virtual ~IEventBinding() = default;

	public:
		virtual void bind(IEventContext & eventContext, EventMessageType const messageType, EventHandler const & handler) = 0;
		virtual void unbind() = 0;
	};
}
