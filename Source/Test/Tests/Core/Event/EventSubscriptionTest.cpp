#include <memory>
#include <gtest/gtest.h>

#include <Core/Event/EventSubscription.h>

namespace sp {
	namespace tests {
		TEST(EventSubscription, CopyConstructor) {
			// arrange
			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			EventHandler handler{ [](auto) {} };
			EventSubscription subscription1{ messageType, handler };
			EventSubscription subscription2{ subscription1 };

			// act - assert
			ASSERT_EQ(subscription1, subscription2);
		}

		TEST(EventSubscription, MoveConstructor) {
			// arrange
			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			EventHandler handler{ [](auto) {} };
			EventSubscription subscription1{ messageType, handler };
			SpInt const firstSubscriptionId{ subscription1.getSubscriptionId() };

			// act
			EventSubscription subscription2{ std::move(subscription1) };

			// assert
			ASSERT_EQ(subscription2.getSubscriptionId(), firstSubscriptionId);
			ASSERT_EQ(subscription2.getMessageType(), messageType);
			ASSERT_EQ(subscription1.getSubscriptionId(), EventSubscription::ErrorSubscriptionId);
			ASSERT_EQ(subscription1.getMessageType(), EventMessageType::ErrorType);
			EventMessage msg{ messageType };
			ASSERT_ANY_THROW(subscription1.handle(msg));
		}


		TEST(EventSubscription, handle) {
			// arrange
			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			SpInt callCount{ 0 };
			
			EventHandler handler{ [&callCount](auto) { ++callCount; } };

			EventSubscription subscription{ messageType, handler };

			// act
			EventMessage msg{ messageType };
			subscription.handle(msg);

			// assert
			ASSERT_EQ(callCount, 1);
		}
		
		TEST(EventSubscription, getMessageType) {
			// arrange
			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			EventHandler handler{ [](auto) { } };
			EventSubscription subscription{ messageType, handler };

			// act
			EventMessageType returnedMessageType{ subscription.getMessageType() };

			// assert
			ASSERT_EQ(messageType, returnedMessageType);
		}

		TEST(EventSubscription, getSubscriptionId) {
			// arrange
			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			EventHandler handler{ [](auto) {} };
			EventSubscription subscription{ messageType, handler };

			// act - assert
			EXPECT_NO_THROW(subscription.getSubscriptionId());
		}

		TEST(EventSubscription, equalsOperator_equal) {
			// arrange
			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			EventHandler handler{ [](auto) {} };
			EventSubscription subscription{ messageType, handler };

			// act - assert
			ASSERT_TRUE(subscription == subscription);
		}

		TEST(EventSubscription, equalsOperator_nonEqual) {
			// arrange
			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			EventHandler handler{ [](auto) {} };
			EventSubscription subscription1{ messageType, handler };
			EventSubscription subscription2{ messageType, handler };

			// act - assert
			ASSERT_FALSE(subscription1 == subscription2);
		}

		TEST(EventSubscription, assignmentOperator) {
			// arrange
			EventMessageType messageType{ static_cast<EventMessageType>(0) };
			EventHandler handler{ [](auto) {} };
			EventSubscription subscription1{ messageType, handler };
			EventSubscription subscription2{ messageType, handler };

			// act
			subscription2 = subscription1;

			// assert
			ASSERT_EQ(subscription1, subscription2);
		}
	}
}
