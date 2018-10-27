#include "window.hpp"

Window::Window()
	:width(0), height(0)
{
	
}

Window::Window(GLuint Width, GLuint Height)
	:width(Width), height(Height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
}

Window::~Window()
{
}

void Window::Init(GLuint Width, GLuint Height, const std::string & title)
{
	window = glfwCreateWindow(Width, Height, title.c_str(), nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "window is nullptr, glfw terminating" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glewExperimental = GL_TRUE;
	glewInit();
	glGetError();

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}
