#include "PlatformIndependence/Input/MouseInputManager.h"

void sp::MouseInputManager::update() {
	if (_updated) {
		_updated = true;
		return;
	}

	_xDelta = 0.0F;
	_yDelta = 0.0F;
}

void sp::MouseInputManager::updateMousePos(SpFloat const xPosition, SpFloat const yPosition) {
	_xDelta = _xPosition - xPosition;
	_yDelta = _yPosition - yPosition;

	_xPosition = xPosition;
	_yPosition = yPosition;
}
