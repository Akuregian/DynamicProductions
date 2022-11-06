# CMakeList.txt : CMake project for DynamicProductions, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(PRE_COMPILED_HEADERS "include/PreCompiledHeader/pch.hpp")

# Add source to this project's executable.
add_executable (DynamicProductions 
			"include/IEngine/IEngine.hpp" 
			"include/Logger/Logger.hpp"
			"include/Timer/Timer.hpp" 
			"include/Events/Events.hpp"
			"include/Core/Core.hpp"

			"include/IEngine/main.cpp" 
			"include/Logger/Logger.cpp"
			"include/IEngine/IEngine.cpp" 
			"include/Timer/Timer.cpp" 
			"include/Events/Events.cpp"
			
	)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DynamicProductions PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
target_precompile_headers(${PROJECT_NAME} PUBLIC ${PRE_COMPILED_HEADERS})

# Disbales GLFW Tests, Examples and Documentation
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("libs/glfw-3.3.8")
add_subdirectory("libs/spdlog-1.x")

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw spdlog::spdlog)
target_include_directories(${PROJECT_NAME} PUBLIC "include/PreCompiledHeader")

