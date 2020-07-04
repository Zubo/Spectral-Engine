#pragma once

#include "PlatformIndependence/SpType.h"

struct GLFWwindow;

namespace sp {
	class SpWindow {
	public:
		static void init(SpInt const width, SpInt const height);
		static SpWindow * const getInstance();

	private:
		static SpWindow * windowInstance;

	private:
		SpWindow(SpInt const width, SpInt const height);
		SpWindow(SpWindow const & window) = delete;

	public:
		void update() const;
		bool const initializedSuccessfuly() const;
		bool const shouldClose() const;
		GLFWwindow * const getConcreteWindow() const;

		inline SpInt getWidht() const {
			return this->_width;
		}

		inline SpInt getHeight() const {
			return this->_height;
		}

	private:
		SpInt _width;
		SpInt _height;
		bool _initialized;
		GLFWwindow * _concreteWindow = nullptr;
	};
}
