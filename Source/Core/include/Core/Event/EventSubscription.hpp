#pragma once

#include <functional>

#include <Core/Event/IEventSubscription.hpp>
#include <Core/Event/IEventContext.hpp>
#include <Core/Event/Message/EventMessage.hpp>
#include <Core/Event/Message/EventMessageType.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class EventSubscription : public IEventSubscription {
	public:
		EventSubscription(EventMessageType const eventMessageType, EventHandler const & eventHandler);
		EventSubscription(EventSubscription const & other) = default;
		EventSubscription(EventSubscription && other);
		~EventSubscription() = default;

	public:
		virtual void handle(EventMessage & message) const override;
		virtual EventMessageType getMessageType() const override;
		virtual SpInt getSubscriptionId() const override;
		virtual bool operator==(IEventSubscription const & other) const override;
		void operator=(EventSubscription const & other);

	private:
		SpInt _subscriptionId;
		EventMessageType _eventMessageType;
		EventHandler _eventHandler;

	public:
		static constexpr SpInt ErrorSubscriptionId = -1;

	private:
		static SpInt _nextSubscriptionId;
	};
}
