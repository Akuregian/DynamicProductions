#include <iostream>
#include "Core.hpp"

int main(void)
{
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