#include "Logger.hpp"

namespace Dynamic {


	Logger::Logger() {
		Logger::Init();
	}

	Logger::~Logger() { }

	void Logger::Init() {
		 spdlog::set_pattern("%^[%T] %n: %v%$");
		 Logger::GetEngineLogger() = spdlog::stdout_color_mt("Dynamic Productions Logger");
		 Logger::GetEngineLogger()->set_level(spdlog::level::trace);
	}

}