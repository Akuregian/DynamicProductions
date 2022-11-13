#pragma once
#include <GLFW/glfw3.h>
#include <memory>

namespace Dynamic {

	class Timer {
	public:
		~Timer();
		Timer(const Timer&) = delete;
		Timer& operator=(const Timer&) = delete;

		static inline std::shared_ptr<Timer>& Reference() {
			static std::shared_ptr<Timer> reference(new Timer);
			return reference;
		}
		void Tick();
		void Initialize();

	private:
		Timer();
		float lastFrame, deltaTime;
	};

	static std::shared_ptr<Timer> Clock = Timer::Reference();

}