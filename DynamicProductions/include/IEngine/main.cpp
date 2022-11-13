#include <iostream>
#include "Core.hpp"

#include "Types.hpp"
#include "EntityManager.hpp"

class TestComponent1 : public ECS::BaseComponent {

};

int main(void)
{

	ECS::EntityManager mngr;

	auto id1 = mngr.AddNewEntity();
	auto id2 = mngr.AddNewEntity();
	auto id3 = mngr.AddNewEntity();

	std::cout << "ComponentID " << id1 << " " << id2 << std::endl;

	mngr.DestroyEntity(id2);

	auto typeID1 = ECS::ComponentType<TestComponent1>();
	std::cout << "ComponentID " << id1 << " " << id3 << " " << typeID1 << std::endl;


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