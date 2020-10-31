#pragma once

#include <functional>
#include <optional>

namespace sp {
	template<typename T>
	class OptionalRef {
	public:
		OptionalRef() = default;
		OptionalRef(const OptionalRef<T>& other) = default;

		OptionalRef(T & ref) : _component{ ref } {
		}

		~OptionalRef() = default;

	public:
		bool HasRef() const {
			return _component.has_value();
		}

		T & operator*() const {
			return _component.value().get();
		}

		T * operator->() const {
			return &(_component.value().get());
		}
		
	private:
		std::optional< std::reference_wrapper<T> > _component;
	};
}
