#pragma once

#ifdef ASSERTIONS_ENABLED

#include <Core/Exception/SpException.hpp>
#include <Core/Utility/StringConcat.hpp>

#define SpAssert(expr, ...) \
	if (expr) { } \
	else { \
		throw sp::SpException(sp::Concat(__FILE__, __LINE__, "Error message: ", ##__VA_ARGS__).c_str()); \
	}

#else

#define SpAssert(expr, ...)

#endif
