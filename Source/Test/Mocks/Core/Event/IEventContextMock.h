#pragma once

#include "gmock/gmock.h"

#include "Core/Event/IEventContext.h"

namespace sp {
	namespace mocks {
		class IEventContextMock : public IEventContext {
		public:
			MOCK_METHOD(void, broadcastEvent, (EventMessage & message), (const, override));
			MOCK_METHOD(IEventSubscription const &, subscribe, (EventMessageType const messageType, EventHandler const & eventHandler), (override));
			MOCK_METHOD(void, unsubscribe, (SpInt const subscriptionId, EventMessageType const messageType), (override));
		};
	}
}