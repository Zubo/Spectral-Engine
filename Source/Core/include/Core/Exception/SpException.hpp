#pragma once

#include <exception>

#include <PlatformIndependence/SpString.hpp>

namespace sp {
	class SpException : public std::exception {
	public:
		explicit SpException(const SpString & message);
		explicit SpException(SpString && message);

	public:
		char const * what() const noexcept override;

	private:
		SpString _message;
	};
}
