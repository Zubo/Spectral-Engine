#include <Core/Event/Message/EventMessage.hpp>

namespace sp {
	EventMessage::EventMessage(EventMessageType const messageType) 
		: _messageType{ messageType } {
	}

	EventMessageType EventMessage::getMessageType() const {
		return _messageType;
	}
}
