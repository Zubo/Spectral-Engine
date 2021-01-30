#pragma once

#include <Core/Event/Message/EventMessageType.hpp>

namespace sp {
	class EventMessage {
	public:
		EventMessage(EventMessageType const messageType);
		virtual ~EventMessage() = default;

	public:
		EventMessageType getMessageType() const;

	protected:
		EventMessageType _messageType;
	};
}
