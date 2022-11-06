#pragma once

#include "pch.hpp"

namespace Dynamic {

	class Timer {
	public:
		Timer();
		~Timer();
		Timer(const Timer&) = delete;
		Timer& operator=(const Timer&) = delete;

		static inline std::shared_ptr<Timer> Reference() {
			return s_Timer;
		}
		void Tick();
		void Initialize();

	private:
		float lastFrame, deltaTime;
		static std::shared_ptr<Timer> s_Timer;
	};

	static std::shared_ptr<Timer> Clock = Timer::Reference();

}