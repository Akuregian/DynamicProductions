#pragma once
#include "pch.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace Dynamic {

	class Logger {
	public:
		static void Init();
		static inline std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
	};
}

#define LOG(...) Dynamic::Logger::GetEngineLogger()->warn(__VA_ARGS__)

