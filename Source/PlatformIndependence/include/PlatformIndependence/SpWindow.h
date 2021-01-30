#pragma once

#include <functional>
#include <memory>

#include "PlatformIndependence/Input/Input.h"
#include "PlatformIndependence/SpType.h"

struct GLFWwindow;

namespace sp {
	class SpWindow {
	public:
		using SetFramebufferSizeCallback = std::function<void(SpInt, SpInt)>;

	public:
		static std::unique_ptr<SpWindow> create(SpInt const width, SpInt const height);

	public:
		~SpWindow();

	private:
		SpWindow(SpInt const width, SpInt const height);
		SpWindow(SpWindow const & window) = delete;

	public:
		void update() const;
		bool shouldClose() const;
		void setCursorEnabled(bool const cursorEnabled) const;
		GLFWwindow * getConcreteWindow() const;
		Input const & getInput() const;
		Input & getInput();
		void registerSetFramebufferSizeCallback(SetFramebufferSizeCallback callback);

		inline SpInt getWidht() const {
			return _width;
		}

		inline SpInt getHeight() const {
			return _height;
		}

	private:
		void initGLFW();

	private:
		SpInt _width;
		SpInt _height;
		GLFWwindow * _concreteWindow = nullptr;
		std::unique_ptr<Input> _inputUnique;
		SetFramebufferSizeCallback _setFramebufferSizeCallback;

	private:
		static bool _GLFWInitialized;
	};
}
