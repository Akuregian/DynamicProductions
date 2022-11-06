#pragma once
#include "pch.hpp"
#include "../IEngine/IEngine.hpp"

namespace Dynamic {

	class Events {
	public:
		Events() { }
		~Events();
		Events(const Events&) = delete;
		Events& operator=(const Events&) = delete;

		static inline std::shared_ptr<Events> Reference() {
			return s_Event;
		}

		void Poll();
		void Initialize();

	private:
		static std::shared_ptr<Events> s_Event;

	};

	static std::shared_ptr<Events> Event = Events::Reference();
}