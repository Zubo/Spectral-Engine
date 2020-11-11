#include "Core/Event/Message/EventMessage.h"

namespace sp {
	EventMessageType EventMessage::getMessageType() const {
		return _messageType;
	}
}
