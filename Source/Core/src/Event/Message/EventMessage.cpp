#include <Core/Event/Message/EventMessage.h>

namespace sp {
	EventMessage::EventMessage(EventMessageType const messageType) 
		: _messageType{ messageType } {
	}

	EventMessageType EventMessage::getMessageType() const {
		return _messageType;
	}
}
