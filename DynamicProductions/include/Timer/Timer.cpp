#include "Timer.hpp"

namespace Dynamic {

	std::shared_ptr<Timer> Timer::s_Timer = std::make_shared<Timer>();

	Timer::Timer() : lastFrame(0.0f), deltaTime(0.0f) { }

	Timer::~Timer() { }

	void Timer::Tick() {
		deltaTime = glfwGetTime() - lastFrame;
		lastFrame = glfwGetTime();
	}

	void Timer::Initialize() { LOG("Initialized Timer");}
}