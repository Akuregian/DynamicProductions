#include "Events.hpp"

namespace Dynamic {


	void WindowCloseCallback(GLFWwindow* window);

	Events::~Events() { }

	void Events::Initialize() { 
		//LOG("Initialized Events");
		GLFWwindow& window = Dynamic::IEngine::Reference()->Window();
		glfwSetWindowCloseCallback(&window, WindowCloseCallback);
	}

	void Events::Poll() {
		glfwPollEvents();
	}

	void WindowCloseCallback(GLFWwindow* window) {
		Dynamic::IEngine::Reference()->Quit();
	}
}