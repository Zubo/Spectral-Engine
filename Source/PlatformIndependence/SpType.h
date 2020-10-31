#pragma once

#include <stdint.h>

namespace sp
{
#ifdef COMPILE_64_BIT
	using SpInt = int;
	using SpUnsigned = unsigned int;
#endif

#ifdef COMPILE_32_BIT
	using SpInt = int32_t;
	using SpUnsigned = uint32_t;
#endif

	using SpFloat = float;
}

