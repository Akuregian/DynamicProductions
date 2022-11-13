#pragma once
#include "IEngine.hpp"

namespace Dynamic {

	class Events {
	public:
		~Events();
		Events(const Events&) = delete;
		Events& operator=(const Events&) = delete;

		static inline std::shared_ptr<Events> Reference() {
			static std::shared_ptr<Events> reference(new Events);
			return reference;
		}

		void Poll();
		void Initialize();

	private:
		Events() { }
	};

	static std::shared_ptr<Events> Event = Events::Reference();
}