#include <Core/Event/EventBinding.hpp>
#include <Core/Event/Message/EventMessage.hpp>
#include <Mocks/Core/Event/IEventContextMock.hpp>
#include <gtest/gtest.h>

namespace sp {
	namespace tests {
		TEST(EventBindingTest, bind) {
			// arrange
			EventMessageType const messageType{ (EventMessageType)0 };
			EventHandler const handler{ [](auto) { } };
			EventSubscription const eventSubscription{ messageType, handler };

			mocks::IEventContextMock eventContext;
			EXPECT_CALL(eventContext, subscribe)
				.WillOnce(::testing::ReturnRef(eventSubscription));

			// act - assert
			EventBinding eventBinding;
			eventBinding.bind(eventContext, messageType, handler);
		}

		TEST(EventBindingTest, unbind) {
			// arrange
			EventMessageType const messageType{ (EventMessageType)0 };
			EventHandler const handler{ [](auto) {} };
			EventSubscription const eventSubscription{ messageType, handler };

			mocks::IEventContextMock eventContext;\

			EXPECT_CALL(eventContext, subscribe)
				.WillOnce(::testing::ReturnRef(eventSubscription));
			EXPECT_CALL(eventContext, unsubscribe)
				.Times(1);

			EventBinding eventBinding;
			eventBinding.bind(eventContext, messageType, handler);

			// act - assert
			eventBinding.unbind();
		}
	}
}
