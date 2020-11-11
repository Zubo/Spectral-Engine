#pragma once

#include "Core/Event/Message/EventMessageType.h"

namespace sp {
	class EventMessage {
	public:
		EventMessage() = delete;
		virtual ~EventMessage() = default;

	public:
		EventMessageType getMessageType() const;

	protected:
		EventMessageType _messageType;
	};
}
