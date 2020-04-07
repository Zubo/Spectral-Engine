#pragma once

struct GLFWwindow;

namespace sp {
	class SpWindow {
	public:
		static void init(int const width, int const height);
		static SpWindow * const getInstance();
		
	private:
		static SpWindow * windowInstance;

	private:
		SpWindow(int const width, int const height);
		SpWindow(SpWindow const & window) = delete;

	public:
		void update() const;
		bool const initializedSuccessfuly() const;
		bool const shouldClose() const;
		GLFWwindow * const getConcreteWindow() const;
		
		inline int getWidht() const {
			return this->width;
		}

		inline int getHeight() const {
			return this->height;
		}

	private:
		int width;
		int height;
		bool initialized;
		GLFWwindow * concreteWindow = nullptr;
	};
}
