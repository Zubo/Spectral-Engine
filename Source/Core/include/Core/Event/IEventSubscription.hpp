#pragma once

#include <Core/Event/Message/EventMessage.hpp>
#include <Core/Event/Message/EventMessageType.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class IEventSubscription {
	public:
		virtual ~IEventSubscription() = default;

	public:
		virtual void handle(EventMessage & message) const = 0;
		virtual EventMessageType getMessageType() const = 0;
		virtual SpInt getSubscriptionId() const = 0;
		virtual bool operator==(IEventSubscription const & other) const = 0;
	};
}
