add_subdirectory("EntityComponentSystem")

add_library( Core STATIC "Core/Core.hpp" "Core/Core.cpp" )
add_library( Events  STATIC "Events/Events.hpp" "Events/Events.cpp" )
add_library( Logger  STATIC "Logger/Logger.hpp" "Logger/Logger.cpp" )
add_library( Timer   STATIC "Timer/Timer.hpp" "Timer/Timer.cpp" )
add_library( IEngine STATIC "IEngine/IEngine.hpp" "IEngine/IEngine.cpp" )

target_link_libraries( Core IEngine Logger Events Timer spdlog glfw )
target_link_libraries( Timer Core )
target_link_libraries( Logger Core )
target_link_libraries( IEngine Core )
target_link_libraries( Events Core)

target_include_directories(IEngine PUBLIC "Logger" "Timer" "Events")
target_include_directories(Events PUBLIC "IEngine" "Events" "Logger" "Timer")
