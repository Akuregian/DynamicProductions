#include "Events.hpp"

namespace Dynamic {

	std::shared_ptr<Events> Events::s_Event = std::make_shared<Events>();

	void WindowCloseCallback(GLFWwindow* window);

	Events::~Events() { }

	void Events::Initialize() { 
		LOG("Initialized Events");
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