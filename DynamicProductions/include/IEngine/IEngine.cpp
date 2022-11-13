#include "IEngine.hpp"

namespace Dynamic {

	IEngine::IEngine()
		: m_Run(true), m_Window(nullptr), WindowHeight(0), WindowWidth(0)
	{
		Logger::Init();

		glfwInit();

		LOG("Instance of IEngine Created");

		m_Window = glfwCreateWindow(800, 800, "Dynamic Productions", NULL, NULL);
		assert(m_Window && "Error Creating Window");
		glfwMakeContextCurrent(m_Window);
	}

	IEngine::~IEngine() {  glfwTerminate(); }

	void IEngine::Initialize() { /* LOG("Initialized Engine"); */ };

	void IEngine::Update() {  }

	void IEngine::Quit() { 
		glfwSetWindowShouldClose(m_Window, GLFW_TRUE); 
		glfwDestroyWindow(m_Window);
		m_Run = false; 
	}
}