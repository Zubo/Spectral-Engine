#pragma once

#include <functional>

#include <Core/Event/IEventBinding.h>
#include <Core/Event/Message/EventMessageType.h>
#include <Core/Utility/OptionalRef.h>
#include <PlatformIndependence/SpType.h>

namespace sp {
	class EventBinding : public IEventBinding {
	public:
		EventBinding() = default;
		~EventBinding();

	public:
		virtual void bind(IEventContext & eventContext, EventMessageType const messageType, EventHandler const & handler) override;
		virtual void unbind() override;

	private:
		SpInt _subscriptionId;
		EventMessageType _messageType;
		OptionalRef<IEventContext> _eventContextRef;
		bool _bound = false;
	};
}
