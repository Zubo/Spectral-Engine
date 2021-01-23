#pragma once

#include "Core/Event/Message/EventMessage.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	class ViewportChangedMessage : public EventMessage {
	public:
		ViewportChangedMessage(SpInt const width, SpInt const height);
		
	public:
		SpInt getWidth() const;
		SpInt getHeight() const;

	private:
		SpInt _width;
		SpInt _height;
	};
}
