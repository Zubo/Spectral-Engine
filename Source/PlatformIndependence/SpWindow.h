#pragma once

#include <memory>

#include "PlatformIndependence/SpType.h"

struct GLFWwindow;

namespace sp {
	class SpWindow {
	public:
		static std::unique_ptr<SpWindow> create(SpInt const width, SpInt const height);

	public:
		~SpWindow();

	private:
		SpWindow(SpInt const width, SpInt const height);
		SpWindow(SpWindow const & window) = delete;

	public:
		void update() const;
		bool const initializedSuccessfuly() const;
		bool const shouldClose() const;
		GLFWwindow * const getConcreteWindow() const;

		inline SpInt getWidht() const {
			return _width;
		}

		inline SpInt getHeight() const {
			return _height;
		}

	private:
		SpInt _width;
		SpInt _height;
		bool _initialized;
		GLFWwindow * _concreteWindow = nullptr;
	};
}
