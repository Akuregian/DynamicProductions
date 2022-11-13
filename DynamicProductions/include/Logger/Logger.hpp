#pragma once
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace Dynamic {

	class Logger {
	public:
		~Logger();
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;

		static void Init();
		static inline std::shared_ptr<spdlog::logger> GetEngineLogger() {
			static std::shared_ptr<spdlog::logger> reference(new spdlog::logger("Dynamic Productions"));
			return reference; 
		};

	private:
		Logger();
	};
}

#define LOG(...) Dynamic::Logger::GetEngineLogger()->warn(__VA_ARGS__)

