#include "MouseInputManager.h"

void sp::MouseInputManager::update() {
	if (this->_updated) {
		this->_updated = true;
		return;
	}

	this->_xDelta = 0.0F;
	this->_yDelta = 0.0F;
}

void sp::MouseInputManager::updateMousePos(SpFloat const xPosition, SpFloat const yPosition) {
	this->_xDelta = this->_xPosition - xPosition;
	this->_yDelta = this->_yPosition - yPosition;

	this->_xPosition = xPosition;
	this->_yPosition = yPosition;
}
