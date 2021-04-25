#include <utility>

#include <Core/Exception/SpException.hpp>

namespace sp {
	SpException::SpException(const SpString & message) :
		_message{ message } {
	}

	SpException::SpException(SpString && message) : 
		_message{ std::move(message) } {
	}

	char const * SpException::what() const noexcept {
		return _message.c_str();
	}
}
