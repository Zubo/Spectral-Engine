#include <gtest/gtest.h>
#include <Core/Event/Message/EventMessage.hpp>

namespace sp {
	namespace tests {
		TEST(MessageTest, getMessageType) {
			// arrange
			constexpr EventMessageType msgType{ static_cast<EventMessageType>(0) };
			EventMessage const message{ msgType };

			// act
			EventMessageType const receivedMsgType{ message.getMessageType() };

			// assert
			ASSERT_EQ(msgType, receivedMsgType);
		}
	}
}
