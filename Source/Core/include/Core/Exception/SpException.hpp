#pragma once

#include <exception>

namespace sp {
	class SpException : public std::exception {
	public:
		SpException(char const * const message);

	public:
		char const * what() const override;

	private:
		char const * _message;
	};
}
