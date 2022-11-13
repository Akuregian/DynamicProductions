#include "Timer.hpp"

namespace Dynamic {

	Timer::Timer() : lastFrame(0.0f), deltaTime(0.0f) { }

	Timer::~Timer() { }

	void Timer::Tick() {
		deltaTime = glfwGetTime() - lastFrame;
		lastFrame = glfwGetTime();
	}

	void Timer::Initialize() {/* LOG("Initialized Timer"); */ }
}