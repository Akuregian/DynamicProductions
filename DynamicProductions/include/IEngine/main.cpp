#include <iostream>
#include "Core.hpp"
#include <Types.hpp>

namespace ECS {
	struct Component {
		virtual ~Component() {};
	};
}

class Test1 : public ECS::Component {

};

class Test2 : public ECS::Component {

};


int main(void)
{

	auto typeID1 = ECS::ComponentType<Test1>();
	auto typeID2 = ECS::ComponentType<Test1>();

	auto typeID3 = ECS::ComponentType<Test2>();

	std::cout << "Component: " << typeID1 << std::endl;
	std::cout << "Component: " << typeID2 << std::endl;
	std::cout << "Component: " << typeID3 << std::endl;


	Dynamic::Core->Initialize();
	Dynamic::Clock->Initialize();
	Dynamic::Event->Initialize();

	while (Dynamic::IEngine::Reference()->Run()) {
		Dynamic::Clock->Tick();
		Dynamic::Event->Poll();
		Dynamic::Core->Update();
	}

	std::cin.get();
	return EXIT_SUCCESS;
}