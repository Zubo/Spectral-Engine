#include <Core/Event/Message/Messages/ViewportChangedMessage.hpp>

namespace sp {
	ViewportChangedMessage::ViewportChangedMessage(SpInt const width, SpInt const height) :
		EventMessage{ EventMessageType::ViewportChanged },
		_width{ width },
		_height{ height } {
	}

	SpInt ViewportChangedMessage::getWidth() const {
		return _width;
	}

	SpInt ViewportChangedMessage::getHeight() const	{
		return _height;
	}
}
