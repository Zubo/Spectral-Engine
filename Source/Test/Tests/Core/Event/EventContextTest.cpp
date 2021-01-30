#include <gtest/gtest.h>

#include <Core/Event/EventContext.h>

namespace sp {
	namespace tests {
		TEST(EventContext, broadcastEvent) {
			// arrange
			EventContext eventContext;

			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			SpInt calledCount = 0;
			EventHandler const handler{ [&calledCount](auto) { ++calledCount; } };
			eventContext.subscribe(messageType, handler);

			// act
			EventMessage msg{ messageType };
			eventContext.broadcastEvent(msg);

			// assert
			ASSERT_EQ(calledCount, 1);
		}

		TEST(EventContext, subscribe) {
			// arrange
			EventContext eventContext;

			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			EventHandler const handler{ [](auto) {} };

			// act
			IEventSubscription const & eventSubscription = eventContext.subscribe(messageType, handler);

			// assert
			ASSERT_EQ(eventSubscription.getMessageType(), messageType);
		}

		TEST(EventContext, unsubscribe) {
			// arrange
			EventContext eventContext;

			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			EventHandler const handler{ [](auto) {} };
			IEventSubscription const & eventSubscription = eventContext.subscribe(messageType, handler);

			// act - assert
			EXPECT_NO_THROW(eventContext.unsubscribe(eventSubscription.getSubscriptionId(), messageType));
		}
	}
}
