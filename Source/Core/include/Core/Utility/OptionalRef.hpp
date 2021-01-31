#pragma once

#include <functional>
#include <optional>

namespace sp {
	template<typename T>
	class OptionalRef {
	public:
		OptionalRef() { };
		OptionalRef(OptionalRef<T> const & other) = default;
		OptionalRef(OptionalRef<T> && other) = default;

		OptionalRef(T & ref) : _component{ ref } {
		}

		~OptionalRef() = default;

	public:
		bool HasRef() const {
			return _component.has_value();
		}

		operator T& () const {
			return _component.value().get();
		}

		T * operator->() const {
			return &(_component.value().get());
		}

		OptionalRef<T> & operator=(T & ref) {
			_component = ref;
			return *this;
		}

		OptionalRef<T> & operator=(OptionalRef<T> const & other) {
			_component = other._component;
			return *this;
		}

		OptionalRef<T> & operator=(OptionalRef<T> && other) {
			_component = std::move(other._component);
			return *this;
		}
		
	private:
		std::optional< std::reference_wrapper<T> > _component;
	};
}
