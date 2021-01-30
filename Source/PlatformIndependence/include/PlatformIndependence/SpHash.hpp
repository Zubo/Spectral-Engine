#pragma once

#include <functional>

namespace sp {
	using SpHashValue = std::size_t;
	
	template<class T>
	SpHashValue calculateHashValue(T obj) {
		std::hash<T> hash;
		return hash(obj);
	}
}
