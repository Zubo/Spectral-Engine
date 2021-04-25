#include <Core/Exception/SpException.hpp>

namespace sp {
	SpException::SpException(char const * const message) :
		_message{ message } {
	}

	char const * SpException::what() const {
		return _message;
	}
}
