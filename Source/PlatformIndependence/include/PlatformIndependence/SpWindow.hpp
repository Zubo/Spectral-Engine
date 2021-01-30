#pragma once

#include <functional>
#include <memory>

#include <PlatformIndependence/Input/Input.hpp>
#include <PlatformIndependence/SpType.hpp>

struct GLFWwindow;

namespace sp {
	class SpWindow {
	public:
		using SetFramebufferSizeCallback = std::function<void(SpInt, SpInt)>;

	public:
		static std::unique_ptr<SpWindow> create(SpInt const width, SpInt const height, bool const isMainWindow);

	private:
		static void initGLFW();
		static void initGlad();

	public:
		~SpWindow();

	private:
		SpWindow(SpInt const width, SpInt const height, bool const isMainWindow, GLFWwindow * const concreteWindow);
		SpWindow(SpWindow const & window) = delete;

	public:
		void update() const;
		bool shouldClose() const;
		void setCursorEnabled(bool const cursorEnabled) const;
		Input const & getInput() const;
		Input & getInput();
		void registerSetFramebufferSizeCallback(SetFramebufferSizeCallback callback);
		void makeCurrentContext() const;
		void swapBuffers() const;
		void pollEvents() const;

		inline SpInt getWidht() const {
			return _width;
		}

		inline SpInt getHeight() const {
			return _height;
		}

	private:
		SpInt _width;
		SpInt _height;
		GLFWwindow * _concreteWindow = nullptr;
		std::unique_ptr<Input> _inputUnique;
		SetFramebufferSizeCallback _setFramebufferSizeCallback;
		bool _isMainWindow = false;

	private:
		static bool _GLFWInitialized;
		static bool _gladInitialized;
	};
}
