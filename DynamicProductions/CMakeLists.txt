# CMakeList.txt : CMake project for DynamicProductions, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (DynamicProductions "include/IEngine/main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DynamicProductions PROPERTY CXX_STANDARD 20)
endif()

# Disbales GLFW Tests, Examples and Documentation
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("libs/glfw-3.3.8")
add_subdirectory("libs/spdlog-1.x")

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw spdlog::spdlog)

target_include_directories(${PROJECT_NAME} PUBLIC 
		"include/IEngine" 
		"include/Core"
		"include/Events"
		"include/Logger"
		"include/Timer"
		"include/EntityComponentSystem/Base"
)
add_subdirectory("include")

target_link_libraries(${PROJECT_NAME} Core)
target_link_libraries(${PROJECT_NAME} Events)
target_link_libraries(${PROJECT_NAME} Logger)
target_link_libraries(${PROJECT_NAME} Timer)
target_link_libraries(${PROJECT_NAME} IEngine)
target_link_libraries(${PROJECT_NAME} ${EntityComponentSystem})

