#pragma once
#include "../Logger/Logger.hpp"
#include "../Timer/Timer.hpp"
#include "../Events/Events.hpp"

namespace Dynamic {

	class IEngine {
	public:
		IEngine();
		~IEngine();
		IEngine( const IEngine& ) = delete;
		IEngine& operator=(const IEngine&) = delete;

		static void Initialize();
		static inline std::shared_ptr<IEngine>& Reference() { return s_Reference; }

		void Update();
		void Quit();

		inline const bool Run() const { return m_Run; };
		inline GLFWwindow& Window() { return *m_Window; };
		inline const float GetWindowHeight() {};
		inline const float GetWindowWidth() {};

	private:
		bool m_Run;
		GLFWwindow* m_Window;
		float WindowWidth, WindowHeight;
		static std::shared_ptr<IEngine> s_Reference;
	};

	static std::shared_ptr<IEngine> Core = IEngine::Reference();
};
